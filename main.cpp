#include "mainwindow.h"
#include <QApplication>
#include "connection.h"
#include <QMessageBox>
#include <QDebug>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Connection conn;

    // Validate database connection
    if (!conn.createconnect()) {
        qDebug() << "Database connection failed!";
        QMessageBox::critical(nullptr, "Database Connection", "Failed to connect to the database.");
        return -1;  // Exit if the connection fails
    } else {
        qDebug() << "Database connection established successfully.";
    }

    MainWindow w;
    qDebug() << "MainWindow created successfully.";

    // Show the main window
    w.show();

    return a.exec();
}
