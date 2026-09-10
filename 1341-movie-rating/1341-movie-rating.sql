# Write your MySQL query statement below
(
select u.name as results
from users u
join (
select user_id,count(*) as cnt
from MovieRating
group by user_id
) as x
on u.user_id = x.user_id
order by x.cnt desc,results
limit 1
)

union all

(select m.title as results
from movies m
join (
select movie_id,avg(rating) as cnt
from MovieRating 
where created_at between '2020-02-1' and '2020-02-29'
group by movie_id
) x
on m.movie_id = x.movie_id
order by x.cnt desc,results
limit 1
)