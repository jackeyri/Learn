import java.awt.EventQueue;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.net.*;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.channels.DatagramChannel;
import java.nio.channels.SelectionKey;
import java.nio.channels.Selector;
import java.util.Iterator;

public class UDPChat {
	private JFrame frame;
	private JTextField txtFDDestIP;
	private JTextField txtFdPort;
	private JTextField txtFdDestPort;
	private JTextField txtFdChat;
	private JTextArea txtare1;

	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					UDPChat window = new UDPChat();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	public UDPChat() {
		initialize();
	}

	private void initialize() {
		frame = new JFrame();
		frame.setBounds(100, 100, 450, 465);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);

		JLabel lblNewLabel_1 = new JLabel("本地端口");
		lblNewLabel_1.setBounds(10, 10, 54, 15);
		frame.getContentPane().add(lblNewLabel_1);

		int yPos = 320;
		JLabel lblNewLabel = new JLabel("目标IP地址:");
		lblNewLabel.setBounds(10, yPos + 2, 100, 15);
		frame.getContentPane().add(lblNewLabel);

		txtFDDestIP = new JTextField();
		txtFDDestIP.setText("127.0.0.1");
		txtFDDestIP.setBounds(100, yPos, 90, 21);
		frame.getContentPane().add(txtFDDestIP);
		txtFDDestIP.setColumns(10);

		txtFdPort = new JTextField();
		txtFdPort.setText("8898");
		txtFdPort.setBounds(150, 7, 66, 21);
		frame.getContentPane().add(txtFdPort);
		txtFdPort.setColumns(10);

		JLabel lblNewLabel_2 = new JLabel("目标端口");
		lblNewLabel_2.setBounds(200, yPos + 2, 54, 15);
		frame.getContentPane().add(lblNewLabel_2);

		txtFdDestPort = new JTextField();
		txtFdDestPort.setText("8898");
		txtFdDestPort.setBounds(260, yPos, 66, 21);
		frame.getContentPane().add(txtFdDestPort);
		txtFdDestPort.setColumns(10);

		JScrollPane scrollPane = new JScrollPane();
		scrollPane.setBounds(10, 36, 414, 274);
		frame.getContentPane().add(scrollPane);

		txtare1 = new JTextArea();
		scrollPane.setViewportView(txtare1);

		txtFdChat = new JTextField();
		txtFdChat.setText("hello JAVA.");
		txtFdChat.setBounds(10, 352, 310, 21);
		frame.getContentPane().add(txtFdChat);
		txtFdChat.setColumns(10);
		JButton btnClose = new JButton("关闭窗口");
		btnClose.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				System.exit(0);
			}
		});
		btnClose.setBounds(331, 6, 93, 23);
		frame.getContentPane().add(btnClose);

		JButton btnSend = new JButton("发送");
		btnSend.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String host = txtFDDestIP.getText();
				int port = Integer.parseInt(txtFdDestPort.getText());
				try {
					DatagramSocket clientUdpSocket = new DatagramSocket(0);
					String strInfo = txtFdChat.getText();
					System.out.println("client send str:" + strInfo);
					byte[] btStr = strInfo.getBytes("utf-8");
					DatagramPacket udpDataPack = new DatagramPacket(btStr, 0, btStr.length,
							new InetSocketAddress(host, port));
					clientUdpSocket.send(udpDataPack);
					clientUdpSocket.close();
				} catch (UnknownHostException e1) {
					e1.printStackTrace();
				} catch (IOException e1) {
					e1.printStackTrace();
					System.out.println("数据发送失败！");
				}
			}
		});
		btnSend.setBounds(350, yPos + 30, 60, 23);

		frame.getContentPane().add(btnSend);
		JButton btnBind = new JButton("绑定端口");
		btnBind.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				int uuport = Integer.parseInt(txtFdPort.getText());
				UdpReceiveThread ust = new UdpReceiveThread(uuport);
				ust.start();
			}
		});
		btnBind.setBounds(250, 6, 93, 23);
		frame.getContentPane().add(btnBind);
	}

	public class UdpReceiveThread extends Thread {
		int port;

		public UdpReceiveThread(int uport) {
			this.port = uport;
		}

		@Override
		public void run() {
			try {
				DatagramChannel udpChannel = DatagramChannel.open();
				udpChannel.configureBlocking(false);
				udpChannel.socket().bind(new InetSocketAddress(port));
				Selector uselector = Selector.open();
				udpChannel.register(uselector, SelectionKey.OP_READ);
				while (uselector.select() > 0) {
					Iterator<SelectionKey> iterator = uselector.selectedKeys().iterator();
					while (iterator.hasNext()) {
						SelectionKey next = iterator.next();
						if (next.isReadable()) {
							ByteBuffer btBuf = ByteBuffer.allocate(1024);
							udpChannel.receive(btBuf);
							btBuf.flip();
							String strRecv = new String(btBuf.array(), 0, btBuf.limit());
							System.out.println("receive str:" + strRecv);
							txtare1.append(strRecv + "\r\n");
							btBuf.clear();
						}
					}
					iterator.remove();
				}
				System.out.println("Thread is over.");
			} catch (SocketException e1) {
				e1.printStackTrace();
			} catch (IOException e0) {
				e0.printStackTrace();
			}
		}
	}
}