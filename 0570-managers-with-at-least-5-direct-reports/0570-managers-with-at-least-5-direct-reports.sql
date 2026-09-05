# Write your MySQL query statement below
select e2.name from employee e2 where e2.id in (select e.managerId
from employee e
group by e.managerId
having count(e.managerId)>=5)