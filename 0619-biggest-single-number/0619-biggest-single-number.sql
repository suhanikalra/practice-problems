# Write your MySQL query statement below
SELECT MAX(num) as num 
FROM (
select num from MyNumbers
group by num
having count( num)=1
order by num desc
) AS unique_numbers;


