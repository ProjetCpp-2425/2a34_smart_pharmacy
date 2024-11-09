#include "ordonnance.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QFileDialog>
#include <QByteArray>
#include <QFile>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include <QDate>
#include <QString>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    ui->tableView_2->setModel(Etmp.afficher());
    ui->tableView_2->resizeColumnsToContents();
    QPixmap pix("C:/projetcpp/interface_qt/img/Nouveau dossier/aze.png");
    ui->pic1->setPixmap(pix);
    ui->pic1_2->setPixmap(pix);
    ui->pic1_4->setPixmap(pix);
    QPixmap pix2("C:/projetcpp/interface_qt/img/Nouveau dossier/stt.png");
       ui->label_64->setPixmap(pix2);
    QPixmap pix3("C:/projetcpp/interface_qt/img/Nouveau dossier/avc.png");
        ui->label_71->setPixmap(pix3);
    QPixmap pix4("C:/projetcpp/interface_qt/img/Nouveau dossier/stat.png");
         ui->label_30->setPixmap(pix4);
    QPixmap pix5("C:/projetcpp/interface_qt/img/Nouveau dossier/stat.png");
         ui->label_3->setPixmap(pix5);
    QPixmap pix6("C:/projetcpp/interface_qt/img/Nouveau dossier/mariem.jpeg");
         ui->label_56->setPixmap(pix6);
    QPixmap pix7("C:/projetcpp/interface_qt/img/Nouveau dossier/mariem1.jpeg");
         ui->label_62->setPixmap(pix7);
    QPixmap pix8("C:/projetcpp/interface_qt/img/Nouveau dossier/siwar.jpeg");
         ui->label_35->setPixmap(pix8);
         QPixmap pix9("C:/projetcpp/interface_qt/img/Nouveau dossier/hazem.jpeg");
              ui->label_34->setPixmap(pix9);


    // Initialize the stacked widget
    stackedWidget = findChild<QStackedWidget*>("stackedWidget");

    // Connect ajoutemp button to its slot
    connect(ui->pushButton_8, &QPushButton::clicked, this, &MainWindow::on_pushButton_8_clicked);


    // Connect salary button to its slot
    connect(ui->pushButton_10, &QPushButton::clicked, this, &MainWindow::on_pushButton_10_clicked);
    connect(ui->pushButton_12, &QPushButton::clicked, this, &MainWindow::on_pushButton_12_clicked);
    connect(ui->pushButton_14, &QPushButton::clicked, this, &MainWindow::on_pushButton_14_clicked);
    connect(ui->pushButton_35, &QPushButton::clicked, this, &MainWindow::on_pushButton_35_clicked);
    connect(ui->pushButton_36, &QPushButton::clicked, this, &MainWindow::on_pushButton_36_clicked);
    connect(ui->pushButton_37, &QPushButton::clicked, this, &MainWindow::on_pushButton_37_clicked);
    connect(ui->pushButton_28, &QPushButton::clicked, this, &MainWindow::on_pushButton_28_clicked);
    connect(ui->pushButton_27, &QPushButton::clicked, this, &MainWindow::on_pushButton_27_clicked);
    connect(ui->pushButton_25, &QPushButton::clicked, this, &MainWindow::on_pushButton_25_clicked);
    connect(ui->pushButton_24, &QPushButton::clicked, this, &MainWindow::on_pushButton_24_clicked);
    connect(ui->updateButton, &QPushButton::clicked, this, &::MainWindow::on_updateButton_clicked);
    connect(ui->update2Button, &QPushButton::clicked, this, &::MainWindow::on_update2Button_clicked);

        /*ui->setupUi(this);
        ui->tableView_2->setModel(Etmp.afficher());
        ui->tableView_2->resizeColumnsToContents();*/

}

MainWindow::~MainWindow()
{
    delete ui;
}

// Slot for ajoutemp button (pushButton_8)
void MainWindow::on_pushButton_8_clicked() {
    stackedWidget->setCurrentIndex(1);  // Assuming 'a1' is the second page (index 1)
}

