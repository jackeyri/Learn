DECLARE @SUM SMALLINT,@I SMALLINT
SET @SUM = 0
SET @I = 1
WHILE (@I <= 100) BEGIN
    SET @SUM = @SUM + @I
    SET @I = @I + 1
END
PRINT '�ܺ��ǣ�' + str(@SUM)