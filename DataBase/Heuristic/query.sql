-- * sub querys fix
    SELECT emp_name FROM employees WHERE emp_id
        IN (SELECT emp_id FROM departments WHERE dept_name = 'HR');
    -- should be
    SELECT emp_name FROM employees e JOIN departments
        d ON e.emp_id = d.emp_id WHERE d.dept_name = 'HR';

-- * better filter
 	SELECT * FROM sales WHERE YEAR(sale_date) = 2023;
    -- should be
 	SELECT * FROM sales WHERE sale_date BETWEEN
        '2023-01-01' AND '2023-12-31';

-- * query planner
    EXPLAIN SELECT c.name, p.product_name FROM customers c
    JOIN purchases p ON c.customer_id = p.customer_id
    WHERE p.purchase_date > '2024-01-01';
