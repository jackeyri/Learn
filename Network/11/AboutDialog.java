import java.awt.*;
import javax.swing.*;

public class AboutDialog extends JDialog {
    public AboutDialog() {
        this.setTitle("About");         // 窗体标题显示
        this.setSize(320, 200);  // 窗体的大小
        // 对话框内容
        JLabel about = new JLabel("关于：JAVA的一个窗口：)");
        // 内容显示在窗口的中央
        about.setHorizontalAlignment(SwingConstants.CENTER);
        this.getContentPane().add(about, BorderLayout.CENTER);
    }

    public static void main(String[] args) throws HeadlessException {
        AboutDialog kk = new AboutDialog();
        kk.setVisible(true);
        // 原来的show()显示己过时
        kk.setDefaultCloseOperation(JDialog.DISPOSE_ON_CLOSE);
    }
}
