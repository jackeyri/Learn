USE jiaoxuedb
GO
SELECT Cname AS �γ̺�, Cno AS �γ���
FROM Course
WHERE NOT EXISTS
    (SELECT *
     FROM Student
     WHERE NOT EXISTS
         (SELECT *
          FROM SC
          WHERE Student.Sno = SC.Sno
            AND SC.Cno = Course.Cno));
GO