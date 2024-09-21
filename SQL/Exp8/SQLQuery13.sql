--�����洢����
IF EXISTS(SELECT NAME
          FROM sysobjects
          WHERE NAME = 'Pro_Dept_Count'
            AND TYPE = 'p')
    DROP PROCEDURE Pro_Dept_Count
GO

CREATE PROCEDURE Pro_Dept_Count @dept_in CHAR(10)
AS
SELECT Dept, COUNT(Teacher.Dept) ��ʦ����, AVG(Age) ��ʦƽ������
INTO #a
FROM Teacher
WHERE Teacher.Dept = @dept_in
GROUP BY Dept

SELECT Dept, COUNT(Student.Dept) ѧ������
INTO #b
FROM Student
WHERE Dept = @dept_in
GROUP BY Dept

SELECT #a.Dept ϵ��, ��ʦ����, ��ʦƽ������, ѧ������
FROM #a,
     #b
WHERE #a.Dept = #b.Dept

GO
--ִ�д洢����
USE jiaoxuedb
DECLARE
    @dept_in CHAR(10)
SELECT @dept_in = '��Ϣ'
EXEC Pro_Dept_Count @dept_in