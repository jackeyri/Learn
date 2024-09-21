package step01;

//使用关键字class定义类Person
public class Person {

    int age;    // int类型成员变量：age，年龄
    // 定义String类型成员变量： name，姓名
    String name;

    // 成员方法：printInfo()，输出信息
    void printInfo() {

        System.out.println("年龄是：" + age + "岁");
        // 输出“姓名是：xxx
        System.out.println("姓名是：" + name);
    }

    public static void main(String[] args) {
        // 创建Person对象p
        Person p = new Person();
        p.age = 20;    //	设置p的成员变量age是20
        // 设置p的成员变量name是"张三"
        p.name = "张三";
        // 调用p的成员方法printInfo()，输出p的信息
        p.printInfo();
    }
}
