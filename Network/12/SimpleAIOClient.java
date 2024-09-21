import java.io.IOException;
import java.net.InetSocketAddress;
import java.nio.ByteBuffer;
import java.nio.channels.AsynchronousSocketChannel;
import java.nio.channels.CompletionHandler;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.TimeUnit;

public class SimpleAIOClient {
    public static void main(String[] args) {
        try {
            AsynchronousSocketChannel client = AsynchronousSocketChannel.open();
            client.connect(new InetSocketAddress("127.0.0.1", 5555), null, new CompletionHandler<Void, Void>() {
                @Override
                public void completed(final Void result, final Void attachment) {
                    System.out.println("成功连接到服务器.");
                    try {
                        client.write(ByteBuffer.wrap("From client:hello i am client.".getBytes())).get();
                        ByteBuffer readBuffer = ByteBuffer.allocate(128);
                        client.read(readBuffer).get();
                        System.out.println(new String(readBuffer.array()));
                    } catch (InterruptedException | ExecutionException e) {
                        e.printStackTrace();
                    }
                }

                @Override
                public void failed(final Throwable exc, final Void attachment) {
                    exc.printStackTrace();
                }
            });

            TimeUnit.MINUTES.sleep(5000);
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }
}
