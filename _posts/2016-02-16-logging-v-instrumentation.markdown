---
layout: post
title: "Logging v. Instrumentation"
date: 2016-02-16 17:39:13 -0800
external-url: http://peter.bourgon.org/blog/2016/02/07/logging-v-instrumentation.html
---

Programs aren't particularly useful when they can't tell us things.
Programs that say too much can be just as useless as programs that say
nothing at all. Programs that say something in the wrong way can cause an
undue burden.

"Logging v. Instrumentation" is a story on the last statement above.
Logging is great as an event stream of actionable data, but not great for
keeping track of the number of requests you had that day. Instrumentation,
on the other hand, does a poor job of providing rich actionable event data,
but it solves questions about utilization, saturation, and errors on your
system fairly well.

There is much more to this argument as you'd imagine. If you monitor
systems, I'd recommend considering this argument and solidifying your ideas
about when to use logging and when to use instrumentation.
