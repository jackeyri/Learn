--创建存储过程
IF EXISTS(SELECT NAME
          FROM sysobjects
          WHERE NAME = 'Pro_Dept_Prof'
            AND TYPE = 'p')
    DROP PROCEDURE Pro_Dept_Prof
GO
CREATE PROCEDURE Pro_Dept_Prof @dept_in CHAR(10),
                               @prof_in CHAR(10)
AS
SELECT Dept     系别,
       Prof     职称,
       COUNT(*) 人数,
       AVG(AGE) 平均年龄,
       AVG(SAL) 平均工资,
       MAX(SAL) 最高工资
FROM Teacher
WHERE Dept = @dept_in
  AND Prof = @prof_in
GROUP BY Dept, Prof
GO
--执行存储过程
USE jiaoxuedb
DECLARE
    @dept_in CHAR(10),
    @prof_in CHAR(10)
SELECT @dept_in = '计算机'
SELECT @prof_in = '教授'
EXEC Pro_Dept_Prof @dept_in, @prof_in