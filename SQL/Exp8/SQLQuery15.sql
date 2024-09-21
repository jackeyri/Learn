--创建存储过程
IF EXISTS(SELECT NAME
          FROM sysobjects
          WHERE NAME = 'Pro_Tname_Cname'
            AND TYPE = 'p')
    DROP PROCEDURE Pro_Tname_Cname
GO

CREATE PROCEDURE Pro_Tname_Cname @tname CHAR(10),
                                 @cname CHAR(10)
AS
SELECT Tname, Cname, SUM(Chour) 课时数, COUNT(Sno) 选课人数, AVG(Score) 平均成绩
FROM Teacher,
     Course,
     SC,
     TC
WHERE Tname = @tname
  AND Cname = @cname
  AND TC.Tno = Teacher.Tno
  AND TC.Cno = Course.Cno
  AND SC.Cno = Course.Cno
GROUP BY Tname, Cname
GO
--执行存储过程
USE jiaoxuedb
DECLARE
    @tname CHAR(10),
    @cname CHAR(10)
SELECT @tname = '张雪'
SELECT @cname = '微机原理'
EXEC Pro_Tname_Cname @tname, @cname