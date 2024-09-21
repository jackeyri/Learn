package reference_array2;

import java.util.Arrays;
import java.util.Comparator;

// 任务点：声明Person类实现Comparable<Person>接口
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
    public int compare(Person a, Person b) {
        return a.name.compareTo(b.name);
    }
    /********* end *********/
}

public class TestObjectArray {
    public static void main(String[] args) {
        // 任务点：创建长度为3的Person类型数组
        Person[] p = new Person[3];

        /*
         * 将数组p的三个元素分别引用三个新建的Person对象
         * p[0]引用的Person对象年龄为：20，姓名为：c
         * p[1]引用的Person对象年龄为：22，姓名为：b
         * p[2]引用的Person对象年龄为：21，姓名为：a
         */
        /********* begin *********/
        p[0] = new Person(20, "c");
        p[1] = new Person(22, "b");
        p[2] = new Person(21, "a");
        /********* end *********/

        // 任务点：使用java.util.Arrays的sort(Object[])方法对数组p中的元素按年龄进行排序
        Arrays.sort(p);

        System.out.println("按年龄排序后，使用普通的for循环遍历数组p");
        // 任务点：使用for循环遍历数组p
        for (int i = 0; i < p.length; i++) {
            System.out.println(p[i]);
        }

        System.out.println("排序后，在数组p中查找年龄为21的Person对象引用的下标");
        // 任务点：使用java.util.Arrays类的binarySearch方法，在数组p中查找年龄为21的Person对象引用的下标
        int index = Arrays.binarySearch(p, new Person(21, "a"));
        if (index >= 0) {
            System.out.println("数组p中，年龄为21的Person对象引用的下标是：" + index);
        } else {
            System.out.println("数组p中不存在年龄为21的Person对象引用");
        }

        // 任务点：使用java.util.Arrays的sort(Object[], Comparator)方法对数组p中的元素按姓名进行排序，比较器使用ComparatorByName
        Arrays.sort(p, new ComparatorByName());

        System.out.println("按姓名排序后，使用增强型的for循环遍历数组p");
        // 任务点：使用增强型for循环遍历数组p
        for (Person e : p) {
            System.out.println(e);
        }
    }
}
