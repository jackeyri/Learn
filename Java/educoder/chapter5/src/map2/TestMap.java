package map2;

import java.util.HashMap;
import java.util.Map;
import java.util.Objects;
import java.util.Set;
import java.util.TreeMap;

class Key implements Comparable<Key> {

    int f1;
    int f2;

    public Key(int f1, int f2) {
        this.f1 = f1;
        this.f2 = f2;
    }

    @Override
    public String toString() {
        return "[" + f1 + "," + f2 + "]";
    }

    // 重写了equals方法，当两个Key对象的f1和f2都相同时，返回true，否则返回false
    @Override
    public boolean equals(Object o) {
        if (this == o)
            return true;
        if (o == null || getClass() != o.getClass())
            return false;
        Key that = (Key) o;
        return f1 == that.f1 && f2 == that.f2;
    }

    // 重写了hashCode方法，和equals方法保持语义的一致性，即：当两个Key对象f1和f2都相同时，返回的hashCode值也相同
    @Override
    public int hashCode() {
        return Objects.hash(f1, f2);
    }

    // 实现了compareTo(Key)方法，制定Key对象之间“按（f1+f2）的大小进行比较”的规则
    @Override
    public int compareTo(Key o) {
        return (f1 + f2) - (o.f1 + o.f2);
    }
}

public class TestMap {

    public static void main(String[] args) {
        // 任务点：创建HashMap对象
        Map<Key, String> hashMap = new HashMap<>();

        Key key1 = new Key(1, 2);
        Key key2 = new Key(2, 1);
        Key key3 = new Key(2, 1);

        // 任务点：思考为什么key2和key3的hashCode值是相等的
        System.out.println("key2和key3的hashCode值是否相等：" + (key2.hashCode() == key3.hashCode()));

        // 任务点：使用put方法，依次将<key1, "张三">、<key2, "李四">、<key3, "王五">放入hashMap中
        /********* begin *********/
        hashMap.put(key1, "张三");
        hashMap.put(key2, "李四");
        hashMap.put(key3, "王五");
        /********* end *********/

        // 任务点：使用size方法，获取hashMap中entry的数量。 思考：此时hashMap中entry的数量为什么是2？
        System.out.println("hashMap中条目的数量：" + hashMap.size());

        System.out.println("通过key集遍历map：");
        // 任务点：通过key集遍历hashMap：
        /********* begin *********/
        Set<Key> keys = hashMap.keySet(); // 获取hashMap的key集
        for (Key key : keys) {
            System.out.println("key=" + key + "，value=" + hashMap.get(key)); // 在hashMap中通过key获取value
        }
        /********* end *********/

        // 任务点：使用构造方法TreeMap(Map)创建TreeMap对象，并将hashMap中所有的entry放入treeMap中
        Map<Key, String> treeMap = new TreeMap<Key, String>(hashMap);

        // 任务点：使用size方法，获取treeMap中entry的数量。 思考：此时treeMap中entry的数量为什么是1？
        System.out.println("treeMap中条目的数量：" + treeMap.size());

        Key key4 = new Key(1, 1);

        // 任务点：将<key4, "钱六">放入treeMap中
        treeMap.put(key4, "钱六");

        System.out.println("遍历treeMap中的entry");
        // 任务点：通过entry集遍历treeMap：
        Set<Map.Entry<Key, String>> entries = treeMap.entrySet(); // 使用entrySet方法，获取treeMap中的entry集合
        for (Map.Entry<Key, String> entry : entries) {
            // 分别获取entry中的key和value
            System.out.println("key=" + entry.getKey() + "，value=" + entry.getValue());
        }
        // 任务点：思考为什么遍历treeMap时会先访问中key[1,1]的entry，后访问key[2,1]的entry

    }
}
