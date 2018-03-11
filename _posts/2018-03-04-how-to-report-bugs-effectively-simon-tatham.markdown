---
layout: post
title: "How to Report Bugs Effectively - Simon Tatham"
date: 2018-03-04 13:40:54 -0500
external-url: https://www.chiark.greenend.org.uk/~sgtatham/bugs.html
mirror:
---

This essay should be required reading for anyone who interacts with
technology. Your favorite app isn't working? This guide can help you
generate the best possible report so the company who makes the app has the
best chance of replicating, debugging, and fixing your problem.

> the aim of a bug report is to enable the programmer to see the program
> failing in front of them. You can either show them in person, or give
> them careful and detailed instructions on how to make it fail.

Lack of information is the top reason bug reports are closed on projects I
follow and maintain. The Homebrew team has a notorious policy of closing
any issue without enough information. As a result, they are much more
organized, much more efficient, and users get their well-reported bugs
fixed quickly.

> If you have to report a bug to a programmer who can't be present in
> person, the aim of the exercise is to enable them to reproduce the
> problem. You want the programmer to run their own copy of the program, do
> the same things to it, and make it fail in the same way. When they can
> see the problem happening in front of their eyes, then they can deal with
> it.

"Show me how to show myself" is how Tatham refers to this. Show the
programmer how to reproduce your issue in a step-by-step, tedious way.
Write out everything you did which may relate to running their program.

> also describe what happened. Tell them exactly what you saw. Tell them
> why you think what you saw is wrong; better still, tell them exactly what
> you expected to see. If you say "and then it went wrong", you have left
> out some very important information.

Next step is to show the programmer what went wrong. If they are unable to
reproduce your bug, they may still understand what happened based on what
went wrong, and what you expected to happen. Was an error message or code
printed?  Include it. Include any stacktrace that may have been printed.
This all helps them determine where the error occurred.

> When something goes wrong, immediately stop doing anything. Don't touch
> any buttons at all. Look at the screen and notice everything out of the
> ordinary, and remember it or write it down. Then perhaps start cautiously
> pressing "OK" or "Cancel", whichever seems safest. Try to develop a
> reflex reaction - if a computer does anything unexpected, freeze.

This rule – don't touch anything – is fantastic. Users can destroy their
whole workstations when some unexpected error occurs trying to fix it.
Write all the details down, exit the program, and see if you can reproduce
the bug a second time. Close attention to detail here makes for a winning
bug report.

> "What's gone wrong?" I'd ask. He would reply by telling me his current
> opinion of what needed to be fixed.

A bug report which suggests what might be going wrong is OK, but not OK if
that's all the bug report says. The most important details are reproduction
details: how can I recreate your state so I can see the error myself?
Presenting theories as to what went wrong exactly or how to fix it to the
author of a software may be very helpful, but more often than not, it's
not. It's a fine line.

Be clear, be precise, and include lots of detail. Hell, my favorite bug
reports are pull requests to the test code which introduce a test case
which reproduces the error shown. Easy to see what's happening when a
computer can reliably reproduce an issue in a test suite.

Next time you file a bug, consider modeling it after Tatham's rules here!
