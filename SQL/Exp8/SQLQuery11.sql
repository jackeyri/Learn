--�����洢����
IF EXISTS(SELECT NAME
          FROM sysobjects
          WHERE NAME = 'Pro_Prof_Count'
            AND TYPE = 'p')
    DROP PROCEDURE Pro_Prof_Count
GO
CREATE PROCEDURE Pro_Prof_Count @prof_in CHAR(10)
AS
SELECT Prof ְ��, COUNT(Prof) ����
FROM Teacher
WHERE Prof = @prof_in
GROUP BY Prof
GO
--ִ�д洢����
USE jiaoxuedb
DECLARE
    @prof_in CHAR(10)
SELECT @prof_in = '������'
EXEC Pro_Prof_Count @prof_in