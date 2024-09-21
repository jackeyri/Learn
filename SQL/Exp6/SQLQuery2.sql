USE jxsk
GO
ALTER VIEW View_CTABLE AS SELECT TN, CN, CT
                          FROM T,
                               C,
                               TC
                          WHERE T.TNO = TC.TNO
                            AND C.CNO = TC.CNO
GO