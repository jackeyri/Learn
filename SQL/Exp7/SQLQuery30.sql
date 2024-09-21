USE jiaoxuedb
GO
SELECT Sno AS 学号,Sname AS 姓名,Age AS 年龄,Dept AS 专业
FROM Student
WHERE Sno=ANY
	(SELECT Sno
	FROM SC
	WHERE Cno=ANY
		(SELECT Cno
		FROM SC
		WHERE Sno='991103'))
	AND Sname <> '张建国'
GO