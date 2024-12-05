/*#ifndef STOCKMANAGER_H
#define STOCKMANAGER_H

#include <QString>
#include <QSqlQuery>
#include "mainwindow.h"
#include "stock.h"

class StockManager {
public:
    StockManager();

    void checkLowstockNotification();  // Check low stock notification

    int lowStockThreshold = 10;  // Threshold for low stock notifications

    void updateStockWarning(const QString &message);  // Update warning message
};

#endif
*/
