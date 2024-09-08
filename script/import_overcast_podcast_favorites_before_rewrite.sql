SELECT
    feed_item.id as episodeID,
    feed_item.feedID,
    feed.title as feedTitle,
    feed_item.title,
    feed_item.userRecommendedTime,
    STRFTIME('%Y-%m-%d', CAST(feed_item.userRecommendedTime AS float),'unixepoch') AS userRecommendedTimeHuman,
    feed.link as feedLink,
    feed_item.url as episodeURL,
    feed.artworkURL as feedArtworkURL
FROM OCFeedItem AS feed_item
INNER JOIN OCFeed AS feed ON (feed_item.feedID = feed.id)
WHERE feed_item.userRecommendedTime IS NOT NULL
AND feed_item.userRecommendedTime > 0
AND feed.isPrivate = 0
ORDER BY feed_item.userRecommendedTime DESC;
