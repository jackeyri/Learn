package step08;

class Point {
    int x; // X轴坐标
    int y; // Y轴坐标

    Point(int x1, int y1) {
        this.x = x1;
        this.y = y1;
    }

    double getDistance() { // 返回到原点到距离
        return Math.sqrt(x * x + y * y);
    }
}

//定义一个类表示二维平面上的“直线”(Line)
public class Line {
    Point startPoint; // 起点
    // 定义Point类型的成员变量endPoint，表示该直线的终点
    Point endPoint;

    // 定义构造方法1，以初始化起点和终点
    public Line(Point p1, Point p2) { // 起点p1和终点p2
        // 初始化成员变量startPoint和endPoint
        startPoint = p1;
        endPoint = p2;
    }

    // 定义构造方法2，以创建并初始化起点和终点的X轴和Y轴坐标
    public Line(int x1, int y1, int x2, int y2) { // 起点坐标x1,y1和终点坐标x2,y2
        // 创建并初始化成员变量startPoint和endPoint
        startPoint = new Point(x1, y1);
        endPoint = new Point(x2, y2);
    }

    double getLength() { // 获得直线段的长度
        int x = startPoint.x - endPoint.x;
        int y = startPoint.y - endPoint.y;
        // 通过Math.sqrt()方法求直线的长度
        double length = Math.sqrt(x * x + y * y);
        return length;
    }

    public static void main(String[] args) {
        Point p1 = new Point(1, 1);
        Point p2 = new Point(2, 2);
        // 通过构造方法1，创建一个表示点p1和点p2之间的Line对象line1
        Line line1 = new Line(p1, p2);
        System.out.printf("%8.3f\n", line1.getLength());
        // 通过构造方法2，创建一个表示点(2,2)和点(4,4)之间的Line对象line2
        Line line2 = new Line(2, 2, 4, 4);
        System.out.printf("%8.3f\n", line2.getLength());
    }

}