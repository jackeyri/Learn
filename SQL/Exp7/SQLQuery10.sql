USE jxsk
GO
SELECT COUNT(*)   AS ����,
       AVG(SCORE) AS ƽ������,
       MAX(SCORE) AS ��߷���
FROM C,
     SC
WHERE CN = '΢��ԭ��'
  AND C.CNO = SC.CNO
GO