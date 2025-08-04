SELECT e1.name AS Employee
FROM Employee e1
JOIN Employee e2 ON e1.managerId = e2.id -- e1 is emp n e2 manager
WHERE e1.salary > e2.salary;