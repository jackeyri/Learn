package object2;

/**
 * 要求Dog类要覆盖继承自Object类中的equals()和toString()方法。
 * 按模板要求，将【代码】处替换成相应的Java程序。
 */
class Dog {
    String name;
    int weight; // 重量

    public Dog(String name, int weight) {
        this.name = name;
        this.weight = weight;
    }

    // 任务点：Override覆盖Object类的toString()方法
    @Override
    public String toString() {
        return this.name + "重" + this.weight + "公斤";
    }

    // Override覆盖Object类的equals方法
    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj instanceof Dog) { // 任务点：如果obj是Dog类或其子类的实例
            Dog dog = (Dog) obj;
            // 任务点：如果this和dog的name和weight都相等则返回true
            if (this.name.equals(dog.name) && this.weight == dog.weight) {
                return true;
            }
        }
        return false;
    }

    // Override覆盖Object类的hashCode方法，和equals方法保持语义的一致性
    @Override
    public int hashCode() {
        // 任务点：根据name和weight属性值返回hashCode值
        return this.name.hashCode() + 1243 * this.weight;
    }

}

public class TestObject {
    public static void main(String[] args) {
        Dog dog1 = new Dog("DaHuan", 10);
        Dog dog2 = new Dog("DaHuan", 10);
        System.out.println(dog1 == dog2); // 为什么表达式的值是"false"?
        System.out.println(dog1.hashCode() == dog2.hashCode());
        //任务点：调用equals方法，判断dog1和dog2是否相等
        System.out.println(dog1.equals(dog2));
        System.out.println(dog1);
    }
}
