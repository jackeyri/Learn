USE master
GO
CREATE DATABASE testbase2
    ON
    PRIMARY
    (NAME =prim_sub_dat1,
        FILENAME ='E:\��Сɽ���ݿ�\prim_sub1_dat.mdf',
        SIZE =5 MB,
        MAXSIZE =50 MB,
        FILEGROWTH =20% ),
    (NAME =prim_sub_dat2,
        FILENAME ='E:\��Сɽ���ݿ�\prim_sub2_dat.ndf',
        SIZE =5 MB,
        MAXSIZE =50 MB,
        FILEGROWTH =20% ),
    FILEGROUP Grouptest1
        (NAME =group1_sub1,
            FILENAME ='E:\��Сɽ���ݿ�\group1_sub1_dat.ndf',
            SIZE =5 MB,
            MAXSIZE =50 MB,
            FILEGROWTH =5 MB ),
        (NAME =group1_sub2,
            FILENAME ='E:\��Сɽ���ݿ�\group1_sub2_dat.ndf',
            SIZE =5 MB,
            MAXSIZE =50 MB,
            FILEGROWTH =5 MB ),
    FILEGROUP Grouptest2
        (NAME =group2_sub1,
            FILENAME ='E:\��Сɽ���ݿ�\group2_sub1_dat.ndf',
            SIZE =5 MB,
            MAXSIZE =50 MB,
            FILEGROWTH =15% ),
        (NAME =group2_sub2, FILENAME ='E:\��Сɽ���ݿ�\group2_sub2_dat.ndf',
            SIZE =5 MB,
            MAXSIZE =50 MB,
            FILEGROWTH =15% )
    LOG ON
    (NAME =testbase2_log,
        FILENAME ='E:\��Сɽ���ݿ�\testbase2_log_file.ldf',
        SIZE =5 MB,
        MAXSIZE =25 MB,
        FILEGROWTH =5 MB )
GO