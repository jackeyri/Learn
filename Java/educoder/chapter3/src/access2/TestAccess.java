package access2;

//任务点：修改SupClass类的声明，使其能被子类继承
class SupClass {
    //任务点：将i的访问控制设为是私有的
    private int i;
    //任务点：将j的访问控制设为是受保护的
    protected int j;
    //任务点：将CONST设置成常量
    final int CONST = 1;

    void SupClass(int i, int j) {
        // 任务点：能否在构造方法中设置CONST的值，为什么，如不能请注释取消下行
        // CONST = 2;
        this.i = i;
        this.j = j;
    }

    //任务点：修改print()的声明，使其能被子类覆盖
    void print() {
        System.out.println("i的值是：" + i);
        System.out.println("j的值是：" + j);
    }

    public void m() {
        System.out.println("SuperClass m()");
    }
}

class SubClass extends SupClass {
    public int k;
    public SubClass(int i, int j, int k) {
        //任务点：修改下列代码，通过调用父类构造方法初始化成员变量i、j，并注释取消相关代码
        SupClass(i, j);
        // this.i = i;
        // this.j = j;
        this.k = k;
    }

    //任务点：修改print()的声明，使其正确覆盖父类方法print()，并能被其它包中的类访问
    public void print() {
        super.print();
        System.out.println("k的值是：" + k);
    }

    //任务点：修改m()的声明，使其正确覆盖父类方法m()
    public void m() {
        System.out.println("SubClass m()");
    }
}

public class TestAccess {
    public static void main(String[] args) {
        SubClass sub = new SubClass(1, 2, 3);
        // 能否访问SupClass类定义的成员变量i，如不能，请注释取消下行
        // System.out.println(sub.i);
        System.out.println(sub.j);
        System.out.println(sub.k);
        sub.print();
        sub.m();
    }
}
