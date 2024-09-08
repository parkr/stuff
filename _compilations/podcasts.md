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

{% assign podcast_episodes_grouped_by_podcast_title = site.data.overcast_recommended_episodes | group_by: "podcastTitle" %}

{%- for group in podcast_episodes_grouped_by_podcast_title -%}
<h4>{{ group.name }} ({{ group.items | size }})</h4>
<p>
<ul>
    {%- for episode in group.items -%}
        <li>{{ episode.userRecommendedTimeHuman }} – <a href="{{ episode.episodeURL }}" title="View this episode">{{ episode.episodeTitle }}</a> (<a href="{{ episode.overcastFMPermalink }}" title="View this episode on Overcast.fm">permalink</a>)</li>
    {%- endfor -%}
</ul>
</p>
{%- endfor -%}

This data is also accessible [as a JSON blob]({{ "/compilations/podcasts.json" | relative_url }}).
