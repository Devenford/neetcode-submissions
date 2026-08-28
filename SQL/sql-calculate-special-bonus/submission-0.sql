-- Write your query below
select employee_id, salary as bonus
from employees
where employee_id % 2 = 1 and name not like 'M%'
union
select employee_id, 0 as bonus
from employees
where employee_id % 2 != 1 or name like 'M%'
order by employee_id;