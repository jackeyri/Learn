DECLARE @MyCursor CURSOR
DECLARE @NAME     VARCHAR(30)
DECLARE @In_NAME  CHAR(8)
DECLARE @SCORE    INT
SELECT @In_NAME = '王一山'
EXECUTE Pro_C @C_cursor=@MyCursor OUTPUT
FETCH NEXT FROM @MyCursor INTO @NAME,@SCORE
WHILE (@@fetch_status = 0) BEGIN
    IF @NAME = @In_NAME
        BEGIN
            PRINT @NAME + '选修了数据库课程，成绩是：' + convert(CHAR(2), @SCORE)
            BREAK
        END
    FETCH NEXT FROM @MyCursor INTO @name,@SCORE
END
IF (@@fetch_status != 0) PRINT @In_NAME + '没有选修数据库课程。'
CLOSE @MyCursor
DEALLOCATE @MyCursor