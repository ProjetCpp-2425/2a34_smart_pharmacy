#include "ordonnance.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMap>
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
#include <QFrame>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QVector>
#include <algorithm>
#include <QMap>

#include <QPrinter>
#include <QPdfWriter>
#include <QFileDialog>
#include <QPainter>
#include <QMessageBox>
#include <QFontDatabase>

#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include "whatsapp.h"

#include <random>
#include <cstdlib>
#include <ctime>
#include <QJsonArray>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->dateEdit_11->setDate(QDate::currentDate());
    ui->tableView_2->setModel(Etmp.afficher());
    ui->tableView_2->resizeColumnsToContents();
    QPixmap pix("C:/projetcpp/interface_qt/img/Nouveau dossier/aze.png");
    QPixmap pix9("C:/Users/USER/Downloads/qtqt6.7/interface_qt/interface_qt/img/Nouveau dossier/logo.png");
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

    stackedWidget = findChild<QStackedWidget*>("stackedWidget");

    connect(ui->pushButton_8, &QPushButton::clicked, this, &MainWindow::on_pushButton_8_clicked);
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
    connect(ui->aa33, &QPushButton::clicked, this, &::MainWindow::on_aa33_clicked);
    connect(ui->aa44, &QPushButton::clicked, this, &::MainWindow::on_aa44_clicked);
    connect(ui->aaa_2, &QPushButton::clicked, this, &MainWindow::on_aaa_2_clicked);    connect(ui->Send_Request, &QPushButton::clicked, this, &MainWindow::sendRequest);



    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(ui->tableView_2->model());
    proxyModel->setFilterKeyColumn(1);
    ui->tableView_2->setModel(proxyModel);

    showStatistics();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_8_clicked() {
    stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_10_clicked() {
    stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_12_clicked() {
    stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_pushButton_14_clicked() {
    stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_pushButton_35_clicked() {
    stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_pushButton_36_clicked() {
    stackedWidget->setCurrentIndex(10);
}

void MainWindow::on_pushButton_37_clicked() {
    stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_28_clicked() {
    stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_27_clicked() {
    stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_25_clicked() {
    stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_24_clicked() {
    stackedWidget->setCurrentIndex(4);
}


//----------------------------------------------ADD---------------------------------------------------


void MainWindow::on_addbutton1_clicked()
{
    proxyModel->sort(6, Qt::DescendingOrder);

    QString statu = ui->comboBox_2->currentText();
    QString nom = ui->lineEdit_nom->text().trimmed();
    QString prenom = ui->lineEdit_prenom->text().trimmed();
    QString med = ui->lineEdit_med->text().trimmed();
    QDate date_ord = ui->dateEdit_11->date();
    int cin = ui->lineEdit_cin->text().toInt();
    int tel = ui->lineEdit_tel->text().toInt();
    QString ordStr = ui->lineEdit_ord->text().trimmed();
    QDate dateActuelle = QDate::currentDate();


    QRegularExpression onlyLettersRegex("^[A-Za-z]+$");


    if (ordStr.contains(" ")) {
        QMessageBox::warning(this, "Invalid Prescription Number", "Prescription number should not contain spaces.");
        return;
    }
    if (ui->lineEdit_cin->text().length() == 0) {
        QMessageBox::warning(this, "Invalid Prescription Number", "Prescription Number should not be empty.");
        return;
    }
    if (ordStr.length() != 5) {
        QMessageBox::warning(this, "Invalid Prescription Number", "Prescription number should be exactly 5 digits.");
        return;
    }

    if (!onlyLettersRegex.match(nom).hasMatch()) {
        if (nom.contains(QRegularExpression("\\d"))) {
            QMessageBox::warning(this, "Invalid Name", "Name should not contain numbers.");
        } else if (nom.contains(" ")) {
            QMessageBox::warning(this, "Invalid Name", "Name should be a single word without spaces.");
        } else if (nom.contains(QRegularExpression("\\W"))) {
            QMessageBox::warning(this, "Invalid Name", "Name should not contain special characters or symbols.");
        } else {
            QMessageBox::warning(this, "Invalid Name", "Name should contain only alphabetic characters.");
        }
        return;
    }

    if (!onlyLettersRegex.match(prenom).hasMatch()) {
        if (prenom.contains(QRegularExpression("\\d"))) {
            QMessageBox::warning(this, "Invalid Last Name", "Last name should not contain numbers.");
        } else if (prenom.contains(" ")) {
            QMessageBox::warning(this, "Invalid Last Name", "Last name should be a single word without spaces.");
        } else if (prenom.contains(QRegularExpression("\\W"))) {
            QMessageBox::warning(this, "Invalid Last Name", "Last name should not contain special characters or symbols.");
        } else {
            QMessageBox::warning(this, "Invalid Last Name", "Last name should contain only alphabetic characters.");
        }
        return;
    }

    if (ui->lineEdit_cin->text().contains(QRegularExpression("[A-Za-z]"))) {
        QMessageBox::warning(this, "Invalid ID Number", "ID Number should not contain letters.");
        return;
    } else if (ui->lineEdit_cin->text().contains(QRegularExpression("\\W"))) {
        QMessageBox::warning(this, "Invalid ID Number", "ID Number should not contain symbols or special characters.");
        return;
    }

    if (ui->lineEdit_cin->text().contains(" ")) {
        QMessageBox::warning(this, "Invalid ID Number", "ID Number should not contain spaces.");
        return;
    }
    if (ui->lineEdit_cin->text().length() == 0) {
        QMessageBox::warning(this, "Invalid ID Number", "ID Number should not be empty.");
        return;
    }
    if (ui->lineEdit_cin->text().length() != 8) {
        QMessageBox::warning(this, "Invalid ID Number", "ID Number should be 8 digits.");
        return;
    }

    if (ui->lineEdit_tel->text().contains(QRegularExpression("[A-Za-z]"))) {
        QMessageBox::warning(this, "Invalid Phone Number", "Phone number should not contain letters.");
        return;
    } else if (ui->lineEdit_tel->text().contains(QRegularExpression("\\W"))) {
        QMessageBox::warning(this, "Invalid Phone Number", "Phone number should not contain symbols or special characters.");
        return;
    }

    if (ui->lineEdit_tel->text().contains(" ")) {
        QMessageBox::warning(this, "Invalid Phone Number", "Phone number should not contain spaces.");
        return;
    }
    if (ui->lineEdit_cin->text().length() == 0) {
        QMessageBox::warning(this, "Invalid Phone Number", "Phone Number should not be empty.");
        return;
    }
    if (ui->lineEdit_tel->text().length() != 8) {
        QMessageBox::warning(this, "Invalid Phone Number", "Phone number should be 8 digits.");
        return;
    }
    if (cin == tel) {
        QMessageBox::warning(this, "Input Error", "ID NUMBER and phone number should be different.");
        return;
    }

    if (ordStr.contains(QRegularExpression("[A-Za-z]"))) {
        QMessageBox::warning(this, "Invalid Prescription Number", "Prescription number should not contain letters.");
        return;
    } else if (ordStr.contains(QRegularExpression("\\W"))) {
        QMessageBox::warning(this, "Invalid Prescription Number", "Prescription number should not contain symbols or special characters.");
        return;
    }
    if (date_ord >= dateActuelle) {
        QMessageBox::warning(this, "Invalid Date", "The prescription date must be earlier than the current date.");
        return;
    }

    if (nom.isEmpty() || prenom.isEmpty() || med.isEmpty() || statu.isEmpty() || ordStr.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "All fields must be filled.");
        return;
    }
    int ord = ordStr.toInt();

    ordonnance E(nom, prenom, statu, med, date_ord, cin, tel, ord);
    bool test = E.ajouter();
    if (test) {
        ui->tableView_2->setModel(Etmp.afficher());
        QMessageBox::information(this, "Success", "Record added successfully.");
        showStatistics();
    } else {
        QMessageBox::critical(this, "Failed", "Prescription Number Already exists.");
    }
}




//----------------------------------------DELETE----------------------------------------------------------------






void MainWindow::on_deletebutton1_clicked()
{
    QModelIndexList selectedIndexes = ui->tableView_2->selectionModel()->selectedIndexes();
    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, QObject::tr("Selection Error"), QObject::tr("Please select a cell to delete."));
        return;
    }
    QModelIndex index = selectedIndexes.first();
    if (index.column() != 0) {
        QMessageBox::warning(this, QObject::tr("Selection Error"), QObject::tr("Please select a Prescription Number cell to delete."));
        return;
    }
    int row = index.row();
    int id = ui->tableView_2->model()->index(row, 0).data().toInt();
    bool test = Etmp.supprimer(id);
    if (test) {
        ui->tableView_2->setModel(Etmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("Success"),
                                 QObject::tr("Record deleted successfully."));
        showStatistics();
    } else {
        // Display an error message if deletion fails
        QMessageBox::critical(nullptr, QObject::tr("Error"),
                              QObject::tr("Failed to delete the record. Please check your data"));
    }
}




//-----------------------------------RETRIEVE------------------------------------------------------------



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
        QString status = Etmp.getstatu().toLower();

        if (status == "filled") {
            ui->comboBox_2->setCurrentText("Filled");
        } else if (status == "expired") {
            ui->comboBox_2->setCurrentText("Expired");
        } else if (status == "pending") {
            ui->comboBox_2->setCurrentText("Pending");
        }
        // Show success message only once
        return;  // Exit the function once data is successfully fetched
    }
}
//-------------------------------UPDATE--------------------------------------------------------------------------------



bool messageShown2 = false;

void MainWindow::on_update2Button_clicked()
{

    // Retrieve values
    QString statu = ui->comboBox_2->currentText();
    QString nom = ui->lineEdit_nom->text().trimmed();
    QString prenom = ui->lineEdit_prenom->text().trimmed();
    QString med = ui->lineEdit_med->text().trimmed();
    QDate date_ord = ui->dateEdit_11->date();
    int cin = ui->lineEdit_cin->text().toInt();
    int tel = ui->lineEdit_tel->text().toInt();
    QString ordStr = ui->lineEdit_ord->text().trimmed();
    QDate dateActuelle = QDate::currentDate();


    // Regular expressions
    QRegularExpression onlyLettersRegex("^[A-Za-z]+$"); // Only letters allowed

    // Validation for Prescription Number (ordStr)
    if (ordStr.contains(QRegularExpression("[A-Za-z]"))) {
        QMessageBox::warning(this, "Invalid Prescription Number", "Prescription number should not contain letters.");
        return;
    } else if (ordStr.contains(QRegularExpression("\\W"))) {  // Non-word characters like symbols or special characters
        QMessageBox::warning(this, "Invalid Prescription Number", "Prescription number should not contain symbols or special characters.");
        return;
    }

    if (ordStr.contains(" ")) {
        QMessageBox::warning(this, "Invalid Prescription Number", "Prescription number should not contain spaces.");
        return;
    }
    if (ordStr.length() == 0) {
        QMessageBox::warning(this, "Invalid Prescription Number", "Prescription Number should not be empty.");
        return;
    }
    if (ordStr.length() != 5) {
        QMessageBox::warning(this, "Invalid Prescription Number", "Prescription number should be exactly 5 digits.");
        return;
    }

    // Validation for Name (nom)
    if (!onlyLettersRegex.match(nom).hasMatch()) {
        if (nom.contains(QRegularExpression("\\d"))) {
            QMessageBox::warning(this, "Invalid Name", "Name should not contain numbers.");
        } else if (nom.contains(" ")) {
            QMessageBox::warning(this, "Invalid Name", "Name should be a single word without spaces.");
        } else if (nom.contains(QRegularExpression("\\W"))) {
            QMessageBox::warning(this, "Invalid Name", "Name should not contain special characters or symbols.");
        } else {
            QMessageBox::warning(this, "Invalid Name", "Name should contain only alphabetic characters.");
        }
        return;
    }

    // Validation for Last Name (prenom)
    if (!onlyLettersRegex.match(prenom).hasMatch()) {
        if (prenom.contains(QRegularExpression("\\d"))) {
            QMessageBox::warning(this, "Invalid Last Name", "Last name should not contain numbers.");
        } else if (prenom.contains(" ")) {
            QMessageBox::warning(this, "Invalid Last Name", "Last name should be a single word without spaces.");
        } else if (prenom.contains(QRegularExpression("\\W"))) {
            QMessageBox::warning(this, "Invalid Last Name", "Last name should not contain special characters or symbols.");
        } else {
            QMessageBox::warning(this, "Invalid Last Name", "Last name should contain only alphabetic characters.");
        }
        return;
    }

    // Validation for CIN
    if (ui->lineEdit_cin->text().contains(QRegularExpression("[A-Za-z]"))) {
        QMessageBox::warning(this, "Invalid CIN", "CIN should not contain letters.");
        return;
    } else if (ui->lineEdit_cin->text().contains(QRegularExpression("\\W")))
    {  // Non-word characters like symbols or special characters
        QMessageBox::warning(this, "Invalid ID Number", "ID Number should not contain symbols or special characters.");
        return;
    }

    if (ui->lineEdit_cin->text().contains(" ")) {
        QMessageBox::warning(this, "Invalid ID Number", "ID Number should not contain spaces.");
        return;
    }
    if (ui->lineEdit_cin->text().length() == 0) {
        QMessageBox::warning(this, "Invalid ID Number", "ID Number should not be empty.");
        return;
    }
    if (ui->lineEdit_cin->text().length() != 8) {
        QMessageBox::warning(this, "Invalid ID Number", "ID Number should be 8 digits.");
        return;
    }

    // Validation for Phone Number (tel)
    if (ui->lineEdit_tel->text().contains(QRegularExpression("[A-Za-z]"))) {
        QMessageBox::warning(this, "Invalid Phone Number", "Phone number should not contain letters.");
        return;
    } else if (ui->lineEdit_tel->text().contains(QRegularExpression("\\W"))) {  // Non-word characters like symbols or special characters
        QMessageBox::warning(this, "Invalid Phone Number", "Phone number should not contain symbols or special characters.");
        return;
    }

    if (ui->lineEdit_tel->text().contains(" ")) {
        QMessageBox::warning(this, "Invalid Phone Number", "Phone number should not contain spaces.");
        return;
    }
    if (ui->lineEdit_tel->text().length() == 0) {
        QMessageBox::warning(this, "Invalid Phone Number", "Phone Number should not be empty.");
        return;
    }
    if (ui->lineEdit_tel->text().length() != 8) {
        QMessageBox::warning(this, "Invalid Phone Number", "Phone number should be 8 digits.");
        return;
    }
    if (cin == tel) {
        QMessageBox::warning(this, "Input Error", "CIN and phone number should be different.");
        return;
    }

    // Date validation
    if (date_ord >= dateActuelle) {
        QMessageBox::warning(this, "Invalid Date", "The prescription date must be earlier than the current date.");
        return;
    }

    // Check if all fields are filled
    if (nom.isEmpty() || prenom.isEmpty() || med.isEmpty() || statu.isEmpty() || ordStr.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "All fields must be filled.");
        return;
    }

    int ord = ordStr.toInt();

    // Proceed with the update if all validations pass
    ordonnance E(nom, prenom, statu, med, date_ord, cin, tel, ord);

    bool test = E.update(ord);

    if (test) {
        ui->tableView_2->setModel(Etmp.afficher());
        showStatistics();
        QMessageBox::information(nullptr, QObject::tr("Update Successful"),
                                 QObject::tr("The record has been successfully updated.\nClick Cancel to exit."),
                                 QMessageBox::Cancel);
        messageShown2 = true;
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Update Failed"),
                              QObject::tr("Failed to update the record. Please ensure the record exists.\nClick Cancel to exit."),
                              QMessageBox::Cancel);
        messageShown2 = true;
    }
}




//--------------------RECHERCHE----------------------------------------------------------------------------------

void MainWindow::on_aa33_clicked() {
    QString inputCin = ui->lineEdit->text();  // Get CIN from lineEdit

    // Access the model directly from the table view
    QAbstractItemModel *model = ui->tableView_2->model();

    if (!model) {
        QMessageBox::critical(this, "Error", "Empty Database.");
        return;
    }

    // Check if input is empty; if so, show all rows and return
    if (inputCin.isEmpty()) {
        for (int row = 0; row < model->rowCount(); ++row) {
            ui->tableView_2->setRowHidden(row, false);  // Unhide all rows
        }
        QMessageBox::information(this, "Empty Search", "The search box is empty. Please enter a value to search.");

        return;
    }

    bool anyMatchFound = false;  // Flag to check if any match was found

    // Loop through each row and check the CIN, PRENOM, and NUMERO_TELEPHONE values
    for (int row = 0; row < model->rowCount(); ++row) {
        bool matchFound = false;

        // Check CIN in column 2
        QModelIndex cinIndex = model->index(row, 1);
        QString cinValue = model->data(cinIndex).toString();
        if (cinValue == inputCin) {
            matchFound = true;
        }

        // Check PRENOM in column 3
        QModelIndex prenomIndex = model->index(row, 2);
        QString prenomValue = model->data(prenomIndex).toString();
        if (prenomValue == inputCin) {
            matchFound = true;
        }

        // Check NUMERO_TELEPHONE in column 5
        QModelIndex numeroTelephoneIndex = model->index(row, 4);
        QString numeroTelephoneValue = model->data(numeroTelephoneIndex).toString();
        if (numeroTelephoneValue == inputCin) {
            matchFound = true;
        }

        // Show or hide the row based on matchFound
        ui->tableView_2->setRowHidden(row, !matchFound);

        // If any match is found, set anyMatchFound to true
        if (matchFound) {
            anyMatchFound = true;
        }
    }

    // Display a message if no matches were found
    if (!anyMatchFound) {
        QMessageBox::information(this, "No Matches", "No records found matching the entered value.");
    }
}


//---------------------------------TRI---------------------------------------------------------------------------




void MainWindow::on_aa44_clicked() {
    QString selectedValue = ui->comboBox4->currentText();  // Get the selected value from comboBox4

    // Access the original model of the table view
    QAbstractItemModel *model = ui->tableView_2->model();

    if (!model) {
        QMessageBox::critical(this, "Error", "No model found for tableView_2.");
        return;
    }

    // Create or access a QSortFilterProxyModel
    QSortFilterProxyModel *proxyModel = qobject_cast<QSortFilterProxyModel *>(ui->tableView_2->model());
    if (!proxyModel) {
        proxyModel = new QSortFilterProxyModel(this);
        proxyModel->setSourceModel(model);
        ui->tableView_2->setModel(proxyModel);
    }

    // Handle sorting based on the selected comboBox4 value
    if (selectedValue == "DEFAULT") {
        proxyModel->sort(-1);  // Reset sorting to the original order
    }
    else if (selectedValue == "STATUS") {
        proxyModel->sort(6, Qt::AscendingOrder);  // Sort column 7 (0-based index 6) alphabetically in ascending order
    }
    else if (selectedValue == "PRESCRIPTION DATE") {
        proxyModel->sort(5, Qt::DescendingOrder);  // Sort column 6 (0-based index 5) by date, latest to farthest
    }
    else if (selectedValue == "MEDECINE") {
        proxyModel->sort(7, Qt::AscendingOrder);  // Sort column 8 (0-based index 7) alphabetically in ascending order
    }
}

//----------------STATS----------------------------------------------------------



void MainWindow::showStatistics() {
    // Ensure there's a model to work with
    QAbstractItemModel *model = ui->tableView_2->model();

    if (!model) {
        QMessageBox::critical(this, "Error", "No model found for tableView_2.");
        return;
    }

    // Prepare data structures
    QMap<QString, int> statusCount;
    QMap<QString, int> medicineCount;

    // Populate the counts
    for (int row = 0; row < model->rowCount(); ++row) {
        // Count prescriptions by status
        QString status = model->data(model->index(row, 6)).toString();
        statusCount[status]++;

        // Count medicines
        QStringList medicines = model->data(model->index(row, 7)).toString().split(" ");
        for (const QString &medicine : medicines) {
            medicineCount[medicine]++;
        }
    }

    // Convert medicineCount to a list of pairs for sorting
    QVector<QPair<QString, int>> sortedMedicines;
    for (auto it = medicineCount.begin(); it != medicineCount.end(); ++it) {
        sortedMedicines.append(qMakePair(it.key(), it.value()));
    }

    // Sort by frequency (descending)
    std::sort(sortedMedicines.begin(), sortedMedicines.end(), [](const QPair<QString, int> &a, const QPair<QString, int> &b) {
        return a.second > b.second;
    });

    // Prepare top medicines for the chart
    QStringList topMedicines;
    QVector<int> topCounts;
    for (int i = 0; i < 3 && i < sortedMedicines.size(); ++i) {
        topMedicines << sortedMedicines[i].first;
        topCounts << sortedMedicines[i].second;
    }

    // Clear existing stats in frame66
    if (ui->frame66->layout() != nullptr) {
        QLayoutItem *child;
        while ((child = ui->frame66->layout()->takeAt(0)) != nullptr) {
            delete child->widget();  // Remove and delete widgets
            delete child;            // Also delete the layout item
        }
        delete ui->frame66->layout();
    }

    // Create the pie chart for "Prescriptions by Status"
    QPieSeries *statusSeries = new QPieSeries();
    int totalStatus = 0;
    for (auto it = statusCount.begin(); it != statusCount.end(); ++it) {
        statusSeries->append(it.key(), it.value());
        totalStatus += it.value();
    }

    // Show percentage labels for the pie chart
    for (auto slice : statusSeries->slices()) {
        double percentage = (slice->value() / totalStatus) * 100;
        slice->setLabel(QString("%1 (%2%)").arg(slice->label()).arg(percentage, 0, 'f', 1));
        slice->setLabelVisible(true);
    }

    QChart *statusChart = new QChart();
    statusChart->addSeries(statusSeries);
    statusChart->setTitle("Prescriptions by Status");

    QChartView *statusChartView = new QChartView(statusChart);
    statusChartView->setRenderHint(QPainter::Antialiasing);

    // Create the bar chart for "Top 3 Medicine Occurrences"
    QBarSet *medicineSet = new QBarSet("Medicine Name");
    for (int count : topCounts) {
        *medicineSet << count;
    }

    QBarSeries *medicineSeries = new QBarSeries();
    medicineSeries->append(medicineSet);

    QChart *medicineChart = new QChart();
    medicineChart->addSeries(medicineSeries);
    medicineChart->setTitle("Top 3 Medicines Sold");
    medicineChart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(topMedicines);
    medicineChart->addAxis(axisX, Qt::AlignBottom);
    medicineSeries->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, topCounts.isEmpty() ? 0 : topCounts[0] + 5);  // Add padding for labels
    medicineChart->addAxis(axisY, Qt::AlignLeft);
    medicineSeries->attachAxis(axisY);



    QChartView *medicineChartView = new QChartView(medicineChart);
    medicineChartView->setRenderHint(QPainter::Antialiasing);

    // Add the charts to frame66's layout
    QHBoxLayout *statsLayout = new QHBoxLayout();
    statsLayout->addWidget(statusChartView);
    statsLayout->addWidget(medicineChartView);
    ui->frame66->setLayout(statsLayout);
}


#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QMessageBox>

void MainWindow::on_aaa_2_clicked()
{
    QModelIndexList selectedIndexes = ui->tableView_2->selectionModel()->selectedIndexes();

    // Check if any row is selected and ensure the first column (Prescription Number) is selected
    if (!selectedIndexes.isEmpty() && selectedIndexes.first().column() == 0) {
        int prescriptionNumber = selectedIndexes.first().data().toInt(); // Retrieve prescription number

        // Retrieve the prescription data from the database
        ordonnance E;
        bool dataRetrieved = E.fetchData(prescriptionNumber);

        if (dataRetrieved) {
            // Open a file dialog for the user to choose where to save the PDF
            QString fileName = QFileDialog::getSaveFileName(this, "Save Prescription as PDF",
                                                            QString("Prescription_%1.pdf").arg(QString::number(E.getord())),
                                                            "PDF Files (*.pdf)");

            // Check if the user canceled the file dialog (fileName will be empty)
            if (fileName.isEmpty()) {
                return;  // Exit if no file was chosen
            }

            // Create the PDF file at the selected path
            QPdfWriter writer(fileName);
            writer.setPageSize(QPageSize::A4);  // Set the page size (A4)

            QPainter painter(&writer);
            painter.setFont(QFont("Arial", 12));  // Set the font size

            // Draw the logo in the top-left corner
            QImage logo("C:/Users/USER/Downloads/qtqt6.7/interface_qt/interface_qt/img/Nouveau dossier/logo.png");
            if (!logo.isNull()) {
                painter.drawImage(50, 50, logo.scaled(1000, 1000, Qt::KeepAspectRatio)); // Adjust size and position
            } else {
                QMessageBox::warning(this, "Logo Error", "Failed to load the logo image.");
            }

            // Title with underline
            int pageWidth = writer.width();
            QString title = "Prescription N° " + QString::number(E.getord());
            QFont titleFont("Arial", 14, QFont::Bold);
            titleFont.setUnderline(true);  // Add underline to the title
            painter.setFont(titleFont);

            // Calculate title position
            int titleWidth = painter.fontMetrics().horizontalAdvance(title);  // Title width for centering
            int titleXPos = (pageWidth - titleWidth) / 2;  // Center the title horizontally
            int yPos = 200;  // Vertical position for the title

            // Draw the title
            painter.drawText(titleXPos, yPos, title);
            yPos += 2 * 30;  // Add extra space after the title

            // Reset font for the details
            painter.setFont(QFont("Arial", 12));

            // Increase lineHeight for better spacing between lines
            int lineHeight = 300;

            // Prescription Number (line 1)
            yPos += lineHeight + 3000;
            painter.drawText(50, yPos, "Prescription Number: " + QString::number(E.getord()));
            yPos += lineHeight;

            // ID Number (line 2)
            painter.drawText(50, yPos, "ID Number: " + QString::number(E.getcin()));
            yPos += lineHeight;

            // Name (line 3)
            painter.drawText(50, yPos, "Name: " + E.getprenom());
            yPos += lineHeight;

            // Last Name (line 4)
            painter.drawText(50, yPos, "Last Name: " + E.getnom());
            yPos += lineHeight;

            // Phone Number (line 5)
            painter.drawText(50, yPos, "Phone Number: " + QString::number(E.gettel()));
            yPos += lineHeight;

            // Medication (line 6)
            painter.drawText(50, yPos, "Medication: " + E.getmed());
            yPos += lineHeight;

            // Date (line 7) - in dd/MM/yyyy format
            painter.drawText(50, yPos, "Date: " + E.getdate_ord().toString("dd/MM/yyyy"));
            yPos += lineHeight;

            // Status (line 8)
            painter.drawText(50, yPos, "Status: " + E.getstatu());
            yPos += lineHeight;

            // Finish the drawing
            painter.end();

            // Inform the user that the PDF has been created
            QMessageBox::information(this, "PDF Created", "The prescription details have been saved to the PDF.");
        } else {
            QMessageBox::warning(this, "Error", "Failed to retrieve prescription data.");
        }
    } else {
        QMessageBox::warning(this, "Selection Error", "Please select a valid prescription number in the first column.");
    }
}









void MainWindow::generatePDFBill(const ordonnance &ord)
{
    QString filePath = QFileDialog::getSaveFileName(this, "Save PDF", "", "*.pdf");
    if (filePath.isEmpty())
        return;

    QPdfWriter writer(filePath);
    writer.setPageSize(QPageSize::A4);
    QPainter painter(&writer);

    int yPosition = 100;

    painter.drawText(100, yPosition, "Prescription Bill");
    yPosition += 40;

    painter.drawText(100, yPosition, "Prescription Number: " + QString::number(ord.getord()));
    yPosition += 20;
    painter.drawText(100, yPosition, "Patient Name: " + ord.getnom());
    yPosition += 20;
    painter.drawText(100, yPosition, "Patient Last Name: " + ord.getprenom());
    yPosition += 20;
    painter.drawText(100, yPosition, "CIN: " + QString::number(ord.getcin()));
    yPosition += 20;
    painter.drawText(100, yPosition, "Telephone: " + QString::number(ord.gettel()));
    yPosition += 20;
    painter.drawText(100, yPosition, "Medicine: " + ord.getmed());
    yPosition += 20;
    painter.drawText(100, yPosition, "Status: " + ord.getstatu());
    yPosition += 20;
    painter.drawText(100, yPosition, "Date of Prescription: " + ord.getdate_ord().toString("dd/MM/yyyy"));

    painter.end();

    QMessageBox::information(this, "PDF Export", "PDF generated and saved successfully.");
}



// MainWindow.cpp
/*void MainWindow::on_pwhatsapp_clicked()
{
    QMessageBox::information(this, "Clicked", "Button Clicked!"); // Debugging message box
    OpenAIImageGenerator *imageWindow = new OpenAIImageGenerator(this);
    imageWindow->show();
}*/


void MainWindow::on_pwhatsapp_2_clicked()
{

    stackedWidget->setCurrentIndex(12);
    ui->quickWidget_MapView->setSource(QUrl(QStringLiteral("qrc:/map.qml")));
    ui->quickWidget_MapView->show();

     auto Obje =  ui->quickWidget_MapView->rootObject();


    connect(this,SIGNAL(setCenterPosition(QVariant, QVariant)),Obje,SLOT(setCenterPosition(QVariant, QVariant)));
    connect(this,SIGNAL(setLocationMarking(QVariant, QVariant)),Obje,SLOT(setLocationMarking(QVariant, QVariant)));

    emit setCenterPosition(36.898765,10.189379);
    emit setLocationMarking(36.898765,10.189379);

}
void MainWindow::on_chatbot_clicked()
{
       stackedWidget->setCurrentIndex(13);
}
void MainWindow::sendRequest()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QUrl url("https://open-ai21.p.rapidapi.com/conversationgpt35");

    QJsonObject payload;
    QJsonArray messages;
    QJsonObject message;
    message["role"] = "user";
    message["content"] = ui->Question->text();
    messages.append(message);
    payload["messages"] = messages;
    payload["web_access"] = false;
    payload["system_prompt"] = "";
    payload["temperature"] = 0.9;
    payload["top_k"] = 5;
    payload["top_p"] = 0.9;
    payload["max_tokens"] = 256;
    QJsonDocument doc(payload);
    QByteArray postData = doc.toJson();

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("X-RapidAPI-Key", "api_key");
    request.setRawHeader("X-RapidAPI-Host", "api_key");

    QNetworkReply *reply = manager->post(request, postData);
    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError)
        {
            QByteArray responseData = reply->readAll();
            qDebug() << responseData;

            QJsonDocument responseDoc = QJsonDocument::fromJson(responseData);
            QJsonObject responseObject = responseDoc.object();

            QString resultMessage = responseObject["result"].toString();
            QStringList words = resultMessage.split(' ');
            QString formattedMessage;
            int wordCount = 0;
            for (const QString &word : words) {
                formattedMessage += word + " ";
                wordCount++;
                if (wordCount == 10) {
                    formattedMessage += "\n";
                    wordCount = 0;
                }
            }

            ui->Reply->setText(formattedMessage.trimmed());
            ui->Question->clear();
        }
        else
        {
            qDebug() << "Error:" << reply->errorString();
            QMessageBox::critical(this, "Error", "Failed to send request: " + reply->errorString());
        }
        reply->deleteLater();
    });
}
