#ifndef CHATWND_H
#define CHATWND_H

#include <QMainWindow>
#include <QtGui>
#include <QtNetwork>
#include <QtWidgets/QMessageBox>

namespace Ui {
class ChatWnd;
}

class ChatWnd : public QMainWindow {
    Q_OBJECT

public:
    int iDestPort;
    explicit ChatWnd(QWidget* parent = 0);
    ~ChatWnd();

private slots:
    void on_pBtnBind_clicked();
    void on_pBtnSend_clicked();
    void receiveUDP();

private:
    Ui::ChatWnd* ui;
    QUdpSocket* udpRecvSocket;
    QUdpSocket* udpSendSocket;

    QString qsDestIP;
};

#endif  // CHATWND_H
