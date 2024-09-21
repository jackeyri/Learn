--创建存储过程
IF EXISTS(SELECT NAME
          FROM sysobjects
          WHERE NAME = 'Pro_Age_Max_Min'
            AND TYPE = 'p')
    drop procedure Pro_Age_Max_Min
GO
CREATE PROCEDURE Pro_Age_Max_Min @sdept_in CHAR(10)
AS
SELECT Dept 系别, MAX(Age) 最大年龄, MIN(Age) 最小年龄
FROM Student
WHERE Dept = @sdept_in
GROUP BY Dept
GO
--执行存储过程
USE jiaoxuedb
DECLARE
    @sdept_in CHAR(10)
SELECT @sdept_in = '计算机'
EXEC Pro_Age_Max_Min @sdept_in