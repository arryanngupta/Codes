# Write your MySQL query statement below
select w.id
from weather w
join weather w2
on w2.recordDate = w.recordDate - interval 1 day
where w2.temperature<w.temperature