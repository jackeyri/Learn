USE jiaoxuedb
GO
SELECT Sno AS 学号, Sname AS 姓名, Age AS 年龄, Dept AS 专业
FROM Student
WHERE Age = ANY
      (SELECT Age
       FROM Student
       WHERE Sname = '张建国')
  AND Sname <> '张建国'
ORDER BY Age DESC
GO