# Write your MySQL query statement below
SELECT s.student_id , s.student_name , su.subject_name , count(e.subject_name )as  attended_exams
FROM Students AS s 
CROSS JOIN  Subjects  AS su
LEFT JOIN Examinations AS e
ON     su.subject_name = e.subject_name
AND    s.student_id   =    e.student_id
GROUP BY s.student_id , s.student_name , su.subject_name
order by student_id , subject_name