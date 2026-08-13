-- Write your query below
select name
from customers c
where id not in (
    select distinct(customer_id)
    from orders o
);