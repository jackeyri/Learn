USE jiaoxuedb
GO
SELECT Sno AS ѧ��,Sname AS ����,Age AS ����,Dept AS רҵ
FROM Student
WHERE Sno=ANY
	(SELECT Sno
	FROM SC
	WHERE Cno=ANY
		(SELECT Cno
		FROM SC
		WHERE Sno='991103'))
	AND Sname <> '�Ž���'
GO