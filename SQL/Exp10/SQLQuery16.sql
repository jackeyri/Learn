USE jxsk
SELECT TN AS 姓名, SEX AS 性别, 2008 - AGE AS 出生日期, PROF AS 职称, SAL + COMM AS 工资
FROM T
WHERE TN = '张雪'
UNION
SELECT t1.TN AS 姓名, t1.SEX AS 性别, 2008 - t1.AGE AS 出生日期, t1.PROF AS 职称, t1.SAL + t1.COMM AS 工资
FROM T t1,
     T t2
WHERE t2.TN = '张雪'
  AND t1.TN <> '张雪'
  AND (t1.SAL + t1.COMM) < (t2.SAL + t2.COMM)
ORDER BY (SAL + COMM) DESC
GO