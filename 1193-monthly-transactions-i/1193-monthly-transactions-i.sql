# Write your MySQL query statement below
select date_format(t2.trans_date,'%Y-%m') as month,t2.country,count(*) as trans_count,(select count(*) from Transactions t1 where t1.state = 'approved' and t1.country <=> t2.country and date_format(t1.trans_date,'%Y-%m') = month) as approved_count ,sum(t2.amount) as trans_total_amount , sum(case when t2.state = 'approved' then t2.amount else 0 end) as approved_total_amount 
from Transactions t2
group by month,t2.country

