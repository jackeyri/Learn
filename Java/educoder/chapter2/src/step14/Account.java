package step14;

public class Account {

    //定义以下静态成员变量：
    //账户最小余额限制值：double minBalance
    /********* begin *********/
    static double minBalance;
    /********* end *********/

    //在静态代码块中初始化静态成员变量，账户最小余额为10元。

    /********* begin *********/
    static {
        minBalance = 10.0;
    }
    /********* end *********/

    //定义以下实例成员变量：
    //账号：String account
    //储户姓名：String name
    //存款余额：double balance
    /********* begin *********/
    String account, name;
    double balance;
    /********* end *********/

    //定义构造方法，用以初始化实例成员变量account、name和balance

    /********* begin *********/
    Account(String account, String name, double balance) {
        this.account = account;
        this.name = name;
        this.balance = balance;
    }

    /********* end *********/

    //定义存钱方法deposit，该方法调用后会显示当前账户的原有金额、现存入金额以及存入后的总金额。
    void deposit(double money) {
        System.out.println("原有金额:" + this.balance);
        System.out.println("现存入金额:" + money);
        // 存入后, 修改账户金额
        /********* begin *********/
        this.balance += money;
        /********* end *********/
        System.out.println("存入后的总金额:" + this.balance);
    }

    //定义取钱方法withdraw，方法调用后会显示当前账户的原有金额、现取出金额以及取出后的最后余额，
    void withdraw(double money) {
        //如果取钱后的余额小于账户最小余额限制值minBalance，则输出"该操作失败"。
        /********* begin *********/
        if (this.balance - money < minBalance) {
            System.out.println("该操作失败");
            return;
        }
        /********* end *********/
        System.out.println("原有金额:" + this.balance);
        System.out.println("现取出金额:" + money);
        this.balance -= money;
        System.out.println("取出后的余额:" + this.balance);
    }

    //定义静态方法setMinBalance，用以设置账户最小余额限制值。

    /********* begin *********/
    static void setMinBalance(double minBalance1) {
        minBalance = minBalance1;
    }

    /********* end *********/

    public static void main(String[] args) {
        // 创建账户account，账号：001，储户姓名：张三，存款余额：500
        /********* begin *********/
        Account account = new Account("001", "张三", 500);
        /********* end *********/
        account.deposit(200);
        account.withdraw(500);
        // 将账户最小余额限制值设置为150
        /********* begin *********/
        setMinBalance(150);
        /********* end *********/
        account.withdraw(100);
    }
}
