USE jiaoxuedb
GO
SELECT Cno AS �γ̺�, Cname AS �γ���
FROM Course
WHERE Cno = ANY
      (SELECT Cno AS �γ̺�
       FROM SC
       GROUP BY Cno
       HAVING COUNT(*) >= 4)
GO