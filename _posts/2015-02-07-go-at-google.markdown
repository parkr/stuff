---
layout: post
title: "Go at Google"
date: 2015-02-07 21:21:01 -0800
external-url: https://www.infoq.com/presentations/Go-Google
---

Rob Pike breaks down the motivations for writing a new programming language
for use at Google, namely [Go](https://golang.org). He walks through the
difficulties Google was having with its go-to language, C++, and how a new
language could tackle those problems. In 2007, Rob Pike, Ken Thompson, and
Robert Griesemer began designing a new language to tackle the frustrations
and friction in the C++, Java and Python workflows at Google. At four
minutes in, he describes them:

1. slow builds
2. uncontrolled dependencies (`#ifndef`'s everywhere)
3. each programmer using a different subset of the language
4. poor program understanding (documentation, etc.)
5. duplication of effort
6. cost of updates (e.g. retrofitting an api change)
7. version skew
8. difficulty of automation (auto rewriters, etc.): tooling
9. cross-language builds (inline python in a c++ program, for example)

He notes the following: *Language features don't usually address these.*

I found this talk incredibly interesting not only because I have used Go
and it is interesting to learn about its history and motivations, but
because the motivations do in fact extend beyond Google, particularly in
the duplication of effort, code readability, and dependency management
aspects of programming. In the start-up world (a world Google exited many
years ago), code is often written as though it were ephemeral. Due to this
attitude toward the longevity of code, most start-ups have a huge problem
with poorly-architected "legacy code" that slows the team down. The natural
inclination for the future-minded start-up CTO is to write huge layers of
abstraction into the code base, which often winds up confusing future
engineers even further.

What Go does is make it easy and "feel right" to use a lot of composition.
And guess what: composition scales really nicely. Imagining your system
from the perspective of composition offers some real benefits over
imagining it from the perspective of an inheritance tree, and it saves a
lot of headaches as a result. Additionally, the concurrency support is
extremely good, the portability of programs is fantastic, and the lack of
arguments about code style (`go fmt`) is just terrific.

After hearing this talk, I'm going to pick up Go in the future as I start
building new systems that don't require a lot of type dynamicity.
