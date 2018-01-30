---
layout: page
title: TED Talks
---

The [TED][] conference is the premier conference for folks with big ideas
about big problems affecting the whole world. Just take a look at these
titles! Below is a compilation of TED Talks I have saved:

{% assign ted_talks = site.tags.TED_Talks %}
<ul>
{% for post in ted_talks %}
<li><a href="{{ post.url }}">{{ post.title }}</a></li>
{% endfor %}
</ul>

[TED]: https://www.ted.com
