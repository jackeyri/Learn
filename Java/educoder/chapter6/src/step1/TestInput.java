package step1;

import java.io.*;

public class TestInput {

    public static void main(String[] args) throws IOException {
        // 读取src/step1/input.txt文件的内容，并输出到控制台
        /********* Begin *********/
        int b = 0;
        FileReader out = null;
        out = new FileReader("src/step1/input.txt");
        while ((b = out.read()) != -1) {
            System.out.print((char) b);
            /********* End *********/
        }
    }
}
