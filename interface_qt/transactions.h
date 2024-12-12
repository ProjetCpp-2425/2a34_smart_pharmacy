#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDate>
#include<QString>
#include <QMap>



class transactions
{ private:
    int id_transaction;
    float total_amount;
    QString type;
    QString category;
    QString payment_method;
    QDate date_transaction;


public:
    //constructeurs
    transactions();
    transactions(int,float,QString,QString,QString,QDate);
    //gettters
    int getId_transaction(){return id_transaction;}
    float getTotal_amount(){return total_amount;}
    QString getType(){return type;}
    QString getCategory(){return category;}
    QString getPayment_method(){return payment_method;}
    QDate getDate(){return date_transaction;};
    //setters


    void setId_transaction(int id){this->id_transaction=id;}
    void setTotal_amount(float totalamount){this->total_amount=totalamount;}
    void setType(QString t){type=t;}
    void setCategory(QString c){category=c;}
    void setPayment_method(QString p){payment_method=p;}
    void setDate(const QDate &date);
    //fonctionnalites de bases
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel* rechercher(int id = 0, const QString& category = "", float total_amount = 0.0);
    QSqlQueryModel* trier(const QString& critere); // Ajoutez cette fonction pour trier les transactions


};

#endif // TRANSACTIONS_H
