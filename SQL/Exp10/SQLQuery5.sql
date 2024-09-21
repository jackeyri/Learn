DECLARE @SNO CHAR(6), @SNAME CHAR(8), @SEX CHAR(2), @AGE TINYINT, @DEPT CHAR(10)
DECLARE Cursor_Famale CURSOR
    FOR SELECT SNO, SNAME, SEX, AGE, DEPT
        FROM Student
OPEN Cursor_Famale
FETCH NEXT FROM Cursor_Famale INTO @SNO, @SNAME,@SEX,@AGE,@DEPT
WHILE @@fetch_status = 0 BEGIN
    IF @SNAME = '牛莉'
        BEGIN
            PRINT '找到牛莉的信息如下：'
            PRINT @SNO + ' ' + @SNAME + ' ' + @SEX + ' ' + convert(CHAR(2), @AGE) + ' ' + @DEPT
            BREAK
        END
    FETCH NEXT FROM Cursor_Famale INTO @SNO,@SNAME,@SEX,@AGE,@DEPT
END
IF @@fetch_status != 0 PRINT '很抱歉，没有找到牛莉的信息！'
CLOSE Cursor_Famale
DEALLOCATE Cursor_Famale