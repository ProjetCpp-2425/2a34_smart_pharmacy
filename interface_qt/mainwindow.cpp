
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



//// arduino
//#include "arduino_ma.h"
//#include<QTimer>
//#include <QSerialPort>





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
         ui->label_5->setPixmap(pix6);
    QPixmap pix7("C:/Users/USER/Desktop/khidma inter/interface_qt/img/Nouveau dossier/mariem1.jpeg");
         ui->label_2->setPixmap(pix7);
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
        // Connecter le bouton pour afficher le calendrier
            //connect(ui->showCalendarButton, &QPushButton::clicked, this, &MainWindow::on_showCalendarButton_clicked);


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
    connect(ui->pushButton_statistics, &QPushButton::clicked, this, &MainWindow::on_pushButton_statistics_clicked);
    connect(ui->pushButton_envoyer, &QPushButton::clicked, this, &MainWindow::on_pushButton_envoyer_clicked);




    // Connecter le signal clicked() du QCalendarWidget à la méthode
        connect(ui->calendarWidget, &QCalendarWidget::clicked, this, &MainWindow::onCalendarDateClicked);

        // Remplir le calendrier avec les transactions
        populateCalendarWithTransactions();




     /*   arduino = new Arduino();  // Création de l'objet Arduino
          //  arduino->connect_arduino(); // Connexion à l'Arduino

            // Configurez le timer pour lire périodiquement les données
            connect(&timer, &QTimer::timeout, this, &MainWindow::readFromArduino);
            timer.start(100);  // Lire toutes les 100 ms*/
}

MainWindow::~MainWindow()
{
    delete ui;
  // delete arduino;
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
{  // Récupération des informations saisies dans les champs
    QString idText = ui->lineEdit_idtrans->text().trimmed();
    QString totalAmountText = ui->lineEdit_totamount->text().trimmed();
    QString type = ui->lineEdit_type->text().trimmed();
    QString paymentMethod = ui->lineEdit_payment->text().trimmed();
    QString category = ui->lineEdit_category->text().trimmed();
    QDate dateTransaction = ui->dateEdit_date->date();

    // Vérifier si tous les champs nécessaires sont remplis
    if (idText.isEmpty() || totalAmountText.isEmpty() || type.isEmpty() || paymentMethod.isEmpty() || category.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Tous les champs doivent être remplis.");
        return;
    }

    // Vérification que l'ID est un nombre de 5 chiffres
    if (idText.length() != 5 || !idText.toInt()) {
        QMessageBox::warning(this, "Erreur de saisie", "L'ID de la transaction doit être un nombre entier de 5 chiffres.");
        return;
    }

    // Vérification du montant (doit être un nombre positif valide)
    bool amountOk;
    float totalAmount = totalAmountText.toFloat(&amountOk);  // Conversion du texte en float
    if (!amountOk || totalAmount <= 0) {
        QMessageBox::warning(this, "Erreur de saisie", "Le montant doit être un nombre positif valide.");
        return;
    }

    // Vérification du type de transaction (doit être 'income' ou 'expense')
    if (type != "income" && type != "expense") {
        QMessageBox::warning(this, "Erreur de saisie", "Le type de transaction doit être 'income' ou 'expense'.");
        return;
    }

    // Créer l'objet transaction avec les valeurs saisies
    int id = idText.toInt(); // ID récupéré comme entier
    transactions T(id, totalAmount, type, category, paymentMethod, dateTransaction);
    bool test = T.ajouter();  // Ajouter la transaction à la base de données

    if (test) {
        // Rafraîchir l'affichage de la table
        ui->tableView->setModel(Ttmp.afficher());
        populateCalendarWithTransactions(); // Mise à jour du calendrier
        QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("Ajout effectué\nClick Cancel to exit."), QMessageBox::Cancel);

        // Effacer les champs après ajout
        ui->lineEdit_idtrans->clear();
        ui->lineEdit_totamount->clear();
        ui->lineEdit_type->clear();
        ui->lineEdit_payment->clear();
        ui->lineEdit_category->clear();
        ui->dateEdit_date->setDate(QDate::currentDate());  // Réinitialiser la date à la date actuelle
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"), QObject::tr("Ajout non effectué.\nClick Cancel to exit."), QMessageBox::Cancel);
    }

}


