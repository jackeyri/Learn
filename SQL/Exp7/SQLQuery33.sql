USE jiaoxuedb
GO
SELECT Student.Sno, Sname
FROM Student
WHERE Student.Sno IN
      (SELECT s1.Sno
       FROM SC s1
       WHERE Sno NOT IN
             (SELECT s2.Sno
              FROM SC s2
              WHERE Cno = '01001'))
GO