# Write your MySQL query statement below
with pt as (
    select patient_id,min(test_date) as pdate
    from covid_tests
    where result='Positive'
    group by patient_id
),nt as (
    select patient_id,test_date as ndate
    from covid_tests
    where result='Negative' 

)

select x.patient_id,y.patient_name,y.age,x.recovery_time
from(
select pt.patient_id ,datediff(min(nt.ndate),pt.pdate) as recovery_time
from 
pt
join nt 
on pt.patient_id=nt.patient_id
where pt.pdate<nt.ndate
group by pt.patient_id,pt.pdate
)x
join patients y
on x.patient_id=y.patient_id
order by x.recovery_time,y.patient_name