void MainWindow::on_pushButton_delete_clicked()
{
    // Récupérer l'ID de la transaction à supprimer
        QString idText = ui->edit_iddelete->text().trimmed();

        // Vérifier que l'ID a exactement 5 chiffres
        if (idText.length() != 5 || !idText.toInt()) {
            QMessageBox::warning(nullptr, QObject::tr("Erreur"), QObject::tr("L'ID doit être un nombre entier de 5 chiffres."), QMessageBox::Cancel);
            return;  // Arrêter l'exécution si l'ID n'est pas valide
        }

        // Convertir l'ID en entier
        int id = idText.toInt();

        // Vérifier si l'ID existe dans la base de données
        QSqlQuery query;
        query.prepare("SELECT COUNT(*) FROM transactions WHERE ID_TRANSACTION = :id");
        query.bindValue(":id", id);

        if (!query.exec()) {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Erreur de base de données !"), QMessageBox::Cancel);
            return;
        }

        query.next();
        int count = query.value(0).toInt();

        if (count == 0) {
            // Si l'ID n'existe pas dans la base de données
            QMessageBox::warning(nullptr, QObject::tr("Erreur"), QObject::tr("Aucune transaction trouvée avec cet ID."), QMessageBox::Cancel);
            return;  // Arrêter l'exécution si l'ID n'existe pas
        }

        // Supprimer la transaction
        bool test = Ttmp.supprimer(id);

        if (test) {
            // Rafraîchir la table et mettre à jour le calendrier
            ui->tableView->setModel(Ttmp.afficher());
            populateCalendarWithTransactions(); // Mise à jour du calendrier

            // Afficher un message de succès
            QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("Suppression effectuée\nClick Cancel to exit."), QMessageBox::Cancel);

            // Effacer le champ ID après la suppression
            ui->edit_iddelete->clear();  // Efface le contenu du champ d'ID
        } else {
            // Afficher un message d'erreur si la suppression a échoué
            QMessageBox::critical(nullptr, QObject::tr("Not OK"), QObject::tr("Suppression non effectuée.\nClick Cancel to exit."), QMessageBox::Cancel);
        }

}




