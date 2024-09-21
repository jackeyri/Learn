--�����洢����
IF EXISTS(SELECT NAME
          FROM sysobjects
          WHERE NAME = 'Pro_Sn'
            AND TYPE = 'p')
    DROP PROCEDURE Pro_Sn
GO
CREATE PROCEDURE Pro_Sn @sname_in CHAR(10)
AS
SELECT Student.Sname ѧ��, Cname ѡ�޿γ�, Score ����, Tname ��ʦ
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
--ִ�д洢����
USE jiaoxuedb
DECLARE
    @sname_in CHAR(10)
SELECT @sname_in = '����'
EXEC Pro_Sn @sname_in