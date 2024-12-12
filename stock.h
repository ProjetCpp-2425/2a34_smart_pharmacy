#ifndef STOCK_H
#define STOCK_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QList>  // If you want to store a list of history logs


class stock
{
private:
    int code_stock, quantity_stock;
    QString nom_stock, type_stock;
    QDate date_stock ;
    double temperature;  // Added temperature field

public:
    // Constructors
    stock();
    stock(int code_stock, int quantity_stock, QString nom_stock, QString type_stock, QDate date_stock, double temperature);

    // Getter methods
    int getCode() const;
    int getQuantity() const;
    QString getNom() const;
    QString getType() const;
    QDate getDateStock() const;
    QDate getExpirationDate() const;
    double getTemperature() const;  // Added getter for temperature

    // Setter methods
    void setCode(int);
    void setQuantity(int);
    void setNom(const QString &);
    void setType(const QString &);
    void setDateStock(const QDate &);
    void setExpirationDate(const QDate &);
    void setTemperature(double temperature);  // Added setter for temperature

    // Other methods
    void on_tri_clicked();
    void on_PDF_clicked();
    bool ajouter();
    void checkLowStockNotification();
    QSqlQueryModel* afficher();
    bool modifier();
    bool supprimer(int);
    QSqlQueryModel* tristock(QString attribut);
    QSqlQuery searchMedicament(const QString &searchColumn, const QString &searchTerm);
    QSqlQueryModel* display();
    QSqlQueryModel* historique();
};

#endif // STOCK_H
