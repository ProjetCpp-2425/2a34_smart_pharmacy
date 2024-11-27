#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QCryptographicHash>
#include <QDebug>

class UserManager {
public:
    UserManager();
    ~UserManager();

    bool login(const QString &username, const QString &password);
    bool signUp(const QString &username, const QString &email, const QString &password);
    int getCurrentUserId() const;

private:
    QString hashPassword(const QString &password);
    int currentUserId = -1; // -1 indicates no user is logged in

};

#endif // USERMANAGER_H

