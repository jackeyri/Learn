#include "chatwnd.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChatWnd w;
    w.show();
    return a.exec();
}
