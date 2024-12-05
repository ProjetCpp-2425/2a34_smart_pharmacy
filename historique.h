#ifndef HISTORIQUE_H
#define HISTORIQUE_H

#include <QSqlQueryModel>
#include <QDateTime>
#include <QList>

struct StockHistory {
    QString action;  // 'update', 'insert', 'delete', etc.
    int code;
    QString nom;
    QString type;
    int quantiteOld;
    int quantiteNew;
    QDate dateExpirationOld;
    QDate dateExpirationNew;
    QString user;
    QDateTime dateAction;
};

extern QList<StockHistory> stockHistoryLog;  // Declaration of the history log to be used globally

class historique
{
public:
    void on_Historique_clicked(QSqlQueryModel* model);  // Modify to pass the model from outside
};

#endif // HISTORIQUE_H
