USE jiaoxuedb
GO
SELECT Sname, Cname, Score
FROM Student,
     SC,
     Course
WHERE Student.Sno =
      (SELECT s1.Sno
       FROM SC s1,
            SC s2
       WHERE s1.Cno = '01001'
         AND s2.Cno = '01002'
         AND s1.Score > s2.Score
         AND s1.Sno = s2.Sno)
  AND SC.Sno = Student.Sno
  AND Course.Cno = SC.Cno
GO