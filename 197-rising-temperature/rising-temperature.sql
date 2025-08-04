-- By doing a self-join on the Weather table, we create a Cartesian product of the table with itself, creating pairs of days. We then use the DATEDIFF function to restrict these pairs to only include consecutive days. Lastly, we filter these pairs of consecutive days further to only include pairs where the temperature is higher on the second day. The resulting ids represent the days where the temperature was higher than the previous day.

SELECT w2.id
FROM Weather w1, Weather w2
WHERE DATEDIFF(w2.recordDate, w1.recordDate) = 1 
AND w2.temperature > w1.temperature;


-- SELECT 
--     w1.id
-- FROM 
--     Weather w1
-- JOIN 
--     Weather w2
-- ON 
--     DATEDIFF(w1.recordDate, w2.recordDate) = 1
-- WHERE 
--     w1.temperature > w2.temperature;