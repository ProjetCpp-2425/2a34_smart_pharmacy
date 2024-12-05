#include <QDate>
#include "mainwindow.h"
#include "notification.h"
#include "ui_mainwindow.h"
#include "stock.h"
#include <QMessageBox>
#include <QRegularExpressionValidator>
#include <QSqlError>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QPainter>
#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextCursor>
#include <QTextTable>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QTableView>
#include <QBrush>
#include <QColor>
#include <QFont>
#include <QLabel>
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QPdfWriter>

QList<StockHistory> stockHistoryLog;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    connect(ui->Historique, &QPushButton::clicked, this, [this]() {
        // Create an instance of stock
        stock stockInstance;

        // Get the stock history model
        QSqlQueryModel* historyModel = stockInstance.historique();

        // Set the model to the table view
        ui->tableView_3->setModel(historyModel);
    });


    // 1. Set up the clickable label with rich text (for links)
   // ui->stockwarning->setText("<a href=\"notification\">Click for notification</a>");

    //ui->export_2, &QPushButton::clicked, this, &MainWindow::on_export_2_c;

   // ui->stockwarning->setAttribute(Qt::WA_Hover, true);
   // ui->stockwarning->setCursor(Qt::PointingHandCursor);

    // Input validation
    QRegularExpression numberRegex("[0-9]{1,10}");
    QRegularExpressionValidator* numberValidator = new QRegularExpressionValidator(numberRegex, this);
    ui->code_ui->setValidator(numberValidator);
    ui->quantity_ui->setValidator(numberValidator);

    QRegularExpression letterRegex("[A-Za-z]{1,20}");
    QRegularExpressionValidator* letterValidator = new QRegularExpressionValidator(letterRegex, this);
    ui->name_ui->setValidator(letterValidator);
    ui->type_ui->setValidator(letterValidator);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Define the link activation handler/
//void MainWindow::on_stockwarning_linkActivated(const QString &link)
//{
    // Handle the link activation here
  //  qDebug() << "Link activated: " << link;
    // Add your notification handling logic here
//}

void MainWindow::logStockHistory(const QString &action, int code, const QString &nom, const QString &type,
                                 int quantiteOld, int quantiteNew, const QDate &dateExpirationOld,
                                 const QDate &dateExpirationNew, const QString &user)
{
    StockHistory history;
    history.action = action;
    history.code = code;
    history.nom = nom;
    history.type = type;
    history.quantiteOld = quantiteOld;
    history.quantiteNew = quantiteNew;
    history.dateExpirationOld = dateExpirationOld;
    history.dateExpirationNew = dateExpirationNew;
    history.user = user;
    history.dateAction = QDateTime::currentDateTime();  // Timestamp of the modification

    // Add the entry to the history log
    stockHistoryLog.append(history);
}




void MainWindow::on_ajoute_clicked()
{
    QString codeText = ui->code_ui->text();
    QString quantityText = ui->quantity_ui->text();
    QString nom_stock = ui->name_ui->text();
    QString type_stock = ui->type_ui->text();
    QDate date_stock = ui->date_ui->date();  // Get date from QDateEdit widget
    QDate date_expiration = ui->date_ui->date();  // Get expiration date from QDateEdit widget

    // Ensure fields are filled
    if (codeText.isEmpty() || quantityText.isEmpty() || nom_stock.isEmpty() || type_stock.isEmpty() ||
        !date_stock.isValid() || !date_expiration.isValid()) {
        QMessageBox::warning(this, "Input Error", "All fields must be filled correctly.");
        return;
    }

    // C text to integers
    int code_stock = codeText.toInt();
    int quantity_stock = quantityText.toInt();

    // Create stock and add to database
    stock s(code_stock, quantity_stock, nom_stock, type_stock, date_stock, date_expiration);
    if (s.ajouter()) {
        QMessageBox::information(this, "Success", "Stock added successfully.");
        ui->tableView->setModel(s.afficher());

        // Log history for the added stock
        QSqlQuery query;
        query.prepare("INSERT INTO STOCK_HISTORY (ACTION, CODE, NOM, TYPE, QUANTITE, DATE_ACTION, USER) "
                      "VALUES ('Added', :code, :nom, :type, :quantite, :date, :user)");
        query.bindValue(":code", code_stock);
        query.bindValue(":nom", nom_stock);
        query.bindValue(":type", type_stock);
        query.bindValue(":quantite", quantity_stock);
        query.bindValue(":date", date_stock);

        if (!query.exec()) {
            qDebug() << "Failed to log history: " << query.lastError().text();
        }

    } else {
        QMessageBox::critical(this, "Error", "Failed to add stock.");
    }

    // Clear inputs after addition
    ui->code_ui->clear();
    ui->quantity_ui->clear();
    ui->name_ui->clear();
    ui->type_ui->clear();
    ui->date_ui->clear();
}

