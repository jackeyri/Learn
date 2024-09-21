USE jxsk
GO
SELECT    SN AS ����,
          CN AS �γ���,
    �ɼ�= CASE
              WHEN SCORE IS NULL THEN 'δ��'
              WHEN SCORE < 60 THEN '������'
              WHEN SCORE >= 60 AND SCORE < 70 THEN '����'
              WHEN SCORE >= 70 AND SCORE < 80 THEN '��'
              WHEN SCORE >= 80 AND SCORE < 90 THEN '����'
              WHEN SCORE >= 90 THEN '��' END
FROM SC,
     S,
     C
WHERE S.SNO = SC.SNO
  AND C.CNO = SC.CNO
ORDER BY S.SNO, C.CNO, SCORE DESC
GO