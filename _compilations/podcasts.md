---
layout: page
title: Podcasts
---

I have consumed podcasts for a very long time, and occasionally I like an episode
so much that I share it here. My interests span technology, politics, government,
law, and science, which can be reflected in some of the podcast episodes I found
the most engaging & memorable:

{% assign podcasts = site.tags.podcast %}
<ul>
{% for post in podcasts %}
<li><a href="{{ post.url }}">{{ post.title }}</a></li>
{% endfor %}
</ul>

I listen in Overcast and extracted my favorited episodes ({{ site.data.overcast_recommended_episodes | size }}!):

{% assign podcast_episodes_grouped_by_feed_id = site.data.overcast_recommended_episodes | group_by: "feedTitle" %}

{%- for group in podcast_episodes_grouped_by_feed_id -%}
<h4>{{ group.name }} ({{ group.items | size }})</h4>
<p>
<ul>
    {%- for episode in group.items -%}
    <li>{{ episode.userRecommendedTimeHuman }} – <a href="{{ episode.episodeURL }}">{{ episode.title }}</a></li>
    {%- endfor -%}
</ul>
</p>
{%- endfor -%}
