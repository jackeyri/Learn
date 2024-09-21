--�����洢����
IF EXISTS(SELECT NAME
          FROM sysobjects
          WHERE NAME = 'Pro_Dept_Prof'
            AND TYPE = 'p')
    DROP PROCEDURE Pro_Dept_Prof
GO
CREATE PROCEDURE Pro_Dept_Prof @dept_in CHAR(10),
                               @prof_in CHAR(10)
AS
SELECT Dept     ϵ��,
       Prof     ְ��,
       COUNT(*) ����,
       AVG(AGE) ƽ������,
       AVG(SAL) ƽ������,
       MAX(SAL) ��߹���
FROM Teacher
WHERE Dept = @dept_in
  AND Prof = @prof_in
GROUP BY Dept, Prof
GO
--ִ�д洢����
USE jiaoxuedb
DECLARE
    @dept_in CHAR(10),
    @prof_in CHAR(10)
SELECT @dept_in = '�����'
SELECT @prof_in = '����'
EXEC Pro_Dept_Prof @dept_in, @prof_in