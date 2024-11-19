
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include<QMessageBox>
#include"transactions.h"
#include<QFileDialog>
#include<QPainter>
#include<QPdfWriter>
#include<QSqlError>
#include<QDebug>
#include<QSqlQuery>
#include <QDesktopServices>
#include<QDir>
#include<QPageSize>
#include<QMargins>
#include<QImage>
#include<QRectF>
#include<QFont>
#include<QStringList>
#include<QUrl>
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
      // Connect modify button to its slot


    connect(ui->modif_trans, &QPushButton::clicked, this, &MainWindow::on_modif_trans_clicked);
    // Connexion du QComboBox pour trier les transactions
        connect(ui->comboBox_triertrans, SIGNAL(currentIndexChanged(int)), this, SLOT(on_comboBox_triertrans_currentIndexChanged(int)));


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


void MainWindow::on_pushButton_exporterpdf_clicked()
{// Définir le chemin où le PDF sera enregistré
    QString currentPath = QDir::currentPath();
    QString pdfPath = currentPath + "/PDFS/transactions.pdf";

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

    // Ajouter un logo (optionnel)
    QImage logo(currentPath + "/icons/Logo.png");
    if (!logo.isNull()) {
        painter.drawImage(QRectF(100, 50, 1500, 1500), logo); // Ajuster la position et la taille du logo
    }

    // Titre du document
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 20, QFont::Bold)); // Taille de police réduite
    painter.drawText(QRectF(0, 1500, pdf.width(), 500), Qt::AlignCenter, "Transactions List");

    // En-têtes de tableau
    int pageWidth = pdf.width();
    int tableWidth = pageWidth * 0.9; // Tableau large à 90% de la largeur de la page
    int columnWidth = tableWidth / 6; // Répartition en 6 colonnes
    int xLeftMargin = (pageWidth - tableWidth) / 2; // Centrer horizontalement
    int yStart = 2500;        // Position verticale de départ
    int rowHeight = 400;      // Hauteur réduite pour chaque ligne

    // Dessiner l'arrière-plan des en-têtes
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::lightGray);
    painter.drawRect(xLeftMargin, yStart, tableWidth, rowHeight);

    // Définir le style des en-têtes
    painter.setFont(QFont("Arial", 8, QFont::Bold)); // Réduction de la taille de la police
    painter.setPen(Qt::black);

    QStringList headers = { "ID", "Total Amount", "Type", "Category", "Payment Method", "Date" };
    for (int i = 0; i < headers.size(); ++i) {
        painter.drawText(xLeftMargin + i * columnWidth, yStart + 300, headers[i]);
    }

    // Dessiner le contenu du tableau
    yStart += rowHeight; // Descendre sous les en-têtes
    painter.setFont(QFont("Arial", 9)); // Police plus petite pour les données
    painter.setPen(Qt::black);

    QSqlQuery query;
    query.prepare("SELECT ID_TRANSACTION, TOTAL_AMOUNT, TYPE, CATEGORY, PAYMENT_METHOD, DATE_TRANSACTION FROM transactions");
    query.exec();

    while (query.next()) {
        painter.drawText(xLeftMargin + 0 * columnWidth, yStart + 300, query.value(0).toString());
        painter.drawText(xLeftMargin + 1 * columnWidth, yStart + 300, query.value(1).toString());
        painter.drawText(xLeftMargin + 2 * columnWidth, yStart + 300, query.value(2).toString());
        painter.drawText(xLeftMargin + 3 * columnWidth, yStart + 300, query.value(3).toString());
        painter.drawText(xLeftMargin + 4 * columnWidth, yStart + 300, query.value(4).toString());
        painter.drawText(xLeftMargin + 5 * columnWidth, yStart + 300, query.value(5).toDate().toString("dd/MM/yyyy"));
        yStart += rowHeight;
    }

    // Terminer le dessin
    painter.end();

    // Afficher un message pour l'utilisateur
    int response = QMessageBox::question(
        this, "Generate PDF",
        "<PDF Saved>... Do You Want to View the PDF?",
        QMessageBox::Yes | QMessageBox::No);

    if (response == QMessageBox::Yes) {
        QDesktopServices::openUrl(QUrl::fromLocalFile(pdfPath));
    }
}
////////////////////////////////////statistiques////////////////////////////////////

/*void MainWindow::sendSms(const QString& toPhoneNumber, const QString& message)
{

    // Twilio credentials
    const QString accountSid = "";
    const QString authToken = "";
    const QString fromPhoneNumber = "";  // Replace with your Twilio number

    // API endpoint
    QUrl apiUrl("https://api.twilio.com/2010-04-01/Accounts/" + accountSid + "/Messages.json");


    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    QNetworkRequest request(apiUrl);



    // QUrl apiUrl("https://api.twilio.com/2010-04-01/Accounts/" + accountSid + "/Messages.json");
    QString authValue = "Basic " + QString(QByteArray(QString("%1:%2").arg(accountSid).arg(authToken).toUtf8()).toBase64());
    request.setRawHeader("Authorization", authValue.toUtf8());


    QHttpMultiPart* multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

    QHttpPart toPart;
    toPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"To\""));
    toPart.setBody(toPhoneNumber.toUtf8());

    QHttpPart fromPart;
    fromPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"From\""));
    fromPart.setBody(fromPhoneNumber.toUtf8());

    QHttpPart bodyPart;
    bodyPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"Body\""));
    bodyPart.setBody(message.toUtf8());


    multiPart->append(toPart);
    multiPart->append(fromPart);
    multiPart->append(bodyPart);


    QNetworkReply* reply = manager->post(request, multiPart);
    multiPart->setParent(reply);

    connect(reply, &QNetworkReply::finished, [reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            QMessageBox::information(nullptr, "Success", "SMS sent successfully!");
        } else {
            QByteArray responseData = reply->readAll();
            QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
            QString errorMessage = jsonResponse["message"].toString();

            qDebug() << "Error sending SMS:" << reply->errorString();
            qDebug() << "Twilio response:" << jsonResponse;
            QMessageBox::warning(nullptr, "Error", "Failed to send SMS: " + errorMessage);
        }
        reply->deleteLater();
    });
}
void MainWindow::onSmsSent(QNetworkReply* reply)
{
    // Check if the SMS was sent successfully
    if (reply->error() == QNetworkReply::NoError) {
        QMessageBox::information(this, "Success", "SMS sent successfully!");
    } else {
        // Handle error and show the response from the Twilio API
        QString error = reply->errorString();
        qDebug() << "Error sending SMS: " << error;
        QMessageBox::warning(this, "Error", "Failed to send SMS: " + error);
    }

    // Clean up after the reply
    reply->deleteLater();
}*/
