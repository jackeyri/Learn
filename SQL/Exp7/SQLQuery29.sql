USE jiaoxuedb
GO
SELECT Sno AS ѧ��, Sname AS ����, Age AS ����, Dept AS רҵ
FROM Student
WHERE Sno = ANY
      (SELECT Sno
       FROM SC
       GROUP BY Sno
       HAVING COUNT(*) >= 2)
GO