#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>
#include "Commande.h"
#include <QSqlError>
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QTextDocument>
#include <QPushButton>
#include <QPdfWriter>
#include <QDate>
#include <QInputDialog>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QChartView>
#include <QVBoxLayout>
#include <QStackedWidget>
#include<QPieSeries>


           MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow),userManager(new UserManager()) {
    ui->setupUi(this);


    /*connect(ui->pushButton_20, &QPushButton::clicked, this, &MainWindow::on_pushButton_20_clicked);*/
    /* connect(ui->pushButton_31, &QPushButton::clicked, this, &MainWindow::on_pushButton_31_clicked);*/
    // Verify Signal-Slot Connection
    /*bool isConnected = connect(ui->pushButton_31, &QPushButton::clicked, this, &MainWindow::on_pushButton_31_clicked);*/
   /* qDebug() << "Signal-slot connected:" << isConnected;*/

    connect(ui->pushButton_20, &QPushButton::clicked, this, &MainWindow::testFunction);

    // Call the function to check the database structure
    checkDatabaseStructure();
    ui->comboBox_7->addItem("ID_COMMANDE");
    ui->comboBox_7->addItem("prix");
    ui->comboBox_7->addItem("dateLivraison");

    //connect(ui->pushButton_55, &QPushButton::clicked, this, &MainWindow::on_pushButton_55_clicked);
    //connect(ui->pushButton_58, &QPushButton::clicked, this, &MainWindow::on_pushButton_58_clicked);
    connect(ui->dashboardButton, &QPushButton::clicked, this, &MainWindow::showDashboard);

}

MainWindow::~MainWindow() {
    delete ui;
     delete userManager;

}

// Display Commandes in the table
void MainWindow::on_pushButton_49_clicked() {
    // Refresh Commandes table (tableWidget)
    afficherCommandesDansTable();

    // Refresh Status table (tableWidget_3)

}


void MainWindow::afficherCommandesDansTable() {
    Commande Commande(0, "", 0, 0.0, QDate::currentDate(),"pending");
    QSqlQueryModel* model = Commande.afficher();

    ui->tableWidget->setRowCount(model->rowCount());
    ui->tableWidget->setColumnCount(model->columnCount());

    // Set column headers
    ui->tableWidget->setHorizontalHeaderLabels({"ID Commande", "Nom Article", "Quantité", "Prix", "Date Livraison","Status"});

    for (int row = 0; row < model->rowCount(); ++row) {
        for (int col = 0; col < model->columnCount(); ++col) {
            QString data = model->index(row, col).data().toString();
            ui->tableWidget->setItem(row, col, new QTableWidgetItem(data));
        }
    }
}


// Add or update a Commande
void MainWindow::on_pushButton_2_clicked() {
    // Get input values from the UI
    int id = ui->lineEdit_43->text().toInt();
    QString nomArticle = ui->lineEdit_42->text();
    int quantite = ui->lineEdit_48->text().toInt();
    double prix = ui->lineEdit_47->text().toDouble();
    QDate dateLivraisonLivraison = ui->dateEdit->date();

    // Get the status from the combo box
    QString status = ui->lineEdit_49->text();

    // If no status is selected, set it to "Pending"
    if (status.isEmpty()) {
        status = "Pending"; // Default value if no selection
    }

    if (nomArticle.isEmpty() || quantite <= 0 || prix <= 0) {
        QMessageBox::warning(this, "Input Error", "Please ensure all fields are filled correctly.");
        return;
    }

    // Create a Commande object with these values
    Commande Commande(id, nomArticle, quantite, prix, dateLivraisonLivraison, status);

    // Check if the Commande already exists in the database
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM Commandes WHERE ID_COMMANDE = :id");
    query.bindValue(":id", id);
    if (!query.exec()) {
        QMessageBox::warning(this, "Database Error", "Failed to check Commande existence.");
        return;
    }

    query.next();
    bool exists = query.value(0).toInt() > 0;

    // If the Commande exists, update it; otherwise, add it
    if (exists) {
        if (Commande.modifier(id)) {
            QMessageBox::information(this, "Update Commande", "Commande updated successfully.");
        } else {
            QMessageBox::warning(this, "Update Commande", "Failed to update Commande.");
        }
    } else {
        if (Commande.ajouter()) {
            QMessageBox::information(this, "Add Commande", "Commande added successfully.");
        } else {
            QMessageBox::warning(this, "Add Commande", "Failed to add Commande.");
        }
    }

    // Refresh display after adding/updating
    afficherCommandesDansTable();
}


