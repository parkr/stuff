/******************************************************************************
 * File: RabinKarp.hh
 * Author: Keith Schwarz (htiek@cs.stanford.edu)
 *
 * An implementation of the Rabin-Karp string-matching algorithm.  Given two
 * strings - a text string T and a pattern string P, the Rabin-Karp algorithm
 * outputs the position of the first spot in which P matches T, or reports that
 * no such matching exists.
 *
 * The Rabin-Karp algorithm can be thought of as an improvement over the naive
 * string matching algorithm that tries to avoid unnecessary comparisons by
 * using a hash function.  In particular, suppose that we have an efficient way
 * (say, O(1)) for computing a hash function for each block of |P| consecutive
 * characters in the pattern string.  We can then get a very efficient string-
 * matching algorithm that works as follows.  For each block of |P| characters
 * in the string, compute its hash function in O(1).  If the hash value matches
 * the hash value of the pattern P, then check whether that particular sequence
 * matches the pattern P.  Assuming that we don't have too many hash 
 * collisions, this approach avoids a lot of unnecessary comparisons in which
 * a potential match is compared when there's no possible way for the substring
 * to match.
 *
 * The problem with this setup is that it makes a somewhat unrealistic
 * assumption - how can we compute hash functions for blocks of size O(|P|) in
 * time O(1)?  In general, this can't be done.  However, for specific choices
 * of hash functions, we can compute a hash function for a collection of blocks
 * of size O(|P|) in amortized O(1) time.  In particular, suppose that we have
 * a hash function with the following property: given a text string A0 A1 ...
 * An An+1 and given the hash code for A0 A1 ... An, then it's possible to
 * compute the hash code for the text string A1 A2 ... An An+1 in time O(1).
 * This type of hash function, called a "rolling hash function," gives us the
 * amortized guarantee we need.  We begin by computing the hash code for both
 * the pattern P and the first |P| characters of |T|, then scan over the text
 * of T, updating the rolling hash one character at a time and actually
 * checking for a match whenever the hash code of the current text string
 * matches the hash code of the pattern.
 *
 * The question now is - what's a good rolling hash funciton to use?  For this,
 * we'll use a hash function developed by Rabin and Karp specifically for this
 * purpose.  Suppose that the strings we're searching over are drawn from an
 * alphabet S = {0, 1, 2, ..., n - 1}.  Then we can treat any string in S* as
 * a number in base n.  For example, the string "12345" can be thought of as
 * number 12345, while the string "4144" would be the number 4144.  More
 * precisely, we can think of the string A1 A2 ... Ak as the base-n number
 *
 *                               k
 *                H[1 .. k] =   sum    Ai n^{k - i}
 *                             i = 1
 *
 * This then gives us a great way to update the hash code.  Given a text string
 * A1 ... Ak and a new character Ak+1, the hash code for the next value is
 *
 *                             k + 1
 *             H[2 .. k + 1] =  sum    Ai n^{k + 1 - i}
 *                             i = 2
 *
 * If we multiply the hash code for the previous string by n, we get
 *
 *                               k                     
 *               nH[1 .. k] =   sum    Ai n^{k + 1 - i}
 *                             i = 1                   
 *
 * And the difference of these two values is
 *
 *               H[1 .. k+1] - nH[0 .. k] = Ak+1 - n^k A1
 *
 * so H[2 .. k+1] = nH[1 .. k] + Ak+1 - n^k A1.  If we cache the value of
 * n^k, this can be computed in constant time.
 *
 * This is all great, but there's a catch - the hash code we're creating uses
 * O(lg k) bits to encode.  This isn't itself a problem, but on most modern
 * machines it can be a real hassle to work with variable-length hash codes. To
 * fix this, we modify the hash code so that all of the work is done modulo
 * some large prime q.  That is, the hash code is
 *
 *                               k
 *                H[1 .. k] =   sum    Ai n^{k - i}     (mod q)
 *                             i = 1
 *
 *                                k
 *                          = (  sum    (Ai n^{k - i}) mod q)  (mod q)
 *                              i = 1
 *
 * If we then work out the math once more about how to update the rolling hash
 * code, we get that
 *
 *                H[2 .. k+1] = nH[1 .. k] + Ak+1 - n^k A0 (mod q)
 *
 * Now, suppose that we pick a q such that nq fits into a single machine word
 * and such that n < q.  Then we know that nH[1 .. k] fits into a machine word,
 * since H[1 .. k] is modulo q.  We also know that Ak+1 fits into a machine
 * word, since it's a single character.  Finally, let's look at -n^k A1.  This
 * is equal to (((-n^k) mod q) A1) mod q, and also fits in a machine word
 * because A1 < n (since it's a character and is drawn from the set {0, 1, ..,
 * n-1}) and -n^k mod q < q.  Since all of these values fit into machine 
 * words, we can compute their sum in constant time.  In short, modding by q 
 * doesn't change the O(1) runtime for this step.  Interestingly, though, it 
 * does make this step much easier to implement.  Since nq fits into a word,
 * the hash code now takes up O(1) space, and more importantly space that can
 * be encoded using a single word rather than an array of words.
 *
 * The runtime of the Rabin-Karp algorithm is, in the worst case, O(|P||T|).
 * This happens if by sheer dumb luck we end up having a hash collision on
 * every length-|P| substring of T.  In the average case, though, it can be
 * shown that the number of hash collisions is expected O(1), in which case the
 * runtime of the algorithm is O(|P| + |T|), asymptotically much faster than
 * the naive implementation.  In practice, Rabin-Karp performs quite well on
 * most strings.
 */
