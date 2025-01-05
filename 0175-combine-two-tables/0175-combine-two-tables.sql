# Write your MySQL query statement below
SELECT p.firstName, p.lastName, a.city, a.state
FROM Person as p
LEFT OUTER JOIN Address a USING (personId)