// Slot for salary button (pushButton_10)
void MainWindow::on_pushButton_10_clicked() {
    stackedWidget->setCurrentIndex(5);  // Assuming 'a1_1' is the third page (index 2)
}
void MainWindow::on_pushButton_12_clicked() {
    stackedWidget->setCurrentIndex(11);  // Assuming 'a1_1' is the third page (index 2)
}
void MainWindow::on_pushButton_14_clicked() {
    stackedWidget->setCurrentIndex(8);  // Assuming 'a1_1' is the third page (index 2)
}
void MainWindow::on_pushButton_35_clicked() {
    stackedWidget->setCurrentIndex(9);  // Assuming 'a1_1' is the third page (index 2)
}
void MainWindow::on_pushButton_36_clicked() {
    stackedWidget->setCurrentIndex(10);  // Assuming 'a1_1' is the third page (index 2)
}
void MainWindow::on_pushButton_37_clicked() {
    stackedWidget->setCurrentIndex(2);  // Assuming 'a1_1' is the third page (index 2)
}
void MainWindow::on_pushButton_28_clicked() {
    stackedWidget->setCurrentIndex(0);  // Assuming 'a1_1' is the third page (index 2)
}
void MainWindow::on_pushButton_27_clicked() {
    stackedWidget->setCurrentIndex(7);  // Assuming 'a1_1' is the third page (index 2)
}
void MainWindow::on_pushButton_25_clicked() {
    stackedWidget->setCurrentIndex(3);  // Assuming 'a1_1' is the third page (index 2)
}
void MainWindow::on_pushButton_24_clicked() {
    stackedWidget->setCurrentIndex(4);  // Assuming 'a1_1' is the third page (index 2)


}


//---------------AJOUTER---------------------------------------------------



void MainWindow::on_addbutton1_clicked()
{
    // Récupération des informations saisies dans les 3 champs
    QString statu = ui->comboBox_2->currentText();
    QString nom=ui->lineEdit_nom->text().trimmed();
    QString prenom=ui->lineEdit_prenom->text().trimmed();
    QString med=ui->lineEdit_med->text().trimmed();

    QDate date_ord = ui->dateEdit_11->date();
    //QString date_ord = selectedDate.toString("yyyy-MM-dd");

    int cin=ui->lineEdit_cin->text().toInt();
    int tel=ui->lineEdit_tel->text().toInt();
    int ord=ui->lineEdit_ord->text().toInt();

    QDate dateActuelle = QDate::currentDate();            // Récupère la date actuelle

    if (date_ord >= dateActuelle) {
        QMessageBox::warning(this, "Date invalide", "La date d'ordonnance doit être antérieure à la date actuelle.");
        return;  // Quitte la fonction si la date est invalide
    }
    QRegularExpression singleWordRegex("^[^\\s]+$");  // Matches any string without whitespace

    if (!singleWordRegex.match(nom).hasMatch() ) {
        QMessageBox::warning(this, "Invalid Input", "Name should contain only one word.");
        return;
    }
    if (!singleWordRegex.match(prenom).hasMatch()) {
        QMessageBox::warning(this, "Invalid Input", "Name should contain only one word.");
        return;
    }
    if (prenom.isEmpty() ||nom.isEmpty() || med.isEmpty() ||statu.isEmpty()) {

        QMessageBox::warning(this, "Input Error", "All fields must be filled.");
        return;
    }
    if (tel < 10000000 || tel > 99999999) {
            QMessageBox::warning(nullptr, "Input Error", "Please enter a valid 8-digit phone number.");
            return;
        }
    if (cin < 10000000 || cin > 99999999) {
            QMessageBox::warning(nullptr, "Input Error", "Please enter a valid 8-digit ID number.");
            return;
        }
    if (ord < 10000 || ord > 99999) {
            QMessageBox::warning(nullptr, "Input Error", "Please enter a valid 5-digit Prescription number.");
            return;
        }

    ordonnance E(nom,prenom,statu,med,date_ord,cin,tel,ord); // instancier un objet de la classe étudiant

    bool test=E.ajouter(); // Insérer l'objet étudiant instancié dans la table étudiant
                           // et récupérer la valeur de retour de query.exec()

    if(test) // Si requête exécutée => QMessageBox::information
    {
        ui->tableView_2->setModel(Etmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué\n""Click Cancel to exit."), QMessageBox::Cancel);
        return;
    }
    else // Si requête non exécutée => QMessageBox::critical
    {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Ajout non effectué.\n""Click Cancel to exit."), QMessageBox::Cancel);
        return;
    }
}
/*MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget_2->setModel(Etmp.afficher());
}*/
void MainWindow::on_deletebutton1_clicked()
{
    QModelIndexList selectedIndexes = ui->tableView_2->selectionModel()->selectedIndexes();
    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, QObject::tr("Selection Error"), QObject::tr("Please select a cell to delete."));
        return;
    }
    QModelIndex index = selectedIndexes.first();
    if (index.column() != 0) {
        QMessageBox::warning(this, QObject::tr("Selection Error"), QObject::tr("Please select a NUMERO_ORDONNANCE cell to delete."));
        return;
    }
    int row = index.row();
    int id = ui->tableView_2->model()->index(row, 0).data().toInt();
    bool test = Etmp.supprimer(id);
    if (test) {
        ui->tableView_2->setModel(Etmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("Success"),
                                 QObject::tr("Record deleted successfully."));
    } else {
        // Display an error message if deletion fails
        QMessageBox::critical(nullptr, QObject::tr("Error"),
                              QObject::tr("Failed to delete the record. Please check your data"));
    }
}