void MainWindow::on_delete_2_clicked()
{
    stock s;
    int code = ui->code_ui->text().toInt();

    bool test = s.supprimer(code);
    if (test) {
        ui->tableView->setModel(s.afficher());
        QMessageBox::information(nullptr, QObject::tr("Suppression avec succès"),
                                 QObject::tr("Suppression réussie.\nClick Cancel to exit."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur de suppression"),
                              QObject::tr("Suppression échouée.\nClick Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_show_clicked() {
    stock s;
    ui->tableView->setModel(s.afficher());
}

void MainWindow::on_edit_clicked()
{
    // Retrieve values from the UI
    QString codeText = ui->code_ui->text();
    if (codeText.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Code must not be empty.");
        return;
    }

    int code_stock = codeText.toInt();
    QString quantityText = ui->quantity_ui->text();
    int quantity_stock = quantityText.isEmpty() ? 0 : quantityText.toInt();  // Default to 0 if empty
    QString nom_stock = ui->name_ui->text();
    QString type_stock = ui->type_ui->text();
    QDate date_stock = ui->date_ui->date();
    QDate date_expiration = ui->date_ui->date();

    // Fetch the old stock data before modification
    stock oldStock = fetchStockByCode(code_stock);  // Fetch the current stock details from the database

    // Get the old values (before modification)
    QString oldNom = oldStock.getNom();
    int oldQuantity = oldStock.getQuantity();
    QDate oldDateExpiration = oldStock.getExpirationDate();

    // Create a new stock object with the updated values
    stock s(code_stock, quantity_stock, nom_stock, type_stock, date_stock, date_expiration);

    // Log the modification to stock_history table
    QString currentUser = "currentUser"; // Replace with actual user context if available
    QSqlQuery queryHistory;
    queryHistory.prepare("INSERT INTO STOCK_HISTORY (CODE_H, NOM_H, TYPE_H, DATE_EXPIRATION_H, QUANTITY_H) "
                         "VALUES (:CODE_H, :NOM_H, :TYPE_H, :DATE_EXPIRATION_H, :QUANTITY_H)");

    queryHistory.bindValue(":CODE_H", code_stock);
    queryHistory.bindValue(":NOM_H", oldNom);  // Log the old stock name
    queryHistory.bindValue(":TYPE_H", type_stock);  // Log the new stock type
    queryHistory.bindValue(":DATE_EXPIRATION_H", oldDateExpiration);  // Log the old expiration date
    queryHistory.bindValue(":QUANTITY_H", oldQuantity);  // Log the old quantity

    // Execute the query to insert into the history table
    if (!queryHistory.exec()) {
        qDebug() << "Error inserting into stock_history: " << queryHistory.lastError();
    } else {
        qDebug() << "History record inserted successfully.";
    }

    // Proceed with modifying the stock in the database
    if (s.modifier()) {
        QMessageBox::information(this, "Success", "Stock modified successfully.");
        ui->tableView->setModel(s.afficher());  // Update the stock table view
    } else {
        QMessageBox::critical(this, "Error", "Failed to modify stock. Ensure CODE exists.");
    }

    // Clear the input fields after modification
    ui->code_ui->clear();
    ui->quantity_ui->clear();
    ui->name_ui->clear();
    ui->type_ui->clear();
    ui->date_ui->clear();
}

void MainWindow::on_Historique_clicked()
{
    // Create a query model for displaying the stock history
    QSqlQueryModel *historyModel = new QSqlQueryModel();

    // Prepare the SQL query to fetch all records from STOCK_HISTORY
    historyModel->setQuery("SELECT * FROM STOCK_HISTORY ORDER BY CODE_H DESC");

    // Check if the query executed successfully
    if (historyModel->lastError().isValid()) {
        qDebug() << "Error fetching stock history: " << historyModel->lastError().text();
        return;
    }

    // Optionally set the column headers
    historyModel->setHeaderData(0, Qt::Horizontal, "Code");
    historyModel->setHeaderData(1, Qt::Horizontal, "Name");
    historyModel->setHeaderData(2, Qt::Horizontal, "Type");
    historyModel->setHeaderData(3, Qt::Horizontal, "Expiration Date");
    historyModel->setHeaderData(4, Qt::Horizontal, "Quantity");

    // Check if the model has data
    if (historyModel->rowCount() == 0) {
        qDebug() << "No data found in the history table.";
    } else {
        qDebug() << historyModel->rowCount() << " rows found in the history table.";
    }

    // Set the model to the table view to display the data
    ui->tableView_3->setModel(historyModel);
}



void MainWindow::on_tri_clicked()
{
    QString searchTerm = ui->searchInput->text();
    QString searchColumn;

    if (ui->radio_code->isChecked()) {
        searchColumn = "CODE";
    } else if (ui->radio_nom->isChecked()) {
        searchColumn = "NOM";
    } else if (ui->radio_type->isChecked()) {
        searchColumn = "TYPE";
    }

    QString queryStr = QString("SELECT CODE, NOM, TYPE, QUANTITE, DATE_EXPIRATION FROM MEDICAMENTS WHERE LOWER(%1) LIKE LOWER(:searchTerm)").arg(searchColumn);
    qDebug() << "Executing query: " << queryStr;

    QSqlQuery query;
    query.prepare(queryStr);
    query.bindValue(":searchTerm", "%" + searchTerm + "%");

    if (query.exec()) {
        qDebug() << "Query executed successfully";

        QSqlQueryModel* model = new QSqlQueryModel;
        model->setQuery(std::move(query));
        ui->tableView_2->setModel(model);
    } else {
        qDebug() << "Query failed: " << query.lastError().text();
    }
}

void MainWindow::on_stats_clicked()
{

    int typeCount = 0, nameCount = 0, quantityCount = 0;

    // Query to get data from MEDICAMENTS table
    QSqlQuery query;
    query.prepare("SELECT TYPE, NOM, QUANTITE FROM MEDICAMENTS");
    if (query.exec()) {
        while (query.next()) {
            QString type = query.value("TYPE").toString();
            QString name = query.value("NOM").toString();
            int quantity = query.value("QUANTITE").toInt();

            if (!type.isEmpty()) typeCount++;
            if (!name.isEmpty()) nameCount++;
            if (quantity > 0) quantityCount++;
        }
    }

    // Total count for calculating percentages
    int totalCount = typeCount + nameCount + quantityCount;
    if (totalCount == 0) {
        QMessageBox::information(this, "Statistiques", "Aucune donnée disponible pour les statistiques.");
        return;
    }

    // Prepare strings for display
    QString typeCountStr = QString::number(typeCount);
    QString nameCountStr = QString::number(nameCount);
    QString quantityCountStr = QString::number(quantityCount);

    // Calculate percentages
    double typePercentage = (static_cast<double>(typeCount) / totalCount) * 100;
    double namePercentage = (static_cast<double>(nameCount) / totalCount) * 100;
    double quantityPercentage = (static_cast<double>(quantityCount) / totalCount) * 100;

    // Create the pie chart series
    auto *series = new QPieSeries();
    series->setHoleSize(0.35);
    series->append(QString("Type: %1 (%2%)").arg(typeCountStr).arg(typePercentage, 0, 'f', 1), typeCount);
    series->append(QString("Nom: %1 (%2%)").arg(nameCountStr).arg(namePercentage, 0, 'f', 1), nameCount);
    series->append(QString("Quantité: %1 (%2%)").arg(quantityCountStr).arg(quantityPercentage, 0, 'f', 1), quantityCount);

    // Customize pie slices to show percentages
    for (auto slice : series->slices()) {
        slice->setLabelVisible(true);
    }

    // Create the chart
    auto *chart = new QChart();
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setTitle("<h2 style='color:darkblue'>Statistiques des Médicaments</h2>");
    chart->legend()->setAlignment(Qt::AlignRight);

    // Create the chart view
    auto *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Create a widget to hold the chart and details
    QWidget *statsWidget = new QWidget(this);
    statsWidget->setWindowTitle("Statistiques des Médicaments");

    // Set a custom background color for the widget
    statsWidget->setStyleSheet("background-color: #f0f8ff;"); // Light blue background

    QVBoxLayout *layout = new QVBoxLayout(statsWidget);

    // Add the chart view
    layout->addWidget(chartView);

    // Add a details section
    QLabel *details = new QLabel(statsWidget);
    details->setText(
        QString("<h3 style='color:darkgreen'>Détails des Statistiques</h3>"
                "<ul>"
                "<li><b>Nombre de Types:</b> %1 (%2%)</li>"
                "<li><b>Nombre de Noms:</b> %3 (%4%)</li>"
                "<li><b>Nombre de Quantités Disponibles:</b> %5 (%6%)</li>"
                "</ul>")
            .arg(typeCountStr)
            .arg(typePercentage, 0, 'f', 1)
            .arg(nameCountStr)
            .arg(namePercentage, 0, 'f', 1)
            .arg(quantityCountStr)
            .arg(quantityPercentage, 0, 'f', 1));
    details->setWordWrap(true);
    layout->addWidget(details);

    // Add a back button
    QPushButton *backButton = new QPushButton("Retour", statsWidget);

    // Set the custom style for the back button
    backButton->setStyleSheet("background-color: #e0ffff; color: black; font-weight: bold;");

    // Add the back button to the layout
    layout->addWidget(backButton);

    // Connect the back button to its functionality
    connect(backButton, &QPushButton::clicked, this, [this, statsWidget]() {
        statsWidget->deleteLater(); // Schedule the stats widget for deletion
        ui->centralwidget->show();  // Immediately show the main UI
    });

    // Set up the stats widget layout
    statsWidget->setLayout(layout);
    statsWidget->resize(800, 600);
    statsWidget->show();

    // Hide the main UI while displaying the stats
    ui->centralwidget->hide();
}



void MainWindow::on_export_2Button_clicked()
{
    QMessageBox::information(this, "Debug", "Button clicked!");
}





void MainWindow::on_PDF_clicked()
{
    qDebug() << "Export PDF button clicked";

    // Create a QSqlQuery to fetch the data directly from the MEDICAMENTS table
    QSqlQuery query;
    query.prepare("SELECT CODE, NOM, TYPE, DATE_EXPIRATION, QUANTITE FROM MEDICAMENTS");

    // Execute the query
    if (!query.exec()) {
        QMessageBox::warning(this, tr("Error"), tr("Failed to fetch stock data: ") + query.lastError().text());
        return;
    }

    // Open a file dialog to save the PDF
    QString filePath = QFileDialog::getSaveFileName(this, tr("Save PDF"), "Stock_Report.pdf", tr("PDF Files (*.pdf)"));
    if (filePath.isEmpty())
        return; // User canceled the dialog

    // Set up the QPrinter object for exporting to a PDF
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filePath); // Use the file path from QFileDialog
    printer.setPageSize(QPageSize::A4);
    printer.setDocName("Stock Report");

    // Create a QPainter object for painting on the PDF
    QPainter painter;
    if (!painter.begin(&printer)) {
        QMessageBox::warning(this, tr("Error"), tr("Failed to create PDF file."));
        return;
    }

    // Set the font for the content (larger font for better readability)
    QFont pdfFont("Arial", 12); // Font size 12 for content
    painter.setFont(pdfFont);

    // Set initial position for drawing text
    int x = 50;  // Starting X coordinate
    int y = 150; // Starting Y coordinate (after title)
    int rowHeight = 50; // Reasonable row height for better spacing
    int headerHeight = 50; // Header row height

    // Define column widths for better visibility and space
    int codeWidth = 150;    // Adjusted width for "Code"
    int nameWidth = 200;    // Adjusted width for "Name"
    int typeWidth = 200;    // Adjusted width for "Type"
    int dateWidth = 200;    // Adjusted width for "Date Expiration"
    int quantityWidth = 200; // Adjusted width for "Quantity"

    // Add extra space between the columns
    int columnSpacing = 10; // Reduced space between columns

    // Draw the title at the top
    painter.setFont(QFont("Arial", 16, QFont::Bold)); // Larger title font
    painter.drawText(x, y, "Stock Report");
    y += 100;  // Increased space after title

    // Draw the header with bold font
    painter.setFont(QFont("Arial", 12, QFont::Bold)); // Header font
    painter.drawText(x, y, "Code");
    painter.drawText(x + codeWidth + columnSpacing, y, "Name");
    painter.drawText(x + codeWidth + nameWidth + columnSpacing * 2, y, "Type");
    painter.drawText(x + codeWidth + nameWidth + typeWidth + columnSpacing * 3, y, "Date Expiration");
    painter.drawText(x + codeWidth + nameWidth + typeWidth + dateWidth + columnSpacing * 4, y, "Quantity");
    y += headerHeight;  // Move to next line after header

    // Draw a line after the header for separation
    painter.drawLine(x, y, x + codeWidth + nameWidth + typeWidth + dateWidth + quantityWidth + columnSpacing * 4, y);
    y += 20; // Added more space before the first data row

    // Calculate the remaining space on the page
    int availableHeight = printer.pageLayout().paintRect().height() - y - 50; // Reserve 50px at the bottom

    // Populate the table rows with data
    painter.setFont(QFont("Arial", 12)); // Regular content font size

    int rowCount = 0;
    while (query.next()) {
        // Draw each column's data
        painter.drawText(x, y, query.value(0).toString()); // Code
        painter.drawText(x + codeWidth + columnSpacing, y, query.value(1).toString()); // Name
        painter.drawText(x + codeWidth + nameWidth + columnSpacing * 2, y, query.value(2).toString()); // Type
        painter.drawText(x + codeWidth + nameWidth + typeWidth + columnSpacing * 3, y, query.value(3).toDate().toString("yyyy-MM-dd")); // Date Expiration
        painter.drawText(x + codeWidth + nameWidth + typeWidth + dateWidth + columnSpacing * 4, y, query.value(4).toString()); // Quantity
        y += rowHeight; // Move to the next row

        // Draw a line for each row to separate them clearly
        painter.drawLine(x, y, x + codeWidth + nameWidth + typeWidth + dateWidth + quantityWidth + columnSpacing * 4, y);

        rowCount++;

        // Check if there is enough space left for the next row
        if (y + rowHeight > availableHeight) {
            // Not enough space left on the page, break out of the loop
            break;
        }
    }

    // Check if we still have data left and start a new page if necessary
    if (rowCount < query.size()) {
        printer.newPage(); // Start a new page
        y = 150;  // Reset vertical position to start for the new page

        // Draw the same header for the new page
        painter.setFont(QFont("Arial", 12, QFont::Bold));
        painter.drawText(x, y, "Code");
        painter.drawText(x + codeWidth + columnSpacing, y, "Name");
        painter.drawText(x + codeWidth + nameWidth + columnSpacing * 2, y, "Type");
        painter.drawText(x + codeWidth + nameWidth + typeWidth + columnSpacing * 3, y, "Date Expiration");
        painter.drawText(x + codeWidth + nameWidth + typeWidth + dateWidth + columnSpacing * 4, y, "Quantity");
        y += headerHeight;  // Move down after header

        // Draw a line after the header for separation
        painter.drawLine(x, y, x + codeWidth + nameWidth + typeWidth + dateWidth + quantityWidth + columnSpacing * 4, y);
        y += 20; // Space before the first row

        // Continue drawing the remaining rows
        while (query.next()) {
            painter.drawText(x, y, query.value(0).toString()); // Code
            painter.drawText(x + codeWidth + columnSpacing, y, query.value(1).toString()); // Name
            painter.drawText(x + codeWidth + nameWidth + columnSpacing * 2, y, query.value(2).toString()); // Type
            painter.drawText(x + codeWidth + nameWidth + typeWidth + columnSpacing * 3, y, query.value(3).toDate().toString("yyyy-MM-dd")); // Date Expiration
            painter.drawText(x + codeWidth + nameWidth + typeWidth + dateWidth + columnSpacing * 4, y, query.value(4).toString()); // Quantity
            y += rowHeight; // Move to the next row

            painter.drawLine(x, y, x + codeWidth + nameWidth + typeWidth + dateWidth + quantityWidth + columnSpacing * 4, y);
        }
    }

    // Finalize the PDF document
    painter.end();
    QMessageBox::information(this, tr("PDF Export"), tr("PDF has been successfully exported to: %1").arg(filePath));
}



void MainWindow::mouseReleaseEvent(QMouseEvent* event)
{
    QMainWindow::mouseReleaseEvent(event); // Call the base class implementation
}

stock MainWindow::fetchStockByCode(int code_stock) {
    QSqlQuery query;
    query.prepare("SELECT NOM, QUANTITE, DATE_EXPIRATION FROM MEDICAMENTS WHERE CODE = :code");
    query.bindValue(":code", code_stock);

    if (query.exec() && query.next()) {
        QString nom = query.value("NOM").toString();
        int quantity = query.value("QUANTITE").toInt();
        QDate date_expiration = query.value("DATE_EXPIRATION").toDate();

        return stock(code_stock, quantity, nom, "Type", QDate::currentDate(), date_expiration);
    }

    // Handle case where stock isn't found (return an empty stock object or handle error)
    return stock();  // Returning an empty stock object (default constructor)
}

void MainWindow::checkStockLevels() {
    QSqlQuery query("SELECT NOM, QUANTITE FROM MEDICAMENTS");
    while (query.next()) {
        QString itemName = query.value("NOM").toString();
        int stockQuantity = query.value("QUANTITE").toInt();
        if (stockQuantity <= 10) {
            Notification::showLowStockNotification(itemName, stockQuantity);
        }
    }
}


void MainWindow::on_stockwarning_clicked()
{
    QVector<QPair<QString, int>> stockData = {
        {"Paracetamol", 0},
        {"Ibuprofen", 8},
        {"Aspirin", 20}
    };

    for (const auto &item : stockData) {
        QString itemName = item.first;
        int quantity = item.second;

        if (quantity == 0) {
            // Critical Alert: Out of stock
            QMessageBox criticalBox;
            criticalBox.setIconPixmap(QPixmap(":/images/critical.png"));  // Custom icon for critical alert
            criticalBox.setWindowTitle("Critical Stock Alert");
            criticalBox.setText(QString("The stock for '%1' is OUT!").arg(itemName));
            criticalBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Retry); // Adding Retry button
            criticalBox.exec();
        } else if (quantity <= 10) {
            // Low Stock Alert
            QMessageBox warningBox;
            warningBox.setIconPixmap(QPixmap(":/images/warning.png")); // Custom icon for low stock warning
            warningBox.setWindowTitle("Low Stock Warning");
            warningBox.setText(QString("The stock for '%1' is running low. Only %2 left.")
                                   .arg(itemName).arg(quantity));
            warningBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Retry); // Adding Retry button
            warningBox.exec();
        }
    }
}

void MainWindow::on_notification_clicked()
{
    QVector<QPair<QString, int>> stockData = {
        {"Paracetamol", 0},
        {"Ibuprofen", 8},
        {"Aspirin", 20}
    };

    for (const auto &item : stockData) {
        QString itemName = item.first;
        int quantity = item.second;

        if (quantity == 0) {
            // Critical Alert: Out of stock
            QMessageBox criticalBox;
            criticalBox.setIconPixmap(QPixmap(":/images/critical.png"));  // Custom icon for critical alert
            criticalBox.setWindowTitle("Critical Stock Alert");
            criticalBox.setText(QString("The stock for '%1' is OUT!").arg(itemName));
            criticalBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Retry); // Adding Retry button
            criticalBox.exec();
        } else if (quantity <= 10) {
            // Low Stock Alert
            QMessageBox warningBox;
            warningBox.setIconPixmap(QPixmap(":/images/warning.png")); // Custom icon for low stock warning
            warningBox.setWindowTitle("Low Stock Warning");
            warningBox.setText(QString("The stock for '%1' is running low. Only %2 left.")
                                   .arg(itemName).arg(quantity));
            warningBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Retry); // Adding Retry button
            warningBox.exec();
        }
    }
}


