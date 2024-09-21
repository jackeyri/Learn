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
            PRINT '�����ɹ�'
            RETURN
        END
    PRINT '�ɼ�����0~100�����������롣'
    ROLLBACK TRANSACTION
GO