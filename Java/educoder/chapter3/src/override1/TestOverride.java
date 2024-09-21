package override1;

class Person {
    int age;
    String name;
    // 定义静态成员变量count，用于存放创建的Person对象数量
    static int count;

    public Person(int age, String name) {
        count++;    // 每次创建对象，调用构造方法时，count值加1
        this.name = name;
        this.age = age;
    }

    static void printCount() {    // 静态成员方法中可以访问静态成员变量
        System.out.println("目前总人数是：" + count);
    }

    void printAge() {    // 打印年龄属性
        System.out.println("年龄是：" + this.age);
    }

    void printName() {    // 打印姓名属性
        System.out.println("姓名是：" + this.name);
    }

    void printInfo() {
        printAge();
        printName();
    }
}

class Student extends Person { // 继承父类Person
    String school;

    public Student(int age, String name, String school) {
        // 使用“super”，调用父类的构造方法
        super(age, name);
        this.school = school;
    }

    void printSchool() {
        System.out.println("学校是：" + this.school);
    }

    // 定义和父类相同的成员方法printInfo()，覆盖父类的printInfo()方法
    void printInfo() {
        // 使用“super”，调用父类中被覆盖的方法printInfo()方法
        super.printInfo();
        printSchool();
    }
}

public class TestOverride {
    public static void main(String[] args) {
        Student s = new Student(20, "张三", "电子科技大学中山学院");
        // 调用对象s的printInfo方法，显示对象s的信息
        s.printInfo();
    }
}
