---
layout: post
title: "Distributed Filesystems"
date: 2016-10-05 22:40:59 -0700
external-url: http://www.wilkie.io/posts/filesystems-what-we-know-what-we-can-learn
mirror: wilkie-filesystems-what-we-know-what-we-can-learn.txt
---

Distributed filesystems have always interested me, and wilkie writes a
compelling story about the way filesystems have lagged behind the
innovations of the internet. There is so much duplication across the many
computers that power the web, and it would be terrific to setup a protocol
to allow for the integrity of content while reducing its massive
duplication.

Content-addressable storage (as wilkie details) is a fairly well-known
concept. I played around with it a bit with
[camlistore](http://camlistore.org) (["content-addressable multi-layer
indexed storage"](https://youtu.be/8Dk2iVlc67M?t=147)), a project bradfitz
put together some time ago to aid with data loss over time. It replicates
data from your home machine to S3, or any other storage backend. Camlistore
gives you a SHA-1 hash which uniquely and immutably identifies your
content. Wouldn't it be cool to ask for `ba0e5fac3155ac6ccafede82aa4bd34e`
and get back the jQuery or React library that every website is using
nowadays?

The power of wilkie's idea is that you don't need much disk space on your
device at all... each chunk of any file, if they match, would simply be
stitched together or fetched at will.

> Now our operating system is the following: a content-addressed
> filesystem, and the means of downloading and uploading chunks of data.
> That is the smallest an operating system needs to be. It can download the
> rest of itself at this point. It can effectively learn what it doesn't
> yet know how to do.
>
> ...
>
> At the end of the day, programs no longer need to break themselves into
> pieces installed independently. They do not need to be installed at
> all... no need to be locally available to use.

---

I love the idea of content-addressable filesystems which reduce duplication
and OS's which know only how to build & fetch blocks of data, but this is
some ways off. A [proposal by Brad
Hill](https://hillbrad.github.io/sri-addressable-caching/sri-addressable-caching.html)
talks about "Subresource Integrity Addressable Caching", which aims to
solve a network goal which is analogous to wilkie's storage goal:

> A small number of large, popular web application frameworks account for a
> substantial portion of the network, battery, and time budgets for a
> modern web user agent (UA). Many applications include these frameworks
> even if they only use a small portion of the functionality they provide.
> It would be a great improvement if UAs could fetch and compile these
> libraries a single time. The benefit would be especially large for UAs
> that do not share cached content across origins / registerable domains
> for privacy reasons.

This would be a great place to start. Eventually this could be built into
the very fiber of the internet, where our disks are more like BitTorrent
networks than hierarchical structures.

This stuff is really neat.
