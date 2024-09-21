package set1;

import java.util.HashSet;
import java.util.Set;
import java.util.TreeSet;

// 任务点：声明Dog类实现Comparable<Dog>接口
class Dog implements Comparable<Dog> {
    String name;
    int weight;

    public Dog(String name, int weight) {
        this.name = name;
        this.weight = weight;
    }

    // 任务点：重写equals方法，要求当两个Dog对象的name和weight都相等时，返回true，否则返回false

    /********* begin *********/
    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        Dog other = (Dog) obj;
        if (weight != other.weight) {
            return false;
        }
        if (name == null) {
            if (other.name != null) {
                return false;
            }
        } else if (!name.equals(other.name)) {
            return false;
        }
        return true;
    }
    /********* end *********/

    // 任务点：重写hashCode方法，和equals方法保持语义的一致性，即：当两个Dog对象name和weight都相等时，返回的hashCode值也相同

    /********* begin *********/
    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + weight;
        result = prime * result + ((name == null) ? 0 : name.hashCode());
        return result;
    }
    /********* end *********/

    // 任务点：实现compareTo(Dog)方法，制定Dog对象之间“按weight大小进行比较”的规则

    /********* begin *********/
    @Override
    public int compareTo(Dog o) {
        return this.weight - o.weight;
    }
    /********* end *********/
}

public class TestSet {
    public static void main(String[] args) {

        // 任务点：创建HashSet对象
        Set<Dog> hashSet = new HashSet<Dog>();

        Dog d1 = new Dog("大黄", 30);
        Dog d2 = new Dog("大黄", 30);
        Dog d3 = new Dog("旺财", 30);

        // 任务点：依次将d1、d2、d3放入hashSet中
        /********* begin *********/
        hashSet.add(d1);
        hashSet.add(d2);
        hashSet.add(d3);
        /********* end *********/

        System.out.println("是否包含d1：" + hashSet.contains(d1)); // true
        System.out.println("是否包含d2：" + hashSet.contains(d2)); // true
        System.out.println("是否包含d3：" + hashSet.contains(d3)); // true

        /*
         * 任务点：使用size方法，获取hashSet中元素的数量
         * 思考：为什么hashSet.contains(d1)、hashSet.contains(d2)、hashSet.contains(d3)
         * 		的值都是true，但是此时hashSet中元素的数量却是2？
         */
        System.out.println("hashSet中元素的数量：" + hashSet.size());

        // 任务点：使用构造方法TreeSet(Set)创建TreeSet对象，并将hashSet中所有的元素放入treeSet中
        Set<Dog> treeSet = new TreeSet<Dog>(hashSet);

        // 任务点：使用size方法，获取treeSet中元素的数量。 思考：此时treeSet中元素的数量为什么是1？
        System.out.println("treeSet中元素的数量：" + treeSet.size());

    }

}
