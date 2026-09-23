# Write your MySQL query statement below
SELECT s.user_id , IFNULL(round(sum(action = 'confirmed')/count(*) , 2) , 0) as  confirmation_rate
FROM Signups AS s
LEFT JOIN Confirmations AS c
ON s.user_id = c.user_id
GROUP BY s.user_id