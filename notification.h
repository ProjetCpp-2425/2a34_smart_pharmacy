#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QMessageBox>
#include <QString>
#include <QPixmap>

class Notification {
public:
    static void showLowStockNotification(const QString& itemName, int quantity);
    static void showCriticalStockNotification(const QString& itemName);
};

#endif // NOTIFICATION_H
