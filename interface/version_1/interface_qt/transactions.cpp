#include "transactions.h"
#include<QSqlQuery>

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
