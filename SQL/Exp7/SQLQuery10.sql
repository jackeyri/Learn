USE jxsk
GO
SELECT COUNT(*)   AS 人数,
       AVG(SCORE) AS 平均分数,
       MAX(SCORE) AS 最高分数
FROM C,
     SC
WHERE CN = '微机原理'
  AND C.CNO = SC.CNO
GO