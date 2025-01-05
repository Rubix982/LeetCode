# Write your MySQL query statement below
SELECT p.firstName, p.lastName, t.city, t.state
FROM Person as p
LEFT JOIN Address t
ON p.personId = t.personId
