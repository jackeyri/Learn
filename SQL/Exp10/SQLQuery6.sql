CREATE PROCEDURE PRO_C @C_cursor CURSOR VARYING OUTPUT AS
    SET @C_cursor = CURSOR FOR SELECT SNAME, SCORE
                               FROM Student,
                                    SC,
                                    Course
                               WHERE Student.SNO = SC.SNO
                                 AND SC.CNO = Course.CNO
                                 AND Course.CNAME = 'Êý¾Ý¿â'
    OPEN @C_cursor