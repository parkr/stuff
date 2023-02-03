---
layout: post
title: "Interviews: Alan Donovan and Brian Kernighan Answer Questions about Go"
date: 2015-11-29 14:20:25 -0800
external-url: https://features.slashdot.org/story/15/11/18/1748247/interviews-alan-donovan-and-brian-kernighan-answer-your-questions
mirror:
---

Great Slashdot (they're still around?) post which catalogs various
questions the Slashdot community asked of Alan Donovan and Brian Kernighan,
the authors of a new book about Go that folks are raving about.

When asked about package/dependency versioning, Donovan writes:

> Go is designed for large programs, and versioning is notoriously hard in
> that context. About ten years ago, there was an experiment to introduce
> versioning into Google's build system (which was designed by Rob Pike and
> others). It failed because of the "diamond dependency" problem, which I'm
> sure many of you have heard of---it's the classic problem of version
> numbering. Consider four packages A, B, C, D, where A depends on B and C,
> and B and C both depend on D. This is a diamond dependency. If the author
> of B decides that only version 1 of D will do, and the author of C
> requires at least version 2 of D, you have an impossible set of
> constraints. If you're lucky, you might be able to build A with both the
> old and the new versions of D, but in general this doesn't work. Since
> that experiment, Google hasn't touched automated versioning again. The
> way we do versioning is simple but manual: we treat each version of a
> package as a separate entity with a distinct name (for example, "D1",
> "D2"), and work hard to limit the number of versions of each
> package---ideally to one. That’s why versioning hasn’t been a priority
> for us at Google. However, this August, the prolific Dave Cheney proposed
> a scheme for Go package version numbering, so perhaps we’ll see
> development of this idea in the near future.

Other great nuggets in there, too.
