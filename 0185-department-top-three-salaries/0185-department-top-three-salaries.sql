# Write your MySQL query statement below
select department, employee , salary 
from (
    select d.name as department , 
    e.name as employee,
    e.salary as salary,
    DENSE_RANK() over ( partition by e.departmentid order by e.salary desc) as ranking 
    from employee e
    left join department d
    on e.departmentId = d.id
) as new_table
where ranking<=3;

