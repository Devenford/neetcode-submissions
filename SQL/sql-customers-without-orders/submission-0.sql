-- Write your query below
select name
from customers c
left join orders o
on c.id = o.customer_id
where o.id is null;