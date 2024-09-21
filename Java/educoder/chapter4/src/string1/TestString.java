package string1;

import java.util.Scanner;

public class TestString {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String str = input.nextLine();

        // 任务点：输出str的长度
        System.out.println(str.length());

        // 任务点：输出"abc"与str的内容是否一致
        System.out.println("abc".equals(str));

        // 任务点：输出在忽视大小写的情况下"aBc"与str的内容是否一致
        System.out.println("aBc".equalsIgnoreCase(str));

        // 任务点：输出"abcd"与str比较大小的结果
        System.out.println("abcd".compareTo(str));

        // 任务点：输出str的第一个字符
        System.out.println(str.charAt(0));

        // 任务点：输出str中字符'b'的索引
        System.out.println(str.indexOf('b'));

        // 任务点：输出str是否以"ab"开头
        System.out.println(str.startsWith("ab"));

        // 任务点：输出str是否以"bc"结尾
        System.out.println(str.endsWith("bc"));

        // 任务点：输出str中从第2个字符开始取2个字符得到的子串
        System.out.println(str.substring(1, 3));

        input.close();
    }
}