#ifndef RabinKarp_Included
#define RabinKarp_Included

#include <iterator>  // For distance
#include <algorithm> // For equal

/**
 * RabinKarpMatch(ForwardIterator1 textBegin, ForwardIterator1 textEnd,
 *                ForwardIterator2 patternBegin, ForwardIterator2 patternEnd);
 * Usage: if (RabinKarpMatch(t.begin(), t.end(), p.begin(), p.end()) != t.end())
 * ----------------------------------------------------------------------------
 * Given a string encoded by the range [textBegin, textEnd) composed of chars,
 * returns the first instance of the string [patternBegin, patternEnd) (also
 * composed of chars) in that string using the Rabin-Karp algorithm.  If no
 * match is found, this function returns textEnd as a sentinel value.
 */
template <typename ForwardIterator1, typename ForwardIterator2>
ForwardIterator1
RabinKarpMatch(ForwardIterator1 textBegin, ForwardIterator1 textEnd,
               ForwardIterator2 patternBegin, ForwardIterator2 patternEnd) {
  /* The number of possible characters. */
  const size_t kNumChars = 256;

  /* A prime number q such that 256q fits into a 32-bit machine word.  On a 64-
   * bit machine, it may be advantageous to pick a larger prime.
   */
  const size_t kPrime = 16777213;

  /* Check that the number of characters in the text is at least as large as
   * the number of characters in the pattern.  Otherwise there's no possible
   * way that we have a match.
   */
  const size_t patternSize = size_t(std::distance(patternBegin, patternEnd));
  const size_t textSize    = size_t(std::distance(textBegin, textEnd));
  if (textSize < patternSize)
    return textEnd;
  
  /* Scan over the pattern and compute its hash code.  This works by building
   * up the base-n number one digit at a time, while always still working
   * modulo the prime.
   */
  size_t patternHash = 0;
  for (ForwardIterator2 itr = patternBegin; itr != patternEnd; ++itr) {
    /* Update the hash code by scaling up the existing hash code by the number
     * of characters, then adding in the new character.  This is the same logic
     * you would use to update the value of a base-n number by appending a new
     * digit to that number.
     */
    patternHash = (patternHash * kNumChars + (unsigned char)*itr) % kPrime;
  }
  
  /* Next, compute the hash code for the first |P| characters of the text.  We
   * declare the iterator that we'll use to scan the text outside of the loop,
   * since we'll need to remember where to pick up from.
   */
  ForwardIterator1 itr = textBegin;
  size_t hashCode = 0;
  
  /* Scan over the first patternSize characters, updating the hash code as in
   * the above case.
   */
  for (size_t i = 0; i < patternSize; ++i, ++itr)
    hashCode = (hashCode * kNumChars + (unsigned char)*itr) % kPrime;
  
  /* Before we can enter the loop, we'll need to know the value of n^k from the
   * above formula, which we'll need to have on-hand so we can update the hash
   * code.
   */
  size_t highestRadix = 1;
  for (size_t i = 0; i < patternSize; ++i)
    highestRadix = (highestRadix * kNumChars) % kPrime;
  
  /* Finally, enter the actual loop logic.  Scan across the rest of the text,
   * checking for matches and updating the hash code as appropriate.  In the
   * course of doing so, we'll maintain an iterator tracking the start of the
   * current string we're considering.
   */
  ForwardIterator1 wordStart = textBegin;
  while (true) {
    /* Check if the candidate string has a matching hash code and, if so, do the
     * actual comparison.
     */
    if (hashCode == patternHash && std::equal(patternBegin, patternEnd, wordStart))
      return wordStart;
    
    /* If we've hit the end of our input, we've failed to find a match and are
     * done.
     */
    if (itr == textEnd)
      return textEnd;
    
    /* Otherwise, update our hash code.  To do this, we need to do the
     * following:
     *
     * 1. Scale up the existing hash code by a factor of n.
     * 2. Add in the next character.
     * 3. Subtract out n^k times the character that was just evicted.
     *
     * We need to do each step individually, since otherwise we risk an integer
     * overflow, which breaks all of our logic.
     */
    
    /* Step one: Scale up the hash code. */
    hashCode = (hashCode * kNumChars) % kPrime;
    
    /* Step two: Add in the next character. */
    hashCode = (hashCode + (unsigned char)*itr) % kPrime;
    
    /* Step three: Subtract out n^k times the character we just evicted.
     * This step is tricky because we can't subtract out one unsigned value from
     * another.  Instead, we'll use the fact that
     *
     *                            -k == q - k  (mod q)
     *
     * To do the subtraction implicitly.
     */
    const size_t toSubtract = kPrime - ((highestRadix * (unsigned char)*wordStart) % kPrime);
    hashCode = (hashCode + toSubtract) % kPrime;
    
    /* Advance the word forward a step. */
    ++wordStart; ++itr;
  }
}

#endif
