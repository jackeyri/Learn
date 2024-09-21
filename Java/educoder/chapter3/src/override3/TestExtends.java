package override3;

class Employee { // 定义员工类
    String name;
    int age;
    // 任务点：定义double类型的成员变量salary，表示工资
    double salary;

    Employee(String name, int age) {
        this.name = name;
        // 任务点：初始化成员变量age
        this.age = age;
    }

    void showInfo() {
        System.out.println("姓名是：" + this.name);
        System.out.println("年龄是：" + this.age);
        // 任务点：打印工资的信息，格式为“工资是：***”
        System.out.println("工资是：" + salary);
    }
}

// 任务点：定义Manager类，继承Employee类
class Manager extends Employee {
    Manager(String name, int age, double salary) {
        // 任务点：调用父类构造方法，以初始化成员变量name和age
        super(name, age);
        this.salary = salary;
    }
}

// 任务点：定义“工人”类Worker，继承“员工”类Employee
class Worker extends Employee {
    int workingDays; // 成员变量workingDays，表示工作天数
    // 任务点：定义 double类型的成员变量 dailyWage，表示日薪
    double dailyWage;

    void setSalary(int workingDays, double dailyWage) {
        this.workingDays = workingDays;
        this.dailyWage = dailyWage;
        this.salary = workingDays * dailyWage; // 工资=工作天数*日薪
    }

    Worker(String name, int age, int workingDays, double dailyWage) {
        // 任务点：调用父类构造方法，以初始化name和age
        super(name, age);
        // 任务点：调用成员方法setSalary，以初始化工作天数、日薪和月薪
        setSalary(workingDays, dailyWage);
    }

    // 任务点：覆盖override父类的showInfo()方法
    void showInfo() {
        // 任务点：调用父类被覆盖的showInfo()，以显示姓名、年龄、工资的信息
        super.showInfo();
        System.out.println("工作天数是：" + this.workingDays);
        System.out.println("日薪是：" + this.dailyWage);
    }
}

public class TestExtends {

    public static void main(String[] args) {
        // 任务点：创建一个经理对象：张三、40岁、10000元月薪
        Manager manager = new Manager("张三", 40, 10000);
        // 任务点：调用manager的showInfo()方法，显示该经理的信息。
        manager.showInfo();
        // 任务点：创建Worker对象：李四、20岁、月工作22天、日薪200
        Worker worker = new Worker("李四", 20, 22, 200);
        worker.showInfo();
    }

}
