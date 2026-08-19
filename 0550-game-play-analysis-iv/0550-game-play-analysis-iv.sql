# Write your MySQL query statement below
select round(count(*)/(select count(distinct player_id) from activity),2) as fraction
from activity a
join (
    select player_id,min(event_date) as event_date
    from activity
    group by player_id
) a2
on a.player_id = a2.player_id and a.event_date = a2.event_date+interval 1 day