USE jxsk
GO
CREATE TRIGGER USC
    ON SC
    FOR UPDATE, INSERT
    AS
    DECLARE
        @sno CHAR(2)
    DECLARE
        @score TINYINT
    SELECT @sno = SNO
    FROM SC
    SELECT @score = SCORE
    FROM SC
    IF @score < 60
        BEGIN
            UPDATE SC SET SCORE='不及格' WHERE SNO = @sno
        END
    IF @score > 60 AND @score < 70
        BEGIN
            UPDATE SC SET SCORE='及格' WHERE SNO = @sno
        END
    IF @score > 70 AND @score < 80
        BEGIN
            UPDATE SC SET SCORE='中' WHERE SNO = @sno
        END
    IF @score > 80 AND @score < 90
        BEGIN
            UPDATE SC SET SCORE='良' WHERE SNO = @sno
        END
    IF @score > 90 AND @score < 100
        BEGIN
            UPDATE SC SET SCORE='优' WHERE SNO = @sno
        END
GO