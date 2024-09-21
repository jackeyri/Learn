package exception2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class TestException {
    public static void main(String[] args) {
        BufferedReader br = null;

        /*
         * 任务点：多异常处理
         * 使用try...catch代码结构，尝试执行下面几行代码，下面几行代码可能会抛出：
         * IO异常java.io.IOException，
         * 数字格式异常java.lang.NumberFormatException，
         * 数学异常java.lang.ArithmeticException，
         * 对于不同类型的异常，异常处理代码中输出该异常的类型名称，例如IO异常，则输出"java.io.IOException"
         */
        try {
            br = new BufferedReader(new InputStreamReader(System.in));
            int x = Integer.parseInt(br.readLine());
            int y = Integer.parseInt(br.readLine());
            System.out.println(x / y);
        } catch (IOException e) {
            System.out.println("java.io.IOException");
        } catch (NumberFormatException e) {
            System.out.println("java.lang.NumberFormatException");
        } catch (ArithmeticException e) {
            System.out.println("java.lang.ArithmeticException");
        } finally {
            try {
                /*
                 * 任务点：将下面几行代码放到finally语句块中，
                 * 注意：关闭IO流的操作，也可能会产生java.io.IOException异常
                 * 如果关闭IO流时产生IO异常，则输出"java.io.IOException"
                 */
                if (br != null) {
                    br.close();
                }
            } catch (IOException e) {
                System.out.println("java.io.IOException");
            }
        }
    }
}