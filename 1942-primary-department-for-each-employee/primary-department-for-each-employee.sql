# Write your MySQL query statement below
SELECT employee_id,department_id
    FROM Employee e1
    WHERE primary_flag = 'Y' OR
    (select COUNT(*) FROM Employee e2
        WHERE e2.Employee_id = e1.Employee_id) = 1;
