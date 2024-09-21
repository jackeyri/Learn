USE jiaoxuedb
GO
SELECT Student.Sno, Sname, Dept, Course.Cno, Score
FROM Student,
     SC,
     Course
WHERE Student.Sno = SC.Sno
  AND SC.Score BETWEEN 80 AND 90
  AND SC.Cno = Course.Cno;
GO