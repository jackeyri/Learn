import java.io.IOException;
import java.net.InetSocketAddress;
import java.nio.ByteBuffer;
import java.nio.channels.SocketChannel;

public class NioTcpClient {
    public static void main(String[] args) throws IOException {
        SocketChannel socketChannel = SocketChannel.open();
        socketChannel.connect(new InetSocketAddress("127.0.1", 3333));
        ByteBuffer writeBuffer = ByteBuffer.allocate(128);
        writeBuffer.put("Hello from NioTcpClient.".getBytes());
        writeBuffer.flip();
        socketChannel.write(writeBuffer);
        ByteBuffer readBuffer = ByteBuffer.allocate(128);
        socketChannel.read(readBuffer);
        StringBuilder strBd = new StringBuilder();
        readBuffer.flip();
        while (readBuffer.hasRemaining()) {
            strBd.append((char) readBuffer.get());
        }
        System.out.println("从服务器接收到的字符信息：" + strBd);
        socketChannel.close();
    }
}
