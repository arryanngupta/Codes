# Write your MySQL query statement below
select date_format(t.trans_date,'%Y-%m') as month,t.country,count(*) as trans_count,(
    select count(*) from transactions t2 where date_format(t2.trans_date,'%Y-%m') = date_format(t.trans_date,'%Y-%m') and t2.country <=> t.country and t2.state = 'approved'
) as approved_count , (ifnull(sum(t.amount),0)) as trans_total_amount , (select ifnull(sum(t2.amount),0) from transactions t2 where date_format(t2.trans_date,'%Y-%m') = date_format(t.trans_date,'%Y-%m') and t2.country <=> t.country and t2.state = 'approved') as approved_total_amount 
from Transactions t
group by date_format(t.trans_date,'%Y-%m'),t.country;