#include "ordonnance.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDate>
#include <QSqlRecord>
#include <QString>

class ordonnanceData : public QSharedData
{
public:

};

bool ordonnance::ajouter()
{
    QSqlQuery query;

    //trans=1;//rand()%90000+10000;
    // prepare() prend la requête en paramètre pour la préparer à l'exécution.
    query.prepare("INSERT INTO ORDONNANCE (NUMERO_ORDONNANCE, CIN, PRENOM, NOM, NUMERO_TELEPHONE, DATE_ORDONNANCE, STATUS, MEDICAMMENT) VALUES (:NUMERO_ORDONNANCE, :CIN, :PRENOM, :NOM, :NUMERO_TELEPHONE, :DATE_ORDONNANCE, :STATUS, :MEDICAMMENT)");

    // Création des variables liées

    query.bindValue(":CIN", cin);
    query.bindValue(":NOM", nom);
    query.bindValue(":PRENOM", prenom);
    query.bindValue(":NUMERO_TELEPHONE", tel);
    query.bindValue(":NUMERO_ORDONNANCE", ord);
    query.bindValue(":STATUS", statu);
    query.bindValue(":MEDICAMMENT", med);
    query.bindValue(":DATE_ORDONNANCE", date_ord);
    //query.bindValue(":ID_TRANSACTION", trans);

    return query.exec(); // exec() envoie la requête pour l'exécuter

}


ordonnance::ordonnance(QString nom, QString prenom, QString statu, QString med, QDate date_ord, int cin, int tel, int ord)
    : nom(nom), prenom(prenom), statu(statu), med(med), date_ord(date_ord), cin(cin), tel(tel), ord(ord)
{

}


QSqlQueryModel * ordonnance::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from ORDONNANCE INFO");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMERO_ORDONNANCE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUMERO_TELEPHONE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("DATE_ORDONNANCE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("STATUS"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("MEDICAMMENT"));
    return model;
}


ordonnance::ordonnance()
{
    date_ord = QDate::currentDate();
    nom="";
    prenom="";
    statu="";
    med="";
    cin=0;
    tel=0;
    ord=0;

}


ordonnance::~ordonnance()
{

}

bool ordonnance::supprimer(int id) {
    QSqlQuery query;
    QString res = QString::number(id);

    query.prepare("DELETE FROM ORDONNANCE WHERE NUMERO_ORDONNANCE = :NUMERO_ORDONNANCE");
    query.bindValue(":NUMERO_ORDONNANCE", res);

    if (!query.exec()) {
        qDebug() << "Error deleting record:" << query.lastError().text();  // Log the error message
        return false;
    }

    // Check if any rows were affected
    if (query.numRowsAffected() == 0) {
        qDebug() << "No record with this ID was found.";
        return false;
    }

    return true;
}

bool ordonnance::fetchData(int id) {
    QSqlQuery query;
    query.prepare("SELECT * FROM ORDONNANCE WHERE NUMERO_ORDONNANCE = :NUMERO_ORDONNANCE");
    query.bindValue(":NUMERO_ORDONNANCE", id);

    if (!query.exec()) {
        qDebug() << "Error fetching record:" << query.lastError().text();
        return false;
    }

    if (query.next()) {  // Check if a record is found
        // Assuming your class has member variables for each column
        nom = query.value("NOM").toString();
        ord = query.value("NUMERO_ORDONNANCE").toInt();
        prenom = query.value("PRENOM").toString();
        statu = query.value("STATUS").toString();
        med = query.value("MEDICAMMENT").toString();
        date_ord = query.value("DATE_ORDONNANCE").toDate();
        cin = query.value("CIN").toInt();
        tel = query.value("NUMERO_TELEPHONE").toInt();

        return true;  // Record found
    } else {
        return false;  // No record found
    }
}


//-------------------------------UPDATE--------------------------------------------------------------------------------


bool ordonnance::update(int ord)
{
    QSqlQuery query;

    // Prepare the SQL statement with individual column updates and a WHERE clause
    query.prepare("UPDATE ORDONNANCE SET CIN = :CIN, NOM = :NOM, PRENOM = :PRENOM, "
                  "NUMERO_TELEPHONE = :NUMERO_TELEPHONE, DATE_ORDONNANCE = :DATE_ORDONNANCE, "
                  "STATUS = :STATUS, MEDICAMMENT = :MEDICAMMENT "
                  "WHERE NUMERO_ORDONNANCE = :NUMERO_ORDONNANCE");

    // Bind values to the placeholders
    query.bindValue(":CIN", cin);
    query.bindValue(":NOM", nom);
    query.bindValue(":PRENOM", prenom);
    query.bindValue(":NUMERO_TELEPHONE", tel);
    query.bindValue(":DATE_ORDONNANCE", date_ord); // Ensure date_ord is QDate and stored in compatible format
    query.bindValue(":STATUS", statu);
    query.bindValue(":MEDICAMMENT", med);
    query.bindValue(":NUMERO_ORDONNANCE", ord); // Primary key in WHERE clause

    if (!query.exec()) {
        qDebug() << "Update failed:" << query.lastError().text(); // For debugging
        return false;
    }

    return true; // Return true if the update was successful
}

bool ordonnance::retrieveDataByPrescriptionNumber(int prescriptionNumber)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM ORDONNANCE WHERE NUMERO_ORDONNANCE = :NUMERO_ORDONNANCE");
    query.bindValue(":UMERO_ORDONNANCE", prescriptionNumber);

    if (query.exec() && query.next()) {
        // Assuming columns: prescription_number, nom, prenom, cin, tel, med, status, date_ord
        this->ord = query.value(0).toInt();
        this->nom = query.value(1).toString();
        this->prenom = query.value(2).toString();
        this->cin = query.value(3).toInt();
        this->tel = query.value(4).toInt();
        this->med = query.value(5).toString();
        this->statu = query.value(6).toString();
        this->date_ord = query.value(7).toDate();
        return true;
    }
    return false;
}

