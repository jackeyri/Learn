USE jiaoxuedb
GO
SELECT Sno AS ѧ��, Sname AS ����, Age AS ����, Dept AS רҵ
FROM Student
WHERE Age = ANY
      (SELECT Age
       FROM Student
       WHERE Sname = '�Ž���')
  AND Sname <> '�Ž���'
ORDER BY Age DESC
GO