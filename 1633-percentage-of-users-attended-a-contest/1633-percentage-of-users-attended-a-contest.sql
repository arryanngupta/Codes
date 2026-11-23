# Write your MySQL query statement below
select r.contest_id as contest_id,round(count(*)*100/(select count(*) from Users),2) as percentage 
from Register r
join Users u
on r.user_id = u.user_id
group by r.contest_id
order by percentage desc,r.contest_id