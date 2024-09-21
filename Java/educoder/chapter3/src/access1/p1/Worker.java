package access1.p1;

//任务点：修改Worker类的访问控制声明，使其能被其它包中的类方法
public class Worker extends Employee { // 任务点：定义“工人”类Worker，继承“员工”类Employee
    int workingDays; // 工作天数
    double dailyWage; // 日薪

    // 任务点：修改Worker类构造方法的访问控制声明，使其能被其它包中的类访问
    public Worker(String number, String name, int age, int workingDays, double dailyWage) {
        // 调用父类构造方法，以初始化number，name和age
        super(number, name, age);
        setSalary(workingDays, dailyWage); // 调用成员方法setSalary，以初始化工作天数、日薪和月薪
    }

    // 任务点：修改showInfo的访问控制声明，使其能正确覆盖父类的showInfo()方法
    public void showInfo() {
        // 调用父类被覆盖的showInfo()，以显示工号、姓名、年龄、工资的信息
        super.showInfo();
        System.out.println("工作天数是：" + this.workingDays);
        System.out.println("日薪是：" + this.dailyWage);
    }

    // 任务点：定义访问控制为公共的getSalary()方法，用以返回成员变量salary的值

    /********* begin *********/
    public double getSalary() {
        return salary;
    }

    /********* end *********/

    // 任务点：修改setSalary的访问控制声明，使其只能在类的内部访问
    public void setSalary(int workingDays, double dailyWage) {
        this.workingDays = workingDays;
        this.dailyWage = dailyWage;
        this.salary = workingDays * dailyWage; // 工资=工作天数*日薪
    }

}
