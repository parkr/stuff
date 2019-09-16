---
layout: page
title: Podcasts
---

I have consumed podcasts for a very long time, and occasionally I like an episode
so much that I share it here. My interests span technology, politics, government,
law, and science, which can be reflected in some of the podcast episodes I found
the most engaging & memorablee:

{% assign podcasts = site.tags.podcast %}
<ul>
{% for post in podcasts %}
<li><a href="{{ post.url }}">{{ post.title }}</a></li>
{% endfor %}
</ul>
