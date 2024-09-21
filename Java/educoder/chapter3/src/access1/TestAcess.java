package access1;

import access1.p1.Worker;

public class TestAcess {
    public static void main(String[] args) {
        Worker worker = new Worker("001", "李四", 20, 22, 200);
        worker.showInfo();
        // 任务点：修改代码，使用正确的方式获取worker的工号
        System.out.println(worker.name + "的工号是：" + worker.number);
        // 任务点：修改代码，使用正确的方式获取worker的工资
        System.out.println(worker.name + "的工资是：" + worker.salary);
    }
}
