package cn.edu.zsc.blms.model;

import cn.edu.zsc.blms.domain.BaseEntity;
import cn.edu.zsc.blms.domain.Book;
import cn.edu.zsc.blms.domain.Reader;
import cn.edu.zsc.blms.util.DateUtil;

import java.util.Date;

public class Borrowing extends BaseEntity {

    /**
     * 读者
     */
    public Reader reader;

    /**
     * 图书
     */
    public Book book;

    /**
     * 借书时间
     */
    public Date borrowTime;

    /**
     * 归还时间
     */
    public Date returnTime;

    public Borrowing() {
    }

    public Borrowing(Integer id, Reader reader, Book book, Date borrowTime, Date returnTime) {
        super(id);
        this.reader = reader;
        this.book = book;
        this.borrowTime = borrowTime;
        this.returnTime = returnTime;
    }

    public Borrowing(int idCounter, Reader reader, Book book, Date date) {
    }

    @Override
    public String toString() {
        return "ID：" + id + "，读者姓名：" + reader.name + "，图书名称：" + book.name + "，借出时间：" + DateUtil.formatTime(borrowTime) + "，归还时间：" + (returnTime == null ? "" : DateUtil.formatTime(returnTime));
    }

}
