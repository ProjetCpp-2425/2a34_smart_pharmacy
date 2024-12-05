#include <QDate>
#include "stock.h"
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QMessageBox>

stock::stock()
{
    code_stock = 0;
    quantity_stock = 0;
    nom_stock = "";
    type_stock = "";
    date_stock = QDate();
    date_expiration = QDate();
}

stock::stock(int code_stock, int quantity_stock, QString nom_stock, QString type_stock, QDate date_stock, QDate date_expiration)
{
    this->code_stock = code_stock;
    this->quantity_stock = quantity_stock;
    this->nom_stock = nom_stock;
    this->type_stock = type_stock;
    this->date_stock = date_stock;
    this->date_expiration = date_expiration;
}

int stock::getCode() const { return code_stock; }  // Updated to match getter method in stock.h
int stock::getQuantity() const { return quantity_stock; }
QString stock::getNom() const { return nom_stock; }
QString stock::getType() const { return type_stock; }
QDate stock::getDateStock() const { return date_stock; }  // Updated to match getter method in stock.h
QDate stock::getExpirationDate() const { return date_expiration; }  // Updated to match getter method in stock.h

void stock::setCode(int code_stock) { this->code_stock = code_stock; }  // Updated to match setter method in stock.h
void stock::setQuantity(int quantity_stock) { this->quantity_stock = quantity_stock; }
void stock::setNom(const QString &nom_stock) { this->nom_stock = nom_stock; }
void stock::setType(const QString &type_stock) { this->type_stock = type_stock; }
void stock::setDateStock(const QDate &date_stock) { this->date_stock = date_stock; }  // Updated to match setter method in stock.h
void stock::setExpirationDate(const QDate &date_expiration) { this->date_expiration = date_expiration; }  // Updated to match setter method in stock.h

bool stock::ajouter()
{
    if (code_stock <= 0 || quantity_stock <= 0 || nom_stock.isEmpty() || type_stock.isEmpty() ||
        !date_stock.isValid() || !date_expiration.isValid()) {
        qDebug() << "Error: All fields must be properly filled.";
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO MEDICAMENTS (CODE, NOM, TYPE, QUANTITE, DATE_EXPIRATION) "
                  "VALUES (:CODE, :NOM, :TYPE, :QUANTITE, :DATE_EXPIRATION)");

    query.bindValue(":CODE", code_stock);
    query.bindValue(":NOM", nom_stock);
    query.bindValue(":TYPE", type_stock);
    query.bindValue(":QUANTITE", quantity_stock);
    query.bindValue(":DATE_EXPIRATION", date_expiration);

    return query.exec();
}

QSqlQueryModel* stock::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM MEDICAMENTS");
    return model;
}

bool stock::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE MEDICAMENTS SET NOM = :NOM, TYPE = :TYPE, QUANTITE = :QUANTITE, DATE_EXPIRATION = :DATE_EXPIRATION "
                  "WHERE CODE = :CODE");

    query.bindValue(":CODE", code_stock);
    query.bindValue(":NOM", nom_stock);
    query.bindValue(":TYPE", type_stock);
    query.bindValue(":QUANTITE", quantity_stock);
    query.bindValue(":DATE_EXPIRATION", date_expiration);

    return query.exec();
}

bool stock::supprimer(int code_stock)
{
    QSqlQuery query;
    query.prepare("DELETE FROM MEDICAMENTS WHERE CODE = :CODE");
    query.bindValue(":CODE", code_stock);
    return query.exec();
}

QSqlQueryModel* stock::tristock(QString attribut)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    if (attribut == "CODE") model->setQuery("SELECT * FROM MEDICAMENTS ORDER BY CODE");
    else if (attribut == "NOM") model->setQuery("SELECT * FROM MEDICAMENTS ORDER BY NOM");
    else model->setQuery("SELECT * FROM MEDICAMENTS ORDER BY TYPE");
    return model;
}

QSqlQuery stock::searchMedicament(const QString &searchColumn, const QString &searchTerm)
{
    QSqlQuery query;

    // Prepare the search query with placeholders
    QString queryStr = QString("SELECT CODE, NOM, TYPE, QUANTITE, DATE_STOCK, DATE_EXPIRATION "
                               "FROM MEDICAMENTS WHERE LOWER(%1) LIKE LOWER(:searchTerm)").arg(searchColumn);
    qDebug() << "Executing query: " << queryStr; // Debugging the query to ensure it's correct

    // Prepare the query and bind search term
    query.prepare(queryStr);
    query.bindValue(":searchTerm", "%" + searchTerm + "%");

    if (!query.exec()) {
        qDebug() << "Query failed: " << query.lastError().text();
    }

    return query;
}

QSqlQueryModel* stock::historique() {
    QSqlQueryModel* model = new QSqlQueryModel();

    // Run the SQL query to fetch history data
    model->setQuery("SELECT * FROM STOCK_HISTORY ORDER BY CODE_H DESC"); // You can modify this query as needed

    // Check if the query executed successfully
    if (model->lastError().isValid()) {
        qDebug() << "Error fetching stock history: " << model->lastError().text();
        return nullptr;
    }

    return model;
}
