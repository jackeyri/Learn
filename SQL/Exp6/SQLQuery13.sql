USE jiaoxuedb
GO
ALTER VIEW S_VIEW AS SELECT Sno AS SNO, Sname AS SN, Sex AS SEX, Age AS AGE
                     FROM Student
                     WHERE Dept = '¼ÆËã»ú'
GO