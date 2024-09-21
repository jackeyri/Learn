package extends2;

class Person {
    String name;
    int age;

    //构造方法
    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    void eat() {
        System.out.println("我会吃饭！");
    }

    //显示人的信息
    void showInfo() {
        System.out.println("姓名：" + name);
        System.out.println("年龄：" + age);
    }
}

class Student extends Person {    // 使用“extends”，继承父类Person
    // 子类新增成员字符串类型的成员变量“专业”：major，
    String major;

    //构造方法
    public Student(String name, int age, String major) {
        // 使用super调用父类构造方法，对继承的姓名和年龄属性进行初始化
        super(name, age);
        // 初始化子类新增成员变量major
        this.major = major;
    }

    // 子类新增成员方法study()
    void study() {
        System.out.println("我必须刻苦学习！");
    }

    // 子类新增成员方法用以显示专业信息showMajor()，显示内容是：专业：XX
    void showMajor() {
        System.out.println("专业：" + major);
    }
}

public class TestExtends {

    public static void main(String[] args) {
        // 创建一个学生对象，姓名为张三，年龄为19，专业为计算机科学与技术
        Student s = new Student("张三", 19, "计算机科学与技术");
        // 显示对象s的个人信息
        s.showInfo();
        // 显示对象s的专业信息
        s.showMajor();
        // 通过对象s调用eat和study方法
        s.eat();
        s.study();
    }

}
