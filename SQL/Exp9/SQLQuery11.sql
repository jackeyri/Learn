USE jxsk
GO
IF EXISTS(SELECT NAME
          FROM sysobjects
          WHERE NAME = 'Age_T_Tri'
            AND TYPE = 'tr')
    DROP TRIGGER Age_T_Tri
GO
CREATE TRIGGER Age_T_Tri
    ON T
    FOR INSERT, UPDATE
    AS
    DECLARE
        @sex_read CHAR(2)
    DECLARE
        @age_read TINYINT
    DECLARE
        @prof_read CHAR(10)
    SELECT @sex_read = SEX
    FROM INSERTED
    SELECT @age_read = AGE
    FROM INSERTED
    SELECT @prof_read = PROF
    FROM INSERTED
    IF (@sex_read = '��' AND @age_read > 60)
        OR (@sex_read = 'Ů' AND @prof_read = '����' AND @age_read > 60)
        OR (@sex_read = 'Ů' AND @prof_read <> '����' AND @age_read > 60)
        BEGIN
            PRINT '���ݲ��Ϸ���'
            Rollback Transaction
        END
GO