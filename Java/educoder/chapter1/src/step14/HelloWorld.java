package step14;

import java.util.Scanner;

public class HelloWorld {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("请给定一个自然数N：");
        int N = sc.nextInt();
        int sum = 1;
        /*****start*****/
        for(int i = N; i > 0; i--){
            sum = sum * i;
        }
        /*****end*****/
        System.out.println("自然数N的阶乘为" + sum);
    }
}
