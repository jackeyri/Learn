USE jxsk
GO
SELECT TN, DEPT
FROM T
WHERE NOT EXISTS(SELECT *
                 FROM TC
                 WHERE TNO = T.TNO
                   AND CNO = 'C5')
GO