/*void MainWindow::on_deletebutton1_clicked()
{
    int id = ui->lineEdit_ord->text().toInt();
    bool test = Etmp.supprimer(id);

    if (test) {
        ui->tableView_2->setModel(Etmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Suppression effectuée"));
    } else {
        // Display the error message if deletion failed
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                              QObject::tr("Suppression non effectuée. "
                                          "Veuillez vérifier l'identifiant."));
    }
}*/
//-----------------------------------------------------------------------------------------------
void MainWindow::on_updateButton_clicked() {
    QModelIndexList selectedIndexes = ui->tableView_2->selectionModel()->selectedIndexes();

        // Ensure at least one cell in the first column is selected
        if (selectedIndexes.isEmpty()) {
            QMessageBox::warning(this, QObject::tr("Selection Error"), QObject::tr("Please select a cell to delete."));
            return;
        }

        // Get the first selected index (assuming it's from the first column)
        QModelIndex index = selectedIndexes.first();

        // Make sure the selected cell is from the first column (ID column)
        if (index.column() != 0) {
            QMessageBox::warning(this, QObject::tr("Selection Error"), QObject::tr("Please select a cell from the NUMERO_ORDONNANCE column to delete."));
            return;
        }

        // Retrieve the id from the selected row and column (first column)
        int row = index.row();  // Get the row index of the selected cell
        int ord = ui->tableView_2->model()->index(row, 0).data().toInt();
        stackedWidget->setCurrentIndex(9);
    //int ord = ui->lineEdit_ord->text().toInt();

    // Create an instance of ordonnance or use an existing one
    ordonnance Etmp;

    // Attempt to fetch the data for the given ord
    if (Etmp.fetchData(ord)) {
            // Record found: fill form fields with retrieved data
            ui->lineEdit_nom->setText(Etmp.getnom());
            ui->lineEdit_ord->setText(QString::number(Etmp.getord()));
            ui->lineEdit_prenom->setText(Etmp.getprenom());
            ui->lineEdit_med->setText(Etmp.getmed());
            ui->dateEdit_11->setDate(Etmp.getdate_ord());  // Assuming dateEdit_dateOrd is a QDateEdit
            ui->lineEdit_cin->setText(QString::number(Etmp.getcin()));
            ui->lineEdit_tel->setText(QString::number(Etmp.gettel()));

            // Show success message only once


            return;  // Exit the function once data is successfully fetched
        }

}
/*void MainWindow::on_update2Button_clicked() {
    // Get the current values from the UI fields
    int ord = ui->lineEdit_ord->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();
    QString statu = ui->comboBox_2->currentText();
    QString med = ui->lineEdit_med->text();
    QDate dateOrd = ui->dateEdit_11->date();
    int cin = ui->lineEdit_cin->text().toInt();
    int tel = ui->lineEdit_tel->text().toInt();

    // Check if any value has changed
    if (nom != originalNom || prenom != originalPrenom || statu != originalStatu ||
        med != originalMed || dateOrd != originalDateOrd || cin != originalCin || tel != originalTel) {

        // If changes are detected, update the database
        ordonnance Etmp;
        Etmp.setnom(nom);
        Etmp.setprenom(prenom);
        Etmp.setstatu(statu);
        Etmp.setmed(med);
        Etmp.setdate_ord(dateOrd);
        Etmp.setcin(cin);
        Etmp.settel(tel);

        bool updateSuccess = Etmp.update(ord);  // Using ord as the primary key for update

        if (updateSuccess) {
            QMessageBox::information(this, "Update Successful", "The record has been updated.");
        } else {
            QMessageBox::critical(this, "Update Failed", "Failed to update the record. Please try again.");
        }
    } else {
        // If no changes, show an error message
        QMessageBox::warning(this, "No Changes", "No changes were made to the record.");
    }
}*/



