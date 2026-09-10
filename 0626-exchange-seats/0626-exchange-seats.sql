# Write your MySQL query statement below
select ifnull(s2.id,s1.id) as id,ifnull(s1.student,s2.student) as student 
from seat s1
left join seat s2
on s1.id = if(s2.id%2=1,s2.id+1,s2.id-1)
order by id