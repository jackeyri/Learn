import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class TcpServer extends Thread {
    Socket clientSocket;

    public TcpServer(Socket cSocket) {// 构造函数
        super();
        this.clientSocket = cSocket;
    }

    @Override
    public void run() {
        try {
            String clientAddress = clientSocket.getInetAddress().getHostAddress();
            String clientHostName = clientSocket.getInetAddress().getHostName();
            System.out.println(clientHostName + "(" + clientAddress + ")连接成功.");
            System.out.println("图片数据传输中....");
            long startTime = System.currentTimeMillis();
            OutputStream out = clientSocket.getOutputStream();
            FileInputStream in = new FileInputStream(new File("./army.jpg"));
            byte[] data = new byte[4096];
            int length = 0;
            while ((length = in.read(data)) != -1) {
                out.write(data, 0, length);
            }
            long endTime = System.currentTimeMillis();
            System.out
                    .println(clientHostName + "(" + clientAddress + ")" + "图片传输完成，用时:" + (endTime - startTime) + "ms");
            in.close();
            clientSocket.close();
            System.out.println("连接关闭。");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) throws IOException {
        ServerSocket tcpServer = new ServerSocket(9090);// 绑定端口并监听
        while (true) {
            Socket clientSocket = tcpServer.accept();
            new TcpServer(clientSocket).start();
        }
    }
}
