DECLARE @SUM SMALLINT , @I SMALLINT, @NUMS SMALLINT
SET @SUM = 0
SET @I = 1
SET @NUMS = 0
WHILE (@I <= 100) BEGIN
    IF (@I % 3 = 0)
        BEGIN
            SET @SUM = @SUM + @I
            SET @NUMS = @NUMS + 1
        END
    SET @I = @I + 1
END
PRINT '�ܺ��ǣ�' + str(@SUM)
PRINT '�����ǣ�' + str(@NUMS)