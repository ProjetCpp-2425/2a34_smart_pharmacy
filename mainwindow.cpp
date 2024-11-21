    #include "mainwindow.h"
#include "ui_mainwindow.h"
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
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QRandomGenerator>
///tikhdem jawha behy gedgt peiii mahyaich tikhdm
void MainWindow::computeSalaryStats()
{
    QMap<QString, int> roleCounts; // Map to store role names and their counts

    // Check if the table widget is empty
    if (ui->tableWidget->rowCount() == 0) {
        // Show placeholder donut chart for no data
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

    // Count occurrences of each role
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        QTableWidgetItem *roleItem = ui->tableWidget->item(row, 4); // Column 4 assumed for roles
        if (roleItem && !roleItem->text().isEmpty()) {
            QString role = roleItem->text().trimmed();
            roleCounts[role]++;
        }
    }

    // Create donut chart
    QPieSeries *series = new QPieSeries();
    series->setHoleSize(0.25); // Donut effect

    // Add slices for each role
    for (auto it = roleCounts.constBegin(); it != roleCounts.constEnd(); ++it) {
        QPieSlice *slice = new QPieSlice(it.key(), it.value());
        slice->setLabelVisible(true);
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

    ui->chat->setLayout(newLayout);
}



#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
///hedha barr nope
void MainWindow::computeSalaryState()
{
    int countLow = 0;
    int countMedium = 0;
    int countHigh = 0;

    // Check if the table is empty
    if (ui->tableWidget->rowCount() == 0) {
        // Display an empty bar chart with placeholder data, but still show bars
        QBarSet *emptySet = new QBarSet("Salary Ranges");
        *emptySet << 0 << 0 << 0; // Displaying zero values but showing bars

        QBarSeries *emptySeries = new QBarSeries();
        emptySeries->append(emptySet);

        QChart *emptyChart = new QChart();
        emptyChart->addSeries(emptySeries);
        emptyChart->setTitle("Employee Salary Ranges (Empty 0)");

        // Set bar colors to grey for empty data
        emptySet->setBrush(QColor(169, 169, 169)); // Grey color for empty bars
        emptyChart->setAnimationOptions(QChart::SeriesAnimations);

        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(QStringList() << "1200-2500 DT" << "2500-3500 DT" << "3500+ DT");
        emptyChart->addAxis(axisX, Qt::AlignBottom);
        emptySeries->attachAxis(axisX);

        QValueAxis *axisY = new QValueAxis();
        axisY->setTitleText("Number of Employees");
        axisY->setRange(0, 1); // Minimum range for the empty chart
        emptyChart->addAxis(axisY, Qt::AlignLeft);
        emptySeries->attachAxis(axisY);

        // Clear and add the new chart dynamically
        QLayout *existingLayout = ui->aziz->layout();
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

        QVBoxLayout *newLayout = new QVBoxLayout(ui->aziz);
        newLayout->addWidget(chartView);

        ui->aziz->setLayout(newLayout);
        return;
    }

    // Iterate through the table to compute salary stats
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        QTableWidgetItem *salaryItem = ui->tableWidget->item(row, 7); // Assuming salary in column 7
        if (salaryItem) {
            int salary = salaryItem->text().toInt();
            if (salary >= 1200 && salary <= 2500) {
                ++countLow;
            } else if (salary > 2500 && salary <= 3500) {
                ++countMedium;
            } else if (salary > 3500) {
                ++countHigh;
            }
        }
    }

    // If there are no valid entries (all counts are 0), still show bars with grey color
    if (countLow == 0 && countMedium == 0 && countHigh == 0) {
        QBarSet *emptySet = new QBarSet("Salary Ranges");
        *emptySet << 0 << 0 << 0; // Displaying zero values but showing bars
        emptySet->setBrush(QColor(169, 169, 169)); // Grey color for empty bars

        QBarSeries *emptySeries = new QBarSeries();
        emptySeries->append(emptySet);

        QChart *emptyChart = new QChart();
        emptyChart->addSeries(emptySeries);
        emptyChart->setTitle("Employee Salary Ranges (Empty 0)");

        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(QStringList() << "1200-2500 DT" << "2500-3500 DT" << "3500+ DT");
        emptyChart->addAxis(axisX, Qt::AlignBottom);
        emptySeries->attachAxis(axisX);

        QValueAxis *axisY = new QValueAxis();
        axisY->setTitleText("Number of Employees");
        axisY->setRange(0, 1); // Minimum range for the empty chart
        emptyChart->addAxis(axisY, Qt::AlignLeft);
        emptySeries->attachAxis(axisY);

        // Clear and add the new chart dynamically
        QLayout *existingLayout = ui->aziz->layout();
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

        QVBoxLayout *newLayout = new QVBoxLayout(ui->aziz);
        newLayout->addWidget(chartView);

        ui->aziz->setLayout(newLayout);
        return;
    }

    // Bar Chart Design
    QBarSet *set = new QBarSet("Salary Ranges");
    *set << countLow << countMedium << countHigh;

    QBarSeries *series = new QBarSeries();
    series->append(set);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Employee Salary Ranges");

    // Set the bar color for the chart
    set->setBrush(QColor(0, 128, 255)); // Blue color for the bars
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // Bar Categories (X-Axis)
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(QStringList() << "1200-2500 DT" << "2500-3500 DT" << "3500+ DT");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Value Range (Y-Axis)
    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Number of Employees");
    axisY->setRange(0, std::max({countLow, countMedium, countHigh}) + 1);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Clear and add the new chart dynamically
    QLayout *existingLayout = ui->aziz->layout();
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

























MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadTableDataFromDatabase();  // Load the data when the window is created

    QPixmap pix("C:/Users/GIGABYTE/Desktop/khidma inter/interface_qt/img/Nouveau dossier/aze.png");
    ui->pic1->setPixmap(pix);
    QPixmap pix2("C:/Users/GIGABYTE/Desktop/khidma inter/interface_qt/img/Nouveau dossier/stt.png");
    ui->label_64->setPixmap(pix2);
    QPixmap pix3("C:/Users/GIGABYTE/Desktop/khidma inter/interface_qt/img/Nouveau dossier/avc.png");
    ui->label_71->setPixmap(pix3);
    QPixmap pix4("C:/Users/GIGABYTE/Desktop/khidma inter/interface_qt/img/Nouveau dossier/stat.png");
    ui->label_30->setPixmap(pix4);
    //QPixmap pix5("C:/Users/GIGABYTE/Desktop/khidma inter/interface_qt/img/Nouveau dossier/stat.png");
   // ui->label_3->setPixmap(pix5);
    QPixmap pix6("C:/Users/GIGABYTE/Desktop/khidma inter/interface_qt/img/Nouveau dossier/mariem.jpeg");
    ui->label_56->setPixmap(pix6);
    QPixmap pix7("C:/Users/GIGABYTE/Desktop/khidma inter/interface_qt/img/Nouveau dossier/mariem1.jpeg");
    ui->label_62->setPixmap(pix7);
    QPixmap pix8("C:/Users/GIGABYTE/Desktop/khidma inter/interface_qt/img/Nouveau dossier/siwar.jpeg");
    ui->label_35->setPixmap(pix8);
    QPixmap pix9("C:/Users/GIGABYTE/Desktop/khidma inter/interface_qt/img/Nouveau dossier/hazem.jpeg");
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

////////////////////////////////maadech tmesha///////////////////////////////////

#include <QtNetwork>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QByteArray>
#include <QFileInfo>
#include <QMimeData>

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

    // Find the row in the table widget to update
    bool found = false;
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        QTableWidgetItem *item = ui->tableWidget->item(row, 2); // Assuming ID is in the 3rd column (index 2)
        if (item && item->text().toInt() == id) {
            found = true;

            // Modify only the fields that are filled in the table
            if (!login.isEmpty()) {
                ui->tableWidget->setItem(row, 0, new QTableWidgetItem(login));
            }
            if (!password.isEmpty()) {
                ui->tableWidget->setItem(row, 1, new QTableWidgetItem(password));
            }
            if (cin != 0) {
                ui->tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(cin)));
            }
            if (!firstName.isEmpty()) {
                ui->tableWidget->setItem(row, 4, new QTableWidgetItem(firstName));
            }
            if (!lastName.isEmpty()) {
                ui->tableWidget->setItem(row, 5, new QTableWidgetItem(lastName));
            }
            if (!email.isEmpty()) {
                ui->tableWidget->setItem(row, 6, new QTableWidgetItem(email));
            }
            if (!role.isEmpty()) {
                ui->tableWidget->setItem(row, 7, new QTableWidgetItem(role));
            }
            if (phone != 0) {
                ui->tableWidget->setItem(row, 8, new QTableWidgetItem(QString::number(phone)));
            }
            if (!gender.isEmpty()) {
                ui->tableWidget->setItem(row, 9, new QTableWidgetItem(gender));
            }
            if (salary != 0) {
                ui->tableWidget->setItem(row, 10, new QTableWidgetItem(QString::number(salary)));
            }
            if (!dob.isEmpty()) {
                ui->tableWidget->setItem(row, 11, new QTableWidgetItem(dob));
            }
            if (!hireDate.isEmpty()) {
                ui->tableWidget->setItem(row, 12, new QTableWidgetItem(hireDate));
            }

            QMessageBox::information(this, "Modification", "Employee details updated successfully.");
            break;
        }
    }

    if (!found) {
        QMessageBox::warning(this, "Modification", "ID not found in the table. Please refresh the table.");
    }
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
    } else if (ui->radioButton_2->isChecked()) {
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

    // Check if the ID already exists in the table (to avoid duplicates)
    bool alreadyInTable = false;
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        if (ui->tableWidget->item(row, 2)->text() == id) { // Assuming column 2 stores the ID
            alreadyInTable = true;
            break;
        }
    }

    if (alreadyInTable) {
        QMessageBox::warning(this, "Duplicate Entry", "This staff member is already in the table.");
        return;
    }

    // If all validations pass, insert data into the table
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);

    // Insert data into the table widget
    ui->tableWidget->setItem(row, 0, new QTableWidgetItem(login));
    ui->tableWidget->setItem(row, 1, new QTableWidgetItem(password));
    ui->tableWidget->setItem(row, 2, new QTableWidgetItem(id));
    ui->tableWidget->setItem(row, 3, new QTableWidgetItem(cin));
    ui->tableWidget->setItem(row, 4, new QTableWidgetItem(firstName));
    ui->tableWidget->setItem(row, 5, new QTableWidgetItem(lastName));
    ui->tableWidget->setItem(row, 6, new QTableWidgetItem(email));
    ui->tableWidget->setItem(row, 7, new QTableWidgetItem(role));
    ui->tableWidget->setItem(row, 8, new QTableWidgetItem(phone));
    ui->tableWidget->setItem(row, 9, new QTableWidgetItem(gender));
    ui->tableWidget->setItem(row, 10, new QTableWidgetItem(salary));
    ui->tableWidget->setItem(row, 11, new QTableWidgetItem(dob));
    ui->tableWidget->setItem(row, 12, new QTableWidgetItem(hireDate));

    // Display success message
    QMessageBox::information(this, "Success", "Data added successfully!");
}

