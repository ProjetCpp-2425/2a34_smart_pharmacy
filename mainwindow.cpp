#include "ordonnance.h"
#include "mainwindow.h"
#include <QPixmap>
#include <QMessageBox>
#include <QRegularExpression>
#include <QPdfWriter>
#include <QPainter>
#include <QTableWidgetItem>
#include <QFileDialog>
#include <QTableWidgetItem>
#include <QDebug>

#include <QtCharts/QValueAxis>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>

#include <QMessageBox>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>



#include <algorithm>
#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <utility>
using std::int8_t;
using std::uint8_t;
using std::size_t;
using std::vector;



#include <QStandardItemModel>
#include <QStandardItem>

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QSqlDatabase>
#include <QSerialPort>
#include <QSerialPortInfo>



///////////////////
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QPieSlice>
#include <QLayoutItem>
#include <QLayout>
#include <QtCharts>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QRandomGenerator>
#include "ui_mainwindow.h"
#include"transactions.h"
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

#include <cstdlib>
#include <ctime>
#include <QJsonArray>


//////STAT
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QChart>

/////////////calender
#include <QPushButton>
#include <QCalendarWidget>
#include <QDate>
#include <QTableView>
#include <QSqlTableModel>
#include <QVBoxLayout>
#include <QDialog>
#include <QTextCharFormat>
#include <QPalette>

#include <QTextCharFormat>
#include <QBrush>
#include <QColor>
#include <QDate>
/////////sms
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QHttpMultiPart>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QUrl>
#include <QLineEdit>  // Pour utiliser les QLineEdit
#include <QPushButton>  // Pour utiliser le QPushButton
#include <QDebug>  // Pour le débogage, si nécessaire
#include <QString>  // Pour utiliser QString
#include <QVariant>  // Pour utiliser QVariant



#include "arduino_ha.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadTableDataFromDatabase();
    ui->dateEdit_11->setDate(QDate::currentDate());
    ui->tableView_2->setModel(Etmp.afficher());
    afficherDescription(ui->tableView_ad);
    // Initialize the stacked widget
    stackedWidget = findChild<QStackedWidget*>("stackedWidget");
    /*int ret = arduino.connect_arduino(); // Launch connection to Arduino
    switch (ret) {
    case (0):
        qDebug() << "Arduino is available and connected to: " << arduino.getarduino_port_name();
        break;
    case (1):
        qDebug() << "Arduino is available but not connected to: " << arduino.getarduino_port_name();
        break;
    case (-1):
        qDebug() << "Arduino is not available";
        break;
    }
    QObject::connect(arduino.getserial(), SIGNAL(readyRead()), this, SLOT(update_label()));
    connect(&timer, &QTimer::timeout, this, &MainWindow::readFromArduino);
    timer.start(100);  // Lire toutes les 100 ms*/
    // Launch update_label slot upon receiving the readyRead signal (data reception).
    //ui->tableView_ad->setModel(Etmp.afficher_map());
    ui->tableView_2->resizeColumnsToContents();
    QPixmap pix("C:/projetcpp/interface_qt/img/Nouveau dossier/aze.png");
    QPixmap pix9("C:/Users/USER/Downloads/qtqt6.7/interface_qt/interface_qt/img/Nouveau dossier/logo.png");
    ui->pic1->setPixmap(pix);
    ui->pic1_2->setPixmap(pix);
    QPixmap pix2("C:/projetcpp/interface_qt/img/Nouveau dossier/stt.png");
    ui->label_64->setPixmap(pix2);
    QPixmap pix3("C:/projetcpp/interface_qt/img/Nouveau dossier/avc.png");
    ui->label_71->setPixmap(pix3);
    QPixmap pix4("C:/projetcpp/interface_qt/img/Nouveau dossier/stat.png");
    ui->label_30->setPixmap(pix4);
    QPixmap pix5("C:/projetcpp/interface_qt/img/Nouveau dossier/stat.png");
    ui->label_3->setPixmap(pix5);
    QPixmap pix6("C:/projetcpp/interface_qt/img/Nouveau dossier/mariem.jpeg");
    //ui->label_56->setPixmap(pix6);
    QPixmap pix7("C:/projetcpp/interface_qt/img/Nouveau dossier/mariem1.jpeg");
    //ui->label_62->setPixmap(pix7);
    QPixmap pix8("C:/projetcpp/interface_qt/img/Nouveau dossier/siwar.jpeg");
    ui->label_35->setPixmap(pix8);

    stackedWidget = findChild<QStackedWidget*>("stackedWidget");

    ui->tableView->setModel(Ttmp.afficher());

    // Initialize the stacked widget
    stackedWidget = findChild<QStackedWidget*>("stackedWidget");

    // Connect ajoutemp button to its slot
    connect(ui->pushButton_8, &QPushButton::clicked, this, &MainWindow::on_pushButton_8_clicked);
        // Connect modify button to its slot


    connect(ui->modif_trans, &QPushButton::clicked, this, &MainWindow::on_modif_trans_clicked);
    // Connexion du QComboBox pour trier les transactions
    connect(ui->comboBox_triertrans, SIGNAL(currentIndexChanged(int)), this, SLOT(on_comboBox_triertrans_currentIndexChanged(int)));
    // Connecter le bouton pour afficher le calendrier


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
    connect(ui->aaa_2, &QPushButton::clicked, this, &MainWindow::on_aaa_2_clicked);
    connect(ui->Send_Request, &QPushButton::clicked, this, &MainWindow::sendRequest);
    connect(ui->adresse, &QPushButton::clicked, this, &MainWindow::on_adresseButton_clicked);
    //connect(ui->lcd, &QPushButton::clicked, this, &MainWindow::on_lcdButton_clicked);


    // Connecter le signal clicked() du QCalendarWidget à la méthode
    connect(ui->calendarWidget, &QCalendarWidget::clicked, this, &MainWindow::onCalendarDateClicked);

    // Remplir le calendrier avec les transactions
    populateCalendarWithTransactions();




    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(ui->tableView_2->model());
    proxyModel->setFilterKeyColumn(1);
    ui->tableView_2->setModel(proxyModel);

    showStatistics();

    //arduino = new Arduino();  // Création de l'objet Arduino
    /*int ret = arduino.connect_arduino(); // Launch connection to Arduino
    switch (ret) {
    case (0):
        qDebug() << "Arduino is available and connected to: " << arduino.getarduino_port_name();
        break;
    case (1):
        qDebug() << "Arduino is available but not connected to: " << arduino.getarduino_port_name();
        break;
    case (-1):
        qDebug() << "Arduino is not available";
        break;
    }
    arduino.connect_arduino(); // Connexion à l'Arduino

    // Configurez le timer pour lire périodiquement les données
    QObject::connect(arduino.getserial(), SIGNAL(readyRead()), this, SLOT(update_label()));
    connect(&timer, &QTimer::timeout, this, &MainWindow::readFromArduino);
    timer.start(100);  // Lire toutes les 100 ms*/





    ///aziz

    // Connect add button to slot
    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::on_addButton_clicked);
    // Assuming your UI setup is in the MainWindow constructor or setup function

    // Connect the addStaffButton click to the addStaff method
    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::addStaff);

    connect(ui->pushButton_29, &QPushButton::clicked, this, &MainWindow::exportTableToPDF);

    // Connect the search button to the search function
        connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::on_pushButton_4_clicked);
        // Inside your main window constructor or appropriate setup function

        connect(ui->comboBox_3, SIGNAL(currentIndexChanged(int)), this, SLOT(sortTable(int)));
        // In your MainWindow constructor
        connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(sortTable(int)));
      /*  int ret=A.connect_arduino(); // lancer la connexion à arduino
                    switch(ret){
                    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
                        break;
                    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
                       break;
                    case(-1):qDebug() << "arduino is not available";
                    }
        QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(input())); */


}


void MainWindow:: afficherDescription(QTableView* tableView)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT DESCRIPTION FROM COMMANDES");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ADRESSES"));

    tableView->setModel(model);
}





MainWindow::~MainWindow()
{
    delete ui;
    arduino.close_arduino(); // Ensure Arduino connection is closed on exit
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
void MainWindow::on_adresseButton_clicked()
{
    // Ensure a row is selected
    QModelIndexList selection = ui->tableView_ad->selectionModel()->selectedRows();
    if (selection.isEmpty()) {
        QMessageBox::warning(this, "No Selection", "Please select a row in the table.");
        return;
    }

    // Get the selected row's index
    QModelIndex index = selection.first();

    // Assuming the coordinates are in column 3
    QString coords = ui->tableView_ad->model()->data(ui->tableView_ad->model()->index(index.row(), 0)).toString();

    // Split the coordinates into latitude and longitude
    QStringList latLng = coords.split(",");
      if (latLng.size() != 2) {
        QMessageBox::warning(this, "Invalid Data", "The selected row does not contain valid coordinates.");
        return;
    }

    double latitude = latLng[0].trimmed().toDouble();
    double longitude = latLng[1].trimmed().toDouble();

    // Emit the signal to update the map
    emit setLocationMarking(latitude, longitude);
}

void MainWindow::on_add_transaction_clicked()
{ // Récupération des informations saisies dans les champs
    int id=ui->lineEdit_idtrans->text().toInt();
    float total_amount=ui->lineEdit_totamount->text().toFloat();
    QString type=ui->lineEdit_type->text();
    QString payment_method=ui->lineEdit_payment->text();
    QString category=ui->lineEdit_category->text();
    QDate date_transaction=ui->dateEdit_date->date();

    transactions T(id,total_amount,type,category,payment_method,date_transaction);
    bool test=T.ajouter();

    if(test)
    {    //refresh
        ui->tableView->setModel(Ttmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),QObject::tr("Ajout effectué\n""Click Cancel to exit."),
                                 QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr , QObject::tr("Not OK"),QObject::tr("Ajout non effectuer.\n""Click Cancel to exit."), QMessageBox::Cancel);}


}


void MainWindow::on_pushButton_delete_clicked()
{
    int id=ui->edit_iddelete->text().toInt();
    bool test=Ttmp.supprimer(id);
    if(test)
    {   //refresh
        ui->tableView->setModel(Ttmp.afficher());

        QMessageBox::information(nullptr, QObject::tr("OK"),QObject::tr("Suppression effectuée\n""Click Cancel to exit."),
                                 QMessageBox::Cancel);
    }
    else{
        QMessageBox::critical(nullptr , QObject::tr("Not OK"),QObject::tr("Suppression non effectuer.\n""Click Cancel to exit."), QMessageBox::Cancel);}

}




