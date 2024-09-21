import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.InetAddress;
import java.net.Socket;

public class Tcpclient {
    public static void main(String[] args) throws IOException {
        // 建立TCP服务
        // 连接本机的TCP服务器
        Socket socket = new Socket(InetAddress.getLocalHost(), 9090);
        // 获得输入流
        InputStream inputStream = socket.getInputStream();
        // 写入数据
        FileOutputStream out = new FileOutputStream(new File("./save.jpg"));
        byte[] data = new byte[4096];
        int length = 0;
        while ((length = inputStream.read(data)) != -1) {
            out.write(data, 0, length);
        }
        // 关闭资源
        out.close();
        socket.close();
    }
}
