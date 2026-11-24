# Write your MySQL query statement below
with cte as (
    select employee_id,count(*) as cnt
    from Employee
    group by employee_id
)

select e.employee_id,e.department_id 
from Employee e
join cte c
on e.employee_id = c.employee_id
where c.cnt = 1

union 

select e.employee_id,e.department_id 
from Employee e
join cte c
on e.employee_id = c.employee_id
where c.cnt > 1 and e.primary_flag = 'Y'

