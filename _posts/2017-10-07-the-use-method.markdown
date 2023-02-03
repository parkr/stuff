---
layout: post
title: "The USE Method"
date: 2017-10-07 23:16:07 -0400
external-url: https://www.brendangregg.com/usemethod.html
---

Enumerate the resources, measure errors, utilization, and saturation of
that resource, repeat.

I like the simplicity of the USE method. As an engineer who in the last 4
years has begun to learn more about hardware (virtual and physical)
limitations on production systems, this is a nice back-to-basics approach.
It requires that you take the time to understand your hardware. How is your
RAID array configured? Do you know how to measure errors, utilization, and
saturation of that system? This is therefore useful for, say, an SRE who is
encountering a performance regression in a technology new to them. What
resources does it use? Measure errors, utilization, and saturation until
you’ve found a resource that is bottlenecked, or until all resources look
fine.

I wonder how methodologies like this could be used to improve alerts:
measuring these resources & setting warning and error thresholds would go a
long way to decreasing mean time to diagnose. If checking these were so
automatic and so built into monitoring systems & tooling, could we move
past an entire class of performance problems more quickly? Could this
process be so well automated that performance regressions can be fixed
automatically by programs without human intervention? Perhaps some of that
can be accomplished.

Are there any utilities (written in Go perhaps) which help measure some of
the basic resources for instantaneous feedback? Say you have a fleet of
hardware that is well-defined (e.g. a subset of the Amazon EC2 instance
flavors). Does a program exist which can simply gather the USE method
metrics and report back after some sampling timeframe?

This post gave me a lot to think about.
