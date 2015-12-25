delimiter #

CREATE FUNCTION findAvgFloat(a1 int,a2 int,a3 int) RETURNS float 
BEGIN 
DECLARE avg float;
SET avg = (a1 + a2 + a3);
SET avg = avg/3; 
RETURN AVG; 
END #


DROP FUNCTION findAvgFloat#
SELECT findAvgFloat(5,2,8)#


//fibonacci function

CREATE FUNCTION fibonacci (n int) RETURNS varchar(250)
BEGIN 
DECLARE i int DEFAULT 2; 
DECLARE a int DEFAULT 0; 
DECLARE b int DEFAULT 1; 
DECLARE c int DEFAULT 0; 
DECLARE sum int DEFAULT 0; 
DECLARE series varchar (250) DEFAULT "0, "; 

myloop : LOOP 
IF i>n THEN 
leave myloop; 

ELSE
SET c = a + b;
SET series = CONCAT(series,c,", ");
SET a = b;
SET b = c;
SET sum = sum + c;
SET i = i+1; 
ITERATE myloop; 

END IF; 
END LOOP;

SET series = concat(series," Sum is:- ",sum); 
RETURN series; 
END #


SELECT fibonacci(8)#

//factorial function


CREATE FUNCTION factorial (n int) RETURNS int 
BEGIN 
DECLARE i int DEFAULT 1; 
DECLARE fact int DEFAULT 1; 

myloop : LOOP 

IF i>n THEN 
leave myloop; 
ELSE
SET fact = fact*i;
SET i = i+1; 
ITERATE myloop; 
END IF; 

END LOOP; 
RETURN fact; 
END #

SELECT factorial(5)#

//factorial procedure


CREATE PROCEDURE factorial (IN n int, OUT fact int) 
BEGIN 
DECLARE i int DEFAULT 1;
SET fact = 1; 

myloop : LOOP 

IF i>n THEN 
leave myloop; 
ELSE
SET fact = fact*i;
SET i = i+1; 
ITERATE myloop; 
END IF; 

END LOOP;
END #


DROP PROCEDURE factorial#
CALL factorial(5,@fact)#
SELECT @fact#




// fibonacci procedure


CREATE PROCEDURE fibonacci (IN n int, OUT series varchar(250)) 
BEGIN DECLARE i int DEFAULT 2; 
DECLARE a int DEFAULT 0; 
DECLARE b int DEFAULT 1; 
DECLARE c int DEFAULT 0; 
DECLARE sum int DEFAULT 0;
SET series = "0, "; 

myloop : LOOP 

IF i>n THEN 
leave myloop; 
ELSE
SET c = a+b;
SET series = CONCAT(series,c,", ");
SET a = b;
SET b = c;
SET sum = sum + c;
SET i = i+1; 
ITERATE myloop; 
END IF; 

END LOOP;
SET series = CONCAT(series," Sum is:- ",sum);
END #


DROP PROCEDURE fibonacci#
CALL fibonacci(8,@fib)#
SELECT @fib#







CREATE table worksfor (
eid int,
deptid int,
foreign key (eid) references emp1303(eid),
foreign key (deptid) references department(deptno)
)#


CREATE procedure Department(IN id int,In department int)
begin

insert into department values(id,'Abdul')
end #


CREATE procedure insertInEmp1303(IN eid int ,IN ename varchar(20),IN esal int)
begin
insert into emp1303 values(eid,ename,esal,"2015-10-08","new delhi");
end #


CREATE procedure insertInWorksFor (IN empid int ,IN ename varchar(20),IN esal int,IN deptid int)
begin
declare n_eid int;
declare n_deptid int;
select count(*) into n_eid from emp1303 where eid = empid;
select count(*) into n_deptid from department where deptno = deptid;

if n_eid*n_deptid > 0 then
call Emp1303(empid,ename,esal);
call Department(deptid);
insert into worksfor values(empid,deptid);

else
select 'entry cannot be inserted';
end if;

END#


drop procedure insertInWorksFor#


call insertInWorksFor(3,"abcdefg",5356,5)#









////////////Triggers/////////////



CREATE TABLE logger
(
username varchar(30),
operation varchar(30),
timestamp datetime,
previousId int,
previousName varchar(30),
previousSal int,
previousDOB date,
previousCity varchar(20),
newId int,
newName varchar(30),
newSal int,
newDOB date,
newCity varchar(20)
)#



//to drop 
drop table log#




CREATE TRIGGER afterInsert AFTER INSERT ON employee_13BCS0003
FOR EACH ROW
BEGIN
INSERT INTO logger VALUES (
user(),
'insert',
now(),
null,
null,
null,
null,
null,
new.eid,
new.ename,
new.esal,
new.edob,
new.ecity);

END#



CREATE TRIGGER afterUpdate AFTER UPDATE ON employee_13BCS0003
FOR EACH ROW
BEGIN
INSERT INTO logger VALUES (
user(),
'update',
now(),
old.eid,
old.ename,
old.esal,
old.edob,
old.ecity,
new.eid,
new.ename,
new.esal,
new.edob,
new.ecity
);

END#

CREATE TRIGGER beforeDelete BEFORE DELETE ON employee_13BCS0003
FOR EACH ROW
BEGIN
INSERT INTO logger VALUES (
user(),
'delete',
now(),
old.eid,
old.ename,
old.esal,
old.edob,
old.ecity,
null,
null,
null,
null,
null
);

END#

