USE jiaoxuedb
GO
SELECT Sname AS ����, AVG(Score) AS ƽ��, MAX(Score) AS ���
FROM Student,
     SC
WHERE Student.Sno = SC.Sno
GROUP BY Sname
ORDER BY Sname DESC
GO