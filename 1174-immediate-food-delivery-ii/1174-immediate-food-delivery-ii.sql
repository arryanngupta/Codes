# Write your MySQL query statement below
select round(count(*)*100/(select count(*) from (select distinct d3.customer_id from delivery d3) as t2),2) as immediate_percentage from delivery d1 where (d1.customer_id,d1.customer_pref_delivery_date) in
(select d2.customer_id,min(d2.order_date)
from delivery d2
group by d2.customer_id)