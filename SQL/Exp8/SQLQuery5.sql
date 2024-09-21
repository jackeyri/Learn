USE [jxsk]
GO
/****** Object:  StoredProcedure [dbo].[Pro_Qsinf] ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
-- =============================================

ALTER PROCEDURE [dbo].[Pro_Qsinf] @sno_in char(2)='S2', @sname_out char(8) OUTPUT,
                                  @sage_out tinyint OUTPUT, @dept_out char(10) OUTPUT
AS
BEGIN
    SET NOCOUNT ON;
    SELECT @sname_out = SN, @sage_out = AGE, @dept_out = DEPT
    FROM S
    WHERE SNO = @sno_in
END
