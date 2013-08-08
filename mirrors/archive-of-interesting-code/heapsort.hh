/****************************************************************
 * File: Heapsort.hh
 * Author: Keith Schwarz (htiek@cs.stanford.edu)
 *
 * Implementation of the Heapsort algorithm, a @(n lg n) sort
 * algorithm (here, @ is the ASCII stand-in for big theta).
 * Heapsort works by rearranging the elements of the input array
 * into a binary max-heap, then continuously dequeueing the max
 * element and placing it at the back of the array.  It is one
 * of the fastest and most reliable sorting algorithms, and is
 * a key building block of various hybrid sorts such as
 * introsort.
 *
 * The algorithm runs in two phases.  In the first phase, in
 * O(n) time, the algorithm rearranges the elements in the
 * range to put them into a max-heap.  In the second phase,
 * the algorithm continuously removes the maximum element
 * from the heap, places it at the last spot in the array,
 * then repeats.  This step takes @(n lg n) and accounts
 * for the majority of the runtime.
 *
 * Note that this could be done using the STL make_heap
 * and sort_heap algorithms.  However, in the interests
 * of explaining this algorithm in more detail, I've
 * avoided doing so here.
 *
 * The key algorithm in Heapsort is the heap join algorithm.
 * Heap join takes as input two max-heaps and a new value,
 * then produces a single max-heap from the elements.  For
 * example, given the singleton max-heaps 1 and 5 and the
 * new element 3, the heap join algorithm would begin by
 * constructing the tree
 *
 *                3
 *               / \
 *              1   5
 *
 * Then balancing it to form
 *
 *                5
 *               / \
 *              1   3
 *
 * This algorithm is useful for two reasons.  First, it allows
 * for an O(n) algorithm for constructing a max-heap from a
 * collection of data.  This algorithm works by taking n/2 of
 * the elements and creating singleton binary heaps from them.
 * Next, half of the remaining elements (n/4 of the original
 * elements) are used to join these singleton heaps together 
 * into n/4 max-heaps.  A remaining half of the remaining 
 * elements (n/8 of the original elements) are then used to
 * join these trees together, etc.  At the end, all of the
 * elements are joined together into a single max-heap of
 * all the data.
 *
 * Second, this algorithm also provides an efficient means for
 * rebalancing a heap after removing the max element.  When the
 * max element is removed, the heap is split into two different
 * max heaps.  An arbitrary leaf of the tree (chosen specifically
 * so that the resulting tree is complete) is then removed from
 * one of these two heaps, then used in the join step to
 * rebalance the heaps.
 *
 * The implementation of this algorithm is simple.  Given two
 * max-heaps and a new element, if the new element is bigger than
 * the roots of both max-heaps, then by transitivity it is bigger
 * than all of the elements of both heaps, and so the max-heap
 * formed by putting the new element as the root is a max-heap.
 * Otherwise, the larger of the roots of the two trees is
 * removed, splitting its tree in two, and that element is
 * placed as the root of the new heap.  The element used to
 * join the trees is then used to recursively join together the
 * two new disjoint trees.  In a sense, this element is
 * "bubbled down" through the tree until it comes to rest.
 *
 * The main complexity of the code is that all of these trees
 * are represented implicitly in the elements of the range to
 * be sorted.  The range of elements is structured so that
 * the first element is the root of a max-heap whose children
 * are in the second and third positions.  In general, the
 * elements are sorted so that the range is a max-heap where
 * node i has children at positions 2 * i + i and 2 * i + 2.
 * In the first step of this algorithm, this heap is built
 * up from right-to-left by constructing the leaves of the
 * max-heap using the latter elements of the array.  In
 * the second stage, the max-heap is deconstructed, putting
 * the maximum element at the end of the sequence and
 * rebalancing the tree.
 */
#ifndef Heapsort_Included
#define Heapsort_Included

#include <iterator>
#include <functional>
#include <algorithm>

/**
 * Function: Heapsort(RandomIterator begin, RandomIterator end);
 * Usage: HeapSort(v.begin(), v.end());
 * -------------------------------------------------------------
 * Sorts the elements in the range [begin, end) into ascending
 * order using the heapsort algorithm.
 */
template <typename RandomIterator>
void Heapsort(RandomIterator begin, RandomIterator end);

