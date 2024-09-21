--创建存储过程
IF EXISTS(SELECT NAME
          FROM sysobjects
          WHERE NAME = 'Pro_Prof_Count'
            AND TYPE = 'p')
    DROP PROCEDURE Pro_Prof_Count
GO
CREATE PROCEDURE Pro_Prof_Count @prof_in CHAR(10)
AS
SELECT Prof 职称, COUNT(Prof) 人数
FROM Teacher
WHERE Prof = @prof_in
GROUP BY Prof
GO
--执行存储过程
USE jiaoxuedb
DECLARE
    @prof_in CHAR(10)
SELECT @prof_in = '副教授'
EXEC Pro_Prof_Count @prof_in