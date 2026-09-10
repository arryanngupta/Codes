# Write your MySQL query statement below
select s1.id,ifnull(s2.student,s1.student) as student 
from seat s1
left join seat s2
on s2.id = if(s1.id%2=1,s1.id+1,s1.id-1)