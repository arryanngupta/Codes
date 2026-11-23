# Write your MySQL query statement below
select today.id 
from Weather today
join Weather yesterday
on today.recordDate = yesterday.recordDate + interval 1 day
where today.temperature > yesterday.temperature