void MainWindow::on_modif_trans_clicked()
{ // Récupération des informations saisies dans les champs pour modification
    QString idText = ui->lineEdit_idtrans->text().trimmed();
    QString totalAmountText = ui->lineEdit_totamount->text().trimmed();
    QString type = ui->lineEdit_type->text().trimmed();
    QString category = ui->lineEdit_category->text().trimmed();
    QString paymentMethod = ui->lineEdit_payment->text().trimmed();
    QDate dateTransaction = ui->dateEdit_date->date();

    // Vérifier si tous les champs nécessaires sont remplis
    if (idText.isEmpty() || totalAmountText.isEmpty() || type.isEmpty() || paymentMethod.isEmpty() || category.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Tous les champs doivent être remplis.");
        return;
    }

    // Vérification que l'ID est un nombre de 5 chiffres
    if (idText.length() != 5 || !idText.toInt()) {
        QMessageBox::warning(this, "Erreur de saisie", "L'ID de la transaction doit être un nombre entier de 5 chiffres.");
        return;
    }

    // Vérification du montant (doit être un nombre positif valide)
    bool amountOk;
    float totalAmount = totalAmountText.toFloat(&amountOk);  // Conversion du texte en float
    if (!amountOk || totalAmount <= 0) {
        QMessageBox::warning(this, "Erreur de saisie", "Le montant doit être un nombre positif valide.");
        return;
    }

    // Vérification du type de transaction (doit être 'income' ou 'expense')
    if (type != "income" && type != "expense") {
        QMessageBox::warning(this, "Erreur de saisie", "Le type de transaction doit être 'income' ou 'expense'.");
        return;
    }

    // Créer un objet temporaire pour mettre à jour la transaction
    int id = idText.toInt(); // ID récupéré comme entier
    transactions T;
    T.setId_transaction(id);
    T.setTotal_amount(totalAmount);
    T.setType(type);
    T.setCategory(category);
    T.setPayment_method(paymentMethod);
    T.setDate(dateTransaction);

    // Appel de la fonction de modification
    bool test = T.modifier(id);

    if (test) {
        // Rafraîchir l'affichage de la table
        ui->tableView->setModel(Ttmp.afficher());
        populateCalendarWithTransactions(); // Mise à jour du calendrier
        QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("Modification effectuée\nClick Cancel to exit."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"), QObject::tr("Modification non effectuée.\nClick Cancel to exit."), QMessageBox::Cancel);
}
}


void MainWindow::on_pushButton_donesearch_clicked()
{
    QString searchText = ui->edit_search->text(); // Texte saisi par l'utilisateur

        // Si le champ de recherche est vide, afficher toutes les transactions
        if (searchText.isEmpty()) {
            ui->tableView->setModel(Ttmp.afficher()); // Méthode pour afficher toutes les transactions
            return;
        }

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

{    Q_UNUSED(index);
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

           // Add slice with percentage
           QPieSlice *slice = paymentMethodSeries->append(
               QString("%1 (%2%)").arg(paymentMethod).arg(QString::number(percentage, 'f', 2)),
               count);
           slice->setLabelVisible(true);                  // Make label visible
           slice->setLabelPosition(QPieSlice::LabelOutside); // Place label outside
           // Removed `slice->setExploded();` to prevent slices from being exploded
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


/*void MainWindow::on_showCalendarButton_clicked()
{
    // Créer un widget de calendrier
        QCalendarWidget *calendar = new QCalendarWidget(this);
        calendar->setGridVisible(true);
        calendar->setFirstDayOfWeek(Qt::Sunday);

        // Changer la couleur de l'année et du mois en noir (en-têtes)
        QPalette palette = calendar->palette();
        palette.setColor(QPalette::WindowText, Qt::black);  // Change la couleur de texte des en-têtes
        calendar->setPalette(palette);

        // Récupérer le modèle de données associé au QTableView
        QSqlTableModel *model = qobject_cast<QSqlTableModel *>(ui->tableView->model());

        // Créer des variables pour compter les entrées de type "Income" et "Expense"
        int incomeCount = 0;
        int expenseCount = 0;

        // Vérifier que le modèle de données est valide
        if (model) {
            // Récupérer toutes les lignes du modèle
            for (int row = 0; row < model->rowCount(); ++row) {
                // Récupérer la date et le type (Income ou Expense) depuis les colonnes correspondantes
                QDate date = model->data(model->index(row, 5)).toDate(); // La colonne "Date" est la 6ème colonne (index 5)
                QString type = model->data(model->index(row, 2)).toString(); // La colonne "Type" est la 3ème colonne (index 2)

                // Vérifier que la date est valide
                if (!date.isValid()) {
                    continue; // Si la date est invalide, on passe à l'enregistrement suivant
                }

                // Créer un format pour la date en fonction du type
                QTextCharFormat format;
                if (type == "Income") {
                    format.setForeground(Qt::blue); // Bleu pour "Income"
                    incomeCount++; // Incrémenter le compteur des "Income"
                } else if (type == "Expense") {
                    format.setForeground(Qt::green); // Vert pour "Expense"
                    expenseCount++; // Incrémenter le compteur des "Expense"
                }

                // Appliquer la couleur à la date sur le calendrier
                calendar->setDateTextFormat(date, format);
            }
        }

        // Créer une fenêtre de dialogue pour afficher le calendrier
        QDialog *calendarDialog = new QDialog(this);
        calendarDialog->setWindowTitle("Calendrier");

        // Créer un layout vertical et ajouter le calendrier à ce layout
        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(calendar);

        // Appliquer le layout à la fenêtre de dialogue
        calendarDialog->setLayout(layout);

        // Afficher la fenêtre du calendrier
        calendarDialog->exec();

        // Afficher les statistiques (compteurs)
        qDebug() << "Total des Income : " << incomeCount;
        qDebug() << "Total des Expense : " << expenseCount;
    }
*/
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
    const QString fromPhoneNumber = "";  // Remplacez par votre numéro Twilio

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




////////////////////////////////


// Méthode pour configurer les dates dans le calendrier
void MainWindow::populateCalendarWithTransactions() {
    // Réinitialiser les formats de texte de toutes les dates
        QTextCharFormat defaultFormat;  // Format par défaut, sans couleur
        QDate startDate = ui->calendarWidget->minimumDate();  // Récupérer la date minimale du calendrier
        QDate endDate = ui->calendarWidget->maximumDate();  // Récupérer la date maximale du calendrier

        // Parcourir toutes les dates et réinitialiser leur format
        for (QDate date = startDate; date <= endDate; date = date.addDays(1)) {
            ui->calendarWidget->setDateTextFormat(date, defaultFormat);
        }

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

/////////////
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



/*void MainWindow::readFromArduino()
{
    QByteArray data = arduino->read_from_arduino();  // Lire les données envoyées par Arduino

    if (!data.isEmpty()) {
        for (int i = 0; i < data.size(); ++i) {
            char key = data[i];

            if (key == '*') {
                // Si la touche '*' est pressée, afficher le code sans '*'
                QMessageBox::information(this, "Succès", "Code saisi : " + code);
                code.clear();  // Réinitialiser le code après l'affichage
            } else {
                // Sinon, ajouter la touche au code
                code.append(key);
            }
        }
    }
}
*/