///tikhdmch

void MainWindow::loadTableDataFromDatabase() {
    // Clear any existing rows in the table widget
    ui->tableWidget->setRowCount(0);

    // Create a query to select all employees from your database
    QSqlQuery query("SELECT * FROM employees");  // Replace with your table name and query

    if (query.exec()) {
        while (query.next()) {
            int row = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row);

            // Assuming your table has columns: login, password, id, etc.
            ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));  // login
            ui->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));  // password
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));  // id
            ui->tableWidget->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));  // cin
            ui->tableWidget->setItem(row, 4, new QTableWidgetItem(query.value(4).toString()));  // firstname
            ui->tableWidget->setItem(row, 5, new QTableWidgetItem(query.value(5).toString()));  // lastname
            ui->tableWidget->setItem(row, 6, new QTableWidgetItem(query.value(6).toString()));  // email
            ui->tableWidget->setItem(row, 7, new QTableWidgetItem(query.value(7).toString()));  // role
            ui->tableWidget->setItem(row, 8, new QTableWidgetItem(query.value(8).toString()));  // phone
            ui->tableWidget->setItem(row, 9, new QTableWidgetItem(query.value(9).toString()));  // gender
            ui->tableWidget->setItem(row, 10, new QTableWidgetItem(query.value(10).toString())); // salary
            ui->tableWidget->setItem(row, 11, new QTableWidgetItem(query.value(11).toString())); // dob
            ui->tableWidget->setItem(row, 12, new QTableWidgetItem(query.value(12).toString())); // hireDate
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
            for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
                QTableWidgetItem *item = ui->tableWidget->item(row, 0); // Assuming the ID is in the first column

                if (item && item->text() == idToDelete) {
                    ui->tableWidget->removeRow(row);
                    QMessageBox::information(this, "Deletion", "Staff member deleted successfully.");
                    found = true;
                    break;
                }
            }

            if (!found) {
                QMessageBox::warning(this, "Deletion Error", "ID not found in table view.");
            }
        } else {
            // If the query fails, rollback the transaction
            db.rollback();
            QMessageBox::warning(this, "Deletion Error", "Failed to delete staff member from database.");
        }
    } else {
        QMessageBox::warning(this, "Transaction Error", "Failed to start transaction.");
    }
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

    // Use tableWidget for PDF export
    QTableWidget *tableWidget = ui->tableWidget;
    if (!tableWidget) {
        QMessageBox::critical(this, "Error", "TableWidget not found!");
        return;
    }

    int leftMargin = 50;
    int topMargin = 50;
    int rowHeight = 50;
    int x = leftMargin;
    int y = topMargin;

    int columnSpacing = 300; // Adjust column spacing for your content
    int rowSpacing = 150;    // Adjust row spacing for readability

    // Write table headers
    painter.setFont(headerFont);
    for (int col = 0; col < tableWidget->columnCount(); ++col) {
        QString header = tableWidget->horizontalHeaderItem(col)->text();
        painter.drawText(x, y, header);
        x += columnSpacing;
    }

    y += rowSpacing;
    x = leftMargin;

    // Write table content
    painter.setFont(contentFont);
    for (int row = 0; row < tableWidget->rowCount(); ++row) {
        for (int col = 0; col < tableWidget->columnCount(); ++col) {
            QTableWidgetItem *item = tableWidget->item(row, col);
            if (item) {
                painter.drawText(x, y, item->text());
            }
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
    QString searchId = ui->edit_2->text().trimmed(); // Assuming the search field is a QLineEdit with objectName 'lineEdit_search'

    // Check if the search ID is empty
    if (searchId.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter an ID to search.");
        return;
    }

    // Search for the ID in the table widget
    bool found = false;
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        QTableWidgetItem *item = ui->tableWidget->item(row, 2); // Assuming ID is in the 3rd column (index 2)
        if (item && item->text() == searchId) {
            found = true;
            // Highlight the found row (optional)
            ui->tableWidget->selectRow(row);
            QMessageBox::information(this, "Search Result", "Employee found!");
            break;
        }
    }

    if (!found) {
        QMessageBox::warning(this, "Search Result", "No employee found with the entered ID.");
    }
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
}

// Function to sort by Salary (Lowest to Highest)
void MainWindow::sortTableBySalary()
{
    // Sort the table by the Salary column (change column number to the correct one)
    ui->tableWidget->sortItems(10, Qt::AscendingOrder);  // Ascending order
}

// Function to sort by Date of Birth (Youngest to Oldest)
void MainWindow::sortTableByDOB()
{
    // Sort the table by the DOB column (change column number to the correct one)
    ui->tableWidget->sortItems(12, Qt::AscendingOrder);  // Ascending order
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
