package cn.edu.zsc.blms.service;

/**
 * 读者Service
 */
public interface ReaderService {

    /** 添加读者 */
    void create();

    /** 禁用读者 */
    void disable();

    /** 修改读者 */
    void update();

    /** 查询读者 */
    void query();

}
