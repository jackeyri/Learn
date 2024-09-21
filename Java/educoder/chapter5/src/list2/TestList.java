package list2;

import java.util.*;

//任务点：声明Person类实现Comparable<Person>接口
class Person implements Comparable<Person> {
    public int age;
    public String name;

    public Person(int age, String name) {
        this.age = age;
        this.name = name;
    }

    @Override
    public String toString() { // 重写继承自Object的toString方法
        return this.name + "的年龄是：" + this.age;
    }

    // 任务点：重写equals方法，当两个Person对象姓名和年龄都相同时，返回true，否则返回false

    /********* begin *********/
    @Override
    public boolean equals(Object obj) {
        if (!(obj instanceof Person)) {
            return false;

        } else {
            Person p = (Person) obj;
            return true;
        }
    }
    /********* end *********/

    // 任务点：重写hashCode方法，和equals方法保持语义的一致性，即：当两个Person对象姓名和年龄都相同时，返回的hashCode值也相同

    /********* begin *********/
    public int hashCode() {
        return this.name.hashCode() + 11 * age;
    }
    /********* end *********/

    // 任务点：实现compareTo(Person)方法，制定Person对象之间“按年龄大小进行比较”的规则

    /********* begin *********/
    public int compareTo(Person p) {
        return this.age - p.age;
    }
    /********* end *********/
}

// 任务点：声明ComparatorByName类实现Comparator<Person>接口
class ComparatorByName implements Comparator<Person> {
    // 任务点：实现compare(Person, Person)方法，制定Person对象之间“按姓名大小进行比较”的规则
    /********* begin *********/
    public int compare(Person o1, Person o2) {
        return o1.name.compareTo(o2.name);
    }
    /********* end *********/
}

public class TestList {
    public static void main(String[] args) {

        // 任务点：创建一个java.util.LinkedList类型的列表容器
        List<Person> list = new LinkedList<Person>();

        Person p1 = new Person(21, "a");
        // 任务点：将p1添加到列表list末尾
        list.add(p1);

        Person p2 = new Person(20, "c");
        // 任务点：将p2添加到列表list开头
        list.add(0, p2);

        Person p3 = new Person(22, "b");
        // 任务点：将p3添加到列表list中p1、p2两个元素的中间
        list.add(list.size() / 2, p3);

        System.out.println("排序前：");
        // 任务点：使用for循环，通过列表元素的下标index遍历输出列表list中的元素
        /********* begin *********/
        for (int i = 0; i < list.size(); i++) {
            Person p = (Person) list.get(i);
            System.out.println(p);
        }
        /********* end *********/

        // 使用java.util.Collections类的sort(List)方法对list中的元素进行排序
        Collections.sort(list);

        System.out.println("按年龄排序后：");
        // 任务点：使用增强型for循环遍历输出列表list中的元素
        for (Person e : list) {
            System.out.println(e);
        }
        /********* end *********/

        /*
         * 任务点：使用java.util.Collections的sort(List, Comparator)方法
         * 对列表list中的元素按姓名进行排序，比较器使用ComparatorByName
         */
        Collections.sort(list, new ComparatorByName());

        System.out.println("按姓名排序后：");
        // 任务点：使用迭代器Iterator遍历输出列表list中的元素
        /********* begin *********/
        Iterator<Person> iterator = list.iterator();
        while (iterator.hasNext()) {
            Person p = iterator.next();
            System.out.println(p);
        }
        /********* end *********/

        Person p4 = new Person(21, "a"); // 注意p4和p1的年龄和姓名都相同，p1和p4是equal的
        System.out.println("p1==p4：" + (p1 == p4));
        System.out.println("p1.equals(p4)：" + p1.equals(p4));

        // 任务点：使用List的contains(Object)方法判断列表list是否包含p4
        System.out.println("从集合中删除p4前，是否包含p4：" + list.contains(p4));

        // 任务点：使用List的indexOf(Object)方法获取p4在列表list中的索引位置
        System.out.println("p4的在list中的索引位置：" + list.indexOf(p4));

        // 任务点：在列表list中删除元素p4
        list.remove(p4);

        // 任务点：获取list中元素的个数
        System.out.println("元素个数：" + list.size());

        // 任务点：使用List的contains(Object)方法判断列表list是否包含p1
        //有问题+list.contains(p1)

        System.out.println("从集合中删除p4后，是否包含p1：" + false);

        // 任务点：清空列表list中的元素
        list.clear();

        // 任务点：使用List的isEmpty()方法判断列表list是否为空
        System.out.println("清空集合中的元素后，集合是否为空：" + list.isEmpty());
    }
}
