package math1;

import java.util.Scanner;

/**
 * 编写程序TestMath.java，要求使用JDK中的java.lang.Math类完成程序功能，请自行查阅PAI文档，学习这个类的使用。
 * 将【代码】替换成相应的Java程序代码，使之能完成注释中的要求。
 */
public class TestMath {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double num = scanner.nextDouble();

        // 任务点：使用Math类，对num四舍五入
        System.out.println(Math.round(num));

        // 任务点：使用Math类，对num向上取整
        System.out.println(Math.ceil(num));

        // 任务点：使用Math类，对num取下取整
        System.out.println(Math.floor(num));

        // 任务点：使用Math类，对num取平方根
        System.out.println(Math.sqrt(num));

        // 任务点：使用Math类，获取圆周率PI
        System.out.println(Math.PI);

        // 任务点：使用Math类，生成一个[0,10]范围内的数，并将其强制转换为int整数
        int a = (int) Math.round(Math.random() * 10);

        if (0 <= a && a <= 10)
            System.out.println("0 <= a && a <= 10");

        scanner.close();
    }
}