// delete commande
void MainWindow::on_pushButton_50_clicked() {
    // Check if edit_5 is empty
    QString idText = ui->edit_5->text();
    if (idText.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter an Order ID to delete.");
        return;  // Exit the function if no ID is entered
    }

    // Convert the input to an integer (ID)
    int id = idText.toInt();

    // Ensure the input is valid (positive integer)
    if (id <= 0) {
        QMessageBox::warning(this, "Input Error", "Please enter a valid Order ID.");
        return;  // Exit if the ID is not valid
    }

    // Check if the order ID exists in the database
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM Commandes WHERE ID_COMMANDE = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        QMessageBox::warning(this, "Error", "Failed to check if the Order exists.");
        return;
    }

    query.next();
    int count = query.value(0).toInt();

    // If no such order exists, show an error message
    if (count == 0) {
        QMessageBox::warning(this, "Error", "Order ID does not exist.");
        return;
    }

    // Proceed with deletion if the order exists
    Commande Commande(0, "", 0, 0.0, QDate::currentDate());
    if (Commande.supprimer(id)) {
        QMessageBox::information(this, "Suppression", "La Commande a été supprimée avec succès.");
        afficherCommandesDansTable();

    } else {
        QMessageBox::warning(this, "Erreur", "Échec de la suppression de la Commande.");
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



// recherche
void MainWindow::on_recherchComboBox_7_currentIndexChanged(int index) {
    QSqlQueryModel* model = nullptr;

    // Fetch data based on the selected index
    switch (index) {
    case 0:  // Search by Date
        model = Commande::rechercheParDate("2024-11-19");  // Replace with user input
        break;
    case 1:  // Search by Price
        model = Commande::rechercheParPrix(100.0);  // Replace with user input
        break;
    case 2:  // Search by ID
        model = Commande::rechercheParID(1);  // Replace with user input
        break;
    default:
        qDebug() << "Invalid search criteria selected.";
        return;
    }

    // Ensure model is valid
    if (!model) {
        qDebug() << "Failed to retrieve data.";
        return;
    }

    // Clear the QTableWidget
    ui->tableWidget->clear();

    // Set the column headers
    ui->tableWidget->setColumnCount(model->columnCount());
    ui->tableWidget->setHorizontalHeaderLabels({
        "ID Commande", "Nom Article", "Quantité", "Prix", "Date Livraison", "Status"
    });

    // Set the row count
    ui->tableWidget->setRowCount(model->rowCount());

    // Populate the QTableWidget
    for (int row = 0; row < model->rowCount(); ++row) {
        for (int col = 0; col < model->columnCount(); ++col) {
            QModelIndex index = model->index(row, col);
            QString data = model->data(index).toString();
            ui->tableWidget->setItem(row, col, new QTableWidgetItem(data));
        }
    }
}

void MainWindow::on_pushButton_51_clicked() {
    QString searchCriteria = ui->comboBox_7->currentText();  // Get the selected search criteria
    QString inputValue = ui->edit_2->text();  // Get the user input from a line edit
    QSqlQuery query;

    // Determine the SQL query based on the selected search criteria
    if (searchCriteria == "ID_COMMANDE") {
        if (inputValue.isEmpty() || !inputValue.toInt()) {
            QMessageBox::warning(this, "Input Error", "Please enter a valid ID.");
            return;
        }
        query.prepare("SELECT ID_COMMANDE, NOM_ARTICLE, QUANTITE, PRIX, DATE_LIVRAISON, STATUS FROM Commandes WHERE ID_COMMANDE = :value");
        query.bindValue(":value", inputValue.toInt());
    } else if (searchCriteria == "prix") {
        bool validPrice = false;
        double price = inputValue.toDouble(&validPrice);
        if (!validPrice || price <= 0) {
            QMessageBox::warning(this, "Input Error", "Please enter a valid price.");
            return;
        }
        query.prepare("SELECT ID_COMMANDE, NOM_ARTICLE, QUANTITE, PRIX, DATE_LIVRAISON, STATUS FROM Commandes WHERE prix = :value");
        query.bindValue(":value", price);
    } else if (searchCriteria == "DATE_LIVRAISON") {
        // Parse the date input (format: yyyy-MM-dd)
        QDate DELIVERY_DATE = QDate::fromString(inputValue, "yyyy-MM-dd");
        if (!DELIVERY_DATE.isValid()) {
            QMessageBox::warning(this, "Input Error", "Please enter a valid date in the format YYYY-MM-DD.");
            return;
        }

        // Convert to SQL-compatible format
        query.prepare("SELECT ID_COMMANDE, NOM_ARTICLE, QUANTITE, PRIX, DATE_LIVRAISON, STATUS FROM Commandes WHERE TRUNC(DATE_LIVRAISON) = TO_DATE(:value, 'YYYY-MM-DD')");
        query.bindValue(":value", DELIVERY_DATE.toString("yyyy-MM-dd"));  // Ensure the correct date format
    } else {
        QMessageBox::warning(this, "Search Error", "Invalid search criteria selected.");
        return;
    }

    // Execute the query and display results
    if (query.exec()) {
        ui->tableWidget->clearContents();
        ui->tableWidget->setRowCount(0);

        // Set table headers (adjust these headers to match your database schema)
        ui->tableWidget->setColumnCount(6);  // Adjust column count to 6 to accommodate STATUS
        ui->tableWidget->setHorizontalHeaderLabels({"ID Commande", "Nom Article", "Quantité", "Prix", "Date Livraison", "Status"});

        int row = 0;
        while (query.next()) {
            ui->tableWidget->insertRow(row);
            for (int col = 0; col < 6; ++col) {  // Now there are 6 columns to display
                QString data = query.value(col).toString();
                ui->tableWidget->setItem(row, col, new QTableWidgetItem(data));
            }
            ++row;
        }

        if (row == 0) {
            QMessageBox::information(this, "No Results", "No commandes found for the given search criteria.");
        }
    } else {
        qDebug() << "Query failed:" << query.lastError().text();
        qDebug() << "Executed query:" << query.lastQuery();
        QMessageBox::warning(this, "Database Error", "Failed to execute search query: " + query.lastError().text());
    }
}





// tri Commande

void MainWindow::on_sortComboBox_3_currentIndexChanged(int index) {
    Commande Commande;
    QSqlQueryModel* model = nullptr;

    bool ascending = true; // Assuming ascending order, set to false if descending

    // Determine sorting column based on selected index
    switch (index) {
    case 0: // Sort by dateLivraison
        model = Commande.triParColonne("dateLivraison_LIVRAISON", ascending);
        break;
    case 1: // Sort by Price
        model = Commande.triParColonne("PRIX", ascending);
        break;
    case 2: // Sort by Quantity
        model = Commande.triParColonne("QUANTITE", ascending);
        break;
    default:
        qDebug() << "Invalid sorting option selected.";
        return;
    }

    if (model) {
        // Clear the QTableWidget before populating new sorted data
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->setColumnCount(model->columnCount());

        // Set column headers from model
        for (int col = 0; col < model->columnCount(); ++col) {
            ui->tableWidget->setHorizontalHeaderItem(col, new QTableWidgetItem(model->headerData(col, Qt::Horizontal).toString()));
        }

        // Populate rows with sorted data
        for (int row = 0; row < model->rowCount(); ++row) {
            ui->tableWidget->insertRow(row);
            for (int col = 0; col < model->columnCount(); ++col) {
                ui->tableWidget->setItem(row, col, new QTableWidgetItem(model->data(model->index(row, col)).toString()));
            }
        }
    } else {
        qDebug() << "Failed to sort and retrieve data.";
    }
}
void MainWindow::on_pushButton_52_clicked() {
    bool ascending = true; // Set to false if you want descending order

    Commande Commande;
    QSqlQueryModel* model = nullptr;

    // Get the selected sorting criterion from the combo box
    int index = ui->comboBox_3->currentIndex(); // Index-based approach
    switch (index) {
    case 0: // Sort by dateLivraison
        model = Commande.triParDate(ascending);
        break;
    case 1: // Sort by Prix
        model = Commande.triParPrix(ascending);
        break;
    case 2: // Sort by Quantité
        model = Commande.triParQuantite(ascending);
        break;
    default:
        qDebug() << "Invalid sorting option selected.";
        return; // Optionally show a message to the user
    }

    if (model != nullptr) {
        // Clear previous data in the table
        ui->tableWidget->setRowCount(0);  // Clear any existing rows
        ui->tableWidget->setColumnCount(model->columnCount());

        // Set column headers dynamically from the model
        for (int col = 0; col < model->columnCount(); ++col) {
            ui->tableWidget->setHorizontalHeaderItem(col, new QTableWidgetItem(model->headerData(col, Qt::Horizontal).toString()));
        }

        // Populate rows with the sorted data
        for (int row = 0; row < model->rowCount(); ++row) {
            ui->tableWidget->insertRow(row);
            for (int col = 0; col < model->columnCount(); ++col) {
                QString data = model->index(row, col).data().toString();
                ui->tableWidget->setItem(row, col, new QTableWidgetItem(data));
            }

        }
    } else {
        qDebug() << "Failed to retrieve sorted data.";
        // Optionally show a message box to inform the user about the failure
    }
}

//stat


void MainWindow::on_pushButton_31_clicked() {
    // Step 1: Query to get the count of orders per month and year
    QSqlQuery query;
    query.prepare("SELECT TO_CHAR(DATE_LIVRAISON, 'YYYY-MM') AS monthYear, COUNT(*) AS orderCount "
                  "FROM Commandes "
                  "GROUP BY TO_CHAR(DATE_LIVRAISON, 'YYYY-MM') "
                  "ORDER BY TO_CHAR(DATE_LIVRAISON, 'YYYY-MM')");

    if (!query.exec()) {
        QMessageBox::warning(this, "Error", "Failed to fetch order data.");
        qDebug() << "Query Error: " << query.lastError().text();  // Debugging line
        return;
    }

    // Step 2: Prepare data for the curve chart
    QLineSeries *series = new QLineSeries();
    QStringList categories;  // Store the month-year labels
    int pointIndex = 0;      // Used for positioning on the X-axis

    while (query.next()) {
        QString monthYear = query.value("monthYear").toString();
        int orderCount = query.value("orderCount").toInt();

        // Add data point to the series
        series->append(pointIndex++, orderCount);

        // Save the category for the axis
        categories.append(monthYear);
    }

    // Check if there's any data to display
    if (categories.isEmpty()) {
        QMessageBox::information(this, "No Data", "No order data available to display.");
        return;
    }

    // Step 3: Create and configure the chart
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Orders Released by Month");
    chart->legend()->hide();

    // Configure X-axis (categories for months)
    QCategoryAxis *axisX = new QCategoryAxis();
    for (int i = 0; i < categories.size(); ++i) {
        axisX->append(categories[i], i);
    }
    axisX->setLabelsAngle(-45);  // Rotate labels for better readability
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Configure Y-axis (order counts)
    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Number of Orders");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Step 4: Display the chart in a QChartView
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Clear the previous layout in the container widget
    QLayout *oldLayout = ui->chartContainer->layout();  // `chartContainer` is the placeholder widget
    if (oldLayout) {
        QLayoutItem *item;
        while ((item = oldLayout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete oldLayout;
    }

    // Add the new chart to the layout
    QVBoxLayout *layout = new QVBoxLayout(ui->chartContainer);
    layout->addWidget(chartView);
    ui->chartContainer->setLayout(layout);

    // Step 5: Confirmation message
    QMessageBox::information(this, "Statistics Updated", "The curve chart for orders has been displayed.");
}





// export pdf
void MainWindow::on_pushButton_20_clicked() {
    // Specify the fixed file path
    QString filePath = "C:/Users/Wissal/Documents/wissalll/list.pdf";

    QFile pdfFile(filePath);
    if (pdfFile.open(QIODevice::WriteOnly)) {
        QPdfWriter writer(&pdfFile);
        writer.setPageSize(QPageSize::A4);
        writer.setResolution(96);
        QPainter painter(&writer);

        // Set font size
        QFont font = painter.font();
        font.setPointSize(12);
        painter.setFont(font);

        // Create the HTML content for the PDF
        QTextDocument doc;
        QString content = "<h1 style='text-align: center;'>Shipped Orders</h1>"
                          "<table border='1' cellpadding='5' cellspacing='0' style='width: 100%; font-size: 12pt;'>"
                          "<tr><th>ID</th><th>NAME</th><th>QUANTITY</th><th>PRICE</th><th>DELIVERY DATE</th></tr>";

        // Query the database for "shipped" orders
        QSqlQuery query("SELECT ID_COMMANDE, NOM_ARTICLE, QUANTITE, PRIX, DATE_LIVRAISON FROM COMMANDES WHERE STATUS = 'Shipped'");
        while (query.next()) {
            content += "<tr>"
                       "<td>" + query.value("ID_COMMANDE").toString() + "</td>"
                                                                 "<td>" + query.value("NOM_ARTICLE").toString() + "</td>"
                                                                 "<td>" + query.value("QUANTITE").toString() + "</td>"
                                                              "<td>" + query.value("PRIX").toString() + "</td>"
                                                          "<td>" + query.value("DATE_LIVRAISON").toString() + "</td>"
                                                                    "</tr>";
        }

        content += "</table>";

        // Set the content to the document and draw it on the PDF
        doc.setHtml(content);
        doc.drawContents(&painter);
        painter.end();

        QMessageBox::information(this, "PDF Generated", "The shipped orders list has been successfully exported to: " + filePath);
    } else {
        QMessageBox::warning(this, "File Error", "Failed to open the file at: " + filePath);
    }
}




void MainWindow::testFunction()
{
    // Implementation of the function
    qDebug() << "testFunction called!";
}


void MainWindow::checkDatabaseStructure() {
    QSqlDatabase db = QSqlDatabase::database(); // Get the active database connection
    if (!db.isOpen()) {
        QMessageBox::warning(this, "Database Error", "Database connection is not open.");
        return;
    }

    QSqlQuery query;
    // Replace 'tableWidget' with your suspected table name
    query.prepare("PRAGMA table_info(tableWidget);"); // For SQLite
    // query.prepare("DESCRIBE tableWidget;");       // For MySQL or MariaDB

    if (!query.exec()) {
        QMessageBox::warning(this, "Error", "Failed to fetch table info: " + query.lastError().text());
        return;
    }

    QString structure = "Table structure for 'tableWidget':\n";
    while (query.next()) {
        QString columnName = query.value("name").toString(); // Column name
        QString columnType = query.value("type").toString(); // Column type
        structure += columnName + " (" + columnType + ")\n";
    }

    QMessageBox::information(this, "Database Structure", structure);
}


// log in , sign up
void MainWindow::on_pushButton_61_clicked() {
    QString username = ui->lineEdit_9->text();
    QString password = ui->lineEdit_10->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Login Failed", "Please fill in all fields.");
        return;
    }

    if (userManager->login(username, password)) {
        QMessageBox::information(this, "Login Success", "Welcome, " + username + "!");
        // Navigate to the dashboard or next page
        ui->stackedWidget->setCurrentIndex(2); // Assuming index 2 is the main page

    } else {
        QMessageBox::critical(this, "Login Failed", "Invalid username or password.");
    }
}
void MainWindow::on_pushButton_62_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_58_clicked() {
    QString username = ui->lineEdit_5->text();
    QString email = ui->lineEdit_6->text();
    QString password = ui->lineEdit_7->text();
    QString confirmPassword = ui->lineEdit_8->text();

    // Check if all fields are filled
    if (username.isEmpty() || email.isEmpty() || password.isEmpty() || confirmPassword.isEmpty()) {
        QMessageBox::warning(this, "Sign-Up Failed", "Please fill in all fields.");
        return;
    }

    // Validate email format
    QRegularExpression emailRegex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    if (!emailRegex.match(email).hasMatch()) {
        QMessageBox::warning(this, "Sign-Up Failed", "Invalid email format. Example: example@gmail.com");
        return;
    }

    // Validate password strength (at least one uppercase letter and one number)
    QRegularExpression passwordRegex("^(?=.*[A-Z])(?=.*\\d).+$");
    if (!passwordRegex.match(password).hasMatch()) {
        QMessageBox::warning(this, "Sign-Up Failed", "Password must contain at least one uppercase letter and one number.");
        return;
    }

    // Check if passwords match
    if (password != confirmPassword) {
        QMessageBox::warning(this, "Sign-Up Failed", "Passwords do not match.");
        return;
    }

    // Attempt to sign up
    if (userManager->signUp(username, email, password)) {
        QMessageBox::information(this, "Sign-Up Success", "Your account has been created successfully!");
        ui->stackedWidget->setCurrentIndex(2); // Redirect to login page
    } else {
        QMessageBox::warning(nullptr, "Sign-Up Failed", "This username or email already exists. Please choose another.");
    }
}
void MainWindow::on_pushButton_63_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}



void MainWindow::showMainPage() {
    // Assuming you're using a stacked widget to navigate between pages
    ui->stackedWidget->setCurrentIndex(1);  // Set to the main page (index 1)
}

void MainWindow::on_pushButton_59_clicked() {
    // Switch to login/sign-up page (index 0)
    ui->stackedWidget->setCurrentIndex(0);  // Go back to the login page

    // Optionally, you can clear any session data here if needed:
    ui->lineEdit_9->clear();  // Clear username field
    ui->lineEdit_10->clear();  // Clear password field
    ui->lineEdit_5->clear();  // Clear username field in sign-up
    ui->lineEdit_6->clear();  // Clear email field in sign-up
    ui->lineEdit_7->clear();  // Clear password field in sign-up
    ui->lineEdit_8->clear();  // Clear confirm password field in sign-up
}


//dashboard

#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>

void MainWindow::showDashboard()
{
    // Example: Create a chart
    QPieSeries *series = new QPieSeries();
    series->append("Category A", 10);
    series->append("Category B", 20);
    series->append("Category C", 30);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Example Pie Chart");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Check if dashboardWidget already has a layout
    QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(ui->dashboardWidget->layout());
    if (!layout) {
        // Create a new layout if none exists
        layout = new QVBoxLayout(ui->dashboardWidget);
        ui->dashboardWidget->setLayout(layout);
    }

    // Add the chart to the layout
    layout->addWidget(chartView);

    ui->dashboardWidget->show(); // Show the dashboard
}
