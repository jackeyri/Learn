USE jiaoxuedb
GO
SELECT Sno AS ѧ��, Sname AS ����, Age AS ����, Dept AS רҵ
FROM Student
WHERE Sno = ANY
      (SELECT Sno
       FROM SC x
       WHERE Score >=
             (SELECT AVG(Score)
              FROM SC y
              WHERE y.Sno = x.Sno));
GO