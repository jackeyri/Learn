package interface1;

interface Flyable {    // 定义一个接口Flyable，表示一个“能够飞的”的行为特征
    void fly();    // 声明方法void fly()，表示这个行为特征中具有“飞”的功能
}

class Bird implements Flyable { // 定义类Bird 实现接口Flyable
    public void fly() { // 实现接口Flyable中声明的方法fly()，输出“小鸟在飞“
        System.out.println("小鸟在飞");
    }
}

class Airplane implements Flyable { // 定义类Airplane 实现接口Flyable
    public void fly() { // 实现接口Flyable中声明的方法fly()，输出“飞机在飞“
        System.out.println("飞机在飞");
    }
}

public class TestInterface {
    public static void main(String[] args) {
        Flyable flyable = new Bird();    // 创建一个Bird对象
        flyable.fly();    // 调用的是Bird类的fly()方法
        flyable = new Airplane();    // 创建一个Airplane对象
        flyable.fly();    //	调用的是Airplane类的fly()方法
    }
}
