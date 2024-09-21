package object1;

class Person {
    String name;
    int age;

    Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    // 任务点：重写equals方法，当两个Person对象姓名和年龄都相同时，返回true，否则返回false
    /********* begin *********/
    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj instanceof Person) {
            Person p = (Person) obj;
            return this.age == p.age && this.name.equals(p.name);
        }
        return false;
    }
    /********* end *********/

    // 任务点：重写hashCode方法，和equals方法保持语义的一致性，即：当两个Person对象姓名和年龄都相同时，返回的hashCode值也相同
    /********* begin *********/
    @Override
    public int hashCode() {
        return this.name.hashCode() + 1243 * this.age;
    }
    /********* end *********/

    // 任务点：重写toString方法，返回的字符串格式为：name的年龄是age
    /********* begin *********/
    @Override
    public String toString() {
        return this.name + "的年龄是" + this.age;
    }
    /********* end *********/

}

public class TestObject {

    public static void main(String[] args) {
        Person p1 = new Person("张三", 20);
        Person p2 = new Person("张三", 20);

        System.out.println(p1 == p2);
        System.out.println(p1.equals(p2));
        System.out.println(p1.hashCode() == p2.hashCode());
        System.out.println(p1);
    }

}