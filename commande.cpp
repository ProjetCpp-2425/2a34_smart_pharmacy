#include "commande.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QVariant>
#include <QSqlError>  // Pour utiliser QSqlError

// Constructeur par défaut
Commande::Commande()
    : idCommande(0), nomArticle(""), quantite(0), prix(0.0), dateLivraison(QDate::currentDate()) {}

// Constructeur avec paramètres
Commande::Commande(int id, QString nom, int quantite, double prix, QDate livraison)
    : idCommande(id), nomArticle(nom), quantite(quantite), prix(prix), dateLivraison(livraison) {}

bool Commande::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO commandes (ID_COMMANDE, NOM_ARTICLE, QUANTITE, PRIX, DATE_LIVRAISON) "
                  "VALUES (:id, :nom, :quantite, :prix, :livraison)");
    query.bindValue(":id", idCommande);
    query.bindValue(":nom", nomArticle);
    query.bindValue(":quantite", quantite);
    query.bindValue(":prix", prix);
    query.bindValue(":livraison", dateLivraison);
    return query.exec();
}

bool Commande::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM commandes WHERE ID_COMMANDE = :id");
    query.bindValue(":id", id);
    return query.exec();
}

QSqlQueryModel* Commande::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM commandes");
    if (model->lastError().isValid()) {
        qDebug() << "Error fetching commandes:" << model->lastError().text();
    }
    return model;
}

bool Commande::modifier(int id) {
    QSqlQuery query;
    query.prepare("UPDATE commandes SET NOM_ARTICLE = :nom, QUANTITE = :quantite, "
                  "PRIX = :prix, DATE_LIVRAISON = :livraison WHERE ID_COMMANDE = :id");
    query.bindValue(":id", id);
    query.bindValue(":nom", nomArticle);
    query.bindValue(":quantite", quantite);
    query.bindValue(":prix", prix);
    query.bindValue(":livraison", dateLivraison);
    return query.exec();
}
