# Write your MySQL query statement below
select distinct c.visited_on as visited_on,(
    select sum(amount)
    from customer
    where visited_on between date_sub(c.visited_on,interval 6 day) and c.visited_on
) as amount,round((
    select sum(amount) as amount
    from customer
    where visited_on between date_sub(c.visited_on,interval 6 day) and c.visited_on
)/7,2) as average_amount 
from customer c
where c.visited_on >= (
    select date_add(min(visited_on),interval 6 day)
    from customer
)
order by c.visited_on