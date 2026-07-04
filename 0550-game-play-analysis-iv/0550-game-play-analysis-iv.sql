# Write your MySQL query statement below

select 
round(
    COUNT(DISTINCT a1.player_id) /
    (SELECT COUNT(DISTINCT player_id) FROM Activity),
    2)
as fraction from 
(select player_id , min(event_date) as first_logged
from activity as a
group by player_id) as a1
join activity as a2
on a1.player_id = a2.player_id and datediff(a2.event_date,a1.first_logged) = 1

