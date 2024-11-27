#include "UserManager.h"
#include <QMessageBox>

UserManager::UserManager() {
    // Ensure the database connection is open
    if (!QSqlDatabase::database().isOpen()) {
        qDebug() << "Database is not open!";
    }
}

UserManager::~UserManager() {}

QString UserManager::hashPassword(const QString &password) {
    // Hash the password using SHA-256
    return QString(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex());
}

bool UserManager::login(const QString &username, const QString &password) {
    QSqlQuery query;
    query.prepare("SELECT PASSWORD_HASH FROM USERS WHERE USERNAME = :username");
    query.bindValue(":username", username);

    if (!query.exec()) {
        qDebug() << "Login query failed: " << query.lastError().text();
        return false;
    }

    if (query.next()) {
        QString storedHash = query.value(0).toString();
        QString enteredHash = hashPassword(password);

        if (storedHash == enteredHash) {
            qDebug() << "Login successful for user:" << username;
            return true;
        } else {
            qDebug() << "Invalid password for user:" << username;
        }
    } else {
        qDebug() << "Username not found:" << username;
    }

    return false;
}

bool UserManager::signUp(const QString &username, const QString &email, const QString &password) {
    QSqlQuery query;

    // Check if the username or email already exists
    query.prepare("SELECT COUNT(*) FROM USERS WHERE USERNAME = :username OR EMAIL = :email");
    query.bindValue(":username", username);
    query.bindValue(":email", email);

    if (!query.exec()) {
        qDebug() << "Sign-up validation query failed: " << query.lastError().text();
        return false;
    }

    if (query.next() && query.value(0).toInt() > 0) {
        qDebug() << "Username or email already exists";
        return false;
    }

    // Insert the new user into the database
    QString passwordHash = hashPassword(password);

    query.prepare("INSERT INTO USERS (USERNAME, EMAIL, PASSWORD_HASH) VALUES (:username, :email, :passwordHash)");
    query.bindValue(":username", username);
    query.bindValue(":email", email);
    query.bindValue(":passwordHash", passwordHash);

    if (!query.exec()) {
        qDebug() << "Sign-up query failed: " << query.lastError().text();
        return false;
    }

    qDebug() << "User signed up successfully:" << username;
    return true;
}
