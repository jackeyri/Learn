package step11;

public class HelloWorld {
    public static void main(String[] args){
        int sum = 0 ;
        int i = 0;
        while (i<=100){
            sum = sum + i;
            i++;
        }
        System.out.println("1到100相加的结果为" + sum);
    }
}
