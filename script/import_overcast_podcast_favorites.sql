SELECT
    episode.id           AS episodeID,
    episode.podcastID    AS podcastID,
    podcast.title        AS podcastTitle,
    episode.title        AS episodeTitle,
    episode.userRecommendedTime AS userRecommendedTime,
    STRFTIME('%Y-%m-%d', CAST(episode.userRecommendedTime AS float), 'unixepoch') AS userRecommendedTimeHuman,
    podcast.linkURL      AS podcastURL,
    episode.linkURL      AS episodeURL,
    episode.enclosureURL AS enclosureURL,
    podcast.imageURL     AS podcastArtworkURL,
    podcast.iTunesID     AS podcastiTunesID
FROM OCEpisode AS episode
INNER JOIN OCPodcast AS podcast ON (episode.podcastID = podcast.id)
WHERE episode.userRecommendedTime IS NOT NULL
AND episode.userRecommendedTime > 0
AND podcast.isPrivate = 0
ORDER BY episode.userRecommendedTime DESC;
--- Import favorite episodes from Overcast's SQLite database.
---
--- Using something like sqlite-utils, run the following query against
--- Overcast's `sqlite.database` file to extract favorite episodes as JSON.
---
--- In parkr/stuff, this is used by script/import-overcast-podcast-favorites.
---
