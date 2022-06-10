#include "mainwindow.h"
#include<QDebug>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setOrganizationName("MSD");
    a.setOrganizationDomain("https://github.com/msduran");
    a.setApplicationDisplayName("Cropper");
    a.setApplicationName("Cropper By MSD");
    a.setApplicationVersion("1.0.0");
    a.setWindowIcon(QIcon(":/images/images/scissors.ico"));

    MainWindow w;
    w.show();
    return a.exec();
}
