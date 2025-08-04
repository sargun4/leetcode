-- UNION ALL keeps duplicates (since a person can both send and receive requests)
SELECT id, COUNT(*) AS num
FROM (
    SELECT requester_id AS id FROM RequestAccepted
    UNION ALL
    SELECT accepter_id FROM RequestAccepted
) AS all_ids
GROUP BY id -- group by each unique user ID
ORDER BY num DESC
LIMIT 1;-- Limit result to just 1 row: user w highest no of friends
