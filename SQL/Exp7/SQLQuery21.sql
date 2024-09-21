USE jxsk
GO
SELECT TN, SAL, DEPT
FROM T
WHERE SAL > ALL (SELECT SAL
                 FROM T
                 WHERE DEPT = '计算机')
  AND (DEPT <> '计算机')
GO