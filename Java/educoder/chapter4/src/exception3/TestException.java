package exception3;

import java.util.Scanner;

/*
 * 任务点：自定义异常类UsernameException，表示用户名异常（不符合要求）
 * 合法的用户名要求：长度必须在[6,15]范围内，并且只能由大小写字母和数字组成。
 */
class UsernameException extends Exception {

    private static final long serialVersionUID = 1L;

    /*
     * 任务点：定义构造方法UsernameException()，在构造方法中调用父类构造方法Exception(String)，
     * 异常消息为"不合法的用户名，只能由大小写字母和数字组成。"
     */

    /********* begin *********/
    public UsernameException() {
        super("不合法的用户名，只能由大小写字母和数字组成。");
    }
    /********* end *********/

    /*
     * 任务点：定义构造方法UsernameException(String)，参数为异常消息，
     * 在构造方法中调用父类构造方法Exception(String)
     */

    /********* begin *********/
    public UsernameException(String log) {
        super("不合法的用户名，用户名长度必须在[6,15]范围内。");
    }
    /********* end *********/
}

public class TestException {

    // 任务点：声明方法checkUsername(String)可能会抛出UsernameException类型的异常
    static void checkUsername(String username) throws UsernameException {

        if (username.length() < 6 || username.length() > 15) {
            // 任务点： 创建一个UsernameException异常对象，异常消息是"不合法的用户名，用户名长度必须在[6,15]范围内。"，并抛出该异常对象
            throw new UsernameException("不合法的用户名，用户名长度必须在[6,15]范围内。");
        }

        if (!username.matches("^[A-Za-z0-9]+$")) {
            // 任务点： 创建一个UsernameException异常对象，不提供异常消息，并抛出该异常对象
            throw new UsernameException();
        }
    }

    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        String username;

        while (true) {
            username = input.nextLine();
            try {
                checkUsername(username);
            } catch (UsernameException e) {
                System.out.println(e.getMessage() + "请重新输入合法的用户名：");
                continue;
            }
            break;
        }

        System.out.println("合法的用户名：" + username);
        input.close();
    }
}
