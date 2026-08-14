# Write your MySQL query statement below
SELECT DISTINCT num AS ConsecutiveNums
FROM (
    SELECT num,
           LAG(num,1) OVER (ORDER BY id) AS P1,
           LAG(num,2) OVER (ORDER BY id) AS P2
    FROM Logs 

) t
WHERE num = p1
AND num = p2;