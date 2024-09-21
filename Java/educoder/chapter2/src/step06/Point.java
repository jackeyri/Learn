package step06;

public class Point {
    int x; // X轴坐标
    int y; // Y轴坐标

    // 定义构造方法Point(int, int)，以初始化x轴和y轴坐标值
    public Point(int x1, int y1) {
        x = x1;
        y = y1;
    }

    double getDistance() { // 返回到原点到距离
        return Math.sqrt(x * x + y * y); //数学类Math的静态方法sqrt：开根号
    }

    public static void main(String[] args) {
        // 使用构造方法Point(int, int)创建并初始化一个Point对象p，该点的坐标是(3,4)
        Point p = new Point(3, 4);
        // 输出点p到原点到距离
        System.out.println(p.getDistance());
    }
}
