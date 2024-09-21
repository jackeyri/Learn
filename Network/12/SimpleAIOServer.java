import java.io.IOException;
import java.net.InetSocketAddress;
import java.nio.ByteBuffer;
import java.nio.channels.AsynchronousServerSocketChannel;
import java.nio.channels.AsynchronousSocketChannel;
import java.nio.channels.CompletionHandler;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.TimeUnit;

public class SimpleAIOServer {
    public static void main(String[] args) {
        try {
            final int port = 5555;
            AsynchronousServerSocketChannel serverSocketChannel = AsynchronousServerSocketChannel.open();
            serverSocketChannel.bind(new InetSocketAddress(port));
            CompletionHandler<AsynchronousSocketChannel, Object> handler = new CompletionHandler<AsynchronousSocketChannel, Object>() {
                @Override
                public void completed(final AsynchronousSocketChannel result, final Object attachment) {
                    serverSocketChannel.accept(attachment, this);
                    try {
                        System.out.println("接收一个客户端连接：" + result.getRemoteAddress().toString());
                        result.getRemoteAddress().toString();
                        result.write(ByteBuffer.wrap("From Server:Hello i am server.".getBytes())).get();
                        ByteBuffer readBuffer = ByteBuffer.allocate(128);
                        result.read(readBuffer).get();
                        System.out.println(new String(readBuffer.array()));
                    } catch (IOException | InterruptedException | ExecutionException e) {
                        e.printStackTrace();
                    }
                }

                @Override
                public void failed(final Throwable exec, final Object attachment) {
                    System.out.println("出错了：" + exec.getMessage());
                }
            };
            serverSocketChannel.accept(null, handler);
            TimeUnit.MINUTES.sleep(20000);
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }
}
