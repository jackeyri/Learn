package cn.edu.zsc.blms.util;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class DateUtil {

    private static final SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd");
    private static final SimpleDateFormat timeFormat = new SimpleDateFormat("yyyy-MM-dd hh:mm:ss");

    /**
     * 将yyyy-MM-dd模式的字符串解析为日期
     *
     * @param source 字符串
     * @return 解析字符串后得到的日期对象
     * @throws ParseException 如解析的字符串不符合yyyy-MM-dd模式，则抛出此异常
     */
    public static Date parse(String source) throws ParseException {
        return dateFormat.parse(source);
    }

    /**
     * 将日期对象格式化为yyyy-MM-dd模式的字符串
     *
     * @param date 日期对象
     * @return 格式化日期对象后得到的字符串
     */
    public static String format(Date date) {
        return dateFormat.format(date);
    }

    public static String formatTime(Date time) {
        return dateFormat.format(time);
    }

}
