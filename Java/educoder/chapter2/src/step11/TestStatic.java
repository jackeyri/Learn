package step11;

class Person {
    int age;
    String name;
    // 定义整型静态成员变量count，用于存放创建的Person对象数量
    static int count;

    public Person(int age, String name) {
        this.age = age;
        this.name = name;
        System.out.println("创建对象" + this.name + "，年龄是：" + this.age);
        // 每次创建对象，调用构造方法时，count值加1
        count++;
    }

    // 定义静态成员方法printCount，用以输出静态成员变量count的值
    static void printCount() {
        System.out.println("目前总人数是：" + count);
    }

    // 定义静态代码块，用以初始化静态成员变量count的值
    static {
        // 初始化静态成员变量count，将count的值设置为0
        count = 0;
        // 调用静态成员方法printCount
        printCount();
    }
}

public class TestStatic {
    public static void main(String[] args) {
        Person p1 = new Person(20, "张三");
        Person p2 = new Person(30, "李四");
        // 调用Person类的静态成员方法printCount
        Person.printCount();
        // 输出Person类的静态成员变量count
        System.out.println("count的值是：" + Person.count);
    }
}
