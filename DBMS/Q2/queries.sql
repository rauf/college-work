CREATE TABLE class_13BCS0003 (
cid int PRIMARY KEY,
cname char(20),
duration int
);

CREATE TABLE student_13BCS0003 (
stud_no int PRIMARY KEY,
stud_name varchar(20),
dob date,
cid int,
FOREIGN KEY (cid) REFERENCES class_13BCS0003(cid) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE lab_13BCS0003 (
mach_no varchar(20) PRIMARY KEY,
lab_no int,
description varchar(100)
);

CREATE TABLE allotment_13BCS0003 (
stud_no int,
mach_no varchar(20),
days_of_week varchar(20),

FOREIGN KEY (stud_no) REFERENCES student_13BCS0003(stud_no) ON DELETE CASCADE ON UPDATE CASCADE,
FOREIGN KEY (mach_no) REFERENCES lab_13BCS0003(mach_no) ON DELETE CASCADE ON UPDATE CASCADE,

PRIMARY KEY pk(stud_no,mach_no)
);



INSERT INTO class_13BCS0003 VALUES
(1,'B.Tech CS',4),
(2,'B.Tech EC',4),
(3,'B.Sc',3),
(4,'BA',2);

INSERT INTO student_13BCS0003 VALUES 
(1,'Asad','1996-01-05',1),
(2,'Atul Kunwar','1998-01-25',2),
(3,'Aakash','1999-02-07',4),
(4,'Shoeib','2000-02-14',1),
(5,'Minnet Khan','1997-03-21',4),
(6,'Varun Bansal','1990-04-28',3),
(7,'Deepak Sharma','1995-05-09',2),
(8,'Faizan','1994-11-11',3);

INSERT INTO lab_13BCS0003 VALUES 
('M1',11,'Apple Lab'),
('M2',12,'Sun Lab'),
('M3',14,'Operating System Lab'),
('M4',11,'Apple Lab'),
('M5',13,'DBMS Lab'),
('M6',12,'Sun Lab'),
('M7',14,'Operating System Lab'),
('M8',13,'DBMS Lab');



INSERT INTO allotment_13BCS0003 VALUES 
(1,'M1','Mon'),
(2,'M5','Thu'),
(3,'M8','Fri'),
(4,'M5','Tue'),
(5,'M1','Fri'),
(6,'M5','Mon'),
(7,'M3','Wed'),
(8,'M4','Mon');




DROP TABLE student_13BCS0003;
DROP TABLE allotment_13BCS0003;
DROP TABLE lab_13BCS0003;
DROP TABLE class_13BCS0003;


SELECT * FROM student_13BCS0003;
SELECT * FROM allotment_13BCS0003;
SELECT * FROM lab_13BCS0003;
SELECT * FROM class_13BCS0003;




Queries:


2. 

SELECT student.stud_name,
lab.lab_no,
allotment.mach_no 
FROM allotment_13BCS0003 AS allotment 
INNER JOIN student_13BCS0003 AS student ON student.stud_no = allotment.stud_no
INNER JOIN lab_13BCS0003 AS lab ON allotment.mach_no = lab.mach_no;


3. 


SELECT 
days_of_week,
count(lab_no) 
FROM lab_13BCS0003 AS lab
INNER JOIN allotment_13BCS0003 AS allotment ON lab.mach_no = allotment.mach_no 
GROUP BY days_of_week;  


4. 


SELECT COUNT(allotment.stud_no) AS count
FROM allotment_13BCS0003 AS allotment
INNER JOIN student_13BCS0003 as student on allotment.stud_no = student.stud_no
INNER JOIN class_13BCS0003 AS class ON class.cid = student.cid
WHERE class.cname = "B.Tech CS";



5.

SELECT 
student.*,
allotment.mach_no,
allotment.days_of_week,
class.cname,
class.duration 
FROM student_13BCS0003 AS student
INNER JOIN allotment_13BCS0003 AS allotment ON student.stud_no = allotment.stud_no
INNER JOIN class_13BCS0003 AS class ON student.cid = class.cid
WHERE student.stud_no = 5;



6. 

SELECT 
count(*) AS count
FROM allotment_13BCS0003 AS allotment
INNER JOIN lab_13BCS0003 AS lab ON allotment.mach_no = lab.mach_no
WHERE allotment.days_of_week = "Mon" AND lab.lab_no = 11;


7.

SELECT 
class.cid,
class.cname,
count(*)
FROM class_13BCS0003 AS class
INNER JOIN student_13BCS0003 AS student ON student.cid = class.cid
INNER JOIN allotment_13BCS0003 AS allotment ON allotment.stud_no = student.stud_no
WHERE allotment.stud_no = student.stud_no
GROUP BY student.cid;


8.

SELECT 
lab.lab_no,
lab.description,
count(*)
FROM lab_13BCS0003 AS lab 
INNER JOIN allotment_13BCS0003 AS allotment ON allotment.mach_no = lab.mach_no
GROUP BY lab.lab_no;



9. 

SELECT 
student.stud_no,
student.stud_name,
class.cname,
allotment.mach_no,
lab.lab_no 
FROM student_13BCS0003 AS student
INNER JOIN allotment_13BCS0003 AS allotment ON student.stud_no = allotment.stud_no 
INNER JOIN class_13BCS0003 AS class ON student.cid = class.cid 
INNER JOIN lab_13BCS0003 AS lab ON allotment.mach_no = lab.mach_no 
ORDER BY student.dob DESC LIMIT 1;



10.

SELECT 
mach_no 
FROM 
allotment_13BCS0003 
GROUP BY mach_no HAVING count(*) >= 2;
