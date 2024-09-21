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
VALUES ('001101', '宋大方', '男', 19, '计算机')
INSERT INTO Student
VALUES ('002102', '李王', '男', 20, '信息')
INSERT INTO Student
VALUES ('991101', '张彬', '男', 18, '计算机')
INSERT INTO Student
VALUES ('991102', '王蕾', '女', 19, '计算机')
INSERT INTO Student
VALUES ('991103', '张建国', '男', 18, '计算机')
INSERT INTO Student
VALUES ('991104', '李平方', '男', 18, '计算机')
INSERT INTO Student
VALUES ('991201', '陈东辉', '男', 19, '计算机')
INSERT INTO Student
VALUES ('991202', '葛鹏', '男', 21, '计算机')
INSERT INTO Student
VALUES ('991203', '潘桃芝', '女', 19, '计算机')
INSERT INTO Student
VALUES ('991204', '姚一峰', '男', 18, '计算机')
INSERT INTO Student
VALUES ('001102', '许辉', '女', 22, '计算机')
INSERT INTO Student
VALUES ('001201', '王一山', '男', 20, '计算机')
INSERT INTO Student
VALUES ('001202', '牛莉', '女', 19, '计算机')
INSERT INTO Student
VALUES ('002101', '李丽丽', '女', 19, '信息')

/*Insert values to Teacher Table*/
INSERT INTO Teacher
VALUES ('000006', '许红霞', '女', 39, '讲师', 1100, 1200, '计算机')
INSERT INTO Teacher
VALUES ('000007', '许永军', '男', 57, '教授', 2000, 3000, '计算机')
INSERT INTO Teacher
VALUES ('000008', '李贵青', '女', 65, '教授', 2000, 3000, '计算机')
INSERT INTO Teacher
VALUES ('000009', '王一凡', '女', 43, '讲师', 1200, 1200, '计算机')
INSERT INTO Teacher
VALUES ('000010', '田峰', '男', 33, '助教', 500, 800, '信息')
INSERT INTO Teacher
VALUES ('000001', '李英', '女', 39, '副教授', 1500, 2000, '信息')
INSERT INTO Teacher
VALUES ('000002', '张雪', '女', 51, '教授', 1900, 3000, '信息')
INSERT INTO Teacher
VALUES ('000003', '张朋', '男', 30, '讲师', 1000, 1200, '计算机')
INSERT INTO Teacher
VALUES ('000004', '王平', '女', 28, '讲师', 850, 1200, '信息')
INSERT INTO Teacher
VALUES ('000005', '李力', '男', 47, '教授', 1800, 3000, '计算机')

/*Insert values to Course Table*/
INSERT INTO Course
VALUES ('01001', '计算机基础', 60, 3)
INSERT INTO Course
VALUES ('01002', '程序设计', 80, 5)
INSERT INTO Course
VALUES ('02003', '数据结构', 60, 6)
INSERT INTO Course
VALUES ('02001', '数据库', 80, 6)
INSERT INTO Course
VALUES ('02002', '计算机网络', 60, 6)
INSERT INTO Course
VALUES ('01003', '微机原理', 60, 8)
INSERT INTO Course
VALUES ('02004', '操作系统', 60, 6)
INSERT INTO Course
VALUES ('03001', '软件工程', 60, 3)
INSERT INTO Course
VALUES ('03002', '大型数据库', 48, 2)
INSERT INTO Course
VALUES ('03003', '图像处理', 48, 2)

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