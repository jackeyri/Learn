USE jiaoxuedb
GO
CREATE VIEW SCORE_View AS
SELECT Student.Sno AS SNO, Sname AS SN, Cname AS CN, Score
FROM Student,
     Course,
     SC
WHERE Student.Sno = SC.Sno
  AND SC.Cno = Course.Cno
GO