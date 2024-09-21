package step10;

public class Point {
    int x; // X轴坐标
    int y; // Y轴坐标

    Point() {
        System.out.println("创建一个Point对象");
    }

    Point(int x, int y) {
        // 调用无参构造方法
        this();
        // 初始化成员变量
        this.x = x;
        this.y = y;
    }

    double getDistance() { // 返回到原点到距离
        return Math.sqrt(x * x + y * y);
    }

    public static void main(String[] args) {
        // 使用构造方法Point(int, int)创建并初始化一个Point对象p，该点的坐标是(3,4)
        Point p = new Point(3, 4);
        System.out.println(p.getDistance());
    }
}
