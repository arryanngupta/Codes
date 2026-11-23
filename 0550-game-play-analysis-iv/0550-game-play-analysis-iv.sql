# Write your MySQL query statement below
with cte as (
    select player_id,min(event_date) as first_day
    from Activity
    group by player_id
)

select round(count(*)/(select count(distinct player_id) from Activity),2) as fraction
from cte c
join Activity a
where a.player_id = c.player_id and a.event_date = c.first_day + interval 1 day
