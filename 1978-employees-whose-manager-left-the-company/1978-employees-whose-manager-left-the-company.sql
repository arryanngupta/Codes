# Write your MySQL query statement below
select e1.employee_id
from Employees e1
where e1.manager_id not in (
select m.employee_id 
from Employees e
join Employees m
on m.employee_id = e.manager_id 
) and e1.salary < 30000
order by e1.employee_id