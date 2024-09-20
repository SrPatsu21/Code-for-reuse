-- * sub querys
SELECT emp_name FROM employees WHERE emp_id 
    IN (SELECT emp_id FROM departments WHERE dept_name = 'HR');

SELECT e.emp_name FROM employees e JOIN departments 
    d ON e.emp_id = d.emp_id WHERE d.dept_name = 'HR';