# Write your MySQL query statement below
select m.name as name
from Employee m
join Employee e
on e.managerId = m.id
group by m.id
having count(*) >= 5