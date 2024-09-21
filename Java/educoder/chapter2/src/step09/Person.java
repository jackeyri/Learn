package step09;

public class Person {
    int age;
    String name;

    Person() { // 构造方法Person()
        System.out.println("创建一个Person对象");
    }

    Person(int age) { // 构造方法Person(int)
        // 调用无参构造方法Person()
        this();
        // 初始化成员变量age
        this.age = age;
    }

    Person(int age, String name) { // 构造方法Person(int, String)
        // 调用构造方法Person(int)，以初始化成员变量age
        this(age);
        // 初始化成员变量name
        this.name = name;
    }

    void printInfo() {
        System.out.println(this.name + "的年龄是" + this.age);
    }

    Person returnThis() {
        // 返回引用this
        return this;
    }

    public static void main(String[] args) {
        // 调用构造方法Person(int, String)，创建并初始化Person对象p1, 年龄是20，姓名是“张三”
        Person p1 = new Person(20, "张三");
        p1.printInfo();
        // 调用p1对象的方法returnThis
        Person p2 = p1.returnThis();
        System.out.println("p1和p2是否引用相同的对象：" + (p1 == p2));
    }
}
