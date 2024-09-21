--创建存储过程
IF EXISTS(SELECT NAME
          FROM sysobjects
          WHERE NAME = 'Pro_Sn'
            AND TYPE = 'p')
    DROP PROCEDURE Pro_Sn
GO
CREATE PROCEDURE Pro_Sn @sname_in CHAR(10)
AS
SELECT Student.Sname 学生, Cname 选修课程, Score 分数, Tname 教师
FROM Student,
     SC,
     Teacher,
     Course,
     TC
WHERE Student.Sname = @sname_in
  AND SC.Sno = Student.Sno
  AND SC.Cno = Course.Cno
  AND SC.Cno = TC.Cno
  AND TC.Cno = Course.Cno
  AND TC.Tno = Teacher.Tno
GO
--执行存储过程
USE jiaoxuedb
DECLARE
    @sname_in CHAR(10)
SELECT @sname_in = '王蕾'
EXEC Pro_Sn @sname_in