void MainWindow::on_modif_trans_clicked()
{
    // Récupération des informations saisies dans les champs pour modification
    int id = ui->lineEdit_idtrans->text().toInt();
    float total_amount = ui->lineEdit_totamount->text().toFloat();
    QString type = ui->lineEdit_type->text();
    QString category = ui->lineEdit_category->text();
    QString payment_method = ui->lineEdit_payment->text();
    QDate date_transaction = ui->dateEdit_date->date();

    // Créer un objet temporaire pour mettre à jour la transaction
    transactions T;
    T.setId_transaction(id);
    T.setTotal_amount(total_amount);
    T.setType(type);
    T.setCategory(category);
    T.setPayment_method(payment_method);
    T.setDate(date_transaction);

    // Appel de la fonction de modification
    bool test = T.modifier(id);

    if (test) {
        // Refresh
        ui->tableView->setModel(Ttmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("Modification effectuée\nClick Cancel to exit."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"), QObject::tr("Modification non effectuée.\nClick Cancel to exit."), QMessageBox::Cancel);
    }
}


void MainWindow::on_pushButton_donesearch_clicked()
{
    QString searchText = ui->edit_search->text(); // Texte saisi par l'utilisateur

    // Vérification des critères
    bool isIdValid = false;
    bool isTotalAmountValid = false;

    int id = searchText.toInt(&isIdValid); // Conversion en int
    float totalAmount = searchText.toFloat(&isTotalAmountValid); // Conversion en float

    if (isIdValid && id > 0) {
        // Recherche par ID
        ui->tableView->setModel(Ttmp.rechercher(id, "", 0.0));
    } else if (!searchText.isEmpty() && !isTotalAmountValid) {
        // Recherche par catégorie (si ce n'est pas un float)
        ui->tableView->setModel(Ttmp.rechercher(0, searchText, 0.0));
    } else if (isTotalAmountValid && totalAmount > 0.0) {
        // Recherche par montant total
        ui->tableView->setModel(Ttmp.rechercher(0, "", totalAmount));
    } else {
        QMessageBox::warning(this, "Recherche invalide", "Veuillez saisir un critère de recherche valide (ID, Catégorie ou Montant total).");
    }
}




void MainWindow::on_comboBox_triertrans_currentIndexChanged(int index)

{       Q_UNUSED(index);
    // Récupération du critère sélectionné dans le QComboBox
    QString critere = ui->comboBox_triertrans->currentText();

    // Appel de la fonction trier de la classe transactions
    ui->tableView->setModel(Ttmp.trier(critere));  // Ttmp est l'objet de la classe transactions
}
//////////////////PDF////////////////

void MainWindow::on_pushButton_exporterpdf_clicked()
{ // Vérifier si une transaction est sélectionnée dans le tableView
    QItemSelectionModel *selection = ui->tableView->selectionModel();
    if (!selection->hasSelection()) {
        QMessageBox::warning(this, "Exportation PDF", "Veuillez sélectionner une transaction dans le tableau.");
        return;
    }

    // Récupérer l'ID de la transaction sélectionnée
    QModelIndex index = selection->currentIndex();
    int id = index.sibling(index.row(), 0).data().toInt(); // Supposons que l'ID est dans la 1ère colonne

    // Préparer la requête pour récupérer les détails de la transaction
    QSqlQuery query;
    query.prepare("SELECT ID_TRANSACTION, TOTAL_AMOUNT, TYPE, CATEGORY, PAYMENT_METHOD, DATE_TRANSACTION FROM transactions WHERE ID_TRANSACTION = :id");
    query.bindValue(":id", id);

    if (!query.exec() || !query.next()) {
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer les détails de la transaction sélectionnée.");
        return;
    }

    // Récupérer les données de la transaction
    int transactionId = query.value(0).toInt();
    float totalAmount = query.value(1).toFloat();
    QString type = query.value(2).toString();
    QString category = query.value(3).toString();
    QString paymentMethod = query.value(4).toString();
    QDate dateTransaction = query.value(5).toDate();

    // Définir le chemin où le PDF sera enregistré
    QString currentPath = QDir::currentPath();
    QString pdfPath = currentPath + QString("/PDFS/transaction_%1.pdf").arg(transactionId);

    // Créer le dossier "PDFS" s'il n'existe pas
    QDir dir(currentPath + "/PDFS");
    if (!dir.exists()) {
        dir.mkpath(".");
    }

    // Initialiser QPdfWriter
    QPdfWriter pdf(pdfPath);
    pdf.setPageSize(QPageSize(QPageSize::A4));
    pdf.setPageMargins(QMargins(30, 30, 30, 30));

    QPainter painter(&pdf);

    // Ajouter un titre au document
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 18, QFont::Bold));
    painter.drawText(QRectF(0, 0, pdf.width(), 1000), Qt::AlignCenter, "Description de la Transaction");

    // Ajouter les détails de la transaction
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 12));

    int y = 1500; // Position verticale de départ
    int lineHeight = 400;

    painter.drawText(100, y, QString("ID de la transaction : %1").arg(transactionId)); y += lineHeight;
    painter.drawText(100, y, QString("Montant total : %1 TND").arg(totalAmount)); y += lineHeight;
    painter.drawText(100, y, QString("Type : %1").arg(type)); y += lineHeight;
    painter.drawText(100, y, QString("Catégorie : %1").arg(category)); y += lineHeight;
    painter.drawText(100, y, QString("Méthode de paiement : %1").arg(paymentMethod)); y += lineHeight;
    painter.drawText(100, y, QString("Date : %1").arg(dateTransaction.toString("dd/MM/yyyy"))); y += lineHeight;

    // Terminer le dessin
    painter.end();

    // Afficher un message pour l'utilisateur
    int response = QMessageBox::question(
        this, "Génération PDF",
        "<PDF enregistré>... Voulez-vous ouvrir le fichier PDF ?",
        QMessageBox::Yes | QMessageBox::No);

    if (response == QMessageBox::Yes) {
        QDesktopServices::openUrl(QUrl::fromLocalFile(pdfPath));
    }

}
////////////////////////////////////statistiques////////////////////////////////////
////////////////////////
/////////////////////////////////////

void MainWindow::on_pushButton_statistics_clicked()
{
    // Reuse or create the layout
    QVBoxLayout *frameLayout = qobject_cast<QVBoxLayout*>(ui->frameStatistics->layout());
    if (!frameLayout) {
        frameLayout = new QVBoxLayout(ui->frameStatistics);
        ui->frameStatistics->setLayout(frameLayout);
    } else {
        QLayoutItem *child;
        while ((child = frameLayout->takeAt(0)) != nullptr) {
            delete child->widget();  // Delete the widget
            delete child;            // Delete the layout item
        }
    }

    // Create pie chart for payment methods
    QPieSeries *paymentMethodSeries = new QPieSeries();
    QSqlQuery query;
    query.exec("SELECT COUNT(*) FROM transactions");
    query.next();
    int totalTransactions = query.value(0).toInt();

    query.prepare("SELECT PAYMENT_METHOD, COUNT(*) FROM transactions GROUP BY PAYMENT_METHOD");
    query.exec();

    while (query.next()) {
        QString paymentMethod = query.value(0).toString();
        int count = query.value(1).toInt();
        double percentage = (static_cast<double>(count) / totalTransactions) * 100;
        paymentMethodSeries->append(
            QString("%1 (%2%)").arg(paymentMethod).arg(QString::number(percentage, 'f', 2)),
            count);
    }

    QChart *paymentMethodChart = new QChart();
    paymentMethodChart->addSeries(paymentMethodSeries);
    paymentMethodChart->setTitle("Transactions by Payment Method (in %)");
    QChartView *paymentMethodChartView = new QChartView(paymentMethodChart);
    paymentMethodChartView->setRenderHint(QPainter::Antialiasing);
    paymentMethodChartView->setMinimumHeight(200);
    paymentMethodChartView->setMaximumHeight(250);

    // Create bar chart for transaction types
    QBarSeries *transactionTypeSeries = new QBarSeries();
    QBarSet *incomeSet = new QBarSet("Income");
    QBarSet *expenseSet = new QBarSet("Expense");

    query.prepare("SELECT TYPE, COUNT(*) FROM transactions GROUP BY TYPE");
    query.exec();

    while (query.next()) {
        QString type = query.value(0).toString();
        int count = query.value(1).toInt();
        double percentage = (static_cast<double>(count) / totalTransactions) * 100;
        if (type == "income") {
            *incomeSet << percentage;
        } else if (type == "expense") {
            *expenseSet << percentage;
        }
    }

    transactionTypeSeries->append(incomeSet);
    transactionTypeSeries->append(expenseSet);

    QChart *transactionTypeChart = new QChart();
    transactionTypeChart->addSeries(transactionTypeSeries);
    transactionTypeChart->setTitle("Percentage of Transactions by Type");
    transactionTypeChart->createDefaultAxes();
    transactionTypeChart->axes(Qt::Vertical).first()->setTitleText("Percentage (%)");
    QChartView *transactionTypeChartView = new QChartView(transactionTypeChart);
    transactionTypeChartView->setRenderHint(QPainter::Antialiasing);
    transactionTypeChartView->setMinimumHeight(250);

    // Add charts to the layout
    frameLayout->addWidget(paymentMethodChartView);
    frameLayout->addSpacing(10);
    frameLayout->addWidget(transactionTypeChartView);
}


////////////////////////////////////////////////

////////////////////////SMS///////////

void MainWindow::on_pushButton_envoyer_clicked()
{
    // Récupérer le numéro de téléphone et le message des QLineEdit
    QString toPhoneNumber = ui->lineEdit_NUMBER->text().trimmed();
    QString message = ui->lineEdit_MESSAGE->text().trimmed();

    // Assurez-vous que les deux champs sont remplis
    if (toPhoneNumber.isEmpty() || message.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Veuillez entrer un numéro de téléphone et un message.");
        return;
    }

    // Appeler la fonction sendSms pour envoyer le SMS
    sendSms(toPhoneNumber, message);
}

void MainWindow::sendSms(const QString& toPhoneNumber, const QString& message)
{
    // Identifiants Twilio - vérifiez que ces valeurs sont correctes
    const QString accountSid = "";  // Remplacez par votre SID Twilio
    const QString authToken = "";    // Remplacez par votre Auth Token Twilio
    const QString fromPhoneNumber = "+12029359133";  // Remplacez par votre numéro Twilio

    // URL de l'API
    QUrl apiUrl("https://api.twilio.com/2010-04-01/Accounts/" + accountSid + "/Messages.json");

    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    QNetworkRequest request(apiUrl);

    // Authentification de base
    QString authValue = "Basic " + QString(QByteArray(QString("%1:%2").arg(accountSid).arg(authToken).toUtf8()).toBase64());
    request.setRawHeader("Authorization", authValue.toUtf8());

    // Préparer les données multipart pour la requête
    QHttpMultiPart* multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

    // Partie pour le numéro de téléphone du destinataire
    QHttpPart toPart;
    toPart.setHeader(QNetworkRequest::ContentDispositionHeader, "form-data; name=\"To\"");
    toPart.setBody(toPhoneNumber.toUtf8());

    // Partie pour le numéro de téléphone de l'expéditeur
    QHttpPart fromPart;
    fromPart.setHeader(QNetworkRequest::ContentDispositionHeader, "form-data; name=\"From\"");
    fromPart.setBody(fromPhoneNumber.toUtf8());

    // Partie pour le message
    QHttpPart bodyPart;
    bodyPart.setHeader(QNetworkRequest::ContentDispositionHeader, "form-data; name=\"Body\"");
    bodyPart.setBody(message.toUtf8());

    // Ajouter les parties au multipart
    multiPart->append(toPart);
    multiPart->append(fromPart);
    multiPart->append(bodyPart);

    // Envoyer la requête POST
    QNetworkReply* reply = manager->post(request, multiPart);
    multiPart->setParent(reply); // Pour gérer la mémoire

    // Connexion du signal terminé à la méthode de gestion des réponses
    connect(reply, &QNetworkReply::finished, this, &MainWindow::onSmsSent);
}

void MainWindow::onSmsSent() {
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());
    if (!reply) return;

    if (reply->error() == QNetworkReply::NoError) {
        QMessageBox::information(this, "Success", "SMS sent successfully!");
    } else {
        QString error = reply->errorString();
        QByteArray responseData = reply->readAll();
        qDebug() << "Failed to send SMS:" << error << "Response:" << responseData; // Debug info
        QMessageBox::warning(this, "Error", "Failed to send SMS: " + error);
    }

    reply->deleteLater();
}






// Méthode pour configurer les dates dans le calendrier
void MainWindow::populateCalendarWithTransactions() {
    // Récupérer les dates des transactions de la base de données
    QSqlQuery query;
    query.prepare("SELECT DATE_TRANSACTION FROM transactions");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer les dates des transactions !");
        return;
    }

    // Initialiser un QTextCharFormat pour définir la couleur des dates
    QTextCharFormat redFormat;
    redFormat.setBackground(QBrush(QColor("red")));
    redFormat.setForeground(Qt::white);  // Texte en blanc pour contraste

    // Parcourir les résultats et ajouter les dates au calendrier
    while (query.next()) {
        QDate transactionDate = query.value(0).toDate();
        if (transactionDate.isValid()) {
            ui->calendarWidget->setDateTextFormat(transactionDate, redFormat);
        }
    }
}
void MainWindow::onCalendarDateClicked(const QDate &date) {
    QSqlQuery query;
    query.prepare("SELECT * FROM transactions WHERE DATE_TRANSACTION = :date");
    query.bindValue(":date", date);

    if (query.exec()) {
        QString details;
        while (query.next()) {
            int id = query.value("ID_TRANSACTION").toInt();
            float totalAmount = query.value("TOTAL_AMOUNT").toFloat();
            QString type = query.value("TYPE").toString();
            QString category = query.value("CATEGORY").toString();
            QString paymentMethod = query.value("PAYMENT_METHOD").toString();

            details += QString("ID: %1\nMontant: %2\nType: %3\nCatégorie: %4\nMéthode: %5\n\n")
                           .arg(id)
                           .arg(totalAmount)
                           .arg(type)
                           .arg(category)
                           .arg(paymentMethod);
        }

        if (details.isEmpty()) {
            QMessageBox::information(this, "Détails", "Aucune transaction pour cette date.");
        } else {
            QMessageBox::information(this, "Détails des transactions", details);
        }
    }
}

//-------------------------------------------ARDUINO_HAZEM-----------------------------------------------------------------------------------

