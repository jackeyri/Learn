USE jxsk
SELECT S.DEPT, count(DISTINCT TNO) "��ʦ��", count(DISTINCT SNO) "ѧ����"
FROM T
         FULL JOIN S ON S.DEPT = T.DEPT
GROUP BY S.DEPT
ORDER BY "��ʦ��" ASC, "ѧ����" ASC
GO