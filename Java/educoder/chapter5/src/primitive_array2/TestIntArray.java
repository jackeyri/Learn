package primitive_array2;

import java.util.Arrays;
import java.util.Scanner;

public class TestIntArray {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 任务点：在创建整型数组original的同时，将数组元素的初始值设置为{ 1, 2, 4, 3, 5 }
        int[] original = {1, 2, 4, 3, 5};

        // 任务点：使用java.util.Arrays类的copyOfRange方法，将数组original的一部分（从第二个元素到最后一个元素）复制到数组copy中
        int[] copy = Arrays.copyOfRange(original, 1, 5);

        // 任务点：使用for循环遍历数组copy
        for (int i = 0; i < copy.length; i++) {
            System.out.print(copy[i] + " ");
        }
        System.out.println();

        // 任务点：使用java.util.Arrays对数组copy进行排序
        Arrays.sort(copy);

        // 任务点：使用增强型for循环遍历数组copy
        for (int e : copy) {
            System.out.print(e + " ");
        }
        System.out.println();

        // 任务点：使用java.util.Arrays类的binarySearch方法，在数组copy中查找值等于2的元素的下标
        int index = Arrays.binarySearch(copy, 2);

        // 任务点：根据index值，判断在数组copy中是否存在值为2的元素
        if (2 == copy[0]) {
            System.out.println("数组copy中，值为2的元素下标是：" + index);
        } else {
            System.out.println("数组copy中不存在值为2的元素");
        }

        scanner.close();
    }
}
