# Write your MySQL query statement below

select name 
from salesperson 
where sales_id not in (
    select ord.sales_id 
    from orders as ord 
    inner join company as com 
    on ord.com_id = com.com_id 
    where com.name='RED'
);