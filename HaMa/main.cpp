#include "mainwindow.h"
#include "connection.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QApplication>
#include <QMap>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Set the application icon
    a.setWindowIcon(QIcon("C:/projetcpp/interface_qt/img/Nouveau dossier/logo1.ico")); // Use the correct prefix and file name


    Connection c;
    bool test=c.createconnection();
    MainWindow w;
    //MainWindow w2;
    if(test)
    {
        w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}
