# Write your MySQL query statement below
-- select round(count(select min(d2.order_date) from delivery d2 where d2.order_date = d2.customer_pref_delivery_date group by d2.customer_id)*100/count(select distinct d1.customer_id from delivery d1),2) as immediate_percentage 
-- from delivery d

select round(count(*)*100/(select count(*) from (select distinct d3.customer_id from delivery d3) as t2),2) as immediate_percentage
from (
    select d2.customer_id,min(d2.order_date) as min_date
    from delivery d2 
    where d2.order_date = d2.customer_pref_delivery_date and d2.order_date=(select min(order_date) from Delivery where d2.customer_id=customer_id group by customer_id)
    group by d2.customer_id
) as t




