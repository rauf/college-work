CREATE TABLE book_13BCS0003 (
bookid int PRIMARY KEY,
title varchar(30),
noofpages int,
copyright varchar(200)
);

CREATE TABLE author_13BCS0003(
authid int PRIMARY KEY,
authFirst varchar(20),
authMid varchar(20),
authLast varchar(20),
authCity varchar(20),
age int
);


CREATE TABLE writtenby_13BCS0003 (
publisher varchar(20),
wbookid int,
wauthid int,
FOREIGN KEY (wbookid) REFERENCES book_13BCS0003 (bookid) ON DELETE CASCADE ON UPDATE CASCADE,
FOREIGN KEY (wauthid) REFERENCES author_13BCS0003 (authid) ON DELETE CASCADE ON UPDATE CASCADE
);



////insertion


INSERT INTO book_13BCS0003  VALUES 
(1, 'Harry Potter', 500, 'XYZ publishers'),
(2, 'ABC', 300, 'Xasi publishers'),
(3, 'D.samanta', 250, 'samanta publishers'),
(4, 'Schaum', 500, 'Scahum publishers'),
(5, 'Hater', 500, 'hat publishers');

INSERT INTO author_13BCS0003 VALUES 
(1, 'Abdul', '', 'Rauf', 'new delhi', 20),
(2, 'Abdullah', '', 'Hasan', 'new delhi', 40),
(3, 'Abhinav', '', 'Rai', 'new delhi', 30),
(4, 'Aakash', '', 'Aggarwal', 'aligarh', 30);

INSERT INTO writtenby_13BCS0003 VALUES 
("Minnat", 1, 1),
("Anamta", 1, 2),
("Adeela", 3, 3),
("Gulnawaz", 4, 3),
("Sharique", 2, 3),
("Asad", 2, 4);




SELECT * FROM book_13BCS0003;
SELECT * FROM author_13BCS0003;
SELECT * FROM writtenby_13BCS0003;


Queries
_____________________________________________________________


1. 

SELECT 
author.authfirst,
book.title,
writtenby.publisher 
FROM author_13BCS0003 AS author 
INNER JOIN writtenby_13BCS0003 AS writtenby ON author.authid = writtenby.wauthid 
INNER JOIN book_13BCS0003 AS book ON book.bookid = writtenby.wbookid
WHERE author.authcity regexp '[b-z]*a[b-z]*a[b-z]*'; 




2 


SELECT * 
FROM book_13BCS0003 as book
INNER JOIN (SELECT wbookid FROM writtenby_13BCS0003 GROUP BY wbookid HAVING COUNT(wbookid)>=2) AS temp
WHERE book.bookid = temp.wbookid;



3. 

delimiter #

CREATE PROCEDURE insertIntoAuth(IN id int, IN first varchar(20),IN mid varchar(20),IN last varchar(20),IN city varchar(20), IN age int)
BEGIN
DECLARE t int;
SELECT count(*) into t FROM author_13BCS0003 WHERE authid = id;

IF t>0 THEN
SELECT 'id already exists';
ELSE
INSERT INTO author_13BCS0003 VALUES(id,first,mid,last,city,age);
SELECT 'record successfully entered';
END IF;
END#



4. 

CREATE PROCEDURE insertBook(IN id int, IN title varchar(20),IN pages int, IN copyright varchar(20))
BEGIN
DECLARE t int;
SELECT count(*) into t FROM book_13BCS0003 WHERE bookid = id;

IF t>0 THEN
SELECT 'id already exists';
ELSE
INSERT into book_13BCS0003 VALUES(id,title,pages,copyright);
SELECT 'booksuccessfully added';
END IF;
END#

CREATE PROCEDURE insertWBy(IN publisher varchar(20), IN bookid int,IN authorid int)
BEGIN
INSERT into writtenby_13BCS0003 VALUES(publisher,bookid,authorid);
SELECT 'writtenby entry successfully added';
END#


CREATE PROCEDURE insertBookInfo(IN bookid int, IN title varchar(20),IN pages int, IN copyright varchar(20),IN publisher varchar(20),IN authorid int)
BEGIN
call insertBook(bookid,title,pages,copyright);
call insertWBy(publisher,bookid,authorid);
END#



5. 

CREATE PROCEDURE deleteAuthorById(IN id int)
BEGIN
DECLARE t int;
DECLARE u int;
DECLARE str varchar(255);

SELECT count(*) INTO t FROM writtenby_13BCS0003 WHERE writtenby_13BCS0003.wauthid = id ;
SELECT count(*) INTO u FROM author_13BCS0003 WHERE author_13BCS0003.authid = id ;

IF u = 0 THEN
SELECT 'Author not present';
ELSE 

IF t>0 THEN
SET STR = concat('You cannot delete author because total ',t,' books exists IN the books table.First delete all the books written by the author. ' );
SELECT str;

ELSE
DELETE FROM author_13BCS0003 WHERE authid =id;
SELECT 'Author deleted';

END IF;
END IF;
END #


6. 


CREATE PROCEDURE deleteBookByAuthorID(IN id int)
BEGIN
DECLARE t int;
SELECT count(*) INTO t FROM author_13BCS0003 WHERE authid = id;
IF t = 0 THEN
SELECT 'Author does not Exist';
else
DELETE FROM book_13BCS0003 WHERE bookid IN (SELECT wbookid FROM writtenby_13BCS0003 WHERE wauthid = id);
SELECT concat('All books of author with id ',id,' are deleted ');
END IF;

END #




