--创建存储过程
IF EXISTS(SELECT NAME
          FROM sysobjects
          WHERE NAME = 'Pro_Qscore'
            AND TYPE = 'P')
    DROP PROCEDURE Pro_Qscore
GO
CREATE PROCEDURE Pro_Qscore @sname_in CHAR(10),
                            @scname_in CHAR(10)
AS
SELECT Sname 学生姓名, Cname 课程名, Score 分数
FROM Student,
     SC,
     Course
WHERE Student.sname = @sname_in
  AND Course.Cname = @scname_in
  AND SC.Sno = Student.Sno
  AND SC.Cno = Course.Cno
GO
--执行存储过程
USE jiaoxuedb
DECLARE
    @sname_in CHAR(10),
    @scname_in CHAR(10)
SELECT @sname_in = '王蕾'
SELECT @scname_in = '程序设计'
EXEC Pro_Qscore @sname_in, @scname_in