/*void MainWindow::on_lcdButton_clicked()
{
    QString enteredNumber = ui->ard->text(); // Replace `ardLabel` with your actual QLabel name

    if (enteredNumber.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a valid prescription number.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT STATUS FROM ORDONNANCE WHERE NUMERO_ORDONNANCE = :NUMERO_ORDONNANCE");
    query.bindValue(":NUMERO_ORDONNANCE", enteredNumber);

    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", "Failed to execute the query.");
        return;
    }

    if (query.next()) {
        QString status = query.value(0).toString(); // Retrieve the STATUS

        if (arduino.getserial()->isWritable()) {
            arduino.write_to_arduino(status.toUtf8()); // Send STATUS to Arduino
            QMessageBox::information(this, "Success", "Status sent to Arduino: " + status);
        } else {
            QMessageBox::warning(this, "Serial Port Error", "Unable to write to Arduino.");
        }
    } else {
        arduino.write_to_arduino("error");
        QMessageBox::warning(this, "Not Found", "The entered prescription number does not exist.");
    }
}*/
/*void MainWindow::readFromArduino()
{
    QByteArray data = arduino.read_from_arduino();  // Lire les données envoyées par Arduino

    if (!data.isEmpty()) {
        for (int i = 0; i < data.size(); ++i) {
            char key = data[i];

            if (key == '*')
            {
                QSqlQuery query;
                query.prepare("SELECT STATUS FROM ORDONNANCE WHERE NUMERO_ORDONNANCE = :NUMERO_ORDONNANCE");
                query.bindValue(":NUMERO_ORDONNANCE", code);

                if (!query.exec())
                {
                    QMessageBox::critical(this, "Database Error", "Failed to execute the query.");
                    return;
                }

                if (query.next()) {
                    QString status = query.value(0).toString(); // Retrieve the STATUS

                    if (arduino.getserial()->isWritable())
                    {
                        arduino.write_to_arduino(status.toUtf8()); // Send STATUS to Arduino
                        QMessageBox::information(this, "Success", "Status sent to Arduino: " + status);
                    }
                    else
                    {
                        QMessageBox::warning(this, "Serial Port Error", "Unable to write to Arduino.");
                    }

                }
                else
                {
                    arduino.write_to_arduino("error");
                    QMessageBox::warning(this, "Not Found", "The entered prescription number does not exist.");
                }



                // Si la touche '*' est pressée, afficher le code sans '*'
                QMessageBox::information(this, "Succès", "Code saisi : "+ code);
                code.clear();  // Réinitialiser le code après l'affichage
            } else {
                // Sinon, ajouter la touche au code
                code.append(key);
            }
        }
    }
}*/










////aziz
///
///

