DECLARE @SNO CHAR(6), @SNAME CHAR(8), @SEX CHAR(2), @AGE TINYINT, @DEPT CHAR(10)
DECLARE Cursor_Famale CURSOR
    FOR SELECT SNO, SNAME, SEX, AGE, DEPT
        FROM Student
OPEN Cursor_Famale
FETCH NEXT FROM Cursor_Famale INTO @SNO, @SNAME,@SEX,@AGE,@DEPT
WHILE @@fetch_status = 0 BEGIN
    IF @SNAME = 'ţ��'
        BEGIN
            PRINT '�ҵ�ţ�����Ϣ���£�'
            PRINT @SNO + ' ' + @SNAME + ' ' + @SEX + ' ' + convert(CHAR(2), @AGE) + ' ' + @DEPT
            BREAK
        END
    FETCH NEXT FROM Cursor_Famale INTO @SNO,@SNAME,@SEX,@AGE,@DEPT
END
IF @@fetch_status != 0 PRINT '�ܱ�Ǹ��û���ҵ�ţ�����Ϣ��'
CLOSE Cursor_Famale
DEALLOCATE Cursor_Famale