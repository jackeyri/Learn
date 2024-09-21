package step2;

import java.io.*;

/**
 * @author pengzheng
 */
public class Task {

    public void run(String src, String dest) throws IOException {
        // 将UTF编码的文本文件src，复制到GBK编码的文本文件dest中，并输出dest文件的内容
        /********* Begin *********/
        int count = 0;
        char[] buf = new char[1024];
        FileInputStream fis = new FileInputStream(src);
        FileOutputStream fos = new FileOutputStream(dest);
        InputStreamReader isr = new InputStreamReader(fis, "utf-8");
        OutputStreamWriter osw = new OutputStreamWriter(fos, "gbk");
        while ((count = isr.read(buf)) != -1) {

            osw.write(buf, 0, count);
        }
        isr.close();
        osw.flush();
        osw.close();
        /********* End *********/
    }
}
