use jiaoxuedb
GO
select distinct sno
from sc s1
where not exists(select *
                 from sc s2
                 where sno = '991101'
                   and not exists(select *
                                  from sc s3
                                  where s1.sno = s3.sno
                                    and s2.cno = s3.cno))
GO