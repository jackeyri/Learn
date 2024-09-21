USE jxsk
GO
DECLARE
    @sno_in char(8),
    @sname_out char(8),
    @sage_out int,
    @sdept_out char(10)
EXEC Pro_Qsinf DEFAULT, @sname_out OUTPUT, @sage_out OUTPUT, @sdept_out OUTPUT
PRINT @sname_out
PRINT @sage_out
PRINT @sdept_out
SELECT @sno_in = 'S4'
EXEC Pro_Qsinf @sno_in, @sname_out OUTPUT, @sage_out OUTPUT, @sdept_out OUTPUT
PRINT @sname_out
PRINT @sage_out
PRINT @sdept_out
GO