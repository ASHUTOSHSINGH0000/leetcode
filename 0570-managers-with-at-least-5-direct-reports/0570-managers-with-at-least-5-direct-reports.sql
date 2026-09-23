# Write your MySQL query statement below
SELECT e1.name 
FROM Employee e1 
JOIN Employee e2 
ON e1.id = e2.managerId
group by e2.managerId
having  count(e2.managerId) >= 5 ;