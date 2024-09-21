USE jiaoxuedb
GO
CREATE VIEW SCORE_View_CDEPT AS
SELECT Student.Sno AS SNO, Sname AS SN, Cname CN, Score
FROM Student,
     Course,
     SC
WHERE Student.Dept = '¼ÆËã»ú'
  AND Student.Sno = SC.Sno
  AND SC.Cno = Course.Cno
GO