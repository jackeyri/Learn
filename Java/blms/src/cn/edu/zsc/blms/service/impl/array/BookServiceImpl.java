package cn.edu.zsc.blms.service.impl.array;

import cn.edu.zsc.blms.App;
import cn.edu.zsc.blms.domain.Book;
import cn.edu.zsc.blms.exception.EntityNotExistException;
import cn.edu.zsc.blms.service.BookService;
import cn.edu.zsc.blms.util.DateUtil;

import java.text.ParseException;
import java.util.Date;

public class BookServiceImpl extends BaseServiceImpl implements BookService {

    /**
     * 单例
     */
    private static BookService singleton;

    /**
     * 私有构造方法
     */
    private BookServiceImpl() {

    }

    /**
     * 获取单例，非线程安全
     *
     * @return ReaderService单例
     */
    public static BookService getSingleton() {
        if (singleton == null) {
            singleton = new BookServiceImpl();
        }
        return singleton;
    }

    @Override
    public void create() {
        if (idCounter >= DATA.length) {
            System.out.println("图书数量已满，不能再添加");
            return;
        }
        System.out.print("请输入书名");
        String name = App.input.nextLine();
        System.out.print("请输入书号");
        String isbn = App.input.nextLine();
        System.out.print("请输入类目");
        String category = App.input.nextLine();
        System.out.print("请输入作者");
        String author = App.input.nextLine();
        System.out.print("请输入出版社");
        String press = App.input.nextLine();
        System.out.print("请输入出版日期，格式为yyyy-MM-dd：");
        Date publishDate = null;
        while (publishDate == null) {
            String strDate = App.input.nextLine();
            try {
                publishDate = DateUtil.parse(strDate);
            } catch (ParseException e) {
                System.out.print("输入的日期格式错误，请重新输入：");
            }
        }
        System.out.print("请输入单价：");
        Double price = null;
        while (price == null) {
            String strPrice = App.input.nextLine();
            try {
                price = Double.parseDouble(strPrice);
            } catch (NegativeArraySizeException e) {
                System.out.print("输入的单价格式错误，请重新输入：");
            }
        }
        Book book = new Book(idCounter, name, isbn, category, author, press, publishDate, price);
        DATA[idCounter] = book;
        System.out.println("成功增加1本图书！");
        idCounter++;
    }

    /**
     * 废弃图书
     */
    @Override
    public void disable() {
        System.out.print("请输入要废弃的图书ID：");
        Book book = null;
        try {
            book = (Book) getOne();
        } catch (EntityNotExistException e) {
            System.out.println(e.getMessage());
        }
        if (book != null) {
            book.disabled = true;
            System.out.println("该用户已被废弃");
        }
    }

    @Override
    public void update() {
        System.out.print("请输入要编辑的图书ID：");
        Book book = null;
        try {
            book = (Book) getOne();
        } catch (EntityNotExistException e) {
            System.out.println(e.getMessage());
        }
        if (book != null) {
            System.out.print("请输入书名，直接按回车表示不修改：");
            String name = App.input.nextLine();
            book.name = "".equals(name) ? book.name : name;
            System.out.print("请输入书号，直接按回车表示不修改：");
            String isbn = App.input.nextLine();
            book.isbn = "".equals(isbn) ? book.isbn : isbn;
            System.out.print("请输入类目，直接按回车表示不修改：");
            String category = App.input.nextLine();
            book.category = "".equals(category) ? book.category : category;
            System.out.print("请输入作者，直接按回车表示不修改：");
            String author = App.input.nextLine();
            book.author = "".equals(author) ? book.author : author;
            System.out.print("请输入出版社，直接按回车表示不修改：");
            String press = App.input.nextLine();
            book.press = "".equals(press) ? book.press : press;
            System.out.print("请输入出版日期，格式为：yyyy-MM-dd，直接按回车表示不修改：");
            Date publishDate = null;
            while (publishDate == null) {
                String strDate = App.input.nextLine();
                if ("".equals(strDate)) {
                    publishDate = book.publishDate;
                    break;
                }
                try {
                    publishDate = DateUtil.parse(strDate);
                } catch (ParseException e) {
                    System.out.print("输入的日期格式错误，请重新输入：");
                }
            }
            book.publishDate = publishDate;
            System.out.print("请输入单位，直接按回车表示不修改：");
            Double price = null;
            while (price == null) {
                String strPrice = App.input.nextLine();
                if ("".equals(strPrice)) {
                    price = book.price;
                    break;
                }
                try {
                    price = Double.parseDouble(strPrice);
                } catch (NegativeArraySizeException e) {
                    System.out.print("输入的单价格式错误，请重新输入：");
                }
            }
            book.price = price;
            App.input.nextLine();
            System.out.println("该图书的信息已被修改");
        }
    }

    @Override
    public void query() {
        System.out.print("请输入要查询的图书名称：");
        String name = App.input.nextLine();
        for (int i = 0; i < idCounter; i++) {
            Book book = (Book) DATA[i];
            if (book.name != null && book.name.contains(name)) {
                System.out.println("ID：" + book.id + "，书名：" + book.name + "，isbn：" + book.isbn + "，类目：" + book.category + "，作者：" + book.author + "，价格：" + book.price + "，废弃：" + (book.disabled ? "是" : "否"));
            }
        }
    }

}
