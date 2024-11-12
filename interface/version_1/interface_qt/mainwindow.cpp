
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include<QMessageBox>
#include"transactions.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/USER/Desktop/khidma inter/interface_qt/img/Nouveau dossier/aze.png");
    ui->pic1->setPixmap(pix);
    QPixmap pix2("C:/Users/USER/Desktop/khidma inter/interface_qt/img/Nouveau dossier/stt.png");
       ui->label_64->setPixmap(pix2);
    QPixmap pix3("C:/Users/USER/Desktop/khidma inter/interface_qt/img/Nouveau dossier/avc.png");
        ui->label_71->setPixmap(pix3);
    QPixmap pix4("C:/Users/USER/Desktop/khidma inter/interface_qt/img/Nouveau dossier/stat.png");
         ui->label_30->setPixmap(pix4);
    QPixmap pix5("C:/Users/USER/Desktop/khidma inter/interface_qt/img/Nouveau dossier/stat.png");
         ui->label_3->setPixmap(pix5);
    QPixmap pix6("C:/Users/USER/Desktop/khidma inter/interface_qt/img/Nouveau dossier/mariem.jpeg");
         ui->label_56->setPixmap(pix6);
    QPixmap pix7("C:/Users/USER/Desktop/khidma inter/interface_qt/img/Nouveau dossier/mariem1.jpeg");
         ui->label_62->setPixmap(pix7);
    QPixmap pix8("C:/Users/USER/Desktop/khidma inter/interface_qt/img/Nouveau dossier/siwar.jpeg");
         ui->label_35->setPixmap(pix8);
         QPixmap pix9("C:/Users/USER/Desktop/khidma inter/interface_qt/img/Nouveau dossier/hazem.jpeg");
              ui->label_34->setPixmap(pix9);
    ui->tableView->setModel(Ttmp.afficher());

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

