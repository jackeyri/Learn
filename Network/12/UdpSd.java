import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetSocketAddress;

public class UdpSd {
    public static void main(String[] args) throws IOException {
        DatagramSocket clientSocket = new DatagramSocket();
        String data = "学富五车，才高八斗";
        byte[] datas = data.getBytes("utf-8");
        int len = datas.length;
        System.out.println(data + " len:" + len);
        DatagramPacket dataPacket = new DatagramPacket(
                datas, 0, datas.length, new InetSocketAddress("localhost", 8888));
        clientSocket.send(dataPacket);
        clientSocket.close();
    }
}
