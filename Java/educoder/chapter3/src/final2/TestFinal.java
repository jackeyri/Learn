package final2;

import java.util.Scanner;

//任务点：修改Person类的定义，使其能被子类继承
class Person {
    // 任务点：对成员name加上适当修饰符，使其成为常量
    final String name = "张三丰";
    int age;

    public Person(String name, int age) {
        // 任务点：能否设置成员name的值，如果不能请屏蔽相关代码
        // this.name = name;
        this.age = age;
    }

    // 任务点：对showName()方法加上适当修饰符，使其不能在派生类中重定义
    final void showName() {
        System.out.println("我是行不改名坐不改姓的" + this.name);
    }

    void showAge() {
        System.out.println("年龄：" + this.age);
    }

    void showInfo() {
        showName();
        showAge();
    }
}

class Employee extends Person { // 任务点：继承Person类
    String position; // 职位

    public Employee(String name, int age, String position) {
        super(name, age); // 任务点：调用父类构造方法
        this.position = position;
    }

    // 任务点：能否覆盖showName()？如果不能请屏蔽相关代码
    // void showName() {
    //	 System.out.println("我的名字是"+name);
    // }

    // 任务点：覆盖父类方法showInfo()
    void showInfo() {
        super.showInfo(); // 任务点：调用父类被覆盖的方法showInfo()
        System.out.println("职位：" + this.position);
    }
}

public class TestFinal {
    public static void main(String[] args) {
        String name, position;
        int age;
        Scanner input = new Scanner(System.in);
        name = input.next();
        age = input.nextInt();
        position = input.next();
        Employee e = new Employee(name, age, position);
        e.showInfo();
        input.close();
    }
}
