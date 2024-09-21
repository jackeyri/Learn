package reference_array1;

import java.util.Arrays;

// 任务点：声明Dog类实现Comparable<Dog>接口
class Dog implements Comparable<Dog> {
    String name;
    int weight; // 重量

    public Dog(String name, int weight) {
        this.name = name;
        this.weight = weight;
    }

    @Override
    public String toString() {
        return this.name + "重" + this.weight + "公斤";
    }

    // 任务点：实现compareTo(Dog)方法，制定Dog对象之间“按重量大小进行比较”的规则
    /********* begin *********/
    public int compareTo(Dog dog) {
        return this.weight - dog.weight;
    }
    /********* end *********/
}

public class TestObjectArray {
    public static void main(String[] args) {

        // 任务点：创建长度为3的Dog类型数组
        Dog[] dogs = new Dog[3];
        dogs[0] = new Dog("大黄", 30);
        dogs[1] = new Dog("旺财", 20);
        dogs[2] = new Dog("福娃", 10);

        System.out.println("排序前：");
        // 任务点：使用for循环遍历数组dogs
        for (int i = 0; i < dogs.length; i++) {
            System.out.print(dogs[i] + " ");
        }

        // 任务点：使用java.util.Arrays的sort(Object[])方法对数组dogs中的元素按重量进行排序
        Arrays.sort(dogs);

        System.out.println("\n排序后：");
        // 任务点：使用增强型for循环遍历数组dogs
        for (Dog e : dogs) {
            System.out.print(e + " ");
        }
    }
}
