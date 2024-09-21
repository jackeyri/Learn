package primitive_array1;

// 任务点：导入数组工具类 java.util.Arrays

import java.util.Scanner;
import java.util.Arrays;

public class TestIntArray {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 任务点：创建一个长度为5的整型数组a
        int[] a = new int[5];

        // 任务点：使用for循环遍历数组a，使用数组的length属性
        for (int i = 0; i < a.length; ++i) {
            a[i] = scanner.nextInt();
            System.out.print(a[i] + " ");
        }
        System.out.println();

        // 任务点：使用java.util.Arrays对数组a进行排序
        Arrays.sort(a);

        // 任务点：使用增强型for循环遍历数组a
        for (int e : a) {
            System.out.print(e + " ");
        }

        scanner.close();
    }
}
