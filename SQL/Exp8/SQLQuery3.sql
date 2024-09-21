CREATE PROCEDURE Pro_Qscore @sname_in char(8), @cname_in char(10),
                            @score_out tinyint OUTPUT
AS
SELECT @score_out = SCORE
FROM S,
     C,
     SC
WHERE S.SNO = SC.SNO
  AND C.CNO = SC.CNO
  AND SN = @sname_in
  AND CN = @cname_in