import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class ButtonListener implements ActionListener {
    public void actionPerformed(ActionEvent e) {
        String name = ((JButton) e.getSource()).getText();
        System.out.println("Button: " + name + "  is clicked.");
    }
}

public class ButtonDemo {
    private ButtonListener bl;

    ButtonDemo() {// 构造函数
        bl = new ButtonListener();
        JFrame frame1 = new JFrame("ButtonDemo");
        frame1.setSize(400, 300);
        frame1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame1.setLayout(new FlowLayout());
        JButton btnUp = new JButton("Up");
        JButton btnDown = new JButton("Down");
        btnUp.addActionListener(bl);
        btnDown.addActionListener(bl);
        frame1.add(btnUp);
        frame1.add(btnDown);
        // frame1.pack();
        frame1.setVisible(true);
    }

    public static void main(String[] args) {
        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new ButtonDemo();
            }
        });

    }

}
