USE jxsk
GO
SELECT X.TN AS ����, X.SAL AS ��ʦ����, Y.SAL AS ��ΰ����
FROM T AS X,
     T AS Y
WHERE X.SAL > Y.SAL
  AND Y.TN = '��ΰ'
GO