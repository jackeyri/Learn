USE jxsk
GO
SELECT C.CNO, TN, COUNT(SC.SNO) AS ѧ������
FROM T,
     TC,
     C,
     SC
WHERE T.TNO = TC.TNO
  AND C.CNO = TC.CNO
  AND C.CNO = SC.CNO
GROUP BY C.CNO, T.TN
GO