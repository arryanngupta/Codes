# Write your MySQL query statement below
with cte as (
    select product_id,min(change_date) as first_date
    from Products 
    group by product_id
)

select c.product_id,(case when c.first_date <= '2019-08-16' then (
    select p.new_price 
    from Products p 
    where p.product_id = c.product_id and p.change_date = (
        select max(p2.change_date) 
        from Products p2
        where p2.product_id = c.product_id and p2.change_date <= '2019-08-16'
    )
) else 10 end) as price
from cte c