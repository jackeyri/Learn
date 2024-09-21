package string2;

import java.util.Scanner;

/**
 * 编写程序TestString.java，要求使用java.lang.String类的相关方法，完成以下练习。
 * 按模板要求，将【代码】处替换成相应的Java程序。
 */
public class TestString {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        // 任务点：通过Scanner对象input的nextLine方法读取输入的表示姓名拼音的一行字符串，如：zhang san
        String name = input.nextLine();

        // 任务点：输出字符串name的长度
        System.out.println("字符串的长度是：" + name.length());

        // 任务点：输出字符串name中的第一个字符
        System.out.println("字符串中的第一个字符是：" + name.charAt(0));

        // 任务点：输出字符串name的最后一个字符
        System.out.println("字符串中的最后一个字符是：" + name.charAt(name.length() - 1));

        // 任务点：使用substring和indexOf方法，输出字符串name中的第一个单词
        System.out.println("字符串中的第一个单词是：" + name.substring(0, name.indexOf(' ')));

        // 任务点：使用substring和lastIndexOf方法，输出字符串name中的最后一个单词
        System.out.println("字符串中的最后一个单词是：" + name.substring(name.lastIndexOf(' ') + 1, name.length()));

        String s1 = new String("how are you");
        String s2 = new String("how are you");

        // 任务点：使用equals方法，判断s1与s2的内容是否相同
        if (s1.equals(s2)) {
            System.out.println("s1与s2的内容相同");
        } else {
            System.out.println("s1与s2的内容不相同");
        }

        // 任务点：使用逻辑等 == ，判断变量s1与s2的值是否相等
        if (s1 == s2) {
            System.out.println("s1与s2的值相等");
        } else {
            System.out.println("s1与s2的值不相等");
        }

        // 任务点：使用startsWith方法，判断s1是否以"how"开始。
        if (s1.substring(0, s1.indexOf(' ')).equals("how")) {
            System.out.println("s1是以how开头的");
        }

        // 任务点：使用contains方法，判断s2是否包含"you"。
        if (s2.contains("you")) {
            System.out.println("s2中包含how");
        }

        String path = "c:/java/A.java";
        // 任务点：获取字符串path中第一个目录分隔符'/'的位置
        int index = path.indexOf('/');
        System.out.println("c:/java/A.java中第一个/出现的位置是：" + index);

        // 任务点：获取字符串path中最后一个目录分隔符'/'的位置
        int lastIndex = path.lastIndexOf('/');
        System.out.println("c:/java/A.java中最后一个/出现的位置是：" + lastIndex);

        // 任务点：使用lastIndex值和substring方法，获取字符串path中包含的文件名"A.java"
        String fileName = path.substring(path.lastIndexOf("A.java"), path.length());
        System.out.println("c:/java/A.java中包含的文件名是：" + fileName);

        input.close();
    }
}
