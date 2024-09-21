package enum1;

/**
 * 根据三基色原理，任何一种颜色都可以由不同比例的红、绿、蓝三种颜色混合而成
 * 程序定义了表示颜色的枚举类Color
 * 在Color中定义了RED红、GREEN绿、BLUE蓝、BLACK黑、WHITE白五种常见的颜色的枚举值。
 */

// 任务点：定义表示颜色的枚举类 Color
enum Color {

    RED(255, 0, 0), // 红色
    GREEN(0, 255, 0), // 绿色
    // 任务点：定义枚举值：蓝色BLUE和黑色BLACK，
    /********* begin *********/
    BLUE(0, 0, 255),
    BLACK(0, 0, 0),
    /********* end *********/
    WHITE(255, 255, 255);

    /*
     * 成员变量，分别表示红、绿、蓝三个颜色分量的值，每种颜色分量的取值范围是0~255
     */
    private int r, g, b;

    // 任务点：定义私有构造方法，初始化rgb颜色分量

    /********* begin *********/
    private Color(int r, int g, int b) {
        this.r = r;
        this.g = g;
        this.b = b;
    }

    /********* end *********/

    /*
     * 返回rgb颜色分量组成的字符串
     */
    public String getRGB() {
        return "[" + r + "," + g + "," + b + "]";
    }
}


public class TestEnum {
    public static void main(String[] args) {

        // 任务点：让color等于Color枚举值BLACK
        Color color = Color.BLACK;

        // 任务点：调用Enum中定义的name()方法，输出color的name属性值
        System.out.println(color.name());

        // 任务点：调用Enum中定义的ordinal()方法，输出color的ordinal属性值
        System.out.println(color.ordinal());

        // 任务点：调用Color中定义的getRGB()方法，输出color的rgb颜色分量
        System.out.println(color.getRGB());

        // 任务点：使用Enum中定义的静态方法values，以获得所有Color枚举常量组成的数组
        Color[] values = color.values();
        for (Color value : values) {
            System.out.println(value);
        }

    }
}
