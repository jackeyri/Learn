import java.io.*;
import java.net.DatagramPacket;
import java.net.DatagramSocket;

public class UdpRv {
    public static void main(String[] args) throws IOException {
        DatagramSocket serviceSocket = new DatagramSocket(8888);
        byte[] container = new byte[1024];
        DatagramPacket dataPacket = new DatagramPacket(container, 0, container.length);
        serviceSocket.receive(dataPacket);
        byte[] datas = dataPacket.getData();
        int len = dataPacket.getLength();
        System.out.println(new String(datas, 0, len));
        serviceSocket.close();
    }
}
