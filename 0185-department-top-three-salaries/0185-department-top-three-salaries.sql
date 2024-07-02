-- select max(salary), d.name as department from Employee as e join Department as d ON e.departmentId = d.id group by d.name;
WITH RankedSalaries AS (
    SELECT 
        d.name AS Department,
        e.name AS Employee, 
        e.salary AS Salary, 
        dense_rank() OVER (PARTITION BY d.id ORDER BY e.salary DESC) AS salary_rank
    FROM 
        Employee AS e
    JOIN 
        Department AS d 
    ON 
        e.departmentId = d.id
)
SELECT 
    Department, 
    Employee, 
    Salary
FROM 
    RankedSalaries
WHERE 
    salary_rank <= 3;