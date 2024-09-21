package cn.edu.zsc.blms.service.impl.collection;

import cn.edu.zsc.blms.domain.Book;
import cn.edu.zsc.blms.domain.Reader;
import cn.edu.zsc.blms.exception.EntityNotExistException;
import cn.edu.zsc.blms.model.Borrowing;
import cn.edu.zsc.blms.service.BookService;
import cn.edu.zsc.blms.service.BorrowingService;
import cn.edu.zsc.blms.service.ReaderService;

import java.util.*;

public class BorrowingServiceImpl extends BaseServiceImpl<Borrowing> implements BorrowingService {

    // 依赖BookServiceImpl和ReaderServiceImpl
    private final BookServiceImpl bookService;
    private final ReaderServiceImpl readerService;

    /** 单例 */
    private static BorrowingService singleton;

    /** 私有构造方法 */
    private BorrowingServiceImpl(BookService bookService, ReaderService readerService) {
        this.bookService = (BookServiceImpl) bookService;
        this.readerService = (ReaderServiceImpl) readerService;
    }

    /** 获取单例，非线程安全 ...*/
    public static BorrowingService getSingleton() {
        if (singleton == null) {
            singleton = new BorrowingServiceImpl(BookServiceImpl.getSingleton(), ReaderServiceImpl.getSingleton());
        }
        return singleton;
    }

    /**
     * 存放已经借出还未归还的图书信息，key为图书id，value为借阅记录
     */
    private final Map<Integer, Borrowing> BOOK_LENDING = new HashMap<>();

    public void borrow() {
        try {
            System.out.print("请输入图书的ID：");
            Book book = bookService.getOne();
            if (Book.Status.可出借 != book.status) {
                System.out.println("该图书已借出");
                return;
            }
            if (book.disabled) {
                System.out.println("该图书已被废弃");;
                return;
            }
            System.out.print("请输入读者的ID：");
            Reader reader = readerService.getOne();
            if (reader.disabled) {
                System.out.println("该读者已被禁用");;
                return;
            }
            Borrowing borrowing = new Borrowing(idCounter, reader, book, new Date());
            DATA.put(borrowing.id, borrowing);
            BOOK_LENDING.put(book.id, borrowing);
            book.status = Book.Status.已借出;
            System.out.println("图书成功借出！");
            idCounter++;
        } catch (EntityNotExistException e) {
            System.out.println(e.getMessage());
        }
    }

    @Override
    public void giveBack() {
        try {
            System.out.print("请输入图书的ID：");
            Book book = bookService.getOne();
            Borrowing borrowing = BOOK_LENDING.get(book.id);
            if (borrowing == null) {
                System.out.println("该图书并未借出");
                return;
            }
            borrowing.returnTime = new Date();
            book.status = Book.Status.可出借;
            BOOK_LENDING.remove(book.id);
            System.out.println("图书归还成功！");
        } catch (EntityNotExistException e) {
            System.out.println(e.getMessage());
        }
    }

    @Override
    public void query() {
        System.out.println("按出借顺序显示当前正在出借的图书：");
        Set<Borrowing> borrowings = new TreeSet<>(BOOK_LENDING.values());
        for (Borrowing borrowing : borrowings) {
            System.out.println(borrowing);
        }
    }

}
