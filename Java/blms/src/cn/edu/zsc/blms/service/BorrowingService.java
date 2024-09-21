package cn.edu.zsc.blms.service;

public interface BorrowingService {

    /** 借阅图书 */
    void borrow();

    /** 归还图书 */
    void giveBack();

    /** 查询记录，按出借顺序显示当前已借出的图书 */
    void query();
}
