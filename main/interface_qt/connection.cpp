#include "connection.h"
#include <QDebug>  // Include QDebug for logging

Connection::Connection() {}

bool Connection::createconnection() {
    bool test = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("source2a34"); // Insert your data source name
    db.setUserName("projetcpp2a34");  // Insert your database username
    db.setPassword("mp2a34");         // Insert your database password

    // Attempt to open the connection and log any errors if unsuccessful
    if (db.open()) {
        test = true;
        qDebug() << "Database connection successful.";
    } else {
        qDebug() << "Database connection failed: " << db.lastError().text();
    }

    return test;
}

// Optional: Uncomment this function to explicitly close the connection if needed
// void Connection::closeconnection() {
//     QSqlDatabase::database().close();
// }
