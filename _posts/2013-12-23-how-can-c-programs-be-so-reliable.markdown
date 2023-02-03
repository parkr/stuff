---
layout: post
title: "How Can C Programs Be So Reliable?"
date: 2013-12-23 00:07:24 -0500
external-url: https://tratt.net/laurie/blog/2008/how_can_c_programs_be_so_reliable.html
---

Laurence Tratt writes eloquently on the topic of software robustness and
language choice. In this short blog post, he explores the possibilities of why
programs written in C tend to be more robust.

It's given me more to think about as I code. How am I handling exceptions? What
is the underlying representation of this method? Is it thread-safe? If I change
the value of array `a` which is set to equal array `b`, does array `b` also
update? _Etcetera, etcetera, etcetera._

Writing robust code is hard, but not impossible. Through thoughtful, careful
crafting of code, you can achieve what most C programmers must do by default.
