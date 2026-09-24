# Write your MySQL query statement below
SELECT user_id , count(user_id) as followers_count
FROM Followers 
group BY user_id
order by user_id
