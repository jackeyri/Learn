package step9;

import java.util.Scanner;

public class HelloIfStep2 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        /******start******/
        System.out.println("请输入学员成绩：");
        int score = input.nextInt();
        if(score >= 85 && score <=100 ){
            System.out.println("优，非常棒！");
        }else{
            System.out.println("良，下次加油！");
        }
        /******end******/
    }
}
