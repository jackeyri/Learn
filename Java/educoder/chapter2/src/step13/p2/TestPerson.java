// 将TestPerson类定义在step13.p2包中
package step13.p2;

// 导入step13.p1包中的Person类

import step13.p1.Person;

public class TestPerson {

    public static void main(String[] args) {
        Person p = new Person();
        p.age = 20;
        p.name = "张三";
        p.printInfo();
    }

}
