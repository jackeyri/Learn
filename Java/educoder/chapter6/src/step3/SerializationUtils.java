package step3;

import java.io.*;

/**
 * @author pengzheng
 */
public class SerializationUtils {

    public static byte[] serialize(Serializable object) throws Exception {
        // 使用ByteArrayOutputStream和ObjectOutputStream，将对象object序列化为字节数组，并返回
        /********* Begin *********/
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        ObjectOutputStream oos = new ObjectOutputStream(out);
        oos.writeObject(object);
        oos.flush();
        byte[] bytes = out.toByteArray();
        return bytes;
        /********* End *********/
    }

    public static Object deserialize(byte[] data) throws Exception {
        // 使用ByteArrayInputStream和ObjectInputStream，将字节数组data反序列化为对象，并返回
        /********* Begin *********/
        ByteArrayInputStream in = new ByteArrayInputStream(data);
        ObjectInputStream ois = new ObjectInputStream(in);
        return ois.readObject();
        /********* End *********/
    }

}
