USE jiaoxuedb
GO
SELECT Sno AS 学号, Sname AS 姓名, Age AS 年龄, Dept AS 专业
FROM Student
WHERE Age > ALL
      (SELECT Age
       FROM Student
       WHERE Dept = '信息')
  AND Dept <> '信息'
ORDER BY Age DESC
GO