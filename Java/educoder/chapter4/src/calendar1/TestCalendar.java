package calendar1;

import java.util.Scanner;
import java.util.Date;
import java.text.SimpleDateFormat;
import java.util.Calendar;

/**
 * 编写程序TestCalendar.java，实现功能：用户在控制台输入一个日期，打印出这个日期的月历。
 * 可按以下步骤完成这个练习：
 * 步骤1、使用Scanner类获取用户在控制台输入的日期，日期的格式为“yyyy-MM-dd”，比如“2015-10-15”。
 * 步骤2、将用户输入的日期字符串转换成Date对象，并由Date对象生成Calendar对象。需要用到java.util.SimpleDateFormat类。
 * 步骤3、将输出月历的功能封装成一个静态方法，该方法通过接收一个Calendar对象，然后输出Calendar对象的月历。
 * 步骤4、调用步骤3中定义的方法，并将将步骤2中生成的Calendar对象传递给该方法。最终打印出Calendar对象的月历。
 */
public class TestCalendar {

    /**
     * 输出指定时刻对应的月历
     *
     * @param moment 指定时刻
     */
    public static void printCalendar(Calendar moment) {

        // 任务点：调用moment的set方法，将时间分量日期Calendar.DATE设为当月1号
        moment.set(Calendar.DATE, 1);

        // 任务点：调用moment的get方法，获得时间分量星期几Calendar.DAY_OF_WEEK的值，即当月1号是星期几
        int dayOfWeek = moment.get(Calendar.DAY_OF_WEEK);

        // 任务点：调用moment的getActualMaximum方法，获得时间分量日期Calendar.DATE的值，即当月最后一天是几号
        int maxDate = moment.getActualMaximum(Calendar.DATE);

        System.out.println("日\t一\t二\t三\t四\t五\t六"); // 打印标题行

        // 任务点：打印1号之前的空格，循环次数=从星期天Calendar.SUNDAY开始，到当月1号对应的星期几dayOfWeek的天数
        for (int i = Calendar.SUNDAY; i < dayOfWeek; i++) {
            System.out.print("\t");
        }

        // 任务点：循环打印当月的每一天，从当月1号到maxDate号遍历循环变量i
        for (int i = 1; i <= maxDate; i++) {
            System.out.print(i + "\t");

            // 任务点：如果当月i号是星期六，则打印换行。提示：i号星期六时，"dayOfWeek+i-1"的值应该是7的整数倍
            if ((dayOfWeek + i - 1) % 7 == 0) {
                System.out.println();
            }
        }
    }

    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        String strDate = scanner.nextLine();

        // 任务点：创建模式为"yyyy-MM-dd"的SimpleDateFormat对象
        SimpleDateFormat format = new SimpleDateFormat("yyyy-MM-dd");

        // 任务点：使用format对象的parse方法，解析字符串strDate
        Date date = format.parse(strDate);

        // 任务点：获取Calendar对象
        Calendar moment = Calendar.getInstance();

        // 任务点：将moment对象的时间设置为date
        moment.setTime(date);

        printCalendar(moment);
        scanner.close();
    }
}
