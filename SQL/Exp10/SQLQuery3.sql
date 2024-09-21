USE jxsk
GO
SELECT    SN AS 姓名,
          CN AS 课程名,
    成绩= CASE
              WHEN SCORE IS NULL THEN '未考'
              WHEN SCORE < 60 THEN '不及格'
              WHEN SCORE >= 60 AND SCORE < 70 THEN '及格'
              WHEN SCORE >= 70 AND SCORE < 80 THEN '中'
              WHEN SCORE >= 80 AND SCORE < 90 THEN '良好'
              WHEN SCORE >= 90 THEN '优' END
FROM SC,
     S,
     C
WHERE S.SNO = SC.SNO
  AND C.CNO = SC.CNO
ORDER BY S.SNO, C.CNO, SCORE DESC
GO