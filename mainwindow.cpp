#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>
#include "commande.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

// Display commandes in the table
void MainWindow::on_pushButton_49_clicked() {
    afficherCommandesDansTable();
}

void MainWindow::afficherCommandesDansTable() {
    Commande commande(0, "", 0, 0.0, QDate::currentDate());
    QSqlQueryModel* model = commande.afficher();

    ui->tableWidget->setRowCount(model->rowCount());
    ui->tableWidget->setColumnCount(model->columnCount());

    // Set column headers
    ui->tableWidget->setHorizontalHeaderLabels({"ID Commande", "Nom Article", "Quantité", "Prix", "Date de Livraison"});

    for (int row = 0; row < model->rowCount(); ++row) {
        for (int col = 0; col < model->columnCount(); ++col) {
            QString data = model->index(row, col).data().toString();
            ui->tableWidget->setItem(row, col, new QTableWidgetItem(data));
        }
    }
}

// Add or update a commande
void MainWindow::on_pushButton_2_clicked() {
    // Get input values from UI
    int id = ui->lineEdit_43->text().toInt();
    QString nomArticle = ui->lineEdit_42->text();
    int quantite = ui->lineEdit_48->text().toInt();
    double prix = ui->lineEdit_47->text().toDouble();
    QDate dateLivraison = ui->dateEdit->date();

    if (nomArticle.isEmpty() || quantite <= 0 || prix <= 0) {
        QMessageBox::warning(this, "Input Error", "Please ensure all fields are filled correctly.");
        return;
    }

    // Create a Commande object with these values
    Commande commande(id, nomArticle, quantite, prix, dateLivraison);

    // Check if the commande already exists in the database
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM commandes WHERE ID_COMMANDE = :id");
    query.bindValue(":id", id);
    if (!query.exec()) {
        QMessageBox::warning(this, "Database Error", "Failed to check commande existence.");
        return;
    }

    query.next();
    bool exists = query.value(0).toInt() > 0;

    // If the commande exists, update it; otherwise, add it
    if (exists) {
        if (commande.modifier(id)) {
            QMessageBox::information(this, "Update Commande", "Commande updated successfully.");
        } else {
            QMessageBox::warning(this, "Update Commande", "Failed to update commande.");
        }
    } else {
        if (commande.ajouter()) {
            QMessageBox::information(this, "Add Commande", "Commande added successfully.");
        } else {
            QMessageBox::warning(this, "Add Commande", "Failed to add commande.");
        }
    }

    // Refresh display after adding/updating
    afficherCommandesDansTable();
}

// Delete a commande
void MainWindow::on_pushButton_50_clicked() {
    int id = ui->lineEdit_43->text().toInt();

    Commande commande(0, "", 0, 0.0, QDate::currentDate());
    if (commande.supprimer(id)) {
        QMessageBox::information(this, "Suppression", "La commande a été supprimée avec succès.");
        afficherCommandesDansTable();
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de la suppression de la commande.");
    }
}

// Additional slot implementations
void MainWindow::on_pushButton_3_clicked() {
    QMessageBox::information(this, "Information", "Succès");
}

void MainWindow::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);  // Avoid warning for unused parameter
    // No custom painting needed
}
