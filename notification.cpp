#include "notification.h"
#include <QMessageBox>



void Notification::showLowStockNotification(const QString& itemName, int quantity) {
    QMessageBox warningBox;
    warningBox.setIconPixmap(QPixmap(":/images/warning.png"));  // Custom icon for low stock warning
    warningBox.setWindowTitle("Low Stock Warning");
    warningBox.setText(QString("The stock for '%1' is running low. Only %2 left.").arg(itemName).arg(quantity));
    warningBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Retry); // Adding Retry button
    warningBox.exec();
}

void Notification::showCriticalStockNotification(const QString& itemName) {
    QMessageBox criticalBox;
    criticalBox.setIconPixmap(QPixmap(":/images/critical.png"));  // Custom icon for critical alert
    criticalBox.setWindowTitle("Critical Stock Alert");
    criticalBox.setText(QString("The stock for '%1' is OUT!").arg(itemName));
    criticalBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Retry); // Adding Retry button
    criticalBox.exec();
}
