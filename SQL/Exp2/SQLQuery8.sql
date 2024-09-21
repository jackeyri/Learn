USE jiaoxuedb
go

CREATE TABLE Course
(
    Cno    CHAR(10) NOT NULL,
    Cname  CHAR(10) NOT NULL,
    Chour  TINYINT,
    Credit CHAR(10),
)
go

CREATE TABLE SC
(
    Sno   CHAR(10) NOT NULL,
    Cno   CHAR(10) NOT NULL,
    Score TINYINT
)
go

CREATE TABLE Student
(
    Sno   CHAR(10) NOT NULL,
    Sname CHAR(10) NOT NULL,
    Sex   CHAR(10),
    Age   TINYINT,
    Dept  CHAR(10),
)
go

CREATE TABLE TC
(
    Tno CHAR(10),
    Cno CHAR(10),
)
go

CREATE TABLE Teacher
(
    Tno   CHAR(10) NOT NULL,
    Tname CHAR(10) NOT NULL,
    Sex   CHAR(10),
    Age   TINYINT,
    Prof  CHAR(10),
    Sal   SMALLINT,
    Comm  SMALLINT,
    Dept  CHAR(10)
)
go

