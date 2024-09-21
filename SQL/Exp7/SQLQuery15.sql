USE jxsk
GO
SELECT X.TN AS 姓名, X.SAL AS 教师工资, Y.SAL AS 刘伟工资
FROM T AS X,
     T AS Y
WHERE X.SAL > Y.SAL
  AND Y.TN = '刘伟'
GO