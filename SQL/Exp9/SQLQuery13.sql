USE jxsk
GO
IF EXISTS(SELECT NAME
          FROM sysobjects
          WHERE NAME = 'UT'
            AND TYPE = 'tr')
    DROP TRIGGER UT
GO
CREATE TRIGGER UT
    ON T
    FOR UPDATE
    AS
    DECLARE
        @prof_old CHAR(10)
    DECLARE
        @prof_new CHAR(10)
    DECLARE
        @tno CHAR(2)
    SELECT @prof_old = PROF
    FROM DELETED
    SELECT @prof_new = PROF
    FROM INSERTED
    SELECT @tno = TNO
    FROM DELETED
    IF @prof_old = '��ʦ' AND @prof_new = '������'
        BEGIN
            UPDATE T SET COMM=COMM + 500 WHERE TNO = @tno
        END
    IF @prof_old = '������' AND @prof_new = '����'
        BEGIN
            UPDATE T SET COMM=COMM + 900 WHERE TNO = @tno
        END
GO