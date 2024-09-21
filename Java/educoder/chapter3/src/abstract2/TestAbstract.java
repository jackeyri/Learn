package abstract2;

import java.util.Scanner;

// 定义抽象类Pet
// 定义String类型属性name和sex
// 定义构造函数初始化name和sex
// 声明抽象方法void talk()
// 声明抽象方法void eat()
abstract class Pet {
    /********* begin *********/
    String name, sex;
    Pet(String name, String sex) {
        this.name = name;
        this.sex = sex;
    }
    abstract void talk();
    abstract void eat();
    /********* end *********/
}

// 定义Dog类继承自Pet类
// 定义String类型属性color
// 构造函数初始化name、sex和color
// 实现继承自父类的抽象方法talk()和eat()
// talk()输出'名称：name，性别：sex，颜色：color，汪汪叫'
// eat()输出'name吃骨头'
class Dog extends Pet {
    /********* begin *********/
    String color;
    public Dog(String name, String sex, String color) {
        super(name, sex);
        this.color = color;
    }
    void talk() {
        System.out.println("名称：" + name + "，" + "性别：" + sex + "，" + "颜色：" + color + "，" + "汪汪叫");
    }
    void eat() {
        System.out.println(name + "吃骨头！");
    }
    /********* end *********/
}

// 定义Cat类继承自Pet类
// 定义double类型属性weight
// 定义构造函数初始化name、sex和weight
// 实现继承自父类的抽象方法talk()和eat()
// talk()输出'名称：name，性别：sex，体重：weight kg，喵喵叫'
// eat()输出'name吃鱼'
class Cat extends Pet {
    /********* begin *********/
    double weight;
    public Cat(String name, String sex, double weight) {
        super(name, sex);
        this.weight = weight;
    }
    void talk() {
        System.out.println("名称：" + name + "，" + "性别：" + sex + "，" + "体重：" + weight + "kg，" + "喵喵叫");
    }
    void eat() {
        System.out.println(name + "吃鱼！");
    }
    /********* end *********/
}

public class TestAbstract {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String dogName = sc.next();
        String dogSex = sc.next();
        String dogColor = sc.next();
        String catName = sc.next();
        String catSex = sc.next();
        double catWeight = sc.nextDouble();

        // 通过有参构造函数创建Dog类对象dog
        // dog调用talk()方法
        // dog调用eat()方法
        /********* begin *********/
        Dog dog = new Dog("阿黄", "雄", "黄");
        dog.talk();
        dog.eat();
        /********* end *********/

        // 通过有参构造函数创建Cat类对象cat
        // cat调用talk()方法
        // cat调用eat()方法
        /********* begin *********/
        Cat cat = new Cat("阿花", "雌", 10);
        cat.talk();
        cat.eat();
        /********* end *********/

        sc.close();
    }
}