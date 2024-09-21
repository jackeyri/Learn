package random1;

import java.util.Random;
import java.util.Scanner;

/**
 * 编写程序TestRandom.java，要求使用java.util.Random类和java.util.Scanner类的相关方法，完成以下练习。
 * 程序的功能是：循环读取用户在控制台输入的整数n，并生成[0, n]之间的随机整数。
 * 按模板要求，将【代码】处替换成相应的Java程序。
 */
public class TestRandom {
    public static void main(String[] args) {

        // 任务点：创建基于标准输入流System.in的扫描器java.util.Scanner对象
        Scanner scanner = new Scanner(System.in);

        // 任务点：使用1000作为种子数，创建伪随机数生成器java.util.Random对象
        Random random = new Random(1000);

        int n = 0;
        System.out.println("输入0表示退出循环");
        while (true) {
            System.out.print("请输入n的值：");

            // 任务点：使用scanner对象将控制台的输入读取为整型
            n = scanner.nextInt();
            if (n == 0) { // 如果n=0，则退出while循环
                break;
            }

            // 任务点：使用random对象生成[0, n]之间的一个随机整数
            int num = random.nextInt(n + 1);
            System.out.println("生成的[0," + n + "]之间的随机数是：" + num);
        }

        System.out.println("程序执行结束");

        // 任务点：关闭扫描器对象scanner
        scanner.close();
    }
}
