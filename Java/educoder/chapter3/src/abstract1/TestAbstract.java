package abstract1;

abstract class Shape {    // 定义一个抽象类Shape，表示形状
    double area; // 属性：面积

    // 声明一个抽象方法void abcaculateArea()

    /********* begin *********/
    abstract void caculateArea();

    /********* end *********/

    void printArea() {
        System.out.println("面积是：" + this.area);
    }
}

class Circle extends Shape { // 定义一个表示圆形的类Circle，继承Shape
    double radius; // 属性：半径

    // 定义Circle类的构造方法

    /********* begin *********/
    public Circle(double radius) {
        this.radius = radius;
    }
    /********* end *********/

    // 实现父类的抽象方法caculateArea计算面积，可以用到java.lang.Math类的静态常量PI

    /********* begin *********/
    void caculateArea() {
        area = Math.PI * radius * radius;
    }
    /********* end *********/
}

class Rectangle extends Shape { // 定义一个表示矩形的类Rectangle，继承Shape
    double width; // 属性：宽
    double height; // 属性：高

    // 定义Rectangle类的构造方法
    /********* begin *********/
    public Rectangle(double width, double height) {
        this.width = width;
        this.height = height;
    }
    /********* end *********/

    // 实现父类的抽象方法caculateArea计算面积，可以用到java.lang.Math类的静态常量PI
    /********* begin *********/
    void caculateArea() {
        area = width * height;
    }
    /********* end *********/
}

public class TestAbstract {
    public static void main(String[] args) {
        Shape s = new Circle(3);  // 创建一个半径为3的圆形对象
        s.caculateArea();
        s.printArea();
        s = new Rectangle(4, 5); // 创建一个长为4，宽为5的矩形对象
        s.caculateArea();
        s.printArea();
    }
}
