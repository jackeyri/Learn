package step05;

public class Person {    // 使用关键字class定义类Person
    int age;    // int类型成员变量：age，年龄
    String name; // String类型成员变量： name，姓名

    // 定义无参的构造方法
    public Person() {
        System.out.println("调用构造方法：Person()");
    }

    // 定义有参构造方法，以初始化姓名和年龄
    public Person(int age1, String name1) { //构造方法，和类同名
        System.out.println("调用构造方法：Person(int, String)");
        // 初始化成员变量age和name
        age = age1;
        name = name1;
    }

    void printInfo() {    // 成员方法：printInfo()，打印信息
        System.out.println("年龄是：" + age + "岁");
        System.out.println("姓名是：" + name);
    }

    public static void main(String[] args) {
        // 使用无参构造方法Person()创建Person对象p1,
        Person p1 = new Person();
        p1.age = 20;    //	设置p的成员变量age是20
        p1.name = "张三"; // 设置p的成员变量name是"张三"
        p1.printInfo();    // 调用p的成员方法printInfo()，打印p的信息
        // 使用有参构造方法Person(int, String)创建并初始化Person对象p2，年龄是21，姓名是“李四”
        Person p2 = new Person(21, "李四");
        p2.printInfo();
    }
}
