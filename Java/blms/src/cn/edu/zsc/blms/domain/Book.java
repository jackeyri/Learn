package cn.edu.zsc.blms.domain;

import cn.edu.zsc.blms.util.DateUtil;

import java.util.Date;

/**
 * 图书Domain
 *
 * @author zhangjunkai
 */
public class Book extends BaseEntity {

    /**
     * ID
     */
    public int id;

    /**
     * 书名
     */
    public String name;

    /**
     * 书号
     */
    public String isbn;

    /**
     * 类目
     */
    public String category;

    /**
     * 作者
     */
    public String author;

    /**
     * 出版社
     */
    public String press;

    /**
     * 出版日期
     */
    public Date publishDate;

    /**
     * 价格
     */
    public Double price;

    /**
     * 是否废弃
     */
    public boolean disabled;

    public Book() {
    }

    public Book(int id, String name, String isbn, String category, String author, String press, Date publishDate, Double price) {
        super(id);
        this.name = name;
        this.isbn = isbn;
        this.category = category;
        this.author = author;
        this.press = press;
        this.publishDate = publishDate;
        this.price = price;
    }

    @Override
    public String toString() {
        return "ID：" + id + "，姓名：" + name + "，isbn：" + isbn + "，类目：" + category + "，作者：" + author + "，出版社：" + press + "，出版日期：" + DateUtil.format(publishDate) + "，价格：" + price + "，废弃：" + (disabled ? "是" : "否");
    }

    /**
     * 状态
     */
    public Status status = Status.可出借;

    public enum Status {
        可出借,
        已借出
    }
}