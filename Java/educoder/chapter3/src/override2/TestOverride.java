package override2;

/**
 * @author pengzheng
 */

class Vehicle {
    int wheels; // 车轮数
    float weight; // 车重

    Vehicle(int wheels, float weight) {
        this.wheels = wheels;
        this.weight = weight;
    }

    void show() {
        System.out.print("车轮:" + this.wheels);
        System.out.print(", 车重:" + this.weight);
    }
}

//定义Vehicle类的子类Trunk，表示“卡车”，新增float类型的属性load，表示载重量

/********* begin *********/
class Trunk extends Vehicle {
    float load;
/********* end *********/

    // 定义构造方法用以初始化对象属性，需要显示调用父类构造方法。

    /********* begin *********/
    public Trunk(int wheels, float weight, float load) {
        super(wheels, weight);
        this.load = load;
    }

    /********* end *********/

    void show() {
        System.out.println("车型:卡车");
        super.show();
        System.out.println(", 载重量:" + this.load);
    }
}

// 定义Vehicle类的子类Minibus，表示“面包车”，新增int类型的属性passenger，表示载客数。
// 定义合适的构造方法用以初始化对象属性，需要显示调用父类构造方法。

/********* begin *********/
class Minibus extends Vehicle {
    int passenger;

    public Minibus(int wheels, float weight, int passenger) {
        super(wheels, weight);
        this.passenger = passenger;
    }

    /********* end *********/

    // 覆盖Override父类的show方法。
    void show() {
        System.out.println("车型:面包车");
        /********* begin *********/
        super.show();
        /********* end *********/
        System.out.println(", 载人:" + this.passenger);
    }
}

public class TestOverride {
    public static void main(String[] args) {
        Vehicle trunk = new Trunk(6, 7500, 80);
        trunk.show();
        Vehicle minibus = new Minibus(4, 3000, 12);
        minibus.show();
    }
}
