USE jiaoxuedb
GO
SELECT Sno AS ѧ��, Sname AS ����, Age AS ����, Dept AS רҵ
FROM Student
WHERE Age > ALL
      (SELECT Age
       FROM Student
       WHERE Dept = '��Ϣ')
  AND Dept <> '��Ϣ'
ORDER BY Age DESC
GO