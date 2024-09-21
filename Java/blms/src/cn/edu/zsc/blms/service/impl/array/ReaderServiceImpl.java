package cn.edu.zsc.blms.service.impl.array;

import cn.edu.zsc.blms.App;
import cn.edu.zsc.blms.domain.Reader;
import cn.edu.zsc.blms.exception.EntityNotExistException;
import cn.edu.zsc.blms.service.ReaderService;

public class ReaderServiceImpl extends BaseServiceImpl implements ReaderService {

    /**
     * 单例
     */
    private static ReaderService singleton;

    /**
     * 私有构造方法
     */
    private ReaderServiceImpl() {

    }

    /**
     * 获取单例，非线程安全
     *
     * @return ReaderService单例
     */
    public static ReaderService getSingleton() {
        if (singleton == null) {
            singleton = new ReaderServiceImpl();
        }
        return singleton;
    }

    /**
     * 添加读者
     */
    @Override
    public void create() {
        if (idCounter >= DATA.length) {
            System.out.println("读者数量已满，不能再添加");
            return;
        }
        System.out.print("请输入姓名：");
        String name = App.input.nextLine();
        System.out.print("请输入电话:");
        String phone = App.input.nextLine();
        Reader reader = new Reader(idCounter, name, phone);
        DATA[idCounter] = reader;
        System.out.println("成功增加1位读者");
        idCounter++;
    }

    /**
     * 禁用读者
     */
    @Override
    public void disable() {
        System.out.print("请输入要禁用的读者ID：");
        Reader reader = null;
        try {
            reader = (Reader) getOne();
        } catch (EntityNotExistException e) {
            System.out.println(e.getMessage());
        }
        if (reader != null) {
            reader.disabled = true;
            System.out.println("该用户已被禁用");
        }
    }

    /**
     * 修改读者
     */
    @Override
    public void update() {
        System.out.print("请输入要编辑的读者ID：");
        Reader reader = null;
        try {
            reader = (Reader) getOne();
        } catch (EntityNotExistException e) {
            System.out.println(e.getMessage());
        }
        if (reader != null) {
            System.out.print("请输入姓名，直接按回车表示不修改：");
            String name = App.input.nextLine();
            reader.name = "".equals(name) ? reader.name : name;
            System.out.print("请输入电话，直接按回车表示不修改：");
            String phone = App.input.nextLine();
            reader.phone = "".equals(phone) ? reader.phone : phone;
            System.out.println("改用户的信息已被修改");
        }
    }

    /**
     * 查询读者
     */
    @Override
    public void query() {
        System.out.print("请输入要查询的读者姓名：");
        String name = App.input.nextLine();
        for (int i = 0; i < idCounter; i++) {
            Reader reader = (Reader) DATA[i];
            if (reader.name != null && reader.name.contains(name)) {
                System.out.println("ID:" + reader.id + "，姓名" + reader.name + "，电话" + reader.phone + "，禁用" + (reader.disabled ? "是" : "否"));
            }
        }
    }

}
