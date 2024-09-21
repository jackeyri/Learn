--创建存储过程
IF EXISTS(SELECT NAME
          FROM sysobjects
          WHERE NAME = 'Pro_Dept_Count'
            AND TYPE = 'p')
    DROP PROCEDURE Pro_Dept_Count
GO

CREATE PROCEDURE Pro_Dept_Count @dept_in CHAR(10)
AS
SELECT Dept, COUNT(Teacher.Dept) 教师人数, AVG(Age) 教师平均年龄
INTO #a
FROM Teacher
WHERE Teacher.Dept = @dept_in
GROUP BY Dept

SELECT Dept, COUNT(Student.Dept) 学生人数
INTO #b
FROM Student
WHERE Dept = @dept_in
GROUP BY Dept

SELECT #a.Dept 系别, 教师人数, 教师平均年龄, 学生人数
FROM #a,
     #b
WHERE #a.Dept = #b.Dept

GO
--执行存储过程
USE jiaoxuedb
DECLARE
    @dept_in CHAR(10)
SELECT @dept_in = '信息'
EXEC Pro_Dept_Count @dept_in