# Write your MySQL query statement below
select Register.contest_id,
round(COUNT(DISTINCT Users.user_id) * 100.0 / 
    (SELECT COUNT(DISTINCT user_id) FROM Users),2) AS percentage
from Register
join Users on Users.user_id = Register.user_id
group by contest_id
order by percentage desc, contest_id asc