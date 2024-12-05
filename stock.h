#ifndef STOCK_H
#define STOCK_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class stock
{
private:
    int code_stock, quantity_stock;
    QString nom_stock, type_stock;
    QDate date_stock, date_expiration; // Added date_expiration as a private member

public:
    stock();
    stock(int code_stock, int quantity_stock, QString nom_stock, QString type_stock, QDate date_stock, QDate date_expiration);

    // Getter methods
    int getCode() const;  // Getters should be named consistently (e.g., getCode instead of codestock)
    int getQuantity() const;
    QString getNom() const;
    QString getType() const;
    QDate getDateStock() const; // Getter for date_stock
    QDate getExpirationDate() const; // Getter for date_expiration

    // Setter methods
    void setCode(int);  // Setters should follow a consistent naming scheme
    void setQuantity(int);
    void setNom(const QString &);
    void setType(const QString &);
    void setDateStock(const QDate &); // Setter for date_stock
    void setExpirationDate(const QDate &); // Setter for date_expiration

    // Other methods
    void on_tri_clicked();
    void on_PDF_clicked();
    bool ajouter();
    void checkLowStockNotification();
    QSqlQueryModel* afficher();
    bool modifier();
    bool supprimer(int);
    QSqlQueryModel * tristock(QString attribut);
    QSqlQuery searchMedicament(const QString &searchColumn, const QString &searchTerm);

    QSqlQueryModel* historique();
};

#endif // STOCK_H
