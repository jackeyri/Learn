import java.net.InetSocketAddress;
import java.nio.ByteBuffer;
import java.nio.channels.ServerSocketChannel;
import java.nio.channels.SocketChannel;

public class NioTcpServer {
    public static void main(String[] args) throws Exception {
        ServerSocketChannel ssc = ServerSocketChannel.open();
        ssc.configureBlocking(false);
        ssc.socket().bind(new InetSocketAddress("127.0.0.1", 3333));
        while (true) {
            SocketChannel socketChannel = ssc.accept();
            if (socketChannel == null) {
                System.out.println("时间段内没有socket接入请求.");
                Thread.sleep(10000);
            } else {
                ByteBuffer writeBuffer = ByteBuffer.allocate(128);
                writeBuffer.put("data from NioTcpServer.".getBytes());
                writeBuffer.flip();
                socketChannel.write(writeBuffer);
                ByteBuffer readBuffer = ByteBuffer.allocate(128);
                socketChannel.read(readBuffer);
                StringBuilder stringBd = new StringBuilder();
                readBuffer.flip();
                while (readBuffer.hasRemaining()) {
                    stringBd.append((char) readBuffer.get());
                }
                System.out.println("从客户端接收到的字符串：" + stringBd);
            }
        }
    }

}
