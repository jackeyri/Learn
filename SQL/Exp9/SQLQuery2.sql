CREATE TRIGGER TRIGGER_SC
    ON SC
    FOR UPDATE AS IF UPDATE(SNO)
    BEGIN
        DECLARE @SNO_NEW char(2),
            @SNO_OLD char(2),
            @SNO_CNT int
        SELECT @SNO_OLD = SNO FROM Deleted
        SELECT @SNO_CNT = COUNT(*) FROM S WHERE SNO = @SNO_OLD
        IF @SNO_CNT <> 0
            ROLLBACK TRANSACTION
    END