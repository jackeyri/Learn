package step12;

public class HelloWorld {
    public static void main(String[] args) {
        int count = 0;    //定义变量存储6的倍数出现的次数
        /*****start*****/
        int i = 1;
        do {
            if (i % 6 == 0) {
                count++;
            }
            i++;
        } while (i <= 100);
        /*****end*****/
        System.out.println("6的倍数出现的次数为：" + count);
    }
}
