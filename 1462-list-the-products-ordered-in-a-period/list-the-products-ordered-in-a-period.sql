# Write your MySQL query statement below
SELECT p1.product_name,
        SUM(o.unit) AS unit
FROM Products p1
INNER JOIN Orders o
ON p1.product_id = o.product_id
WHERE MONTH(order_date) = '02' AND YEAR(order_date) = '2020'
GROUP BY p1.product_id,p1.product_name
HAVING SUM(o.unit) >= 100;