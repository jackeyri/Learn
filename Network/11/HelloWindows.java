import java.awt.*;
import javax.swing.*;

public class HelloWindows {
    public static void main(String[] args) {
        JFrame windows1 = new JFrame("窗口1");
        JFrame windows2 = new JFrame("窗口2");
        Container container1 = windows1.getContentPane();
        container1.setBackground(Color.blue);
        windows1.setBounds(60, 100, 188, 108);
        windows2.setBounds(260, 100, 188, 108);
        windows1.setVisible(true);
        windows1.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        windows2.setVisible(true);
        windows2.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
    }
}
