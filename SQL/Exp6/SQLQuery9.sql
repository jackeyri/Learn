USE jiaoxuedb
GO
CREATE VIEW S_View AS
SELECT Sno AS SNO, Sname AS SN, Sex AS SEX
FROM Student
WHERE Dept = '�����'
GO