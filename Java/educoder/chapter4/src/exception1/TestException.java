package exception1;

import java.util.Scanner;

public class TestException {

    // 任务点：声明方法m(int,int)可能会抛出Exception类型的异常
    static void m(int a, int b) throws Exception {
        if (b == 0) {
            // 任务点： 创建一个Exception异常对象，异常消息是"除数为零"，并抛出该异常对象
            throw new Exception();
        } else {
            int c = a / b;
            System.out.println(c);
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int a = input.nextInt();
        int b = input.nextInt();
        // 任务点：使用异常处理代码结构，尝试执行方法m(a, b)，如果发生异常则输出异常消息，无论是否发生异常都输出"总会执行"
        /********* begin *********/
        try {
            m(a, b);
        } catch (Exception e) {
            System.out.println("除数为零");
        } finally {
            System.out.println("总会执行");
        }
        /********* end *********/
        System.out.println("程序正常结束");
        input.close();
    }
}