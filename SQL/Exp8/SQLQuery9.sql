--�����洢����
IF EXISTS(SELECT NAME
          FROM sysobjects
          WHERE NAME = 'Pro_Age_Max_Min'
            AND TYPE = 'p')
    drop procedure Pro_Age_Max_Min
GO
CREATE PROCEDURE Pro_Age_Max_Min @sdept_in CHAR(10)
AS
SELECT Dept ϵ��, MAX(Age) �������, MIN(Age) ��С����
FROM Student
WHERE Dept = @sdept_in
GROUP BY Dept
GO
--ִ�д洢����
USE jiaoxuedb
DECLARE
    @sdept_in CHAR(10)
SELECT @sdept_in = '�����'
EXEC Pro_Age_Max_Min @sdept_in