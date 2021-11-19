-- question 2.

Create database HW7;

-- connect to hw7 database 
-- \c hw7;

CREATE TABLE employee ("employeeId" varchar(20) NOT NULL, "name" varchar(100) NOT NULL, "username" varchar(20) NOT NULL);

insert into employee values ('1001','Ali','ali1001');
insert into employee values ('1002','zahra','zahra1002');
insert into employee values ('1003','atosa','atosa1003');
insert into employee values ('1004','mohammd','mohammd1004');
insert into employee values ('1005','hossein','hossein1005');
insert into employee values ('1006','testrole1','testrole11006');

CREATE USER super SUPERUSER password '123';

-- \q
--  psql -U super -d postgres -h 127.0.0.1 -W
-- password : 123

CREATE ROLE gprole WITH createrole VALID UNTIL '2045-04-08';
CREATE ROLE testrole1 WITH login password '123';
CREATE ROLE testrole2 WITH login password '123';

GRANT gprole to testrole1;
GRANT gprole to testrole2;

alter role testrole1 with NOBYPASSRLS INHERIT; 
alter role testrole2 rename to newtstrole2;

-- \q
--  psql -U testrole1 -d postgres -h 127.0.0.1 -W
-- \c hw7

select * from employee;
-- got ERROR:  permission denied for relation employee
-- \q
--  psql -U super -d postgres -h 127.0.0.1 -W
-- password : 123
-- solution:
GRANT SELECT ON employee TO testrole1;
-- \q
--  psql -U testrole1 -d postgres -h 127.0.0.1 -W
-- password : 123
-- \c hw7 
select * from employee;
-- \q
--  psql -U super -d postgres -h 127.0.0.1 -W
-- password : 123

ALTER TABLE employee ENABLE ROW LEVEL SECURITY;
CREATE POLICY employee_testrole1 ON employee TO testrole1 USING (name = 'testrole1');

-- \c hw7 testrole1
select * from employee;
-- \c hw7 super
drop role newtstrole2 ;
-- \du
