package step12;

public class Student {
    int age;
    String name;
    // 定义静态成员变量count，用以存放创建的学生对象数量
    static int count;

    public Student() {
        System.out.println("调用无参的构造方法");
        // 静态成员变量count自增1，表示新创建了一个学生对象
        count++;
    }

    public Student(int age) {
        // 此处调用无参的构造方法Student()
        this();
        System.out.println("调用只有一个参数的构造方法");
        this.age = age;
    }

    public Student(int age, String name) {
        // 此处调用只有一个参数的构造方法Student(int)
        this(age);
        System.out.println("调用有两个参数的构造方法");
        //初始成员变量name
        this.name = name;
    }

    // 定义实例成员方法printInfo()，用以输出学生信息
    void printInfo() {
        System.out.println(this.name + "的年龄是" + this.age);
    }

    // 定义静态成员方法printCount()，用以输出学生对象的数量
    static void printCount() {
        System.out.println("学生的数量是" + count);
    }

    public static void main(String[] args) {
        //创建学生对象s：张三， 20岁
        Student s = new Student(20, "张三");
        // 调用学生s的方法printInfo
        s.printInfo();
        /// 调用Student类的方法printCount
        Student.printCount();
    }
}
