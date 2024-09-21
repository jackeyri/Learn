--创建存储过程
IF EXISTS(SELECT NAME
          FROM sysobjects
          WHERE NAME = 'Pro_Cname'
            AND TYPE = 'p')
    DROP PROCEDURE Pro_Cname
GO
CREATE PROCEDURE Pro_Cname @cname CHAR(10)
AS
SELECT Sname, Sex, Dept, Score
FROM Student,
     SC,
     Course
WHERE Cname = @cname
  AND SC.Cno = Course.Cno
  AND SC.Sno = Student.Sno
GO
--执行存储过程
USE jiaoxuedb
DECLARE
    @cname CHAR(10)
SELECT @cname = '程序设计'
EXEC Pro_Cname @cname