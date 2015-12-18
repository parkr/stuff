---
layout: post
title: "Why I'm Not Using Your Open Source Project - NCZOnline"
date: 2015-12-18 00:59:53 -0800
external-url: https://www.nczonline.net/blog/2015/12/why-im-not-using-your-open-source-project/
---

Nicholas makes some excellent points on reasons open source can hurt rather
than help. He writes from a business perspective, as an architect at Box.
His concerns are therefore quite ordinary:

1. It should have an explicit license, not GPL or LGPL
2. There must be active maintenance, prompt replies to issues/pull requests
3. The maintainer(s) should use the product frequently to catch edge cases
4. Tests are crucial for technical confidence
5. Must have documentation written for end user

Writing from a business point of view, this all makes a lot of sense. If
there is a problem, a patch must be issued or else production code can be
in jeopardy. If devs can't understand how to use it because there is no
documentation, then the library is unusable. Etcetera.

From a normal everyday user perspective, this matters less. If it's a
security vulnerability, it could be a big issue, sure. But individuals
aren't relying on having a strong community using the library and
submitting patches. The average user has to be concerned about the license
and the documentation, mostly.

It was also funny to me that Nicholas thought people wanted to open source
technology and find users for the fame. I open source things because I
don't want to pay for private repos, and the code is generally not that
unique or has little business value for me. So I make it public. If someone
wants to use it, they can open an issue and I'll respond.

I have offered my projects to people and companies who might find benefit,
but it always comes with the caveat that I have not run it through its
paces in every environment. Frankly, authors shouldn't have to do that for
every library they create. If you find a library that seems promising but
has one or two things that should be fixed, maybe they weren't fixed
beforehand because the author(s) didn't think that anyone else would use
it. Now that you found it and want to use it to help build your business,
the least you can do is submit those patches and open dialogue with the
author. Contributions are the building blocks of an open source community,
and the first ones have to come from somewhere.
