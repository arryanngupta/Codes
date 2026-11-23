# Write your MySQL query statement below
select round((count(*))*100/(select count(distinct customer_id) from delivery),2) as immediate_percentage 
from Delivery d1
where d1.order_date = (select min(order_date) from delivery where customer_id = d1.customer_id) and d1.order_date = d1.customer_pref_delivery_date