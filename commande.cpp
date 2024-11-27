#include "Commande.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QVariant>
#include <QSqlError>  // Pour utiliser QSqlError
#include <QMap>
#include <QString>
#include <QDate>
#include <QDebug>
#include <QLabel>
#include <QPushButton>



// Constructeur par défaut
Commande::Commande()
    : idCommande(0), nomArticle(""), quantite(0), prix(0.0), dateLivraison(QDate::currentDate()),status("Pending") {}


// Constructeur avec paramètres
Commande::Commande(int id, QString nom, int quantite, double prix, QDate livraison, QString status)
    : idCommande(id), nomArticle(nom), quantite(quantite), prix(prix), dateLivraison(livraison), status(status.isEmpty() ? "Pending" : status) {}


Commande::~Commande(){}


QString Commande::getStatus() const {
    return status;
}

void Commande::setStatus(const QString& newStatus) {
    status = newStatus;
}


bool Commande::ajouter() {
    QSqlQuery query;

    query.prepare("INSERT INTO Commandes (ID_COMMANDE, NOM_ARTICLE, QUANTITE, PRIX, DATE_LIVRAISON, STATUS) "
                  "VALUES (:id, :nom, :quantite, :prix, :dateLivraison, :status)");

    // Bind all the values correctly to the query placeholders
    query.bindValue(":id", idCommande);
    query.bindValue(":nom", nomArticle);
    query.bindValue(":quantite", quantite);
    query.bindValue(":prix", prix);
    query.bindValue(":dateLivraison", dateLivraison);
    query.bindValue(":status", status.isEmpty() ? "Pending" : status);  // Default to "Pending" if status is empty

    if (!query.exec()) {
        qDebug() << "Error inserting Commande: " << query.lastError().text();
        return false;
    }
    return true;
}




// supprimer
bool Commande::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM Commandes WHERE ID_Commande = :id");
    query.bindValue(":id", id);
    return query.exec();
}

//afficher
QSqlQueryModel* Commande::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Commandes");
    if (model->lastError().isValid()) {
        qDebug() << "Error fetching Commandes:" << model->lastError().text();
    }
    return model;
}

//modifier
bool Commande::modifier(int id) {
    QSqlQuery query;
    query.prepare("UPDATE Commandes SET NOM_ARTICLE = :nom, QUANTITE = :quantite, "
                  "PRIX = :prix, DATE_LIVRAISON = :livraison, STATUS = :status WHERE ID_Commande = :id");
    query.bindValue(":id", id);
    query.bindValue(":nom", nomArticle);
    query.bindValue(":quantite", quantite);
    query.bindValue(":prix", prix);
    query.bindValue(":livraison", dateLivraison);
    query.bindValue(":status", status);
    return query.exec();
}

//recherch

// Search by Date
QSqlQueryModel* Commande::rechercheParDate(const QString& DELIVERY_DATE) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    // Include the STATUS column in the SELECT statement
    query.prepare("SELECT ID_COMMANDE, NOM_ARTICLE, QUANTITE, PRIX, DATE_LIVRAISON, STATUS "
                  "FROM Commandes WHERE DATE_LIVRAISON = :DELIVERY_DATE");
    query.bindValue(":DELIVERY_DATE", DELIVERY_DATE);

    if (!query.exec()) {
        qDebug() << "Error executing search by date:" << query.lastError().text();
        return model;
    }

    model->setQuery(std::move(query));
    return model;
}

// Search by Price
QSqlQueryModel* Commande::rechercheParPrix(double price) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    // Include the STATUS column in the SELECT statement
    query.prepare("SELECT ID_COMMANDE, NOM_ARTICLE, QUANTITE, PRIX, DATE_LIVRAISON, STATUS "
                  "FROM Commandes WHERE PRIX = :price");
    query.bindValue(":price", price);

    if (!query.exec()) {
        qDebug() << "Error executing search by price:" << query.lastError().text();
        return model;
    }

    model->setQuery(std::move(query));
    return model;
}


// Search by ID
QSqlQueryModel* Commande::rechercheParID(int id) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    // Include the STATUS column in the SELECT statement
    query.prepare("SELECT ID_COMMANDE, NOM_ARTICLE, QUANTITE, PRIX, DATE_LIVRAISON, STATUS "
                  "FROM Commandes WHERE ID_COMMANDE = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Error executing search by ID:" << query.lastError().text();
        return model;
    }

    model->setQuery(std::move(query));
    return model;
}





//tri
QSqlQueryModel* Commande::triParColonne(const QString& columnName, bool ascending) {
    QString order = ascending ? "ASC" : "DESC";
    QSqlQuery query;
    query.prepare("SELECT * FROM Commandes ORDER BY " + columnName + " " + order);
    query.exec();

    QSqlQueryModel* model = new QSqlQueryModel;
    model->setQuery(std::move(query));  // Pass the query by move
    return model;
}

