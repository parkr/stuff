---
layout: post
title: "UNIX Time Definitions"
date: 2015-12-13 22:41:05 -0800
external-url: https://unix4lyfe.org/time/
mirror: /unix4lyfe-time.html
---

Notables:

> According to POSIX.1, Unix time is supposed to handle a leap second by
> replaying the previous second

> Timezones are a presentation-layer problem!
> Most of your code shouldn't be dealing with timezones or local time, it
> should be passing Unix time around.

> Leap seconds happen more often than leap years.

> Time passes at a rate of one second per second for every observer. The
> frequency of a remote clock relative to an observer is affected by
> velocity and gravity. The clocks inside GPS satellites are adjusted for
> relativistic effects.

> If you want to store a humanly-readable time (e.g. logs), consider
> storing it along with Unix time, not instead of Unix time.

> When displaying time, always include the timezone offset. A time format
> without an offset is useless.

> - The system clock is inaccurate.
> - You're on a network? Every other system's clock is differently inaccurate.
