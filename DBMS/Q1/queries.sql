CREATE TABLE department_13BCS0003 (
deptno int PRIMARY KEY,
dname varchar(20),
manager varchar(20),
loc varchar(20)
);

CREATE TABLE employee_13BCS0003 (
empno int PRIMARY KEY,
name varchar(30),
deptno int,
job varchar(10),
hiredate date,
sal int,
commission int,
dob date,
city varchar(20),
phone int,

FOREIGN KEY (deptno) REFERENCES department_13BCS0003 (deptno) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE salary_13BCS0003 (
eno int,
basic int,
HR int,
DA int,
tax int,

FOREIGN KEY (eno) REFERENCES employee_13BCS0003 (empno) ON UPDATE CASCADE ON DELETE CASCADE
);




INSERT INTO department_13BCS0003 VALUES
(1,"accounting","abdul","new delhi"),
(2,"CS","rauf","new delhi"),
(3,"EC","abhinav","new delhi"),
(4,"Civil","aakash","chennai"),
(5,"ME","sharique","new delhi");

INSERT INTO employee_13BCS0003 VALUES
(1,"abdullah",1,"ceo","2013-1-13",10000,500,"1995-1-1","mumbai",58020048),
(2,"adeela",2,"head","2010-8-15",24500,5000,"1994-1-1","mumbai",88020),
(3,"minnat",3,"head","2009-8-13",15000,200,"1994-5-1","delhi",8834020),
(4,"asad",4,"head","2007-3-18",156030,200,"1991-8-1","chennai",88454020),
(5,"gulnawaz",5,"head","2000-3-3",15000,200,"1997-8-1","mumbai",98454020),
(6,"ajay",1,"clerk","2013-8-13",10010,500,"1995-1-1","delhi",88020048),
(7,"anamta",2,"technician","2010-8-13",20000,5000,"1994-1-1","delhi",88020),
(8,"amit",3,"technician","2009-8-13",15000,200,"1994-5-1","chennai",8834020),
(9,"aamir",4,"head","2007-3-3",156000,200,"1994-8-1","delhi",88454020),
(10,"aakash aggarwal",5,"clerk","1981-04-07",15000,200,"1997-8-1","delhi",98454020);


INSERT INTO salary_13BCS0003 VALUES
(1,23454,132,145,14),
(2,24454,334,255,234),
(3,23334,3324,355,68),
(4,63454,734,45,234),
(5,4453454,334,55,726),
(6,83534,824,1455,814),
(7,13454,134,645,874),
(8,253454,334,725,274),
(9,95334,324,857,764),
(10,153534,244,252,134);



DROP TABLE employee_13BCS0003;
DROP TABLE department_13BCS0003;
DROP TABLE salary_13BCS0003;



SELECT * FROM employee_13BCS0003;
SELECT * FROM department_13BCS0003;
SELECT * FROM salary_13BCS0003;



1.

SELECT 
employee.name,
employee.city
FROM employee_13BCS0003 AS employee 
INNER JOIN department_13BCS0003 AS department ON department.deptno = employee.deptno
WHERE department.dname = 'accounting';

2. 

SELECT 
employee.name,
department.dname 
FROM employee_13BCS0003 AS employee
INNER JOIN department_13BCS0003 AS department ON employee.deptno = department.deptno 
WHERE employee.sal > 10000;

3.

SELECT 
employee.name 
FROM employee_13BCS0003 AS employee 
ORDER BY employee.name ASC;  

SELECT 
employee.name 
FROM employee_13BCS0003 AS employee 
ORDER BY employee.name DESC;  

4.

UPDATE employee_13BCS0003 
SET city = "Delhi"
WHERE empno = 2;

5.

SELECT 
SUM(sal)
FROM employee_13BCS0003
WHERE city = 'Delhi';

6.

SELECT *
FROM employee_13BCS0003 AS employee
INNER JOIN (SELECT eno FROM salary_13BCS0003 ORDER BY tax DESC LIMIT 1) AS temp
WHERE employee.empno = temp.eno;

XX7.




8.  

SELECT * 
FROM employee_13BCS0003 
ORDER BY sal 
DESC LIMIT 1,1;


9.

SELECT MAX(sal) AS 2ndHighest
FROM employee_13BCS0003 
WHERE sal NOT IN(SELECT MAX(sal) FROM employee_13BCS0003);


10.



11. 

SELECT * 
FROM employee_13BCS0003 
WHERE sal = (SELECT DISTINCT sal FROM employee_13BCS0003 ORDER BY sal DESC LIMIT 4,1);



12. 

SELECT COUNT(*) 
FROM employee_13BCS0003 
WHERE job = 'clerk';


13. 

SELECT 
department.dname 
FROM department_13BCS0003 AS department
INNER JOIN (SELECT deptno FROM employee_13BCS0003 WHERE job='clerk' GROUP BY deptno HAVING count(*)=1) AS temp
WHERE department.deptno = temp.deptno;


14.

SELECT deptno,count(*) AS count
FROM employee_13BCS0003 
WHERE job = 'clerk' 
GROUP BY deptno DESC
LIMIT 0,1;

15. 

SELECT 
department.deptno,
department.dname,
temp.count
FROM department_13BCS0003 AS department
INNER JOIN (SELECT deptno, COUNT(*) AS count FROM employee_13BCS0003 GROUP BY deptno) AS temp
WHERE department.deptno = temp.deptno;


16. 

SELECT 
job,
MIN(sal) AS min 
FROM employee_13BCS0003 
GROUP BY job 
ORDER BY min DESC;



17.

SELECT 
deptno,
AVG(sal) AS avg 
FROM employee_13BCS0003 
GROUP BY deptno 
ORDER BY avg LIMIT 0,1;



18. 

SELECT 
job,
MIN(sal) AS min,
MAX(sal) as max,
avg(sal) as avg 
FROM employee_13BCS0003 
GROUP BY job;




19. 

SELECT 
(MAX(sal)-MIN(sal)) AS difference 
FROM employee_13BCS0003;



20. 

SELECT 
name 
FROM employee_13BCS0003 
WHERE name LIKE '%LA%';



21. 

SELECT 
name 
FROM employee_13BCS0003 
WHERE hiredate BETWEEN '1981-04-02' AND '1981-09-08';


22. 

SELECT 
COUNT(DISTINCT job) 
FROM employee_13BCS0003;



23. 

SELECT 
SUM(sal) AS sum
FROM employee_13BCS0003
WHERE deptno = 3;


24. 

SELECT 
employee.name,
employee.deptno,
department.dname 
FROM employee_13BCS0003 AS employee 
INNER JOIN department_13BCS0003 AS department ON employee.deptno=department.deptno;



25. 


SELECT 
employee.name,
department.manager 
FROM employee_13BCS0003 AS employee 
INNER JOIN department_13BCS0003 AS department ON employee.deptno=department.deptno;


26. 

SELECT 
employee.name
FROM employee_13BCS0003 AS employee 
INNER JOIN department_13BCS0003 AS department ON employee.deptno=department.deptno
WHERE department.loc = "chennai";

27.


SELECT 
employee.name
FROM employee_13BCS0003 AS employee 
INNER JOIN department_13BCS0003 AS department ON employee.deptno = department.deptno
WHERE department.loc = employee.city;


28.

SELECT 
dname
FROM department_13BCS0003 AS department
LEFT OUTER JOIN employee_13BCS0003 AS employee ON department.deptno = employee.deptno
WHERE employee.deptno IS NULL;


29.


SELECT 
department.dname
FROM department_13BCS0003 AS department 
LEFT OUTER JOIN employee_13BCS0003 AS employee ON employee.deptno = department.deptno
WHERE employee.deptno IS NULL;


30.

DELETE FROM department_13BCS0003 
WHERE dname = "EC";

