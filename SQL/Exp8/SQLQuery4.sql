USE jxsk
GO
DECLARE
    @sname_in char(8),
    @cname_in char(8),
    @score_out tinyint
SELECT @sname_in = '��˼'
SELECT @cname_in = '�������'
EXEC Pro_Qscore @sname_in, @cname_in, @score_out OUTPUT
PRINT RTRIM(@sname_in) + ' = ' + LTRIM(STR(@score_out))
GO