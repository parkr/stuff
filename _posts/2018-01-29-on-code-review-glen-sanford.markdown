---
layout: post
title: '"On Code Review" - Glen Sanford'
date: 2018-01-29 16:35:55 -0500
external-url: https://medium.com/@9len/on-code-review-16ea85f7c585
---

Code Review is a central part of every programmer's process: generate an
idea, write the idea as code (including tests!), submit for review,
incorporate review notes, merge to mainline. It's also the only time in
this process that _other people_ are required. You can come up with your
own idea and code it and write tests and merge back into mainline without
any input from anyone else! But code review is essentially the idea that
your code has fewer bugs and greater logical coherence when it's reviewed
thoroughly by someone else. So.

Glen argues two things:

1. Make reviewing your teammates' code your top priority
2. Make the code & pull requests you write a pleasure to review

**Timely code review is crucial to feature throughput of a team.**

This article hit home when Glen wrote this:

> Pending code review represent blocked threads of execution.
> ...
> In the best case, an engineer blocked on code review is able to make progress on some other change, at the cost of (1) context switching and (2) increased memory allocation.
> ...
> In the worst case, an engineer blocked on code review can’t make any progress at all, because the work allocated to them is serialized on the review.

All the allegories to computers aside, this is exactly my frustration as a
programmer. I tend to do 10 or 12 different things because I get blocked on
code review. Then a month goes by and I forget to ping the reviewers again
and oh goodness now the code is totally outdated and I may as well give up.
Wasted work!

Glen also makes the case that we should review others' code promptly.
"Expect to spend time on code review every day, throughout the day," he
writes. Shortening iterations between reviewing, responding to review,
and re-reviewing can drastically increase work throughput of the team.
