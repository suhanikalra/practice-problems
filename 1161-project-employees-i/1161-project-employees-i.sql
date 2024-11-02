# Write your MySQL query statement below
select  Project.project_id  , round(AVG(Employee.experience_years),2) as average_years
from Employee
join Project on Project.employee_id= Employee.employee_id
group by Project.project_id
