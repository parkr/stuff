---
layout: page
title: Derek Sivers
---

Who is Derek Sivers in 10 seconds? Well, [just read his website][sive.rs] which
places it prominently on the home page. To me, Derek is a programmer with a
philosopher's approach to the world. His deep curiosity is heartfelt and
fascinating to observe.
Below is a compilation of links I have saved regarding Derek:

<ul>
{% for podcast in site.data.overcast_recommended_episodes %}
    {% unless podcast.episodeTitle contains 'Derek Sivers' %}{% continue %}{% endunless %}
    <li class="podcast-episode"><span title="Podcast">🎙️</span> <a href="{{ podcast.overcastFMPermalink }}">{{ podcast.episodeTitle }} ({{ podcast.podcastTitle }})</a></li>
{% endfor %}

{% for post in site.tags.derek-sivers %}
    <li class="stuff-post"><span title="Post">📓</span> <a href="{{ post.url }}">{{ post.title }}</a></li>
{% endfor %}
</ul>

[sive.rs]: https://sive.rs