/**
 * Function: Heapsort(RandomIterator begin, RandomIterator end,
 *                    Comparator comp);
 * Usage: HeapSort(v.begin(), v.end(), comp);
 * -------------------------------------------------------------
 * Sorts the elements in the range [begin, end) into ascending
 * order using the heapsort algorithm.  The elements are compared
 * using the comparator comp, which should be a strict weak
 * ordering.
 */
template <typename RandomIterator, typename Comparator>
void Heapsort(RandomIterator begin, RandomIterator end,
              Comparator comp);

/* * * * * Implementation Below This Point * * * * */
namespace heapsort_detail {

  /**
   * Function: HeapJoin(RandomIterator begin, RandomIterator heapStart,
   *                    RandomIterator end, Comparator comp);
   * -----------------------------------------------------------------
   * Given a range of elements [begin, end) and a suffix [heapStart, end)
   * that represents two max-heaps with the element to join them at the
   * top, applies the heap join algorithm to rearrange the elements of
   * [heapStart, end) such that the result is a max-heap according to
   * comp.  The reason for also passing in the argument begin defining
   * the beginning of the heap is so that it is possible to compute
   * the positions of the children of each node in the sequence by
   * using the absolute position in the sequence.
   */
  template <typename RandomIterator, typename Comparator>
  void HeapJoin(RandomIterator begin, RandomIterator heapStart,
                RandomIterator end, Comparator comp) {
    /* Utility typedef.  This type represents "the distance between two 
     * RandomIterators."
     */
    typedef typename std::iterator_traits<RandomIterator>::difference_type diff_t;

    /* Cache the number of elements in the range. */
    const diff_t kNumElems = distance(begin, end);

    /* The initial position of the max element is at the top of the
     * heap, which is at the index given by the offset of heapStart
     * into the range starting at begin.
     */
    diff_t position = distance(begin, heapStart);

    /* Iterate until we have no children.  The first child of node i
     * is at position 2 * (i + 1) - 1 = 2 * i + 1, and the second
     * at 2 * (i + 1) + 1 - 1 = 2 * i + 2.
     */
    while (2 * position + 1 < kNumElems) {
      /* Get the index of the child we will compare to.  This defaults to
       * the first child, but if there are two children becomes the bigger
       * of the two.
       */
      diff_t compareIndex = 2 * position + 1;

      /* If two children exist, we only change the compare index if the 
       * second child is bigger.
       */
      if (2 * position + 2 < kNumElems &&
          comp(begin[2 * position + 1], begin[2 * position + 2]))
        compareIndex = 2 * position + 2;

      /* If we're bigger than the bigger child, we're done. */
      if (comp(begin[compareIndex], begin[position]))
        break;

      /* Otherwise, swap with the child and continue. */
      std::swap(begin[compareIndex], begin[position]);
      position = compareIndex;
    }
  }
}

/* The actual Heapsort implementation is rather straightforward - we just keep
 * HeapInserting until we get everything, then repeatedly HeapRemove the
 * max element.
 */
template <typename RandomIterator, typename Comparator>
void Heapsort(RandomIterator begin, RandomIterator end, Comparator comp) {
  /* If the range is empty or a singleton, there is nothing to do. */
  if (begin == end || begin + 1 == end)
    return;

  /* Heapify the range.  This works by building a forest of singleton
   * max-heaps out of the final elements of the range, then joining
   * them together with more and more elements.  Alternatively, this
   * can be viewed as calling HeapJoin on all suffixes of the range.
   */
  for (RandomIterator itr = end; itr != begin; --itr)
    heapsort_detail::HeapJoin(begin, itr - 1, end, comp);

  /* Now, break down the heap.  We continuously move the last element
   * of the heap into the last open position, then restore the heap
   * balance by bubbling down the last element of the heap.
   */
  for (RandomIterator itr = end - 1; itr != begin; --itr) {
    std::iter_swap(begin, itr);
    heapsort_detail::HeapJoin(begin, begin, itr, comp);
  }
}

/* The default comparator version of Heapsort just uses the default
 * comparator on elements.  The hackery with std::iterator_traits
 * is necessary to recover the underlying iterator type.
 */
template <typename RandomIterator>
void Heapsort(RandomIterator begin, RandomIterator end) {
  Heapsort(begin, end,
           std::less<typename std::iterator_traits<RandomIterator>::value_type>());
}

#endif
