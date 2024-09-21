USE jiaoxuedb
GO
SELECT Sname AS 姓名, AVG(Score) AS 平均, MAX(Score) AS 最高
FROM Student,
     SC
WHERE Student.Sno = SC.Sno
GROUP BY Sname
ORDER BY Sname DESC
GO