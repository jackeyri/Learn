USE jxsk
UPDATE T
SET SAL =SAL + CASE
                   WHEN T.TNO IN (SELECT TC.TNO
                                  FROM T,
                                       TC
                                  WHERE T.TNO = TC.TNO
                                    AND (SAL + COMM) >= 4000
                                  GROUP BY TC.TNO
                                  HAVING count(*) >= 2) THEN 300
                   WHEN T.TNO IN (SELECT TC.TNO
                                  FROM T,
                                       TC
                                  WHERE T.TNO = TC.TNO
                                    AND (SAL + COMM) >= 3000
                                    AND (SAL + COMM) < 4000
                                  GROUP BY TC.TNO
                                  HAVING count(*) >= 2) THEN 200
                   WHEN T.TNO IN (SELECT TC.TNO
                                  FROM T,
                                       TC
                                  WHERE T.TNO = TC.TNO
                                    AND (SAL + COMM) < 3000
                                  GROUP BY TC.TNO
                                  HAVING count(*) >= 2) THEN 100
                   WHEN T.TNO IN (SELECT TC.TNO
                                  FROM T,
                                       TC
                                  WHERE T.TNO = TC.TNO
                                  GROUP BY TC.TNO
                                  HAVING count(*) >= 1) THEN 50
                   ELSE 0 END
GO