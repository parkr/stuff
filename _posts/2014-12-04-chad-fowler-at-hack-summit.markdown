---
layout: post
title: "Chad Fowler at Hack Summit"
date: 2014-12-04 19:55:30 -0800
external-url: https://www.youtube.com/watch?v=DVSNsAei0VE
---

[Chad Fowler](https://chadfowler.com/) is unassumingly brilliant. His
expertise seems to come from a perfect mixture of experience and careful
introspection and discussion of what has worked and what hasn't (and why).
He join 6Wunderkinder three weeks after I started as an intern there, in
very early 2013. I feel I have learned more from Chad than most any other
leader I have ever encountered. He was concise and direct in his
discussions about various decisions that were being made, and he inspired
great confidence that he was doing the right thing, by bringing together
meaningful data and a careful and thoughtful attitude.

He spoke at `hack.summit()` this year about several interesting topics:

1. Being heterogenous by default:

    > On our service layer, we have at least Ruby, Scala, Haskell, Clojure,
    > Node, Elixir, and so on so on. This is for three reasons. One, I want
    > people on the team to enjoy themselves as technologists. I’ve spent too
    > many years in environments where people sit around the coffee machine and
    > daydream about how they could work somewhere else where they could use
    > some hip technology, but they’re stuck in this terrible environment where
    > they have to use Rails 2.3 and they’re stuck. I just wanted to erase
    > that. Like, that’s a silly thing. That’s a stupid thing to be sitting
    > around, complaining about for many reasons. […] The other one though is
    > that when you are heterogeneous by default — and that’s from languages,
    > runtimes, databases, whatever it is — then technology upgrade is just
    > part of your world, all the time. Technology upgrade scared us in the
    > past, but when you’re heterogenous by default, you’re already in the
    > process all the time of doing technology upgrades. You’re not stuck on
    > one technology. You have a bunch of different components on different
    > technologies and it’s much easier to change them, much easier to replace
    > them.

2. Immutable deployment, disposable nodes:

    > So just since we released Wunderlist 3 in July, we have rewritten many
    > of the underlying services in languages and runtimes that perform better,
    > just to optimize and save money, but none of our users knew [i.e. no
    > downtime].
    >
    > To make this work, the nodes [i.e. servers] must be disposable. […] The
    > nodes we’re running, they’re kind of like cells. Replenishing them means
    > there’s not really a chance to build up cruft by lazy system
    > administrators. And we’re all lazy when it comes down to it, making
    > changes that aren’t repeatable.
    >
    > Never upgrade software on an existing node.
    >
    > Provisioning new services must be trivial.

3. Optimizing your MTBF & MTTR:

    > It really boils down to optimizing between mean time between failure
    > vs. mean time to resolution. If you spend all of your time trying to
    > increase the time between failures in your system, then you’re not
    > going to be very good at resolving them when they happen.

4. Data should be small, services should encapsulate it:

    > Data should be as small as possible. Now that starts to be
    > impossible, because each service owns and encapsulates its data. I
    > have a crazy idea. We're dealing with large amounts of data at
    > Wunderlist [...]. My crazy idea is that we'll move from having any
    > large databases to each user having his or her own SQLite database.
    >
    > Services own and encapsulate data.

This talk is available on YouTube through the link in the title.
