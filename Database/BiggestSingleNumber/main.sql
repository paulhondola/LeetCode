SELECT max(num) AS num
FROM
(
SELECT num FROM mynumbers GROUP BY num HAVING count(*) = 1
)
