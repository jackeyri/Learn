package step13;

public class HelloWorld {
    public static void main(String[] args) {
        int i = 0;
        while(i <= 20){
            i++;
            /*****start*****/
            if(  i%2 ==0   ){
                System.out.println( i + "是偶数");
                continue;
            }
            System.out.println(i + "是奇数");
            if( i == 13 ) {
                break;
            }
            /*****end*****/
        }
    }
}
