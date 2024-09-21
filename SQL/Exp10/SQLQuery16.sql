USE jxsk
SELECT TN AS ����, SEX AS �Ա�, 2008 - AGE AS ��������, PROF AS ְ��, SAL + COMM AS ����
FROM T
WHERE TN = '��ѩ'
UNION
SELECT t1.TN AS ����, t1.SEX AS �Ա�, 2008 - t1.AGE AS ��������, t1.PROF AS ְ��, t1.SAL + t1.COMM AS ����
FROM T t1,
     T t2
WHERE t2.TN = '��ѩ'
  AND t1.TN <> '��ѩ'
  AND (t1.SAL + t1.COMM) < (t2.SAL + t2.COMM)
ORDER BY (SAL + COMM) DESC
GO