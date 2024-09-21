CREATE DATABASE jiaoxuedb
GO
USE jiaoxuedb
CREATE TABLE Student
(
    Sno   CHAR(10) NOT NULL,
    Sname CHAR(10) NOT NULL,
    Sex   CHAR(2)  NULL,
    Age   TINYINT  NULL,
    Dept  CHAR(10) NULL
)
CREATE TABLE Teacher
(
    Tno   CHAR(10) NOT NULL,
    Tname CHAR(10) NOT NULL,
    Sex   CHAR(2)  NULL,
    Age   TINYINT  NULL,
    Prof  CHAR(10) NULL,
    Sal   SMALLINT NULL,
    Comm  SMALLINT NULL,
    Dept  CHAR(10) NULL
)
CREATE TABLE Course
(
    Cno     CHAR(10) NOT NULL,
    Cname   CHAR(10) NOT NULL,
    Chour   TINYINT  NULL,
    Ccredit TINYINT  NULL
)
CREATE TABLE SC
(
    Sno   CHAR(10) NOT NULL,
    Cno   CHAR(10) NOT NULL,
    SCORE TINYINT  NULL
)
CREATE TABLE TC
(
    Tno CHAR(10) NOT NULL,
    Cno CHAR(10) NOT NULL
)

/*Insert values to Student Table*/
INSERT INTO Student
VALUES ('001101', '�δ�', '��', 19, '�����')
INSERT INTO Student
VALUES ('002102', '����', '��', 20, '��Ϣ')
INSERT INTO Student
VALUES ('991101', '�ű�', '��', 18, '�����')
INSERT INTO Student
VALUES ('991102', '����', 'Ů', 19, '�����')
INSERT INTO Student
VALUES ('991103', '�Ž���', '��', 18, '�����')
INSERT INTO Student
VALUES ('991104', '��ƽ��', '��', 18, '�����')
INSERT INTO Student
VALUES ('991201', '�¶���', '��', 19, '�����')
INSERT INTO Student
VALUES ('991202', '����', '��', 21, '�����')
INSERT INTO Student
VALUES ('991203', '����֥', 'Ů', 19, '�����')
INSERT INTO Student
VALUES ('991204', 'Ҧһ��', '��', 18, '�����')
INSERT INTO Student
VALUES ('001102', '���', 'Ů', 22, '�����')
INSERT INTO Student
VALUES ('001201', '��һɽ', '��', 20, '�����')
INSERT INTO Student
VALUES ('001202', 'ţ��', 'Ů', 19, '�����')
INSERT INTO Student
VALUES ('002101', '������', 'Ů', 19, '��Ϣ')

/*Insert values to Teacher Table*/
INSERT INTO Teacher
VALUES ('000006', '���ϼ', 'Ů', 39, '��ʦ', 1100, 1200, '�����')
INSERT INTO Teacher
VALUES ('000007', '������', '��', 57, '����', 2000, 3000, '�����')
INSERT INTO Teacher
VALUES ('000008', '�����', 'Ů', 65, '����', 2000, 3000, '�����')
INSERT INTO Teacher
VALUES ('000009', '��һ��', 'Ů', 43, '��ʦ', 1200, 1200, '�����')
INSERT INTO Teacher
VALUES ('000010', '���', '��', 33, '����', 500, 800, '��Ϣ')
INSERT INTO Teacher
VALUES ('000001', '��Ӣ', 'Ů', 39, '������', 1500, 2000, '��Ϣ')
INSERT INTO Teacher
VALUES ('000002', '��ѩ', 'Ů', 51, '����', 1900, 3000, '��Ϣ')
INSERT INTO Teacher
VALUES ('000003', '����', '��', 30, '��ʦ', 1000, 1200, '�����')
INSERT INTO Teacher
VALUES ('000004', '��ƽ', 'Ů', 28, '��ʦ', 850, 1200, '��Ϣ')
INSERT INTO Teacher
VALUES ('000005', '����', '��', 47, '����', 1800, 3000, '�����')

/*Insert values to Course Table*/
INSERT INTO Course
VALUES ('01001', '���������', 60, 3)
INSERT INTO Course
VALUES ('01002', '�������', 80, 5)
INSERT INTO Course
VALUES ('02003', '���ݽṹ', 60, 6)
INSERT INTO Course
VALUES ('02001', '���ݿ�', 80, 6)
INSERT INTO Course
VALUES ('02002', '���������', 60, 6)
INSERT INTO Course
VALUES ('01003', '΢��ԭ��', 60, 8)
INSERT INTO Course
VALUES ('02004', '����ϵͳ', 60, 6)
INSERT INTO Course
VALUES ('03001', '�������', 60, 3)
INSERT INTO Course
VALUES ('03002', '�������ݿ�', 48, 2)
INSERT INTO Course
VALUES ('03003', 'ͼ����', 48, 2)

/*Insert values to SC Table*/
INSERT INTO SC
VALUES ('991101', '01001', 88)
INSERT INTO SC
VALUES ('991102', '01001', 93)
INSERT INTO SC
VALUES ('991103', '01001', 90)
INSERT INTO SC
VALUES ('991101', '01002', 90)
INSERT INTO SC
VALUES ('991102', '01002', 98)
INSERT INTO SC
VALUES ('991103', '01002', 74)
INSERT INTO SC
VALUES ('991104', '01002', 85)
INSERT INTO SC
VALUES ('001201', '01002', 64)
INSERT INTO SC
VALUES ('991104', '02001', 33)
INSERT INTO SC
VALUES ('991104', '01001', 35)
INSERT INTO SC
VALUES ('991201', '01001', 76)

/*Insert values to TC Table*/
INSERT INTO TC
VALUES ('000001', '02001')
INSERT INTO TC
VALUES ('000008', '02002')
INSERT INTO TC
VALUES ('000003', '02001')
INSERT INTO TC
VALUES ('000011', '02003')
INSERT INTO TC
VALUES ('000001', '01001')
INSERT INTO TC
VALUES ('000002', '01002')
INSERT INTO TC
VALUES ('000002', '01003')
INSERT INTO TC
VALUES ('000004', '02002')
INSERT INTO TC
VALUES ('000005', '01001')
INSERT INTO TC
VALUES ('000006', '01002')
INSERT INTO TC
VALUES ('000003', '01003')