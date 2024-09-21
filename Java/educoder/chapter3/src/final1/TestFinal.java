package final1;

// 任务点1：修改T类的定义，使其能被TT类继承
class T {
    // 任务点2：修改下条语句，使在构造方法中能对i进行赋值
    int i = 5;

    public T() {
        i = 10;
    }

    // 任务点3：修改方法m的声明，使子类能override此方法
    void m(int j) { // 任务点4：修改形参j的声明，使其在方法m中能被修改值
        j++;
        // 任务点5：修改局部变量k的声明，使其在方法m中能被修改值
        int k = 9;
        k++;
        System.out.println(k + j);
    }
}

class TT extends T {
    void m(int j) {
        super.m(j);
        System.out.println("覆盖父类方法m");
    }
}

public class TestFinal {
    public static void main(String[] args) {
        TT tt = new TT();
        tt.m(20);
    }
}
