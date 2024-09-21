CREATE DATABASE mybase
    ON
    (NAME =group1,
        FILENAME ='D:\mytestbase\group1.mdf',
        MAXSIZE =100 MB,
        FILEGROWTH =20%)
    LOG ON
    (NAME =group2,
        FILENAME ='D:\mytestbase\group2.ldf')
GO