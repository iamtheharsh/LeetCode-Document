# Write your MySQL query statement below
SELECT a.id as  id ,sum(a.num) as num from (select requester_id as id ,
count(requester_id) as num
from RequestAccepted
group by requester_id

union all

select accepter_id as id ,
count(accepter_id) as num
from RequestAccepted
group by accepter_id) as a
group by a.id
order by num desc limit 1