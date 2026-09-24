# Write your MySQL query statement below
SELECT max(num) as num 
from MyNumbers
where num IN (SELECT num 
              from MyNumbers 
              group by num
              having count(num) = 1)
