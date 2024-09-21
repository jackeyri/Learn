package wrapper1;

import java.util.Scanner;

public class WrapperTest {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        String strDouble = input.nextLine();
        String strInteger = input.nextLine();

        // 任务点：将字符串strDouble和strInteger分别转换为Double和Integer类型，然后相“+”
        double numSum = Double.valueOf(strDouble) + Integer.valueOf(strInteger);

        System.out.println(strDouble + " + " + strInteger + " = " + numSum);

        double numDouble = input.nextDouble();
        int numInteger = input.nextInt();

        // 任务点：将numDouble和numInteger转换为String类型，然后相“+”
        String strJoin = String.valueOf(numDouble) + String.valueOf(numInteger);
        System.out.println(numDouble + " join " + numInteger + " = " + strJoin);

        input.close();
    }

}