QSqlQueryModel* Commande::triParDate(bool ascending) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QString order = ascending ? "ASC" : "DESC";

    QSqlQuery query;
    query.prepare("SELECT * FROM Commandes ORDER BY DATE_LIVRAISON " + order);

    if (query.exec()) {
        model->setQuery(std::move(query));
    } else {
        qDebug() << "Error sorting by date:" << query.lastError().text();
    }

    return model;
}
// Sorting by price (ascending/descending)
QSqlQueryModel* Commande::triParPrix(bool ascending) {
    QSqlQueryModel* model = new QSqlQueryModel;
    QString order = ascending ? "ASC" : "DESC";

    QSqlQuery query;
    query.prepare("SELECT * FROM Commandes ORDER BY prix " + order);

    if (query.exec()) {
        model->setQuery(std::move(query));
    } else {
        qDebug() << "Error sorting by price:" << query.lastError().text();
    }

    return model;
}
// Sorting by quantity (ascending/descending)
QSqlQueryModel* Commande::triParQuantite(bool ascending) {
     QSqlQueryModel* model = new QSqlQueryModel;
    QString order = ascending ? "ASC" : "DESC";

    QSqlQuery query;
    query.prepare("SELECT * FROM Commandes ORDER BY quantite " + order);

    if (query.exec()) {
        model->setQuery(std::move(query));
    } else {
        qDebug() << "Error sorting by date:" << query.lastError().text();
    }

    return model;
}



//stat

void Commande::stat(QLabel *label) {
    qDebug() << "stat() function called.";

    QSqlQuery query;
    query.prepare("SELECT YEAR(DATE_LIVRAISON), MONTH(DATE_LIVRAISON), SUM(QUANTITE) "
                  "FROM Commandes "
                  "GROUP BY YEAR(DATE_LIVRAISON), MONTH(DATE_LIVRAISON) "
                  "ORDER BY YEAR(DATE_LIVRAISON) DESC, MONTH(DATE_LIVRAISON) DESC");

    if (!query.exec()) {
        qDebug() << "Query execution failed: " << query.lastError().text();
        return;
    }

    int totalCommandes = 0;
    QMap<QString, int> commandesParMois;

    // Process the query results
    while (query.next()) {
        int year = query.value(0).toInt();
        int month = query.value(1).toInt();
        int quantity = query.value(2).toInt();

        QString monthYear = QString("%1 %2").arg(month).arg(year);
        commandesParMois[monthYear] += quantity;
        totalCommandes += quantity;
    }

    // Generate statistics
    QString statResult;
    for (auto it = commandesParMois.cbegin(); it != commandesParMois.cend(); ++it) {
        QString monthYear = it.key();
        int quantity = it.value();
        double percentage = (static_cast<double>(quantity) / totalCommandes) * 100;
        statResult += QString("%1: %2%\n").arg(monthYear).arg(percentage, 0, 'f', 2);
    }

    qDebug() << "Stat results ready: " << statResult;

    // Display results in the label
    if (label) {
        label->setText(statResult);
        label->repaint();  // Ensure the label updates immediately
    } else {
        qDebug() << "Label is not valid for displaying results.";
    }
}

// metiers
void Commande::calculatePriorityAndUrgency()
{
    int priorityScore = 0;

    // Factor 1: Delivery Date (closer delivery date = higher priority)
    int daysUntilDelivery = QDate::currentDate().daysTo(dateLivraison);
    if (daysUntilDelivery <= 7) {
        priorityScore += 50;  // High priority if delivery is within 7 days
    } else if (daysUntilDelivery <= 14) {
        priorityScore += 30;  // Medium priority for delivery within 14 days
    } else {
        priorityScore += 10;  // Low priority for delivery beyond 14 days
    }

    // Factor 2: Order Quantity (larger orders = higher priority)
    if (quantite > 50) {
        priorityScore += 30;  // Larger orders get more priority
    } else if (quantite > 20) {
        priorityScore += 20;  // Medium-sized orders get some priority
    } else {
        priorityScore += 10;  // Smaller orders get lower priority
    }

    // Factor 3: VIP Status (VIP customers = higher priority)
    // Assuming you have a VIP status attribute, if not, you can add it or make it an argument
    if (status == "VIP") {  // Replace with actual VIP condition
        priorityScore += 20;  // VIP customers get additional priority
    }

    // Factor 4: Payment Status (paid orders = higher priority)
    if (status == "Paid") {  // Replace with actual paid status condition
        priorityScore += 20;  // Paid orders are more urgent
    }

    // Assign the calculated priority to the object
    priority = priorityScore;

    // Determine urgency based on the delivery date
    if (daysUntilDelivery <= 7) {
        urgencyLevel = "High";  // Urgent
    } else if (daysUntilDelivery <= 14) {
        urgencyLevel = "Medium";  // Moderate urgency
    } else {
        urgencyLevel = "Low";  // Low urgency
    }
}







