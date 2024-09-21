package extends1;

class Person {
    int age;
    String name;

    public Person(int age, String name) {
        this.name = name;
        this.age = age;
    }

    void printInfo() {
        System.out.println("姓名是：" + this.name);
        System.out.println("年龄是：" + this.age);
    }
}

class Student extends Person {    // 使用“extends”，继承父类Person
    String school;    // 子类新增成员变量

    public Student(int age, String name, String school) {
        // 使用“super(参数列表)”，调用父类构造方法，必须写在第1行。
        super(age, name);
        // 初始化子类新增成员变量school
        this.school = school;
    }

    // 定义子类新增成员方法 printSchool，输出学校的信息
    void printSchool() {
        System.out.println("学校是：" + school);
    }

}

public class TestExtends {
    public static void main(String[] args) {
        Student s1 = new Student(20, "张三", "电子科技大学中山学院");
        s1.printInfo();
        s1.printSchool();
    }
}
