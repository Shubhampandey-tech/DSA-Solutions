SELECT EmployeeUNI.unique_id,Employees.name
FROM Employees
left JOIN EmployeeUNI
ON Employees.id = EmployeeUNI.id;

