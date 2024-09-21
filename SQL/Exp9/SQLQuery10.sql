USE jxsk
GO
IF EXISTS(SELECT NAME
          FROM sysobjects
          WHERE NAME = 'Score_sc_tri'
            AND TYPE = 'tr')
    DROP TRIGGER Score_sc_tri
GO
CREATE TRIGGER Score_sc_tri
    ON SC
    FOR INSERT, UPDATE
    AS
    DECLARE
        @score_read TINYINT
    SELECT @score_read = SCORE
    FROM INSERTED
    IF @score_read < 0 OR @score_read > 100
        BEGIN
            PRINT '�ɼ�����0~100�����������롣'
            Rollback Transaction
        END
GO