# Write your MySQL query statement below
# SELECT e1.name as Employee
# FROM Employee e1
# INNER JOIN Employee e2
# ON e1.managerId = e2.id
# WHERE e2.salary < e1.salary
SELECT e1.name AS Employee
FROM Employee e1
WHERE EXISTS (
    SELECT 1 
    FROM Employee e2
    WHERE e1.managerId = e2.id 
    AND e2.salary < e1.salary
);