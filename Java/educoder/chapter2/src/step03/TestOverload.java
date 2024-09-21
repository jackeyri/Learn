package step03;

public class TestOverload {
    static int max(int x, int y) { // static是修饰符，int是返回值类型
        System.out.println("方法签名：max(int,int)");
        return (x > y) ? x : y;
    }

    // 定义重载的方法 max，该方法能返回三个整型中的最大值
    static int max(int x, int y, int z) {
        System.out.println("方法签名：max(int,int,int)");
        if (x > y)
            return x > z ? x : z;
        else
            return y > z ? y : z;
    }

    // 定义重载的方法 max，该方法能返回两个双精度浮点型中的最大值
    static double max(double x, double y) {
        System.out.println("方法签名：max(double,double)");
        return x > y ? x : y;
    }

    public static void main(String[] args) {
        int a = 10;
        int b = 20;
        int c = 30;
        int max1 = max(a, b);
        // 调用方法max(int,int,int)，得到a、b、c中的最大值
        int max2 = max(a, b, c);
        double d1 = 10.1;
        double d2 = 10.2;
        // 调用方法max(double,double)，得到d1、d2中的最大值
        double d3 = max(d1, d2);
        System.out.println(max1);
        System.out.println(max2);
        System.out.println(d3);
    }
}