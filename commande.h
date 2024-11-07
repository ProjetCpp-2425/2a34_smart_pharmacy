#ifndef COMMANDE_H
#define COMMANDE_H

#include <QString>
#include <QDate>
#include <QSqlQueryModel>

class Commande {
private:
    int idCommande;
    QString nomArticle;
    int quantite;
    double prix;
    QDate dateLivraison;

public:
    Commande(); // Constructeur par défaut
    Commande(int id, QString nom, int quantite, double prix, QDate livraison);

    bool ajouter();   // Create
    bool supprimer(int id);  // Delete
    static QSqlQueryModel* afficher();  // Read
    bool modifier(int id);  // Update
};

#endif // COMMANDE_H
