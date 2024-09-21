USE jiaoxuedb
GO
SELECT Sno AS 学号, Sname AS 姓名, Age AS 年龄, Dept AS 专业
FROM Student
WHERE Sno = ANY
      (SELECT Sno
       FROM SC
       GROUP BY Sno
       HAVING COUNT(*) >= 2)
GO