/*void MainWindow::on_update2Button_clicked() {
    // Get the current values from the UI fields
    int ord = ui->lineEdit_ord->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();
    QString statu = ui->comboBox_2->currentText();
    QString med = ui->lineEdit_med->text();
    QDate date_ord = ui->dateEdit_11->date();
    int cin = ui->lineEdit_cin->text().toInt();
    int tel = ui->lineEdit_tel->text().toInt();

    // Check if any value has changed
    if (nom != originalNom || prenom != originalPrenom || statu != originalStatu ||
        med != originalMed || date_ord != originalDate_ord || cin != originalCin || tel != originalTel) {

        // If changes are detected, update the database
        ordonnance Etmp;
        Etmp.setnom(nom);
        Etmp.setprenom(prenom);
        Etmp.setstatu(statu);
        Etmp.setmed(med);
        Etmp.setdate_ord(date_ord);
        Etmp.setcin(cin);
        Etmp.settel(tel);

        bool updateSuccess = Etmp.update(ord);  // Using ord as the primary key for update

        if (updateSuccess) {
            QMessageBox::information(this, "Update Successful", "The record has been updated.");
        } else {
            QMessageBox::critical(this, "Update Failed", "Failed to update the record. Please try again.");
        }
    } else {
        // If no changes, show an error message
        QMessageBox::warning(this, "No Changes", "No changes were made to the record.");
    }
}*/
/*void MainWindow::on_update2Button_clicked() {
    // Retrieve primary key and other fields from the UI
    int ord = ui->lineEdit_ord->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();
    QString statu = ui->comboBox_2->currentText();
    QString med = ui->lineEdit_med->text();
    QDate dateOrd = ui->dateEdit_11->date();
    int cin = ui->lineEdit_cin->text().toInt();
    int tel = ui->lineEdit_tel->text().toInt();

        ordonnance Etmp;
        Etmp.setnom(nom);
        Etmp.setprenom(prenom);
        Etmp.setstatu(statu);
        Etmp.setmed(med);
        Etmp.setdate_ord(dateOrd);
        Etmp.setcin(cin);
        Etmp.settel(tel);

        // Attempt to update the record in the database
        bool updateSuccess = Etmp.update(ord);
        if (updateSuccess) {
            QMessageBox::information(this, "Update Successful", "The record has been updated.");
        } else {
            QMessageBox::critical(this, "Update Failed", "Failed to update the record. Record may not exist.");
        }
    }*/
bool messageShown2 = false;
void MainWindow::on_update2Button_clicked()
{
    if (messageShown2) {
            return; // Prevent the message from being shown again
        }
    // Retrieve values
    QString statu = ui->comboBox_2->currentText();
    QString nom = ui->lineEdit_nom->text().trimmed();
    QString prenom = ui->lineEdit_prenom->text().trimmed();
    QString med = ui->lineEdit_med->text().trimmed();
    QDate date_ord = ui->dateEdit_11->date();
    int cin = ui->lineEdit_cin->text().toInt();
    int tel = ui->lineEdit_tel->text().toInt();
    int ord = ui->lineEdit_ord->text().toInt();

    // Debug: Print values to verify they are correct
    qDebug() << "Values to update:"
             << "ORD:" << ord
             << "CIN:" << cin
             << "Nom:" << nom
             << "Prenom:" << prenom
             << "Tel:" << tel
             << "Date:" << date_ord
             << "Status:" << statu
             << "Medicament:" << med;

    ordonnance E(nom, prenom, statu, med, date_ord, cin, tel, ord);

    bool test = E.update(ord);

    if (test) {
        ui->tableView_2->setModel(Etmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("Update Successful"),
                                 QObject::tr("The record has been successfully updated.\nClick Cancel to exit."),
                                 QMessageBox::Cancel);messageShown = true;
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Update Failed"),
                              QObject::tr("Failed to update the record. Please ensure the record exists.\nClick Cancel to exit."),
                              QMessageBox::Cancel);messageShown = true;
    }
}

/*MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget_2->setModel(Etmp.afficher());
}*/
