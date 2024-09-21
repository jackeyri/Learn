package string_buffer1;

/**
 * 编写程序TestStringBuffer.java，要求使用java.lang.StringBuffer类的相关方法，完成以下练习。
 * 按模板要求，将【代码】处替换成相应的Java程序。
 */
public class TestStringBuffer {
    public static void main(String[] args) {
        String s = "MicroSoft";

        // 任务点：使用String对象s创建StringBuffer对象sb
        StringBuffer sb = new StringBuffer(s);
        System.out.println(sb);

        // 任务点：使用append方法在sb末尾添加字符串"Oracle"
        System.out.println(sb.append("Oracle"));

        // 任务点：使用insert和indexOf方法，在sb中的MicroSoft和Oracle之间插入字符'/'
        System.out.println(sb.insert(sb.indexOf("t") + 1, "/"));

        // 任务点：使用replace和indexOf方法，将sb中的MicroSoft替换成MicroSun
        System.out.println(sb.replace(sb.indexOf("M"), sb.indexOf("t") + 1, "MicroSun"));

        // 任务点：使用delete和indexOf方法，将sb中'/'字符之前的字串删除
        System.out.println(sb.delete(0, sb.indexOf("/")));
    }
}
