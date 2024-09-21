package generics1;

// 任务点：声明Person实现Comparable<Person>接口
class Person implements Comparable<Person> {
    public int age;
    public String name;

    public Person(int age, String name) {
        this.age = age;
        this.name = name;
    }

    @Override
    public String toString() {
        return this.name + "的年龄是：" + this.age;
    }

    // 任务点：实现了compareTo(Person)方法，制定Person对象之间“按age的大小进行比较”的规则

    /********* begin *********/
    @Override
    public int compareTo(Person o) {
        return this.age - o.age;
    }
    /********* end *********/
}

// 任务点：定义泛型类MySorter，限定的泛型T必须实现Comparable<T>接口
class MySorter<T extends Comparable<T>> {

    // 任务点：定义方法sort，限定了方法参数a的类型必须是泛型T的数组类型 T[]
    public void sort(T[] a) {
        // 以下使用了冒泡算法对数组a中的元素进行排序
        T temp = null;
        for (int i = a.length - 1; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                // 任务点：判断是否a[j]大于a[j+1]
                if (a[j].compareTo(a[j + 1]) > 0) {
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
    }
}

public class TestGenerics {
    public static void main(String[] args) {
        Person[] p = {new Person(20, "张三"), new Person(22, "李四"), new Person(21, "王五")};

        // 任务点：创建MySorter<Person>对象
        MySorter<Person> sorter = new MySorter<Person>();

        System.out.println("按Person类制定的默认比较规则排序：");
        // 任务点：使用sorter对数组p中的元素进行排序
        sorter.sort(p);

        for (Person e : p) {
            System.out.println(e);
        }

    }
}
