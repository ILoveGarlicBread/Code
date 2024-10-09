//1
SELECT E.employee_id, E.first_name,
    E.last_name, E.job_id, E.department_id, E.salary
FROM EMPLOYEES E
WHERE (job_id= 'IT_PROG' AND salary>6000)
    OR (job_id= 'FI_ACCOUNT' AND salary>8000)
//2
SELECT 'Mr. '||first_name||' '||last_name||' '||'earns '||salary AS STAFF
FROM Employees
//3
SELECT E.last_name, E.department_id,D.department_name, L.city
FROM EMPLOYEES E
JOIN DEPARTMENTS D ON D.department_id= E.department_id
JOIN LOCATIONS L ON L.location_id= D.location_id
WHERE E.job_id IN ('IT_PROG','FI_ACCOUNT')
//4
SELECT E1.last_name,E1.hire_date, E1.salary
FROM EMPLOYEES E1
JOIN EMPLOYEES E2 ON E1.salary= E2.salary 
    AND (NOT E1.employee_id = E2.employee_id) AND (COALESCE(E1.commission_pct, 0)= COALESCE(E2.commission_pct,0))
WHERE E2.last_name= 'Kochhar'
//5
SELECT *
FROM Employees
WHERE salary >(SELECT Max(salary)
                FROM Employees 
                WHERE job_id= 'SA_MAN')
ORDER BY salary DESC
//6
SELECT location_id, city
FROM LOCATIONS
WHERE location_id IN(
        SELECT D.location_id
        FROM DEPARTMENTS D
        WHERE department_name IN ('Payroll','Treasury')
)
