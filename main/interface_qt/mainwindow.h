#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QStackedWidget>
#include <staff.h>
#include <QMainWindow>
#include <QFileDialog>     // For file dialog to save the PDF
#include <QPdfWriter>      // For creating PDF files
#include <QPainter>        // For drawing on the PDF
#include <QMessageBox>     // For message boxes

#include <QTableWidgetItem>
#include <QLineEdit>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void onValiderButtonClicked();
    void searchEmployee(const QString &searchTerm); // Search function

private slots:
    void on_pushButton_8_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_35_clicked();
    void on_pushButton_36_clicked();
    void on_pushButton_37_clicked();
    void on_pushButton_28_clicked();
    void on_pushButton_27_clicked();
    void on_pushButton_25_clicked();
    void on_pushButton_24_clicked();
    void on_addButton_clicked();
    void on_deleteButton_clicked();
    void on_modifyButton_clicked();
    void addStaff();
    void on_pushButton_4_clicked(); // Search button slot
    // Add this slot for PDF export
    void exportTableToPDF();

    // Slot for sorting based on ComboBox selection
       void sortTable(int index);

       // Functions to handle sorting by Salary and DOB
       void sortTableBySalary();
       void sortTableByDOB();

private:
    QStackedWidget *stackedWidget;
};

#endif // MAINWINDOW_H
