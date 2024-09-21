--�����洢����
IF EXISTS(SELECT NAME
          FROM sysobjects
          WHERE NAME = 'Pro_Tname_Cname'
            AND TYPE = 'p')
    DROP PROCEDURE Pro_Tname_Cname
GO

CREATE PROCEDURE Pro_Tname_Cname @tname CHAR(10),
                                 @cname CHAR(10)
AS
SELECT Tname, Cname, SUM(Chour) ��ʱ��, COUNT(Sno) ѡ������, AVG(Score) ƽ���ɼ�
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
--ִ�д洢����
USE jiaoxuedb
DECLARE
    @tname CHAR(10),
    @cname CHAR(10)
SELECT @tname = '��ѩ'
SELECT @cname = '΢��ԭ��'
EXEC Pro_Tname_Cname @tname, @cname