package access1.p1;

// 任务点：修改Employee类的访问控制声明，使其只能在本包内被访问
class Employee {
    // 任务点：修改number的访问控制声明，使其只能在类的内部访问
    public String number; // 工号
    // 任务点：修改name和age的访问控制声明，使其能被其它包中的类访问
    public String name; // 姓名
    int age; // 年龄
    // 任务点：修改salary的访问控制声明，使其能被同一个包中的类和子类访问，不能被其它包中的无关类访问
    public double salary; // 表示工资

    public Employee(String number, String name, int age) {
        this.number = number;
        this.name = name;
        this.age = age;
    }

    // 任务点：定义访问控制为公共的getNumber()方法，用以返回成员变量number的值

    /********* begin *********/
    public String getNumber(String number) {
        return this.number;
    }

    /********* end *********/

    public void showInfo() {
        System.out.println("工号是：" + this.number);
        System.out.println("姓名是：" + this.name);
        System.out.println("年龄是：" + this.age);
        System.out.println("工资是：" + this.salary);
    }
}
