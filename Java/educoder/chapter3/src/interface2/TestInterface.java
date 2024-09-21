package interface2;

// 定义一个抽象类Door
// 声明抽象方法void open()和void close()

/********* begin *********/
abstract class Door {
    abstract void open();

    abstract void close();
}
/********* end *********/

// 定义一个接口Alarmable
// 声明方法void alarm()

/********* begin *********/
interface Alarmable {
    void alarm();
}
/********* end *********/

// 定义一个类SafetyDoor，使其继承Door，并实现接口Alarmable
// 实现继承自抽象类Door的方法open，方法体内打印出"open"
// 实现继承自抽象类Door的方法close，方法体内打印出"close"
// 实现继承自接口的方法alarm，方法体内打印出"alarm"

/********* begin *********/
class SafetyDoor extends Door implements Alarmable {
    public void open() {
        System.out.println("open");
    }

    public void close() {
        System.out.println("close");
    }

    public void alarm() {
        System.out.println("alarm");
    }
}

/********* end *********/

public class TestInterface {
    public static void main(String[] args) {
        Door door = new SafetyDoor();
        door.open();
        door.close();
        // 使用关键字instanceof判断door引用的是否SafetyDoor类型的对象
        if (door instanceof SafetyDoor) {
            // 将door向下转型成SafetyDoor类型
            SafetyDoor safetyDoor = (SafetyDoor) door;
            safetyDoor.alarm();
        }
    }
}
