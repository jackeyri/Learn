CREATE DATABASE testbase1
    ON
    ( NAME =testbase1_data,
        FILENAME ='e:\张小山数据库\testbase1_data.mdf')
    LOG ON
    ( NAME =testbase1_log,
        FILENAME ='e:\张小山数据库\testbase1_log.ldf')
GO