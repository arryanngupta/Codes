# Write your MySQL query statement below
with cte as (
    select person_id,sum(weight) over(
        order by turn 
    ) as total_wt
    from Queue
)

select q.person_name as person_name
from Queue q
join cte c
on q.person_id = c.person_id
where c.total_wt <= 1000
order by total_wt desc 
limit 1