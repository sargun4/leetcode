SELECT actor_id,director_id
FROM ActorDirector
GROUP BY actor_id,director_id
HAVING COUNT(*)>=3;

-- (actor_id, director_id) pairs where the same actor and director hv worked together at least 3 times.