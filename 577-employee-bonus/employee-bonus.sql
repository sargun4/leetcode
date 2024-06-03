-- no bonus = 0 = less than 1000 still
SELECT e.name,b.bonus FROM Employee e
LEFT JOIN Bonus b ON e.empID = b.empID
WHERE bonus < 1000 OR Bonus IS NULL ;