# Write your MySQL query statement below
select round(count(*)/(select count(distinct player_id) from activity),2) as fraction
from activity a1
join (
        select player_id,min(event_date) as min_date
        from activity
        group by player_id
    ) a2
on a1.player_id = a2.player_id and a1.event_date = a2.min_date + interval 1 day