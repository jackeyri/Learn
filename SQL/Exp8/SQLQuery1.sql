-- =============================================

CREATE PROCEDURE Pro_Qsinf @sno_in char(8)='S2', @sname_out char(8) OUTPUT,
                           @sage_out int OUTPUT, @dept_out char(10) OUTPUT
AS
BEGIN
    SET NOCOUNT ON;
    SELECT @sname_out = SN, @sage_out = AGE, @dept_out = DEPT
    FROM S
    WHERE SNO = @sno_in
END
GO