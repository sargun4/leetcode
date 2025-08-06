-- node is a Root if its p_id is NULL.
-- node is an Inner node if it appears as a parent for other nodes.
-- node is a Leaf if it doesn't appear as a parent and its p_id is not null.
SELECT id,
    CASE
        WHEN p_id IS NULL THEN 'Root'
        WHEN id IN (SELECT p_id FROM Tree) THEN 'Inner'
        ELSE 'Leaf'
        END AS type
FROM Tree
