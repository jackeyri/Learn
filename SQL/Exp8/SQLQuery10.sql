--�����洢����
IF EXISTS(SELECT NAME
          FROM sysobjects
          WHERE NAME = 'Pro_Qscore'
            AND TYPE = 'P')
    DROP PROCEDURE Pro_Qscore
GO
CREATE PROCEDURE Pro_Qscore @sname_in CHAR(10),
                            @scname_in CHAR(10)
AS
SELECT Sname ѧ������, Cname �γ���, Score ����
FROM Student,
     SC,
     Course
WHERE Student.sname = @sname_in
  AND Course.Cname = @scname_in
  AND SC.Sno = Student.Sno
  AND SC.Cno = Course.Cno
GO
--ִ�д洢����
USE jiaoxuedb
DECLARE
    @sname_in CHAR(10),
    @scname_in CHAR(10)
SELECT @sname_in = '����'
SELECT @scname_in = '�������'
EXEC Pro_Qscore @sname_in, @scname_in