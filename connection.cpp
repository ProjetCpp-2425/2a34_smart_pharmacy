#include "connection.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Connection::Connection() {}

bool Connection::createconnect() {
    bool test = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

    db.setDatabaseName("source2a34");  // Updated database name
    db.setUserName("projetcpp2a34");      // Username
    db.setPassword("mp2a34");      // Password

    if (db.open()) {
        test = true;
        QMessageBox::information(nullptr, "Database Connection", "Connected successfully to Oracle XE.");
    } else {
        QMessageBox::critical(nullptr, "Database Connection", "Connection failed: " + db.lastError().text());
    }

    return test;
}
