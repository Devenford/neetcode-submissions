-- Write your query below
SELECT first_name, last_name, city, state
FROM person p
LEFT JOIN address a ON p.person_id = a.person_id;
