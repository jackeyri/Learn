package list1;

// 任务点：导入java.util包中的所有类

import java.util.*;


//任务点：声明Dog类实现Comparable<Dog>接口
class Dog implements Comparable<Dog> {
    String name;
    int weight;

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

public class TestList {
    public static void main(String[] args) {

        // 任务点：创建一个java.util.ArrayList类型的列表容器
        List<Dog> list = new ArrayList<Dog>();
        Dog dog1 = new Dog("dog1", 30);
        Dog dog2 = new Dog("dog2", 20);
        Dog dog3 = new Dog("dog3", 10);

        // 任务点：使用list的add(E)方法，依次将dog1、dog2、dog3添加到list中
        /********* begin *********/
        list.add(dog1);
        list.add(dog2);
        list.add(dog3);
        /********* end *********/

        System.out.println("排序前：");
        /*
         * 任务点：使用for循环，通过列表元素的下标index遍历输出列表list中的元素
         * 提示：可以使用int size()方法获取list中的元素个数
         * 提示：可以使用E get(int index)方法获取list中下标为index的元素
         */
        /********* begin *********/
        for (int i = 0; i < list.size(); i++) {
            System.out.println(list.get(i));
        }
        /********* end *********/

        // 任务点：使用java.util.Collections类的sort(List)方法对list中的元素进行排序
        Collections.sort(list);

        System.out.println("排序后：");
        // 任务点：使用增强型for循环遍历输出列表list中的元素
        /********* begin *********/
        for (Dog e : list) {
            System.out.println(e);
        }
        /********* end *********/

        Dog dog4 = new Dog("dog4", 40);
        // 任务点：将dog4替换列表list中的第2个元素
        list.set(1, dog4);

        System.out.println("替换后：");
        // 任务点：使用迭代器Iterator遍历输出列表list中的元素
        /********* begin *********/
        Iterator<Dog> iterator = list.iterator(); // 使用iterator()方法，获取list中的迭代器
        while (iterator.hasNext()) { // 使用Iterator的boolean hasNext()方法，判断是否存在另一个可访问的元素
            Dog dog = iterator.next(); // 使用Iterator的Object next()方法，返回要访问的下一个元素
            System.out.println(dog);
        }
        /********* end *********/
    }
}
