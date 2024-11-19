#include "transactions.h"
#include<QSqlQuery>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>
#include <QPageSize>
#include<QDebug>

transactions::transactions(int id,float totalamount,QString type,QString category,QString paymentmethod,QDate date)
{
    this->id_transaction=id;
    this->total_amount=totalamount;
    this->type=type;
    this->category=category;
    this->payment_method=paymentmethod;
    this->date_transaction=date;

}
// transactions.cpp
transactions::transactions() {
    id_transaction = 0;
    total_amount = 0.0;
    type = "";
    category = "";
    payment_method = "";
    date_transaction = QDate::currentDate();
}
void transactions::setDate(const QDate &date) {
    date_transaction = date;  // Assurez-vous que `date_transaction` est un membre de la classe
}

bool transactions::ajouter()
{
    QSqlQuery query;
        QString res=QString::number(id_transaction);
        query.prepare("insert into transactions (ID_TRANSACTION, TOTAL_AMOUNT, TYPE, CATEGORY,PAYMENT_METHOD,DATE_TRANSACTION) "
                      "VALUES (:ID_TRANSACTION, :TOTAL_AMOUNT, :TYPE, :CATEGORY, :PAYMENT_METHOD, :DATE_TRANSACTION)");

        query.bindValue(":ID_TRANSACTION", res);
        query.bindValue(":TOTAL_AMOUNT", total_amount);
        query.bindValue(":TYPE", type);
        query.bindValue(":CATEGORY", category);
        query.bindValue(":PAYMENT_METHOD", payment_method);
        query.bindValue(":DATE_TRANSACTION", date_transaction);
        return query.exec();

}
QSqlQueryModel *transactions::afficher()   //AFFICHAGE
{
    QSqlQueryModel * model=new QSqlQueryModel();
            model->setQuery("select * from transactions");
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_TRANSACTION"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("TOTAL_AMOUNT"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("CATEGORY"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("PAYMENT_METHOD"));
            model->setHeaderData(5,Qt::Horizontal,QObject::tr("DATE_TRANSACTION"));

            return model;
}

bool transactions::supprimer(int id)
{
    QSqlQuery query;
        QString res=QString::number(id);
        query.prepare("DELETE FROM transactions WHERE ID_TRANSACTION = :id");
        query.bindValue(":id",res);
        return query.exec();
}
bool transactions::modifier(int id)
{
    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("UPDATE transactions SET TOTAL_AMOUNT = :total_amount, TYPE = :type, CATEGORY = :category, PAYMENT_METHOD = :payment_method, DATE_TRANSACTION = :date_transaction WHERE ID_TRANSACTION = :id");
    query.bindValue(":id", res);
    query.bindValue(":total_amount", total_amount);
    query.bindValue(":type", type);
    query.bindValue(":category", category);
    query.bindValue(":payment_method", payment_method);
    query.bindValue(":date_transaction", date_transaction);
    return query.exec();
}
QSqlQueryModel* transactions::rechercher(int id, const QString& category, float total_amount) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    QString queryString;

    // Priorité : ID > Category > Total Amount
    if (id > 0) { // Recherche par ID
        queryString = "SELECT * FROM transactions WHERE ID_TRANSACTION = :id";
        query.prepare(queryString);
        query.bindValue(":id", id);
    } else if (!category.isEmpty()) { // Recherche par catégorie
        queryString = "SELECT * FROM transactions WHERE CATEGORY LIKE :category";
        query.prepare(queryString);
        query.bindValue(":category", "%" + category + "%");
    } else if (total_amount > 0.0) { // Recherche par montant total
        queryString = "SELECT * FROM transactions WHERE TOTAL_AMOUNT = :total_amount";
        query.prepare(queryString);
        query.bindValue(":total_amount", total_amount);
    } else {
        // Si aucun critère n'est fourni, retourner tous les résultats
        queryString = "SELECT * FROM transactions";
        query.prepare(queryString);
    }

    query.exec();

    model->setQuery(std::move(query));
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_TRANSACTION"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TOTAL_AMOUNT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("CATEGORY"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PAYMENT_METHOD"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("DATE_TRANSACTION"));

    return model;
}
QSqlQueryModel* transactions::trier(const QString& critere) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QString queryString;

    // Tri selon le critère choisi
    if (critere == "ID") {
        queryString = "SELECT * FROM transactions ORDER BY ID_TRANSACTION";
    } else if (critere == "Total Amount") {
        queryString = "SELECT * FROM transactions ORDER BY TOTAL_AMOUNT";
    } else if (critere == "Date Transaction") {
        queryString = "SELECT * FROM transactions ORDER BY DATE_TRANSACTION";
    } else {
        queryString = "SELECT * FROM transactions"; // Si aucun critère, afficher tout
    }

    QSqlQuery query;
    query.prepare(queryString);
    query.exec();

    model->setQuery(std::move(query));
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_TRANSACTION"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TOTAL_AMOUNT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("CATEGORY"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PAYMENT_METHOD"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("DATE_TRANSACTION"));

    return model;
}

