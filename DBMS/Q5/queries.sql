CREATE TABLE faculty_13BCS0003(
fid int PRIMARY KEY,
fname varchar(20),
deptid int
);

CREATE TABLE class_13BCS0003(
name varchar(20) PRIMARY KEY,
meets_at varchar(20),
room varchar(20),
fid int,

FOREIGN KEY (fid) REFERENCES faculty_13BCS0003 (fid) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE student_13BCS0003(
snum int PRIMARY KEY,
sname varchar(20),
major varchar(20),
level varchar(20),
age int
);

CREATE TABLE enrolled_13BCS0003 (
snum int,
cname varchar(20),

FOREIGN KEY (snum) REFERENCES student_13BCS0003 (snum) ON DELETE CASCADE ON UPDATE CASCADE,
FOREIGN KEY (cname) REFERENCES class_13BCS0003 (name) ON DELETE CASCADE ON UPDATE CASCADE
);



INSERT INTO faculty_13BCS0003 VALUES 
(201,"S.Jackson",301),
(202,"M.Shanks",301),
(203,"I.Teach",302);

INSERT INTO class_13BCS0003 VALUES
("CSC343","W1","BA1080",201),
("CSC443","T2","BA1170",202),
("ECE300","M1","BA1080",203),
("ECE201","F12","BA1060",203),
("CSC165","R3","BA1170",202);

INSERT INTO student_13BCS0003 VALUES
(101,"Helen","CS","JR",19),
(102,"Charles","CS","SR",21),
(103,"Andy","CS","GR",25),
(104,"Bob","CS","SR",23),
(105,"Zorba","CS","GR",31);

INSERT INTO enrolled_13BCS0003 VALUES
(101,"CSC343"),
(101,"CSC443"),
(101,"ECE300"),
(102,"CSC343"),
(102,"ECE201"),
(103,"CSC343"),
(103,"CSC443"),
(103,"ECE300"),
(103,"ECE201"),
(105,"CSC343");




SELECT * FROM student_13BCS0003;
SELECT * FROM faculty_13BCS0003;
SELECT * FROM class_13BCS0003;
SELECT * FROM enrolled_13BCS0003;



Queries:


1. 

SELECT 
sname 
FROM student_13BCS0003 AS student
INNER JOIN enrolled_13BCS0003 AS enrolled ON student.snum = enrolled.snum
INNER JOIN class_13BCS0003 AS class ON enrolled.cname = class.name
INNER JOIN faculty_13BCS0003 AS faculty ON class.fid = faculty.fid
WHERE faculty.fname = "S.Jackson" AND student.level = "JR";



2. 


SELECT 
MAX(age) 
FROM student_13BCS0003 as student
INNER JOIN enrolled_13BCS0003 AS enrolled ON student.snum = enrolled.snum
INNER JOIN class_13BCS0003 AS class ON enrolled.cname = class.name
INNER JOIN faculty_13BCS0003 AS faculty ON class.fid = faculty.fid
WHERE faculty.fname = "S.Jackson" AND student.major = "CS";



3.

SELECT 
name 
FROM class_13BCS0003 AS class
INNER JOIN (SELECT count(*) AS count,cname FROM enrolled_13BCS0003 GROUP BY cname HAVING count(*) >=4) AS temp
WHERE class.meets_at = "W1";



xx4. 


SELECT sname FROM student_13BCS0003 WHERE snum in (SELECT snum FROM enrolled_13BCS0003 
WHERE cname in(SELECT name FROM class_13BCS0003 group by meets_at having count(*)>=2));

//JOINS

SELECT 
sname 
FROM student_13BCS0003 AS student
INNER JOIN enrolled_13BCS0003 AS enrolled ON student.snum = enrolled.snum
GROUP BY enrolled.cname;




xx5. 

SELECT 
fname 
FROM faculty_13BCS0003 
WHERE fid IN(SELECT fid FROM class_13BCS0003 GROUP BY fid HAVING count(*)>=5 );



SELECT fname
FROM faculty_13BCS0003 AS faculty
INNER JOIN class_13BCS0003 As class ON class.fid = faculty.fid
INNER JOIN (SELECT cname FROM enrolled_13BCS0003 GROUP BY cname) AS temp ; 



6. 

SELECT 
DISTINCT fname 
FROM faculty_13BCS0003 AS faculty
INNER JOIN class_13BCS0003 AS class ON faculty.fid = class.fid
INNER JOIN (SELECT cname,COUNT(*) AS count FROM enrolled_13BCS0003 GROUP BY cname HAVING COUNT(*)<5) AS temp
WHERE temp.cname = class.name;


7. 

SELECT 
level,
AVG(age) 
FROM student_13BCS0003 
GROUP BY level;


8. 

SELECT 
level,
AVG(age) 
FROM student_13BCS0003 
WHERE level!='JR' GROUP BY level;


9.



10.


SELECT 
sname
FROM student_13BCS0003 AS student
INNER JOIN (SELECT snum,COUNT(*) AS COUNT FROM enrolled_13BCS0003 GROUP BY snum ORDER BY count DESC LIMIT 0,1) AS temp
WHERE student.snum = temp.snum;



