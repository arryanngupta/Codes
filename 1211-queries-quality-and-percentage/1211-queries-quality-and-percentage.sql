# Write your MySQL query statement below
# quality :- sum(rating/position)/count(*)
# poor query :- (count(<3)/count(*))*100

select q.query_name, round(sum(q.rating/q.position)/count(*),2) as quality , 
round(((select count(*) from queries where rating < 3 and query_name=q.query_name)/count(*))*100,2) as poor_query_percentage 
from queries q
group by q.query_name