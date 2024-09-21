DECLARE @N INT,@I SMALLINT
SET @N = 1
SET @I = 2
WHILE (@I <= 10) BEGIN
    SET @N = @N * @I
    SET @I = @I + 1
END
PRINT '10! =' + str(@N)