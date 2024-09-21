USE jxsk
GO
SELECT DISTINCT SNO
FROM SC SCX
WHERE NOT EXISTS(SELECT *
                 FROM SC SCY
                 WHERE SCY.SNO = 'S2'
                   AND NOT EXISTS
                     (SELECT *
                      FROM SC SCZ
                      WHERE SCZ.SNO = SCX.SNO
                        AND SCZ.CNO = SCY.CNO))
GO