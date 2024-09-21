package date1;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;

public class DateTest {

    public static void main(String[] args) throws ParseException {
        Scanner input = new Scanner(System.in);
        String strDate = input.nextLine();

        // 任务点：创建模式为"yyyy-MM-dd"的SimpleDateFormat对象
        SimpleDateFormat format1 = new SimpleDateFormat("yyyy-MM-dd");

        // 任务点：使用format对象的parse方法，解析字符串strDate
        Date date = format1.parse(strDate);

        // 任务点：使用getTime方法，输出date对象中包含的表示时刻的数值，思考这个数值的含义。
        System.out.println(date.getTime());

        // 任务点：创建模式为"yyyy年MM月dd日 HH小时mm分钟ss秒"的SimpleDateFormat对象
        SimpleDateFormat format2 = new SimpleDateFormat("yyyy年MM月dd日 HH小时mm分钟ss秒");

        // 任务点：按format2的格式输出date时间
        System.out.println(format2.format(date));

        // 任务点：创建一个表示当前时刻的Date对象now
        Date now = new Date();

        input.close();
    }

}
