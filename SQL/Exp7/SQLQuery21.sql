USE jxsk
GO
SELECT TN, SAL, DEPT
FROM T
WHERE SAL > ALL (SELECT SAL
                 FROM T
                 WHERE DEPT = '�����')
  AND (DEPT <> '�����')
GO