QString ref1;
///tikhdem jawha behy gedgt peiii mahyaich tikhdm
void MainWindow::computeSalaryStats()
{
    QMap<QString, int> roleCounts; // Map to store role names and their counts
    QAbstractItemModel *model = ui->xx1->model(); // Get the model from the QTableView

    // Check if the model is valid
    if (!model) {
        return;
    }

    // Count occurrences of each role from the model
    int totalRoles = 0;
    for (int row = 0; row < model->rowCount(); ++row) {
        QModelIndex index = model->index(row, 7); // Column 8 is index 7 (0-based index)
        if (index.isValid()) {
            QString role = model->data(index).toString().trimmed(); // Get role data
            if (!role.isEmpty()) {
                roleCounts[role]++;
                totalRoles++; // Count total roles
            }
        }
    }

    // If there are no roles, display an empty chart
    if (totalRoles == 0) {
        QPieSeries *emptySeries = new QPieSeries();
        emptySeries->setHoleSize(0.25); // Donut effect
        QPieSlice *slice = emptySeries->append("No Data", 1);
        slice->setBrush(Qt::gray);
        slice->setLabel("No Data");
        slice->setLabelVisible(true);

        QChart *emptyChart = new QChart();
        emptyChart->addSeries(emptySeries);
        emptyChart->setTitle("Employee Roles (No Data)");
        emptyChart->setAnimationOptions(QChart::SeriesAnimations);
        emptyChart->setTheme(QChart::ChartThemeDark);

        // Clear existing layout and display chart
        QLayout *existingLayout = ui->chat->layout();
        if (existingLayout) {
            QLayoutItem *item;
            while ((item = existingLayout->takeAt(0)) != nullptr) {
                delete item->widget();
                delete item;
            }
            delete existingLayout;
        }

        QChartView *chartView = new QChartView(emptyChart);
        chartView->setRenderHint(QPainter::Antialiasing);

        QVBoxLayout *newLayout = new QVBoxLayout(ui->chat);
        newLayout->addWidget(chartView);
        ui->chat->setLayout(newLayout);

        return;
    }

    // Create donut chart
    QPieSeries *series = new QPieSeries();
    series->setHoleSize(0.25); // Donut effect

    // Define role colors
    QMap<QString, QColor> roleColors;
    roleColors["admin"] = Qt::blue;
    roleColors["orderM"] = Qt::green;
    roleColors["order"] = Qt::red;
    roleColors["stock"] = Qt::yellow;
    roleColors["transaction"] = Qt::magenta;

    // Add slices for each role with percentages
    for (auto it = roleCounts.constBegin(); it != roleCounts.constEnd(); ++it) {
        double percentage = totalRoles > 0 ? (static_cast<double>(it.value()) / totalRoles) * 100.0 : 0;
        QString label = QString("%1: %2%").arg(it.key()).arg(QString::number(percentage, 'f', 1));

        QPieSlice *slice = new QPieSlice(label, it.value());
        slice->setLabelVisible(true);
        slice->setBrush(roleColors.value(it.key(), Qt::gray)); // Use predefined color or default to gray
        series->append(slice);
    }

    // Create and customize chart
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Employee Roles");
    chart->setTheme(QChart::ChartThemeDark);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    // Clear existing layout and display new chart
    QLayout *existingLayout = ui->chat->layout();
    if (existingLayout) {
        QLayoutItem *item;
        while ((item = existingLayout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete existingLayout;
    }

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout *newLayout = new QVBoxLayout(ui->chat);
    newLayout->addWidget(chartView);

    // Show role names with colors below the pie chart
    QString roleText;
    for (auto it = roleCounts.constBegin(); it != roleCounts.constEnd(); ++it) {
        double percentage = totalRoles > 0 ? (static_cast<double>(it.value()) / totalRoles) * 100.0 : 0;
        roleText += QString("<font color='%1'>%2: %3%</font><br>").arg(roleColors.value(it.key(), Qt::gray).name()).arg(it.key()).arg(QString::number(percentage, 'f', 1));
    }

    QLabel *roleLabel = new QLabel(roleText);
    roleLabel->setTextFormat(Qt::RichText);  // Use rich text for colored font
    roleLabel->setWordWrap(true);  // Ensure long text wraps properly
    newLayout->addWidget(roleLabel);  // Add the role information below the chart

    ui->chat->setLayout(newLayout);
}

// Helper function to update the chart layout
void MainWindow::updateChartInLayout(QChart *chart)
{
    // Clear the existing layout
    QLayout *existingLayout = ui->chat->layout();
    if (existingLayout) {
        QLayoutItem *item;
        while ((item = existingLayout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete existingLayout;
    }

    // Create a new layout and add the chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout *newLayout = new QVBoxLayout(ui->chat);
    newLayout->addWidget(chartView);
    ui->chat->setLayout(newLayout);
}



void MainWindow::input() {
    data = A.read_from_arduino();
    ref1 = data;
    qDebug() << ref1.left(ref1.length() - 2);

    QSqlQuery query;
    query.prepare("SELECT * FROM staff WHERE ard = :UDC");
    query.bindValue(":UDC", ref1.left(ref1.length() - 2));
    if (query.exec() && query.next()) {
        QSqlQuery updateQuery;
        updateQuery.prepare("UPDATE staff SET presence = :presence WHERE ard = :UDC");
        updateQuery.bindValue(":presence", "in");
        updateQuery.bindValue(":UDC", ref1.left(ref1.length() - 2));

        // Check if the update query executed successfully
        if (updateQuery.exec()) {
            QMessageBox msgBox(this);
            msgBox.setWindowTitle("Welcome");
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setText("Welcome to our desktop " + query.value(0).toString() + " Mr/Mme: " + query.value(4).toString() + " is now IN.");
            msgBox.setStyleSheet(
                "QMessageBox {"
                "    background-color: #f0f0f0;"
                "    color: #333;"
                "    border-radius: 10px;"
                "    padding: 15px;"
                "}"
                "QLabel {"
                "    font-size: 14px;"
                "    color: #555;"
                "}"
                "QPushButton {"
                "    background-color: #0078d7;"
                "    color: white;"
                "    border: none;"
                "    border-radius: 5px;"
                "    padding: 8px 15px;"
                "}"
                "QPushButton:hover {"
                "    background-color: #005a9e;"
                "}"
            );
            msgBox.exec();
        } else {
            qDebug() << "Failed to update presence:" << updateQuery.lastError().text();
        }
    } else {
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Welcome");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Does not exist");
        msgBox.setStyleSheet(
            "QMessageBox {"
            "    background-color: #f0f0f0;"
            "    color: #333;"
            "    border-radius: 10px;"
            "    padding: 15px;"
            "}"
            "QLabel {"
            "    font-size: 14px;"
            "    color: #555;"
            "}"
            "QPushButton {"
            "    background-color: #0078d7;"
            "    color: white;"
            "    border: none;"
            "    border-radius: 5px;"
            "    padding: 8px 15px;"
            "}"
            "QPushButton:hover {"
            "    background-color: #005a9e;"
            "}"
        );
        msgBox.exec();
    }
}





///hedha barr nope
void MainWindow::computeSalaryState()
{
    QMap<QString, int> salaryRanges; // Map to store salary ranges and their counts
    QAbstractItemModel *model = ui->xx1->model(); // Get the model from the QTableView

    // Check if the model is valid
    if (!model) {
        return;
    }

    // Define salary ranges
    int range1Min = 0, range1Max = 2500; // 0 - 2500
    int range2Min = 2501, range2Max = 3500; // 2501 - 3500
    int range3Min = 3501, range3Max = 5000; // 3501 - 5000
    int range4Min = 5001; // 5000+

    // Count occurrences of each salary range
    for (int row = 0; row < model->rowCount(); ++row) {
        QModelIndex index = model->index(row, 9); // Column 10 is index 9 (0-based index)
        if (index.isValid()) {
            int salary = model->data(index).toInt(); // Get salary data
            if (salary >= range1Min && salary <= range1Max) {
                salaryRanges["0 - 2500"]++;
            } else if (salary >= range2Min && salary <= range2Max) {
                salaryRanges["2501 - 3500"]++;
            } else if (salary >= range3Min && salary <= range3Max) {
                salaryRanges["3501 - 5000"]++;
            } else if (salary >= range4Min) {
                salaryRanges["5000+"]++;
            }
        }
    }

    // If there are no salaries, display an empty chart
    if (salaryRanges.isEmpty()) {
        QBarSeries *emptySeries = new QBarSeries();
        QBarSet *emptySet = new QBarSet("No Data");
        *emptySet << 1;  // Empty bar set with one value
        emptySeries->append(emptySet);

        QChart *emptyChart = new QChart();
        emptyChart->addSeries(emptySeries);
        emptyChart->setTitle("Salary Ranges (No Data)");
        emptyChart->setAnimationOptions(QChart::SeriesAnimations);

        // Clear existing layout and display chart in QFrame "aziz"
        updateChartInAzizLayout(emptyChart);
        return;
    }

    // Create bar chart series
    QBarSeries *series = new QBarSeries();

    // Create a bar set for each salary range
    QBarSet *range1Set = new QBarSet("0 - 2500");
    QBarSet *range2Set = new QBarSet("2501 - 3500");
    QBarSet *range3Set = new QBarSet("3501 - 5000");
    QBarSet *range4Set = new QBarSet("5000+");

    // Add data to the bar sets
    *range1Set << salaryRanges["0 - 2500"];
    *range2Set << salaryRanges["2501 - 3500"];
    *range3Set << salaryRanges["3501 - 5000"];
    *range4Set << salaryRanges["5000+"];

    // Add the bar sets to the series
    series->append(range1Set);
    series->append(range2Set);
    series->append(range3Set);
    series->append(range4Set);

    // Create and customize chart
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Salary Ranges");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // Set categories for the X-axis (salary ranges)
    QStringList categories;
    categories << "0 - 2500" << "2501 - 3500" << "3501 - 5000" << "5000+";
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->setAxisX(axisX, series);

    // Customize the chart layout
    chart->setTheme(QChart::ChartThemeDark);

    // Clear existing layout and display new chart in QFrame "aziz"
    updateChartInAzizLayout(chart);
}

void MainWindow::updateChartInAzizLayout(QChart *chart)
{
    // Find the layout inside the "aziz" QFrame
    QLayout *existingLayout = ui->aziz->layout();
    if (existingLayout) {
        QLayoutItem *item;
        while ((item = existingLayout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete existingLayout;
    }

    // Create a new layout and add the chart to QFrame "aziz"
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout *newLayout = new QVBoxLayout(ui->aziz);
    newLayout->addWidget(chartView);
    ui->aziz->setLayout(newLayout);
}






void MainWindow::on_stat_clicked()
{
    // Show the frames containing the charts
    ui->chat->setVisible(true);
    ui->aziz->setVisible(true);

    // Clear any existing charts in ui->aziz (for computeSalaryStats)
    QLayout *layoutAziz = ui->aziz->layout();
    if (layoutAziz) {
        QLayoutItem *child;
        while ((child = layoutAziz->takeAt(0)) != nullptr) {
            QWidget *widget = child->widget();
            if (widget) {
                widget->deleteLater();
            }
        }
    }

    // Clear any existing charts in ui->chat (for computeSalaryState)
    QLayout *layoutChat = ui->chat->layout();
    if (layoutChat) {
        QLayoutItem *child;
        while ((child = layoutChat->takeAt(0)) != nullptr) {
            QWidget *widget = child->widget();
            if (widget) {
                widget->deleteLater();
            }
        }
    }

    // Compute and display the statistics for salary ranges in ui->aziz
    computeSalaryStats();  // Updates the 'chart' used in ui->aziz

    // Compute and display the state for salary ranges in ui->chat
    computeSalaryState();  // Updates the 'chart' used in ui->chat

    // Create and add the chart for ui->aziz
    QChartView *chartViewAziz = new QChartView(chart);  // Assuming 'chart' is updated in computeSalaryStats()
    chartViewAziz->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout *layoutAzizNew = qobject_cast<QVBoxLayout*>(ui->aziz->layout());
    if (layoutAzizNew) {
        layoutAzizNew->addWidget(chartViewAziz);  // Add the updated chart view to 'aziz'
    }

    // Create and add the chart for ui->chat
    QChartView *chartViewChat = new QChartView(chart);  // Assuming 'chart' is updated in computeSalaryState()
    chartViewChat->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout *layoutChatNew = qobject_cast<QVBoxLayout*>(ui->chat->layout());
    if (layoutChatNew) {
        layoutChatNew->addWidget(chartViewChat);  // Add the updated chart view to 'chat'
    }
}

////////////////////







mailer::mailer()
{
}

#include <QtNetwork>
#include <QDebug>
int mailer::sendEmailWithAttachment(QString smtpEmail, QString smtpPassword, QString dist, QString obj, QString bdy, QString filePath)
{
    qDebug() << "sslLibraryBuildVersionString:" << QSslSocket::sslLibraryBuildVersionString();
    qDebug() << "sslLibraryVersionNumber:" << QSslSocket::sslLibraryVersionNumber();
    qDebug() << "supportsSsl:" << QSslSocket::supportsSsl();
    qDebug() << "Chemins des bibliothèques Qt:" << QCoreApplication::libraryPaths();

    // SMTP server information
    QString smtpServer = "smtp.gmail.com";
    int smtpPort = 465; // Adjust this based on your SMTP server configuration

    // Sender and recipient information
    QString from = smtpEmail;
    QString to = dist;
    QString subject = obj;
    QString body = bdy;

    // Check if the file exists and can be opened
    qDebug() << "Chemin du fichier à attacher:" << filePath;
    QFile file(filePath);
    if (!file.exists()) {
        qDebug() << "Le fichier spécifié n'existe pas au chemin:" << filePath;
        return -1; // Quitte la fonction si le fichier est introuvable
    }

    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Impossible d'ouvrir le fichier pour la lecture:" << filePath;
        return -1; // Exit if the file cannot be opened
    }

    QByteArray fileData = file.readAll();
    file.close();

    QString fileName = QFileInfo(filePath).fileName();
    QString boundary = "boundary_" + QString::number(QDateTime::currentMSecsSinceEpoch());

    QSslSocket socket;
    socket.connectToHostEncrypted(smtpServer, smtpPort);
    if (!socket.waitForConnected()) {
        qDebug() << "Error connecting to the server:" << socket.errorString();
        return -1;
    }

    if (!socket.waitForReadyRead()) {
        qDebug() << "Error reading from server:" << socket.errorString();
        return -1;
    }

    // Send HELO
    socket.write("HELO localhost\r\n");
    socket.waitForBytesWritten();
    if (!socket.waitForReadyRead()) {
        qDebug() << "Error reading HELO response:" << socket.errorString();
        return -1;
    }

    // Authenticate
    socket.write("AUTH LOGIN\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();
    socket.write(QByteArray().append(smtpEmail.toUtf8()).toBase64() + "\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();
    socket.write(QByteArray().append(smtpPassword.toUtf8()).toBase64() + "\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();

    // Send MAIL FROM
    socket.write("MAIL FROM:<" + from.toUtf8() + ">\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();

    // Send RCPT TO
    socket.write("RCPT TO:<" + to.toUtf8() + ">\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();

    // Send DATA
    socket.write("DATA\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();

    // Compose the email content
    QString content;
    content += "From: " + from + "\r\n";
    content += "To: " + to + "\r\n";
    content += "Subject: " + subject + "\r\n";
    content += "MIME-Version: 1.0\r\n";
    content += "Content-Type: multipart/mixed; boundary=" + boundary + "\r\n\r\n";

    // Email body
    content += "--" + boundary + "\r\n";
    content += "Content-Type: text/plain; charset=\"utf-8\"\r\n";
    content += "Content-Transfer-Encoding: 7bit\r\n\r\n";
    content += body + "\r\n";

    // Attachment
    content += "--" + boundary + "\r\n";
    content += "Content-Type: application/octet-stream; name=\"" + fileName + "\"\r\n";
    content += "Content-Transfer-Encoding: base64\r\n";
    content += "Content-Disposition: attachment; filename=\"" + fileName + "\"\r\n\r\n";
    content += fileData.toBase64() + "\r\n";

    content += "--" + boundary + "--\r\n";

    // Send the email content
    socket.write(content.toUtf8());
    socket.waitForBytesWritten();
    socket.write(".\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();

    // Send QUIT
    socket.write("QUIT\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();

    socket.close();
    qDebug() << "Email sent successfully with attachment.";
    return 0;
}

void MainWindow::on_email_clicked()
{
    QString smtpEmail = ui->lineEdit_21->text(); // SMTP email (sender)
    QString smtpPassword = ui->lineEdit_18->text(); // SMTP password
    QString destinataire = ui->lineEdit_21->text(); // Email recipient
    QString objet = "QR Code for New Employee";
    QString corps = "Dear employee, please find your QR code attached.";

    if (smtpEmail.isEmpty() || smtpPassword.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer votre email et mot de passe SMTP.");
        return;
    }

    // Save QR Code
    QPixmap qrPixmap = ui->labelQRCode->pixmap(Qt::ReturnByValue);
    QString qrCodeFilePath = QDir::currentPath() + "/QR_code.png";

    if (!qrPixmap.isNull()) {
        if (!qrPixmap.save(qrCodeFilePath)) {
            qDebug() << "Failed to save QR Code at:" << qrCodeFilePath;
            QMessageBox::warning(this, "Erreur", "Échec de l'enregistrement du fichier QR Code : " + qrCodeFilePath);
            return;
        }
        qDebug() << "QR Code successfully saved at:" << qrCodeFilePath;
    } else {
        QMessageBox::warning(this, "Erreur", "Aucun QR code disponible à sauvegarder.");
        return;
    }

    if (!QFile::exists(qrCodeFilePath)) {
        QMessageBox::warning(this, "Erreur", "Le fichier QR Code est introuvable : " + qrCodeFilePath);
        return;
    }

    // Send Email
    int success = mailer::sendEmailWithAttachment(smtpEmail, smtpPassword, destinataire, objet, corps, qrCodeFilePath);

    if (success == 0) {
        QMessageBox::information(this, "Succès", "Email envoyé avec succès.");
    } else {
        QMessageBox::warning(this, "Erreur", "L'envoi de l'email a échoué.");
    }
}


////////////////////hedhy zeda//////////////////////////////////////////////

void MainWindow::saveQRCode() {
    QString qrCodeFilePath = QDir::currentPath() + "/QR_code.png";

    // Get QR code from QLabel and save it
    QPixmap qrPixmap = ui->labelQRCode->pixmap(Qt::ReturnByValue);
    if (qrPixmap.isNull()) {
        qDebug() << "QR code is not displayed in QLabel.";
        return;
    }

    if (!qrPixmap.save(qrCodeFilePath)) {
        qDebug() << "Failed to save QR code at:" << qrCodeFilePath;
        return;
    }

    // Verify that the file exists
    if (!QFile::exists(qrCodeFilePath)) {
        qDebug() << "QR code file does not exist at:" << qrCodeFilePath;
        return;
    }

    qDebug() << "QR Code successfully saved at:" << qrCodeFilePath;
}




/////////////////////////////////////////////////////tikhdem jawaha behy fi daata base
///////////////////////////


void MainWindow::on_modifyButton_clicked() {
    // Collect data from modification fields
    int id = ui->lineEdit_16->text().toInt();
    int cin = ui->lineEdit_19->text().toInt();
    QString login = ui->lineEdit_17->text();
    QString password = ui->lineEdit_18->text();
    QString firstName = ui->lineEdit_20->text();
    QString lastName = ui->lineEdit_40->text();
    QString email = ui->lineEdit_21->text();
    QString role = ui->comboBox->currentText(); // Get the selected role
    int phone = ui->lineEdit_22->text().toInt();
    QString gender = ui->radioButton->isChecked() ? "Male" : "Female";
    int salary = ui->lineEdit_39->text().toInt();
    QString dob = ui->dateEdit->date().toString("yyyy-MM-dd");
    QString hireDate = ui->dateEdit_2->date().toString("yyyy-MM-dd");

    // Validate input fields (checking that ID exists)
    if (id == 0) {
        QMessageBox::warning(this, "Input Error", "ID must not be empty.");
        return;
    }

    // Check if the ID exists in the database
    Staff staff;
    if (!staff.exists(id)) {
        QMessageBox::warning(this, "Modification", "ID not found. Please enter a valid ID.");
        return;
    }

    // Update the database with the new values
    bool dbUpdateSuccess = staff.modify(id, login, password, firstName, lastName, email, role, phone, gender, salary, dob, hireDate);

    if (!dbUpdateSuccess) {
        QMessageBox::warning(this, "Modification", "Failed to update employee details in the database.");
        return;
    }

    // Find the row in the table view to update
    bool found = false;
    for (int row = 0; row < ui->xx1->model()->rowCount(); ++row) {
        QModelIndex index = ui->xx1->model()->index(row, 2); // Assuming ID is in the 3rd column (index 2)
        if (ui->xx1->model()->data(index).toInt() == id) {
            found = true;

            // Modify only the fields that are filled in the table
            if (!login.isEmpty()) {
                ui->xx1->model()->setData(ui->xx1->model()->index(row, 0), login); // Column 0 for login
            }
            if (!password.isEmpty()) {
                ui->xx1->model()->setData(ui->xx1->model()->index(row, 1), password); // Column 1 for password
            }
            if (cin != 0) {
                ui->xx1->model()->setData(ui->xx1->model()->index(row, 3), QString::number(cin)); // Column 3 for CIN
            }
            if (!firstName.isEmpty()) {
                ui->xx1->model()->setData(ui->xx1->model()->index(row, 4), firstName); // Column 4 for first name
            }
            if (!lastName.isEmpty()) {
                ui->xx1->model()->setData(ui->xx1->model()->index(row, 5), lastName); // Column 5 for last name
            }
            if (!email.isEmpty()) {
                ui->xx1->model()->setData(ui->xx1->model()->index(row, 6), email); // Column 6 for email
            }
            if (!role.isEmpty()) {
                ui->xx1->model()->setData(ui->xx1->model()->index(row, 7), role); // Column 7 for role
            }
            if (phone != 0) {
                ui->xx1->model()->setData(ui->xx1->model()->index(row, 8), QString::number(phone)); // Column 8 for phone
            }
            if (!gender.isEmpty()) {
                ui->xx1->model()->setData(ui->xx1->model()->index(row, 9), gender); // Column 9 for gender
            }
            if (salary != 0) {
                ui->xx1->model()->setData(ui->xx1->model()->index(row, 10), QString::number(salary)); // Column 10 for salary
            }
            if (!dob.isEmpty()) {
                ui->xx1->model()->setData(ui->xx1->model()->index(row, 11), dob); // Column 11 for date of birth
            }
            if (!hireDate.isEmpty()) {
                ui->xx1->model()->setData(ui->xx1->model()->index(row, 12), hireDate); // Column 12 for hire date
            }

            QMessageBox::information(this, "Modification", "Employee details updated successfully.");
            break;
        }
    }

    if (!found) {
        QMessageBox::warning(this, "Modification", "ID not found in the table. Please refresh the table.");
    }
    ui->xx1->setModel( emtpaz.afficher());
}








void MainWindow::addStaff() {
    // Retrieve the data from the input fields
    int id = ui->lineEdit_16->text().toInt();
    int cin = ui->lineEdit_19->text().toInt();
    QString login = ui->lineEdit_17->text();
    QString password = ui->lineEdit_18->text();
    QString firstName = ui->lineEdit_20->text();
    QString lastName = ui->lineEdit_40->text();
    QString email = ui->lineEdit_21->text();
    QString role = ui->comboBox->currentText(); // Get the selected role
    int phone = ui->lineEdit_22->text().toInt();
    QString gender = ui->radioButton->isChecked() ? "Male" : "Female";
    int salary = ui->lineEdit_39->text().toInt();

    // Format the dates as 'yyyy-MM-dd'
    QString dob = ui->dateEdit->date().toString("yyyy-MM-dd");
    QString hireDate = ui->dateEdit_2->date().toString("yyyy-MM-dd");

    // Create a Staff object
    Staff newStaff(id, cin, login, password, firstName, lastName, email, role, phone, gender, salary, dob, hireDate);

    // Call the add method to add the staff member to the database
    bool success = newStaff.add();

    if (success) {
        QMessageBox::information(this, "Success", "Staff member added successfully!");
    } else {
        QMessageBox::critical(this, "Error", "Failed to add staff member.");
    }
   ui->xx1->setModel( emtpaz.afficher());
}
















//////////////kan fama erur raw fi hedhy  ekhir modif lina
void MainWindow::on_addButton_clicked() {
    // Collect data from input fields
    QString login = ui->lineEdit_17->text().trimmed();
    QString password = ui->lineEdit_18->text().trimmed();
    QString id = ui->lineEdit_16->text().trimmed();
    QString cin = ui->lineEdit_19->text().trimmed();
    QString firstName = ui->lineEdit_20->text().trimmed();
    QString lastName = ui->lineEdit_40->text().trimmed();
    QString email = ui->lineEdit_21->text().trimmed();
    QString role = ui->comboBox->currentText();
    QString phone = ui->lineEdit_22->text().trimmed();

    // Check gender based on radio buttons
    QString gender;
    if (ui->radioButton->isChecked()) {
        gender = "Male";
    } else if (ui->radioButton_3->isChecked()) {
        gender = "Female";
    } else {
        gender = "Unknown"; // Handle case where no gender is selected
    }

    QString salary = ui->lineEdit_39->text().trimmed();
    QString dob = ui->dateEdit->date().toString("dd/MM/yyyy");
    QString hireDate = ui->dateEdit_2->date().toString("dd/MM/yyyy");

    // Validate input fields
    if (login.isEmpty() || password.isEmpty() || id.isEmpty() || cin.isEmpty() ||
        firstName.isEmpty() || lastName.isEmpty() || email.isEmpty() ||
        phone.isEmpty() || salary.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "All fields must be filled.");
        return;
    }

    // Check email format
    QRegularExpression emailRegex(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");
    if (!emailRegex.match(email).hasMatch()) {
        QMessageBox::warning(this, "Input Error", "Please enter a valid email address.");
        return;
    }

    // Check phone format (assuming a 10-digit phone number, modify as needed)
    QRegularExpression phoneRegex("^\\d{10}$");
    if (!phoneRegex.match(phone).hasMatch()) {
        QMessageBox::warning(this, "Input Error", "Please enter a valid 10-digit phone number.");
        return;
    }

    // Check salary format (numeric)
    bool salaryOk;
    salary.toDouble(&salaryOk);
    if (!salaryOk || salary.toDouble() <= 0) {
        QMessageBox::warning(this, "Input Error", "Please enter a valid salary amount.");
        return;
    }

    // Check if ID and CIN are numeric
    bool idOk, cinOk;
    id.toInt(&idOk);
    cin.toInt(&cinOk);
    if (!idOk || !cinOk) {
        QMessageBox::warning(this, "Input Error", "ID and CIN must be numeric values.");
        return;
    }

    // Set up the model if not already done
    QStandardItemModel* model = dynamic_cast<QStandardItemModel*>(ui->xx1->model());
    if (!model) {
        model = new QStandardItemModel(this);
        model->setHorizontalHeaderLabels({
            "Login", "Password", "ID", "CIN", "First Name", "Last Name",
            "Email", "Role", "Phone", "Gender", "Salary", "DOB", "Hire Date"
        });
        ui->xx1->setModel(model);
    }

    // Check if the model is valid
    if (!model) {
        QMessageBox::critical(this, "Error", "Failed to initialize the table model.");
        return;
    }

    // Ensure the model has 13 columns
    if (model->columnCount() < 13) {
        model->setColumnCount(13);
    }

    // Check if the ID already exists in the table (to avoid duplicates)
    bool alreadyInTable = false;
    for (int row = 0; row < model->rowCount(); ++row) {
        QStandardItem* item = model->item(row, 2); // Column 2 assumed for IDs
        if (item && item->text() == id) {
            alreadyInTable = true;
            break;
        }
    }

    if (alreadyInTable) {
        QMessageBox::warning(this, "Duplicate Entry", "This staff member is already in the table.");
        return;
    }

    // Add data to the model
    QList<QStandardItem*> items;
    items << new QStandardItem(login)
          << new QStandardItem(password)
          << new QStandardItem(id)
          << new QStandardItem(cin)
          << new QStandardItem(firstName)
          << new QStandardItem(lastName)
          << new QStandardItem(email)
          << new QStandardItem(role)
          << new QStandardItem(phone)
          << new QStandardItem(gender)
          << new QStandardItem(salary)
          << new QStandardItem(dob)
          << new QStandardItem(hireDate);

    // Ensure the number of items matches the columns
    if (items.size() != 13) {
        QMessageBox::critical(this, "Error", "Mismatch between item count and table columns.");
        return;
    }
    ui->xx1->setModel( emtpaz.afficher());

    QMessageBox::information(this, "Success", "Data added successfully!");
}

///tikhdmch

void MainWindow::loadTableDataFromDatabase() {
    // Clear any existing rows in the table view
    QAbstractItemModel* model = ui->xx1->model();
    if (model) {

    }

    // Create a query to select all employees from your database
    QSqlQuery query("SELECT * FROM employees");  // Replace with your table name and query

    if (query.exec()) {
        while (query.next()) {
            int row = model->rowCount();
            // Insert a new row in the model (if the model is a QStandardItemModel or derived class)
            QStandardItemModel* itemModel = qobject_cast<QStandardItemModel*>(model);
            if (itemModel) {
                itemModel->insertRow(row);
                // Add data to the model for each column
                itemModel->setItem(row, 0, new QStandardItem(query.value(0).toString()));  // login
                itemModel->setItem(row, 1, new QStandardItem(query.value(1).toString()));  // password
                itemModel->setItem(row, 2, new QStandardItem(query.value(2).toString()));  // id
                itemModel->setItem(row, 3, new QStandardItem(query.value(3).toString()));  // cin
                itemModel->setItem(row, 4, new QStandardItem(query.value(4).toString()));  // firstname
                itemModel->setItem(row, 5, new QStandardItem(query.value(5).toString()));  // lastname
                itemModel->setItem(row, 6, new QStandardItem(query.value(6).toString()));  // email
                itemModel->setItem(row, 7, new QStandardItem(query.value(7).toString()));  // role
                itemModel->setItem(row, 8, new QStandardItem(query.value(8).toString()));  // phone
                itemModel->setItem(row, 9, new QStandardItem(query.value(9).toString()));  // gender
                itemModel->setItem(row, 10, new QStandardItem(query.value(10).toString())); // salary
                itemModel->setItem(row, 11, new QStandardItem(query.value(11).toString())); // dob
                itemModel->setItem(row, 12, new QStandardItem(query.value(12).toString())); // hireDate
            }
        }
    } else {
        qDebug() << "Database query failed: " << query.lastError();
    }
}
















// hedhy jawha behi tikhdem tfasakh mil data base ama tkharij alert zydin
void MainWindow::on_deleteButton_clicked() {
    QString idToDelete = ui->lineEdit_128->text().trimmed(); // Using lineEdit_128 for ID input

    // Check if ID input is empty
    if (idToDelete.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter an ID to delete.");
        return;
    }

    // Start a transaction
    QSqlDatabase db = QSqlDatabase::database();
    if (db.transaction()) {
        // Create the SQL query to delete the staff from the database
        QSqlQuery query;
        query.prepare("DELETE FROM staff WHERE id = :id"); // Assuming the table is 'staff' and 'id' is the column name
        query.bindValue(":id", idToDelete);

        // Execute the query
        if (query.exec()) {
            // If the delete operation is successful, commit the transaction
            db.commit();

            // Now delete from the UI table (if applicable)
            bool found = false;
            QAbstractItemModel* model = ui->xx1->model();
            if (model) {
                for (int row = 0; row < model->rowCount(); ++row) {
                    QModelIndex index = model->index(row, 0); // Assuming the ID is in the first column
                    if (model->data(index).toString() == idToDelete) {
                        // Remove the row from the model
                        QStandardItemModel* itemModel = qobject_cast<QStandardItemModel*>(model);
                        if (itemModel) {
                            itemModel->removeRow(row);
                            QMessageBox::information(this, "Deletion", "Staff member deleted successfully.");
                            found = true;
                        }
                        break;
                    }
                }

                if (!found) {
                    QMessageBox::warning(this, "Deletion Error", "ID not found in table view.");
                }
            }
        } else {
            // If the query fails, rollback the transaction
            db.rollback();
            QMessageBox::warning(this, "Deletion Error", "Failed to delete staff member from database.");
        }
    } else {
        QMessageBox::warning(this, "Transaction Error", "Failed to start transaction.");
    }
    ui->xx1->setModel( emtpaz.afficher());
}















//bech nbadil fil design ta3 pdf
void MainWindow::exportTableToPDF()
{
    QString defaultPath = "C:/Users/Admin/Desktop/Gestion_Client/ClientReport.pdf";

    QString pdfFilePath = QFileDialog::getSaveFileName(this, "Save as PDF", defaultPath, "PDF Files (*.pdf)");

    if (pdfFilePath.isEmpty()) {
        QMessageBox::warning(this, "Warning", "No file selected!");
        return;
    }

    if (!pdfFilePath.endsWith(".pdf"))
        pdfFilePath += ".pdf";

    QPdfWriter pdfWriter(pdfFilePath);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setResolution(300);

    QPainter painter(&pdfWriter);
    if (!painter.isActive()) {
        QMessageBox::critical(this, "Error", "Failed to initialize QPainter.");
        return;
    }

    // Define fonts
    QFont headerFont("Arial", 12, QFont::Bold);
    QFont contentFont("Arial", 10);

    // Use tableView for PDF export
    QTableView *tableView = ui->xx1;
    QAbstractItemModel *model = tableView->model();
    if (!model) {
        QMessageBox::critical(this, "Error", "Table model not found!");
        return;
    }

    // Define the column indices to export
    QList<int> exportColumns = {2, 3, 4, 5, 7, 6, 8}; // ID, CIN, First Name, Last Name, Role, Email, Phone Number

    int leftMargin = 50;
    int topMargin = 50;
    int rowHeight = 50;
    int x = leftMargin;
    int y = topMargin;

    int columnSpacing = 300; // Adjust column spacing for your content
    int rowSpacing = 150;    // Adjust row spacing for readability

    // Write table headers
    painter.setFont(headerFont);
    for (int col : exportColumns) {
        QString header = model->headerData(col, Qt::Horizontal).toString();
        painter.drawText(x, y, header);
        x += columnSpacing;
    }

    y += rowSpacing;
    x = leftMargin;

    // Write table content
    painter.setFont(contentFont);
    for (int row = 0; row < model->rowCount(); ++row) {
        for (int col : exportColumns) {
            QModelIndex index = model->index(row, col);
            QString itemText = model->data(index).toString();
            painter.drawText(x, y, itemText);
            x += columnSpacing;
        }
        y += rowSpacing;
        x = leftMargin;

        // Check for page overflow
        if (y > pdfWriter.height() - 50) {
            pdfWriter.newPage();
            y = topMargin;
        }
    }

    painter.end();

    QMessageBox::information(this, "Success", "Data exported to PDF file successfully.");
}

// Slot to handle the search button click
void MainWindow::on_pushButton_4_clicked() {
    QString searchText = ui->edit_2->text().trimmed(); // Assuming the search field is a QLineEdit with objectName 'edit_2'

    // Check if the search text is empty
    if (searchText.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter an ID, CIN, or Name to search.");
        return;
    }

    // Get the model from the QTableView
    QTableView *tableView = ui->xx1;
    QAbstractItemModel *model = tableView->model();

    // Check if the model exists
    if (!model) {
        QMessageBox::warning(this, "Error", "No model found in the table view.");
        return;
    }

    // Search for the text in the model
    bool found = false;
    int idColumn = 2;    // Assuming ID is in column 3 (index 2)
    int cinColumn = 3;   // Assuming CIN is in column 4 (index 3)
    int nameColumn = 4;  // Assuming Name is in column 5 (index 4)

    for (int row = 0; row < model->rowCount(); ++row) {
        QModelIndex idIndex = model->index(row, idColumn);
        QModelIndex cinIndex = model->index(row, cinColumn);
        QModelIndex nameIndex = model->index(row, nameColumn);

        QString idText = model->data(idIndex).toString().trimmed();
        QString cinText = model->data(cinIndex).toString().trimmed();
        QString nameText = model->data(nameIndex).toString().trimmed();

        // Check if any of the fields match the search text
        if (idText == searchText || cinText == searchText || nameText.contains(searchText, Qt::CaseInsensitive)) {
            found = true;

            // Highlight the found row
            tableView->selectRow(row);

            // Show the message
            QMessageBox::information(this, "Search Result",
                QString("Match found!\n\nID: %1\nCIN: %2\nName: %3")
                .arg(idText, cinText, nameText));
            break;
        }
    }

    if (!found) {
        QMessageBox::warning(this, "Search Result", "No match found with the entered ID, CIN, or Name.");
    }
}




void MainWindow::afficher() {
    // Create a new instance of Staff
    Staff staff;

    // Check if connection is established, if not, log error
    if (QSqlDatabase::database().isOpen()) {
        qDebug() << "Database is open!";
    } else {
        qDebug() << "Database is not open!";
    }

    // Get the model with staff data
    QSqlQueryModel* staffModel = staff.display();

    // Set the model to the QTableView (assuming you have a QTableView named 'xx1')
    ui->xx1->setModel(staffModel);

    // You can also set additional properties for the table view if needed
    ui->xx1->resizeColumnsToContents();  // Resize columns to fit content
    ui->xx1->setSelectionMode(QAbstractItemView::SingleSelection);  // Single row selection
    ui->xx1->setSelectionBehavior(QAbstractItemView::SelectRows);  // Select whole rows
}




// tikhdm jawha behyy


// Slot for sorting
void MainWindow::sortTable(int index)
{
    if (index == 1) {  // Sorting by salary
        sortTableBySalary();
    } else if (index == 2) {  // Sorting by Date of Birth (DOB)
        sortTableByDOB();
    }
    ui->xx1->setModel( emtpaz.afficher());
}

// Function to sort by Salary (Lowest to Highest)
void MainWindow::sortTableBySalary()
{
    QStandardItemModel* model = dynamic_cast<QStandardItemModel*>(ui->xx1->model());
    if (model) {
        ui->xx1->setSortingEnabled(false); // Disable sorting temporarily
        model->sort(10, Qt::AscendingOrder); // Sort by Salary column (Column 10)
        ui->xx1->setSortingEnabled(true); // Re-enable sorting
    } else {
        QMessageBox::warning(this, "Error", "Unable to sort. No valid model attached.");
    }
    ui->xx1->setModel( emtpaz.afficher());
}

// Function to sort by Date of Birth (DOB)
void MainWindow::sortTableByDOB()
{
    QStandardItemModel* model = dynamic_cast<QStandardItemModel*>(ui->xx1->model());
    if (model) {
        ui->xx1->setSortingEnabled(false); // Disable sorting temporarily
        model->sort(11, Qt::AscendingOrder); // Sort by DOB column (Column 11)
        ui->xx1->setSortingEnabled(true); // Re-enable sorting
    } else {
        QMessageBox::warning(this, "Error", "Unable to sort. No valid model attached.");
    }
    ui->xx1->setModel( emtpaz.afficher());
}


/////qr code jawou behy

void MainWindow::on_qr_clicked()
{
    // Retrieve employer details from the input fields
    QString id = ui->lineEdit_16->text();
    QString firstName = ui->lineEdit_20->text();
    QString lastName = ui->lineEdit_40->text();

    // Validate input fields
    if (id.isEmpty() || firstName.isEmpty() || lastName.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please ensure all fields (ID, First Name, Last Name) are filled.");
        return;
    }

    // Construct the QR code text
    QString qrText = "ID: " + id + "\nFirst Name: " + firstName + "\nLast Name: " + lastName;

    using namespace qrcodegen;

    // Create the QR Code object
    QrCode qr = QrCode::encodeText(qrText.toUtf8().data(), QrCode::Ecc::MEDIUM);
    qint32 sz = qr.getSize();

    // Create an image for the QR Code
    QImage qrImage(sz, sz, QImage::Format_RGB32);
    QRgb black = qRgb(0, 0, 0);
    QRgb white = qRgb(255, 255, 255);

    // Fill the image with the QR code's modules
    for (int y = 0; y < sz; y++) {
        for (int x = 0; x < sz; x++) {
            qrImage.setPixel(x, y, qr.getModule(x, y) ? black : white);
        }
    }

    // Display the QR code in the QLabel `labelQRCode`
    ui->labelQRCode->setPixmap(QPixmap::fromImage(qrImage.scaled(256, 256, Qt::KeepAspectRatio, Qt::FastTransformation)));

    // Show success message
    QMessageBox::information(this, "QR Code Generated", "QR Code has been successfully generated and displayed.");
}



namespace qrcodegen {

/*---- Class QrSegment ----*/

QrSegment::Mode::Mode(int mode, int cc0, int cc1, int cc2) :
        modeBits(mode) {
    numBitsCharCount[0] = cc0;
    numBitsCharCount[1] = cc1;
    numBitsCharCount[2] = cc2;
}


int QrSegment::Mode::getModeBits() const {
    return modeBits;
}


int QrSegment::Mode::numCharCountBits(int ver) const {
    return numBitsCharCount[(ver + 7) / 17];
}


const QrSegment::Mode QrSegment::Mode::NUMERIC     (0x1, 10, 12, 14);
const QrSegment::Mode QrSegment::Mode::ALPHANUMERIC(0x2,  9, 11, 13);
const QrSegment::Mode QrSegment::Mode::BYTE        (0x4,  8, 16, 16);
const QrSegment::Mode QrSegment::Mode::KANJI       (0x8,  8, 10, 12);
const QrSegment::Mode QrSegment::Mode::ECI         (0x7,  0,  0,  0);


QrSegment QrSegment::makeBytes(const vector<uint8_t> &data) {
    if (data.size() > static_cast<unsigned int>(INT_MAX))
        throw std::length_error("Data too long");
    BitBuffer bb;
    for (uint8_t b : data)
        bb.appendBits(b, 8);
    return QrSegment(Mode::BYTE, static_cast<int>(data.size()), std::move(bb));
}


QrSegment QrSegment::makeNumeric(const char *digits) {
    BitBuffer bb;
    int accumData = 0;
    int accumCount = 0;
    int charCount = 0;
    for (; *digits != '\0'; digits++, charCount++) {
        char c = *digits;
        if (c < '0' || c > '9')
            throw std::domain_error("String contains non-numeric characters");
        accumData = accumData * 10 + (c - '0');
        accumCount++;
        if (accumCount == 3) {
            bb.appendBits(static_cast<uint32_t>(accumData), 10);
            accumData = 0;
            accumCount = 0;
        }
    }
    if (accumCount > 0)  // 1 or 2 digits remaining
        bb.appendBits(static_cast<uint32_t>(accumData), accumCount * 3 + 1);
    return QrSegment(Mode::NUMERIC, charCount, std::move(bb));
}


QrSegment QrSegment::makeAlphanumeric(const char *text) {
    BitBuffer bb;
    int accumData = 0;
    int accumCount = 0;
    int charCount = 0;
    for (; *text != '\0'; text++, charCount++) {
        const char *temp = std::strchr(ALPHANUMERIC_CHARSET, *text);
        if (temp == nullptr)
            throw std::domain_error("String contains unencodable characters in alphanumeric mode");
        accumData = accumData * 45 + static_cast<int>(temp - ALPHANUMERIC_CHARSET);
        accumCount++;
        if (accumCount == 2) {
            bb.appendBits(static_cast<uint32_t>(accumData), 11);
            accumData = 0;
            accumCount = 0;
        }
    }
    if (accumCount > 0)  // 1 character remaining
        bb.appendBits(static_cast<uint32_t>(accumData), 6);
    return QrSegment(Mode::ALPHANUMERIC, charCount, std::move(bb));
}


vector<QrSegment> QrSegment::makeSegments(const char *text) {
    // Select the most efficient segment encoding automatically
    vector<QrSegment> result;
    if (*text == '\0');  // Leave result empty
    else if (isNumeric(text))
        result.push_back(makeNumeric(text));
    else if (isAlphanumeric(text))
        result.push_back(makeAlphanumeric(text));
    else {
        vector<uint8_t> bytes;
        for (; *text != '\0'; text++)
            bytes.push_back(static_cast<uint8_t>(*text));
        result.push_back(makeBytes(bytes));
    }
    return result;
}


QrSegment QrSegment::makeEci(long assignVal) {
    BitBuffer bb;
    if (assignVal < 0)
        throw std::domain_error("ECI assignment value out of range");
    else if (assignVal < (1 << 7))
        bb.appendBits(static_cast<uint32_t>(assignVal), 8);
    else if (assignVal < (1 << 14)) {
        bb.appendBits(2, 2);
        bb.appendBits(static_cast<uint32_t>(assignVal), 14);
    } else if (assignVal < 1000000L) {
        bb.appendBits(6, 3);
        bb.appendBits(static_cast<uint32_t>(assignVal), 21);
    } else
        throw std::domain_error("ECI assignment value out of range");
    return QrSegment(Mode::ECI, 0, std::move(bb));
}


QrSegment::QrSegment(const Mode &md, int numCh, const std::vector<bool> &dt) :
        mode(&md),
        numChars(numCh),
        data(dt) {
    if (numCh < 0)
        throw std::domain_error("Invalid value");
}


QrSegment::QrSegment(const Mode &md, int numCh, std::vector<bool> &&dt) :
        mode(&md),
        numChars(numCh),
        data(std::move(dt)) {
    if (numCh < 0)
        throw std::domain_error("Invalid value");
}


int QrSegment::getTotalBits(const vector<QrSegment> &segs, int version) {
    int result = 0;
    for (const QrSegment &seg : segs) {
        int ccbits = seg.mode->numCharCountBits(version);
        if (seg.numChars >= (1L << ccbits))
            return -1;  // The segment's length doesn't fit the field's bit width
        if (4 + ccbits > INT_MAX - result)
            return -1;  // The sum will overflow an int type
        result += 4 + ccbits;
        if (seg.data.size() > static_cast<unsigned int>(INT_MAX - result))
            return -1;  // The sum will overflow an int type
        result += static_cast<int>(seg.data.size());
    }
    return result;
}


bool QrSegment::isNumeric(const char *text) {
    for (; *text != '\0'; text++) {
        char c = *text;
        if (c < '0' || c > '9')
            return false;
    }
    return true;
}


bool QrSegment::isAlphanumeric(const char *text) {
    for (; *text != '\0'; text++) {
        if (std::strchr(ALPHANUMERIC_CHARSET, *text) == nullptr)
            return false;
    }
    return true;
}


const QrSegment::Mode &QrSegment::getMode() const {
    return *mode;
}


int QrSegment::getNumChars() const {
    return numChars;
}


const std::vector<bool> &QrSegment::getData() const {
    return data;
}


const char *QrSegment::ALPHANUMERIC_CHARSET = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ $%*+-./:";



/*---- Class QrCode ----*/

int QrCode::getFormatBits(Ecc ecl) {
    switch (ecl) {
        case Ecc::LOW     :  return 1;
        case Ecc::MEDIUM  :  return 0;
        case Ecc::QUARTILE:  return 3;
        case Ecc::HIGH    :  return 2;
        default:  throw std::logic_error("Unreachable");
    }
}


QrCode QrCode::encodeText(const char *text, Ecc ecl) {
    vector<QrSegment> segs = QrSegment::makeSegments(text);
    return encodeSegments(segs, ecl);
}


QrCode QrCode::encodeBinary(const vector<uint8_t> &data, Ecc ecl) {
    vector<QrSegment> segs{QrSegment::makeBytes(data)};
    return encodeSegments(segs, ecl);
}


QrCode QrCode::encodeSegments(const vector<QrSegment> &segs, Ecc ecl,
        int minVersion, int maxVersion, int mask, bool boostEcl) {
    if (!(MIN_VERSION <= minVersion && minVersion <= maxVersion && maxVersion <= MAX_VERSION) || mask < -1 || mask > 7)
        throw std::invalid_argument("Invalid value");

    // Find the minimal version number to use
    int version, dataUsedBits;
    for (version = minVersion; ; version++) {
        int dataCapacityBits = getNumDataCodewords(version, ecl) * 8;  // Number of data bits available
        dataUsedBits = QrSegment::getTotalBits(segs, version);
        if (dataUsedBits != -1 && dataUsedBits <= dataCapacityBits)
            break;  // This version number is found to be suitable
        if (version >= maxVersion) {  // All versions in the range could not fit the given data
            std::ostringstream sb;
            if (dataUsedBits == -1)
                sb << "Segment too long";
            else {
                sb << "Data length = " << dataUsedBits << " bits, ";
                sb << "Max capacity = " << dataCapacityBits << " bits";
            }
            throw data_too_long(sb.str());
        }
    }
    assert(dataUsedBits != -1);

    // Increase the error correction level while the data still fits in the current version number
    for (Ecc newEcl : {Ecc::MEDIUM, Ecc::QUARTILE, Ecc::HIGH}) {  // From low to high
        if (boostEcl && dataUsedBits <= getNumDataCodewords(version, newEcl) * 8)
            ecl = newEcl;
    }

    // Concatenate all segments to create the data bit string
    BitBuffer bb;
    for (const QrSegment &seg : segs) {
        bb.appendBits(static_cast<uint32_t>(seg.getMode().getModeBits()), 4);
        bb.appendBits(static_cast<uint32_t>(seg.getNumChars()), seg.getMode().numCharCountBits(version));
        bb.insert(bb.end(), seg.getData().begin(), seg.getData().end());
    }
    assert(bb.size() == static_cast<unsigned int>(dataUsedBits));

    // Add terminator and pad up to a byte if applicable
    size_t dataCapacityBits = static_cast<size_t>(getNumDataCodewords(version, ecl)) * 8;
    assert(bb.size() <= dataCapacityBits);
    bb.appendBits(0, std::min(4, static_cast<int>(dataCapacityBits - bb.size())));
    bb.appendBits(0, (8 - static_cast<int>(bb.size() % 8)) % 8);
    assert(bb.size() % 8 == 0);

    // Pad with alternating bytes until data capacity is reached
    for (uint8_t padByte = 0xEC; bb.size() < dataCapacityBits; padByte ^= 0xEC ^ 0x11)
        bb.appendBits(padByte, 8);

    // Pack bits into bytes in big endian
    vector<uint8_t> dataCodewords(bb.size() / 8);
    for (size_t i = 0; i < bb.size(); i++)
        dataCodewords.at(i >> 3) |= (bb.at(i) ? 1 : 0) << (7 - (i & 7));

    // Create the QR Code object
    return QrCode(version, ecl, dataCodewords, mask);
}


QrCode::QrCode(int ver, Ecc ecl, const vector<uint8_t> &dataCodewords, int msk) :
        // Initialize fields and check arguments
        version(ver),
        errorCorrectionLevel(ecl) {
    if (ver < MIN_VERSION || ver > MAX_VERSION)
        throw std::domain_error("Version value out of range");
    if (msk < -1 || msk > 7)
        throw std::domain_error("Mask value out of range");
    size = ver * 4 + 17;
    size_t sz = static_cast<size_t>(size);
    modules    = vector<vector<bool> >(sz, vector<bool>(sz));  // Initially all light
    isFunction = vector<vector<bool> >(sz, vector<bool>(sz));

    // Compute ECC, draw modules
    drawFunctionPatterns();
    const vector<uint8_t> allCodewords = addEccAndInterleave(dataCodewords);
    drawCodewords(allCodewords);

    // Do masking
    if (msk == -1) {  // Automatically choose best mask
        long minPenalty = LONG_MAX;
        for (int i = 0; i < 8; i++) {
            applyMask(i);
            drawFormatBits(i);
            long penalty = getPenaltyScore();
            if (penalty < minPenalty) {
                msk = i;
                minPenalty = penalty;
            }
            applyMask(i);  // Undoes the mask due to XOR
        }
    }
    assert(0 <= msk && msk <= 7);
    mask = msk;
    applyMask(msk);  // Apply the final choice of mask
    drawFormatBits(msk);  // Overwrite old format bits

    isFunction.clear();
    isFunction.shrink_to_fit();
}


int QrCode::getVersion() const {
    return version;
}


int QrCode::getSize() const {
    return size;
}


QrCode::Ecc QrCode::getErrorCorrectionLevel() const {
    return errorCorrectionLevel;
}


int QrCode::getMask() const {
    return mask;
}


bool QrCode::getModule(int x, int y) const {
    return 0 <= x && x < size && 0 <= y && y < size && module(x, y);
}


void QrCode::drawFunctionPatterns() {
    // Draw horizontal and vertical timing patterns
    for (int i = 0; i < size; i++) {
        setFunctionModule(6, i, i % 2 == 0);
        setFunctionModule(i, 6, i % 2 == 0);
    }

    // Draw 3 finder patterns (all corners except bottom right; overwrites some timing modules)
    drawFinderPattern(3, 3);
    drawFinderPattern(size - 4, 3);
    drawFinderPattern(3, size - 4);

    // Draw numerous alignment patterns
    const vector<int> alignPatPos = getAlignmentPatternPositions();
    size_t numAlign = alignPatPos.size();
    for (size_t i = 0; i < numAlign; i++) {
        for (size_t j = 0; j < numAlign; j++) {
            // Don't draw on the three finder corners
            if (!((i == 0 && j == 0) || (i == 0 && j == numAlign - 1) || (i == numAlign - 1 && j == 0)))
                drawAlignmentPattern(alignPatPos.at(i), alignPatPos.at(j));
        }
    }

    // Draw configuration data
    drawFormatBits(0);  // Dummy mask value; overwritten later in the constructor
    drawVersion();
}


void QrCode::drawFormatBits(int msk) {
    // Calculate error correction code and pack bits
    int data = getFormatBits(errorCorrectionLevel) << 3 | msk;  // errCorrLvl is uint2, msk is uint3
    int rem = data;
    for (int i = 0; i < 10; i++)
        rem = (rem << 1) ^ ((rem >> 9) * 0x537);
    int bits = (data << 10 | rem) ^ 0x5412;  // uint15
    assert(bits >> 15 == 0);

    // Draw first copy
    for (int i = 0; i <= 5; i++)
        setFunctionModule(8, i, getBit(bits, i));
    setFunctionModule(8, 7, getBit(bits, 6));
    setFunctionModule(8, 8, getBit(bits, 7));
    setFunctionModule(7, 8, getBit(bits, 8));
    for (int i = 9; i < 15; i++)
        setFunctionModule(14 - i, 8, getBit(bits, i));

    // Draw second copy
    for (int i = 0; i < 8; i++)
        setFunctionModule(size - 1 - i, 8, getBit(bits, i));
    for (int i = 8; i < 15; i++)
        setFunctionModule(8, size - 15 + i, getBit(bits, i));
    setFunctionModule(8, size - 8, true);  // Always dark
}


void QrCode::drawVersion() {
    if (version < 7)
        return;

    // Calculate error correction code and pack bits
    int rem = version;  // version is uint6, in the range [7, 40]
    for (int i = 0; i < 12; i++)
        rem = (rem << 1) ^ ((rem >> 11) * 0x1F25);
    long bits = static_cast<long>(version) << 12 | rem;  // uint18
    assert(bits >> 18 == 0);

    // Draw two copies
    for (int i = 0; i < 18; i++) {
        bool bit = getBit(bits, i);
        int a = size - 11 + i % 3;
        int b = i / 3;
        setFunctionModule(a, b, bit);
        setFunctionModule(b, a, bit);
    }
}


void QrCode::drawFinderPattern(int x, int y) {
    for (int dy = -4; dy <= 4; dy++) {
        for (int dx = -4; dx <= 4; dx++) {
            int dist = std::max(std::abs(dx), std::abs(dy));  // Chebyshev/infinity norm
            int xx = x + dx, yy = y + dy;
            if (0 <= xx && xx < size && 0 <= yy && yy < size)
                setFunctionModule(xx, yy, dist != 2 && dist != 4);
        }
    }
}


void QrCode::drawAlignmentPattern(int x, int y) {
    for (int dy = -2; dy <= 2; dy++) {
        for (int dx = -2; dx <= 2; dx++)
            setFunctionModule(x + dx, y + dy, std::max(std::abs(dx), std::abs(dy)) != 1);
    }
}


void QrCode::setFunctionModule(int x, int y, bool isDark) {
    size_t ux = static_cast<size_t>(x);
    size_t uy = static_cast<size_t>(y);
    modules   .at(uy).at(ux) = isDark;
    isFunction.at(uy).at(ux) = true;
}


bool QrCode::module(int x, int y) const {
    return modules.at(static_cast<size_t>(y)).at(static_cast<size_t>(x));
}


vector<uint8_t> QrCode::addEccAndInterleave(const vector<uint8_t> &data) const {
    if (data.size() != static_cast<unsigned int>(getNumDataCodewords(version, errorCorrectionLevel)))
        throw std::invalid_argument("Invalid argument");

    // Calculate parameter numbers
    int numBlocks = NUM_ERROR_CORRECTION_BLOCKS[static_cast<int>(errorCorrectionLevel)][version];
    int blockEccLen = ECC_CODEWORDS_PER_BLOCK  [static_cast<int>(errorCorrectionLevel)][version];
    int rawCodewords = getNumRawDataModules(version) / 8;
    int numShortBlocks = numBlocks - rawCodewords % numBlocks;
    int shortBlockLen = rawCodewords / numBlocks;

    // Split data into blocks and append ECC to each block
    vector<vector<uint8_t> > blocks;
    const vector<uint8_t> rsDiv = reedSolomonComputeDivisor(blockEccLen);
    for (int i = 0, k = 0; i < numBlocks; i++) {
        vector<uint8_t> dat(data.cbegin() + k, data.cbegin() + (k + shortBlockLen - blockEccLen + (i < numShortBlocks ? 0 : 1)));
        k += static_cast<int>(dat.size());
        const vector<uint8_t> ecc = reedSolomonComputeRemainder(dat, rsDiv);
        if (i < numShortBlocks)
            dat.push_back(0);
        dat.insert(dat.end(), ecc.cbegin(), ecc.cend());
        blocks.push_back(std::move(dat));
    }

    // Interleave (not concatenate) the bytes from every block into a single sequence
    vector<uint8_t> result;
    for (size_t i = 0; i < blocks.at(0).size(); i++) {
        for (size_t j = 0; j < blocks.size(); j++) {
            // Skip the padding byte in short blocks
            if (i != static_cast<unsigned int>(shortBlockLen - blockEccLen) || j >= static_cast<unsigned int>(numShortBlocks))
                result.push_back(blocks.at(j).at(i));
        }
    }
    assert(result.size() == static_cast<unsigned int>(rawCodewords));
    return result;
}


void QrCode::drawCodewords(const vector<uint8_t> &data) {
    if (data.size() != static_cast<unsigned int>(getNumRawDataModules(version) / 8))
        throw std::invalid_argument("Invalid argument");

    size_t i = 0;  // Bit index into the data
    // Do the funny zigzag scan
    for (int right = size - 1; right >= 1; right -= 2) {  // Index of right column in each column pair
        if (right == 6)
            right = 5;
        for (int vert = 0; vert < size; vert++) {  // Vertical counter
            for (int j = 0; j < 2; j++) {
                size_t x = static_cast<size_t>(right - j);  // Actual x coordinate
                bool upward = ((right + 1) & 2) == 0;
                size_t y = static_cast<size_t>(upward ? size - 1 - vert : vert);  // Actual y coordinate
                if (!isFunction.at(y).at(x) && i < data.size() * 8) {
                    modules.at(y).at(x) = getBit(data.at(i >> 3), 7 - static_cast<int>(i & 7));
                    i++;
                }
                // If this QR Code has any remainder bits (0 to 7), they were assigned as
                // 0/false/light by the constructor and are left unchanged by this method
            }
        }
    }
    assert(i == data.size() * 8);
}


void QrCode::applyMask(int msk) {
    if (msk < 0 || msk > 7)
        throw std::domain_error("Mask value out of range");
    size_t sz = static_cast<size_t>(size);
    for (size_t y = 0; y < sz; y++) {
        for (size_t x = 0; x < sz; x++) {
            bool invert;
            switch (msk) {
                case 0:  invert = (x + y) % 2 == 0;                    break;
                case 1:  invert = y % 2 == 0;                          break;
                case 2:  invert = x % 3 == 0;                          break;
                case 3:  invert = (x + y) % 3 == 0;                    break;
                case 4:  invert = (x / 3 + y / 2) % 2 == 0;            break;
                case 5:  invert = x * y % 2 + x * y % 3 == 0;          break;
                case 6:  invert = (x * y % 2 + x * y % 3) % 2 == 0;    break;
                case 7:  invert = ((x + y) % 2 + x * y % 3) % 2 == 0;  break;
                default:  throw std::logic_error("Unreachable");
            }
            modules.at(y).at(x) = modules.at(y).at(x) ^ (invert & !isFunction.at(y).at(x));
        }
    }
}


long QrCode::getPenaltyScore() const {
    long result = 0;

    // Adjacent modules in row having same color, and finder-like patterns
    for (int y = 0; y < size; y++) {
        bool runColor = false;
        int runX = 0;
        std::array<int,7> runHistory = {};
        for (int x = 0; x < size; x++) {
            if (module(x, y) == runColor) {
                runX++;
                if (runX == 5)
                    result += PENALTY_N1;
                else if (runX > 5)
                    result++;
            } else {
                finderPenaltyAddHistory(runX, runHistory);
                if (!runColor)
                    result += finderPenaltyCountPatterns(runHistory) * PENALTY_N3;
                runColor = module(x, y);
                runX = 1;
            }
        }
        result += finderPenaltyTerminateAndCount(runColor, runX, runHistory) * PENALTY_N3;
    }
    // Adjacent modules in column having same color, and finder-like patterns
    for (int x = 0; x < size; x++) {
        bool runColor = false;
        int runY = 0;
        std::array<int,7> runHistory = {};
        for (int y = 0; y < size; y++) {
            if (module(x, y) == runColor) {
                runY++;
                if (runY == 5)
                    result += PENALTY_N1;
                else if (runY > 5)
                    result++;
            } else {
                finderPenaltyAddHistory(runY, runHistory);
                if (!runColor)
                    result += finderPenaltyCountPatterns(runHistory) * PENALTY_N3;
                runColor = module(x, y);
                runY = 1;
            }
        }
        result += finderPenaltyTerminateAndCount(runColor, runY, runHistory) * PENALTY_N3;
    }

    // 2*2 blocks of modules having same color
    for (int y = 0; y < size - 1; y++) {
        for (int x = 0; x < size - 1; x++) {
            bool  color = module(x, y);
            if (  color == module(x + 1, y) &&
                  color == module(x, y + 1) &&
                  color == module(x + 1, y + 1))
                result += PENALTY_N2;
        }
    }

    // Balance of dark and light modules
    int dark = 0;
    for (const vector<bool> &row : modules) {
        for (bool color : row) {
            if (color)
                dark++;
        }
    }
    int total = size * size;  // Note that size is odd, so dark/total != 1/2
    // Compute the smallest integer k >= 0 such that (45-5k)% <= dark/total <= (55+5k)%
    int k = static_cast<int>((std::abs(dark * 20L - total * 10L) + total - 1) / total) - 1;
    assert(0 <= k && k <= 9);
    result += k * PENALTY_N4;
    assert(0 <= result && result <= 2568888L);  // Non-tight upper bound based on default values of PENALTY_N1, ..., N4
    return result;
}


vector<int> QrCode::getAlignmentPatternPositions() const {
    if (version == 1)
        return vector<int>();
    else {
        int numAlign = version / 7 + 2;
        int step = (version * 8 + numAlign * 3 + 5) / (numAlign * 4 - 4) * 2;
        vector<int> result;
        for (int i = 0, pos = size - 7; i < numAlign - 1; i++, pos -= step)
            result.insert(result.begin(), pos);
        result.insert(result.begin(), 6);
        return result;
    }
}


int QrCode::getNumRawDataModules(int ver) {
    if (ver < MIN_VERSION || ver > MAX_VERSION)
        throw std::domain_error("Version number out of range");
    int result = (16 * ver + 128) * ver + 64;
    if (ver >= 2) {
        int numAlign = ver / 7 + 2;
        result -= (25 * numAlign - 10) * numAlign - 55;
        if (ver >= 7)
            result -= 36;
    }
    assert(208 <= result && result <= 29648);
    return result;
}


int QrCode::getNumDataCodewords(int ver, Ecc ecl) {
    return getNumRawDataModules(ver) / 8
        - ECC_CODEWORDS_PER_BLOCK    [static_cast<int>(ecl)][ver]
        * NUM_ERROR_CORRECTION_BLOCKS[static_cast<int>(ecl)][ver];
}


vector<uint8_t> QrCode::reedSolomonComputeDivisor(int degree) {
    if (degree < 1 || degree > 255)
        throw std::domain_error("Degree out of range");
    // Polynomial coefficients are stored from highest to lowest power, excluding the leading term which is always 1.
    // For example the polynomial x^3 + 255x^2 + 8x + 93 is stored as the uint8 array {255, 8, 93}.
    vector<uint8_t> result(static_cast<size_t>(degree));
    result.at(result.size() - 1) = 1;  // Start off with the monomial x^0

    // Compute the product polynomial (x - r^0) * (x - r^1) * (x - r^2) * ... * (x - r^{degree-1}),
    // and drop the highest monomial term which is always 1x^degree.
    // Note that r = 0x02, which is a generator element of this field GF(2^8/0x11D).
    uint8_t root = 1;
    for (int i = 0; i < degree; i++) {
        // Multiply the current product by (x - r^i)
        for (size_t j = 0; j < result.size(); j++) {
            result.at(j) = reedSolomonMultiply(result.at(j), root);
            if (j + 1 < result.size())
                result.at(j) ^= result.at(j + 1);
        }
        root = reedSolomonMultiply(root, 0x02);
    }
    return result;
}


vector<uint8_t> QrCode::reedSolomonComputeRemainder(const vector<uint8_t> &data, const vector<uint8_t> &divisor) {
    vector<uint8_t> result(divisor.size());
    for (uint8_t b : data) {  // Polynomial division
        uint8_t factor = b ^ result.at(0);
        result.erase(result.begin());
        result.push_back(0);
        for (size_t i = 0; i < result.size(); i++)
            result.at(i) ^= reedSolomonMultiply(divisor.at(i), factor);
    }
    return result;
}


uint8_t QrCode::reedSolomonMultiply(uint8_t x, uint8_t y) {
    // Russian peasant multiplication
    int z = 0;
    for (int i = 7; i >= 0; i--) {
        z = (z << 1) ^ ((z >> 7) * 0x11D);
        z ^= ((y >> i) & 1) * x;
    }
    assert(z >> 8 == 0);
    return static_cast<uint8_t>(z);
}


int QrCode::finderPenaltyCountPatterns(const std::array<int,7> &runHistory) const {
    int n = runHistory.at(1);
    assert(n <= size * 3);
    bool core = n > 0 && runHistory.at(2) == n && runHistory.at(3) == n * 3 && runHistory.at(4) == n && runHistory.at(5) == n;
    return (core && runHistory.at(0) >= n * 4 && runHistory.at(6) >= n ? 1 : 0)
         + (core && runHistory.at(6) >= n * 4 && runHistory.at(0) >= n ? 1 : 0);
}


int QrCode::finderPenaltyTerminateAndCount(bool currentRunColor, int currentRunLength, std::array<int,7> &runHistory) const {
    if (currentRunColor) {  // Terminate dark run
        finderPenaltyAddHistory(currentRunLength, runHistory);
        currentRunLength = 0;
    }
    currentRunLength += size;  // Add light border to final run
    finderPenaltyAddHistory(currentRunLength, runHistory);
    return finderPenaltyCountPatterns(runHistory);
}


void QrCode::finderPenaltyAddHistory(int currentRunLength, std::array<int,7> &runHistory) const {
    if (runHistory.at(0) == 0)
        currentRunLength += size;  // Add light border to initial run
    std::copy_backward(runHistory.cbegin(), runHistory.cend() - 1, runHistory.end());
    runHistory.at(0) = currentRunLength;
}


bool QrCode::getBit(long x, int i) {
    return ((x >> i) & 1) != 0;
}


/*---- Tables of constants ----*/

const int QrCode::PENALTY_N1 =  3;
const int QrCode::PENALTY_N2 =  3;
const int QrCode::PENALTY_N3 = 40;
const int QrCode::PENALTY_N4 = 10;


const int8_t QrCode::ECC_CODEWORDS_PER_BLOCK[4][41] = {
    // Version: (note that index 0 is for padding, and is set to an illegal value)
    //0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40    Error correction level
    {-1,  7, 10, 15, 20, 26, 18, 20, 24, 30, 18, 20, 24, 26, 30, 22, 24, 28, 30, 28, 28, 28, 28, 30, 30, 26, 28, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30},  // Low
    {-1, 10, 16, 26, 18, 24, 16, 18, 22, 22, 26, 30, 22, 22, 24, 24, 28, 28, 26, 26, 26, 26, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28},  // Medium
    {-1, 13, 22, 18, 26, 18, 24, 18, 22, 20, 24, 28, 26, 24, 20, 30, 24, 28, 28, 26, 30, 28, 30, 30, 30, 30, 28, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30},  // Quartile
    {-1, 17, 28, 22, 16, 22, 28, 26, 26, 24, 28, 24, 28, 22, 24, 24, 30, 28, 28, 26, 28, 30, 24, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30},  // High
};

const int8_t QrCode::NUM_ERROR_CORRECTION_BLOCKS[4][41] = {
    // Version: (note that index 0 is for padding, and is set to an illegal value)
    //0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40    Error correction level
    {-1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 4,  4,  4,  4,  4,  6,  6,  6,  6,  7,  8,  8,  9,  9, 10, 12, 12, 12, 13, 14, 15, 16, 17, 18, 19, 19, 20, 21, 22, 24, 25},  // Low
    {-1, 1, 1, 1, 2, 2, 4, 4, 4, 5, 5,  5,  8,  9,  9, 10, 10, 11, 13, 14, 16, 17, 17, 18, 20, 21, 23, 25, 26, 28, 29, 31, 33, 35, 37, 38, 40, 43, 45, 47, 49},  // Medium
    {-1, 1, 1, 2, 2, 4, 4, 6, 6, 8, 8,  8, 10, 12, 16, 12, 17, 16, 18, 21, 20, 23, 23, 25, 27, 29, 34, 34, 35, 38, 40, 43, 45, 48, 51, 53, 56, 59, 62, 65, 68},  // Quartile
    {-1, 1, 1, 2, 4, 4, 4, 5, 6, 8, 8, 11, 11, 16, 16, 18, 16, 19, 21, 25, 25, 25, 34, 30, 32, 35, 37, 40, 42, 45, 48, 51, 54, 57, 60, 63, 66, 70, 74, 77, 81},  // High
};


data_too_long::data_too_long(const std::string &msg) :
    std::length_error(msg) {}



/*---- Class BitBuffer ----*/

BitBuffer::BitBuffer()
    : std::vector<bool>() {}


void BitBuffer::appendBits(std::uint32_t val, int len) {
    if (len < 0 || len > 31 || val >> len != 0)
        throw std::domain_error("Value out of range");
    for (int i = len - 1; i >= 0; i--)  // Append bit by bit
        this->push_back(((val >> i) & 1) != 0);
}

}

void MainWindow::on_p16_clicked()
{
    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE staff SET presence = :presence WHERE ard = :UDC");
    updateQuery.bindValue(":presence", "out");
    updateQuery.bindValue(":UDC", ref1.left(ref1.length() - 2));
    updateQuery.exec();
}









