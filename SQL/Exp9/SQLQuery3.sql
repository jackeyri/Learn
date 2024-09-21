USE jxsk
GO
CREATE TRIGGER Score_SC_Tri
    ON SC
    FOR INSERT, UPDATE
    AS DECLARE
    @score_read tinyint
    SELECT @score_read = SCORE
    FROM Inserted
    IF @score_read >= 0 AND @score_read <= 100
        BEGIN
            PRINT '操作成功'
            RETURN
        END
    PRINT '成绩超出0~100！请重新输入。'
    ROLLBACK TRANSACTION
GO