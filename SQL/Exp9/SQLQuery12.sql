--级联删除
USE jxsk
GO
IF EXISTS(SELECT NAME
          FROM sysobjects
          WHERE NAME = 'DC_SC_TC'
            AND TYPE = 'tr')
    DROP TRIGGER DC_SC_TC
GO
CREATE TRIGGER DC_SC_TC
    ON C
    FOR DELETE
    AS
    DECLARE
        @cno_del CHAR(2)
    SELECT @cno_del = CNO
    FROM DELETED
    DELETE
    FROM SC
    WHERE CNO = @cno_del
    DELETE
    FROM TC
    WHERE CNO = @cno_del
GO
--级联更新
USE jxsk
GO
IF EXISTS(SELECT NAME
          FROM sysobjects
          WHERE NAME = 'UC_SC_TC'
            AND TYPE = 'tr')
    DROP TRIGGER UC_SC_TC
GO
CREATE TRIGGER UC_SC_TC
    ON C
    FOR UPDATE
    AS
    DECLARE
        @cno_old CHAR(2)
    DECLARE
        @cno_new CHAR(2)
    SELECT @cno_old = CNO
    FROM DELETED
    SELECT @cno_new = CNO
    FROM INSERTED
    UPDATE SC
    SET CNO=@cno_new
    WHERE CNO = @cno_old
    UPDATE TC
    SET CNO=@cno_new
    WHERE CNO = @cno_old
GO
--验证级联删除
USE jxsk
DELETE
FROM C
WHERE CNO = 'C2'
GO
--验证级联更新
USE jxsk
UPDATE C
SET CNO='C0'
WHERE CNO = 'C1'
GO