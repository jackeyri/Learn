USE jxsk
GO
ALTER PROCEDURE Pro_Qsinf @sno_in char(2)='S1',
                          @sname_out char(8) OUTPUT,
                          @ssex_out char(2) OUTPUT,
                          @dept_out char(10) OUTPUT
AS
SELECT @sname_out = SN, @ssex_out = SEX, @dept_out = DEPT
FROM S
WHERE SNO = @sno_in
GO