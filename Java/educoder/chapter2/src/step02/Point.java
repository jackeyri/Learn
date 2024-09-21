package step02;

public class Point { // 定义一个类Point表示二维平面上的“点”
    // 定义整型成员变量x和y，分别表示x轴和y轴的坐标
    int x, y;

    // 定义成员方法getDistance，计算并返回该“点”到原点的距离
    double getDistance() {
        double distance = Math.sqrt(x * x + y * y);  //数学类Math的静态方法sqrt：开根号
        // 返回distance的值
        return distance;
    }

    public static void main(String[] args) {
        // 创建一个Point对象p
        Point p = new Point();
        // 设置该点的坐标是(3,4)
        p.x = 3;
        p.y = 4;
        // 调用对象p的getDistance方法，输出p到原点的距离
        System.out.println(p.getDistance());
    }
}
