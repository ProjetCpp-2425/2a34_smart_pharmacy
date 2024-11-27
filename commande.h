#ifndef COMMANDE_H
#define COMMANDE_H

#include <QString>
#include <QDate>
#include <QSqlQueryModel>
#include <QMap>
#include <QLabel>


class Commande {
private:
    int idCommande;
    QString nomArticle;
    int quantite;
    double prix;
    QDate dateLivraison;
      QString status;

    void displayStatistics();

public:
    Commande(); // Constructeur par défaut
    Commande(int id, QString nom, int quantite, double prix, QDate livraison, QString status = "Pending" );
    ~Commande();

    int priority;  // Store priority score
    QString urgencyLevel;  // Store urgency level (e.g., High, Medium, Low)

    int getId() const { return idCommande; }
    QString getNomArticle() const { return nomArticle; }
    int getQuantite() const { return quantite; }


    // Methods to calculate priority and urgency
    void calculatePriorityAndUrgency();


    bool ajouter();   // Create
    bool supprimer(int id);  // Delete
    static QSqlQueryModel* afficher();  // Read
    bool modifier(int id);  // Update
    void stat(QLabel* label);    // stat

    QString getStatus() const;             // Getter for status
    void setStatus(const QString& status); // Setter for status



    QSqlQueryModel* triParDate(bool ascending = true); // tri
    QSqlQueryModel* triParPrix(bool ascending = true); // tri
    QSqlQueryModel* triParQuantite(bool ascending = true); // tri
    QSqlQueryModel* triParColonne(const QString& columnName, bool ascending);
    QSqlQueryModel* chercherParDate(const QDate& date) ;

    static QSqlQueryModel* rechercheParDate(const QString& date);
    static QSqlQueryModel* rechercheParPrix(double price);
    static QSqlQueryModel* rechercheParID(int id);


    // Generalized sorting method



    /*bool updateStatus(int id, const QString& newStatus); // This is already correct*/

    QMap<QDate, int> statistiquescommandesParDate(); // Statistics of commandes by delivery date
bool recherche(const QVariant &value, const QString &field);  // Add this function declaration in the commande class

};

#endif // COMMANDE_H
