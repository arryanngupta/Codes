# Write your MySQL query statement below
select person_name as person_name 
from (
select q1.person_id,q1.person_name,sum(q2.weight) as total_wt
from Queue q1
join Queue q2
on q1.turn>=q2.turn
group by q1.person_id,q1.person_name
order by q1.turn
) x
where x.total_wt<=1000
order by x.total_wt desc
limit 1 