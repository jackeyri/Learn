package cn.edu.zsc.blms.service;

/**
 * 图书Service
 *
 * @author zhangjunkai
 */
public interface BookService {

    /** 添加图书 */
    void create();

    /** 废弃图书 */
    void disable();

    /** 修改图书 */
    void update();

    /** 查询图书 */
    void query();

}
