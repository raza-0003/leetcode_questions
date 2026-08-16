DELETE p1
FROM Person p1 INNER JOIN person p2
WHERE p1.email = p2.email AND
p1.id > p2.id;