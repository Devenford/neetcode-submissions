-- Write your query below
SELECT customer_id, customer_name
FROM customers c
WHERE EXISTS (
    SELECT customer_id
    FROM orders o
    WHERE o.customer_id = c.customer_id AND product_name = 'A'
) AND EXISTS (
    SELECT customer_id
    FROM orders o
    WHERE o.customer_id = c.customer_id AND product_name = 'B'
) AND NOT EXISTS (
    SELECT customer_id
    FROM orders o
    WHERE o.customer_id = c.customer_id AND product_name = 'C'
)
ORDER BY customer_name;
