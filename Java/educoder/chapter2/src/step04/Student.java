package step04;

//创建一个Student类，在该类中对setCard()方法进行重载
public class Student {

    String name; // 姓名
    int score; //成绩

    // setCard()重载方法1 设置学生姓名
    public void setCard(String name1) {
        name = name1;
    }

    // 定义setCard()重载方法2，用以设置学生成绩
    public void setCard(int score1) {
        score = score1;
    }

    // 定义setCard()重载方法3，用以同时设置学生姓名和成绩
    public void setCard(String name1, int score1) {
        score = score1;
        name = name1;
    }

    void printInfo() {    // 成员方法：printInfo()，打印信息
        System.out.println("姓名：" + name + "，成绩：" + score);
    }

    public static void main(String[] args) {
        // 创建一个学生对象s1
        Student s1 = new Student();
        // 通过setCard()重载方法1 设置学生s1的姓名为张三
        s1.setCard("张三");
        // 通过setCard()重载方法2 设置学生s1的成绩为90
        s1.setCard(90);
        s1.printInfo();
        // 创建一个学生对象s2
        Student s2 = new Student();
        // 通过setCard()重载方法3 设置学生s2的姓名为李四，成绩为70
        s2.setCard("李四", 70);
        s2.printInfo();
    }

}
