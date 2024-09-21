#include "chatwnd.h"
#include "ui_chatwnd.h"

ChatWnd::ChatWnd(QWidget* parent) : QMainWindow(parent), ui(new Ui::ChatWnd) {
    udpRecvSocket = new QUdpSocket(this);
    udpSendSocket = new QUdpSocket(this);
    ui->setupUi(this);
}

ChatWnd::~ChatWnd() {
    delete ui;
}

void ChatWnd::on_pBtnBind_clicked() {
    QHostAddress* hostaddr1;
    hostaddr1 = new QHostAddress(ui->lineEditLocalIP->text());
    int iLocalPort = ui->lineEditLocalPort->text().toInt();
    bool conn;
    conn =
        udpRecvSocket->bind(*hostaddr1, iLocalPort, QUdpSocket::ShareAddress);
    if (!conn) {
        QMessageBox::information(NULL, "Error.", "UDP port bind failure.",
                                 QMessageBox::Ok);
    } else {
        QMessageBox::information(NULL, "Success.", "UDP port bind Success.",
                                 QMessageBox::Ok);
        ui->pBtnBind->setEnabled(false);
        connect(udpRecvSocket, SIGNAL(readyRead()), this, SLOT(receiveUDP()));
    }
}

void ChatWnd::on_pBtnSend_clicked() {
    int iDestPort = ui->lineEditDestPort->text().toInt();
    QHostAddress* desthostaddr;
    desthostaddr = new QHostAddress(ui->lineEditDestIP->text());
    QString oneStr = ui->lineEditTxt->text();
    QByteArray baArray = oneStr.toUtf8();
    udpSendSocket->writeDatagram(baArray, baArray.size(), *desthostaddr,
                                 iDestPort);
}

void ChatWnd::receiveUDP() {
    while (udpRecvSocket->hasPendingDatagrams()) {
        QByteArray baData;
        baData.resize(udpRecvSocket->pendingDatagramSize());
        udpRecvSocket->readDatagram(baData.data(), baData.size());
        QString str = QString::fromUtf8(baData.data());
        ui->textEdit->insertPlainText(str + "\n");
    }
}
