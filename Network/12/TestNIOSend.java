import java.io.IOException;
import java.net.InetSocketAddress;
import java.nio.ByteBuffer;
import java.nio.channels.DatagramChannel;
import java.util.Scanner;

public class TestNIOSend {
    public static void main(String[] args) throws Exception {
        send();
    }

    public static void send() throws IOException {
        DatagramChannel dc = DatagramChannel.open();
        dc.configureBlocking(false);
        ByteBuffer buffer = ByteBuffer.allocate(1024);
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            String str = scanner.next();
            buffer.put(str.getBytes());
            buffer.flip();
            dc.send(buffer, new InetSocketAddress("127.0.0.1", 9898));
            buffer.clear();
        }
        scanner.close();
        dc.close();
    }
}
