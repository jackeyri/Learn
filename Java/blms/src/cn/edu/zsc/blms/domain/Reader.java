package cn.edu.zsc.blms.domain;

public class Reader extends BaseEntity {
    /**
     * 读者domain
     */
    public int id;

    /**
     * 读者
     */
    public String name;

    /**
     * 电话
     */
    public String phone;

    /**
     * 是否禁用
     */
    public boolean disabled; // false

    public Reader(int id, String name, String phone) {
        super(id);
        this.name = name;
        this.phone = phone;
    }

    @Override
    public String toString() {
        return "ID：" + id + "，姓名：" + name + "，电话：" + phone + "，禁用：" + (disabled ? "是" : "否");
    }
}