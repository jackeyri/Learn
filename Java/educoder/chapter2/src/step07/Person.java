package step07;

/**
 * 阅读程序后，请先直接运行，
 * 然后分析程序运行时，出现空指针异常NullPointException的原因。
 */
public class Person {

    int age = 10;
    Person father; // 父亲

    public Person(int a) {
        age = a;
    }

    void printFatherAge() { // 输出父亲的年龄
        System.out.println(father.age);
    }

    public static void main(String[] args) {
        Person p1 = new Person(20);
        Person p2 = new Person(50);
        p1.father = p2;
        p1.printFatherAge();
        // 在下方添加代码，创建p2的father对象，并将其年龄设置为80
        p2.father = new Person(80);
        p2.printFatherAge();
    }
}
