#ifndef ORDONNANCE_H
#define ORDONNANCE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>

class ordonnanceData;

class ordonnance
{
    QString nom, prenom,statu,med;
    QDate date_ord;
    int cin,tel,ord,trans;
public:
    ordonnance();
    ordonnance(QString,QString,QString,QString,QDate,int,int,int);
    ~ordonnance();

    // Getters
    QString getnom() const { return nom; }
    QString getprenom() const { return prenom; }
    int getcin() const { return cin; }
    int gettel() const { return tel; }
    int getord() const { return ord; }
    QString getstatu() const { return statu; }
    QString getmed() const { return med; }
    QDate getdate_ord() const { return date_ord; }

    //Setters
    void setnom(QString n) { nom=n; }
    void setprenom(QString p) { prenom=p; }
    void setcin(int c) { cin=c; }
    void settel(int t) { tel=t; }
    void setord(int o) { ord=o; }
    void setstatu(QString s) { statu=s; }
    void setmed(QString m) { med=m; }
    void setdate_ord(QDate d) { date_ord=d; }


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool fetchData(int);
    bool update(int ord);
    bool retrieveDataByPrescriptionNumber(int prescriptionNumber);
    //QSharedDataPointer<ordonnanceData> data;
};



#endif // ORDONNANCE_H


