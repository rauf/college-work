CREATE TABLE product_13BCS0003 (
pid varchar(20) PRIMARY KEY,
pname varchar(20) NOT NULL,
price int NOT NULL,
discount int,
pcompany varchar(20)
);

CREATE TABLE customer_13BCS0003(
cid varchar(20) PRIMARY KEY,
cname varchar(20) NOT NULL,
cadd varchar(20),
ccity varchar(20)
);

CREATE TABLE orderdetail_13BCS0003 (
oid varchar(20),
pid varchar(20),
cid varchar(20),
odate date,
qty int,
status varchar(20),

FOREIGN KEY (cid) REFERENCES customer_13BCS0003 (cid) ON DELETE CASCADE ON UPDATE CASCADE,
FOREIGN KEY (pid) REFERENCES product_13BCS0003 (pid) ON DELETE CASCADE ON UPDATE CASCADE,

PRIMARY KEY (oid, cid, pid)
);




INSERT INTO product_13BCS0003 VALUES
('p001','pendrive',700,5,'kingston'),
('p005','dvd',20,2,'moserbaer'),
('p007','headphone',500,25,'intex'),
('p009','modem',1500,10,'intex'),
('p010','harddisk',4500,7,'seagate'),
('p012','speaker',1000,5,'creative'),
('p101','ram',2000,6,'hynix');


INSERT INTO customer_13BCS0003 VALUES
('c01','sonaal','dwarka','new delhi'),
('c02','abhinav','mehrauli','new delhi'),
('c03','abdul rauf','jamia hostel','new delhi'),
('c05','insan','jamia hostel','new delhi'),
('c06','javed ahmed','allahabad','Uttar Pradesh'),
('c07','deepak','borivali','Mumbai'),
('c08','minnat khan','allahabad','UP');

INSERT INTO orderdetail_13BCS0003 VALUES
('o01','p001','c01','2015-07-23',2,'success'),
('o01','p007','c01','2015-07-23',2,'success'),
('o02','p010','c05','2015-08-28',5,'success'),
('o02','p012','c05','2015-08-28',5,'success'),
('o03','p005','c02','2015-08-31',20,'success'),
('o04','p009','c06','2015-09-01',2,'success'),
('o05','p010','c07','2015-09-02',1,'success'),
('o06','p012','c02','2015-09-03',2,'pending'),
('o07','p007','c06','2015-08-25',1,'failed');





SELECT * FROM product_13BCS0003;
SELECT * FROM customer_13BCS0003;
SELECT * FROM orderdetail_13BCS0003;



Queries:

2. 

SELECT customer.cid,
customer.cname,
product.pname
FROM customer_13BCS0003 AS customer
INNER JOIN orderdetail_13BCS0003 AS orderdetail ON orderdetail.cid = customer.cid AND orderdetail.status = "success"
INNER JOIN product_13BCS0003 AS product ON orderdetail.pid = product.pid;




3.

SELECT 
temp.odate,
((temp.qty * (product.price * product.discount)/100)) AS total_discount
FROM product_13BCS0003 AS product
INNER JOIN (SELECT pid,SUM(qty) AS qty,odate FROM orderdetail_13BCS0003  GROUP BY odate) AS temp
WHERE temp.pid = product.pid;



4. 

SELECT product.*
FROM 
product_13BCS0003 AS product
INNER JOIN (SELECT pid FROM orderdetail_13BCS0003 AS orderdetail GROUP BY orderdetail.pid HAVING count(*)>=2) AS temp
WHERE product.pid = temp.pid;



5. 

SELECT pname 
FROM product_13BCS0003 
ORDER BY price DESC limit 2,1;


6. 

SELECT customer.cname
FROM customer_13BCS0003 AS customer
LEFT OUTER JOIN orderdetail_13BCS0003 AS orderdetail ON customer.cid = orderdetail.cid
WHERE orderdetail.cid IS NULL;




7. 

SELECT customer.cname
FROM customer_13BCS0003 AS customer
INNER JOIN (SELECT cid FROM orderdetail_13BCS0003 GROUP BY cid HAVING count(distinct pid)>=2) AS temp
WHERE customer.cid = temp.cid;




8. 

SELECT 
customer.cid,
customer.cname
FROM customer_13BCS0003 AS customer
INNER JOIN (SELECT  cid FROM orderdetail_13BCS0003 GROUP BY cid HAVING count(*)>=2) AS temp
WHERE customer.cid = temp.cid;


9. 

SELECT 
product.pname,
product.price,
temp.quantity,
(temp.quantity * (product.price - (product.price * product.discount)/100)) AS finalAmount
FROM product_13BCS0003 AS product
INNER JOIN (SELECT pid,SUM(qty) AS quantity FROM orderdetail_13BCS0003 GROUP BY pid)  AS temp
WHERE temp.pid = product.pid;


10.

SELECT 
customer.cname,
temp.quantity 
FROM customer_13BCS0003 AS customer
INNER JOIN (SELECT cid,SUM(qty) AS quantity FROM orderdetail_13BCS0003 GROUP BY cid) AS temp
WHERE customer.cid = temp.cid;
