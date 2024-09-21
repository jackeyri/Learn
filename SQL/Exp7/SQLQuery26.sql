USE jiaoxuedb
GO
SELECT Cno AS 课程号, Cname AS 课程名
FROM Course
WHERE Cno = ANY
      (SELECT Cno AS 课程号
       FROM SC
       GROUP BY Cno
       HAVING COUNT(*) >= 4)
GO