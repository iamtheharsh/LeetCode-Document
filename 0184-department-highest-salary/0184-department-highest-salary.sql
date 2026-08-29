# Write your MySQL query statement below
select d.name as department , 
e.name as employee,
e.salary as salary 
from employee e
left join Department d
on e.departmentid = d.id
where (e.departmentid,e.salary) in 
(select departmentId , max(salary) from employee
group by departmentId
)