package map1;

import java.util.*;

class Reader {
    Integer id;
    String name;

    public Reader(int id, String name) {
        this.id = id;
        this.name = name;
    }

    @Override
    public String toString() {
        return "ID：" + id + "，姓名：" + name;
    }
}

public class TestMap {
    public static void main(String[] args) {

        // 任务点：创建一个java.util.HashMap类型的映射容器
        Map<Integer, Reader> map = new HashMap<Integer, Reader>();

        Reader reader1 = new Reader(1, "张三");
        Reader reader2 = new Reader(2, "李四");

        /*
         * 任务点：使用map的push(K,V)方法，
         * 依次将 <reader1.id, reader1>、<reader2.id, reader2>添加到map中
         */
        /********* begin *********/
        map.put(reader1.id, reader1);
        map.put(reader2.id, reader2);
        /********* end *********/

        // 任务点：获取map中的条目数量
        System.out.println("添加reader1, reader2后，map中的条目数量：" + map.size());

        System.out.println("通过key集遍历map：");
        // 任务点：通过key集遍历map：
        /********* begin *********/
        Set<Integer> keys = map.keySet(); // 获取map的key集
        for (Integer key : keys) {
            System.out.println("key=" + key + "，value=" + map.get(key)); // 在map中通过key获取value
        }
        /********* end *********/

        // 任务点：判断map的key中是否包含2
        System.out.println("key中是否包含2：" + map.containsKey(2));

        // 任务点：判断map中value中是否包含reader2
        System.out.println("value中是否包含reader2：" + map.containsValue(reader2));

        Reader reader3 = new Reader(2, "王五"); // 注意reader3和reader2的id是相同的
        map.put(reader3.id, reader3);

        // 任务点：思考为什么添加reader3后，map中的条目数量还是2
        System.out.println("添加reader3后，map中的条目数量：" + map.size());

        // 任务点：思考为什么添加reader3后，map中的value不再包含reader2
        System.out.println("value中是否包含reader2：" + map.containsValue(reader2));

        System.out.println("通过entry集遍历map：");
        // 任务点：通过entry集遍历map：
        /********* begin *********/
        Set<Map.Entry<Integer, Reader>> entries = map.entrySet(); // 获取map的entry集
        for (Map.Entry<Integer, Reader> entry : entries) {
            // 分别获取entry中的key和value
            System.out.println("key=" + entry.getKey() + "，value=" + entry.getValue());
        }
        /********* end *********/

        // 任务点：在map中删除key为1的条目
        System.out.println("删除key为1的条目：" + map.remove((1)));

        // 任务点：清空map
        map.clear();

        // 任务点：使用map的isEmpty()方法判断map是否为空
        System.out.println("调用clear方法后，是否清空：" + map.isEmpty());
    }
}
