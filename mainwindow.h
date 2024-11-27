#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Commande.h"
#include "UserManager.h"

#include <QVector>
#include <QPushButton>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void testFunction();
    void pushButton_53_clicked();
    /*void displayStatistics();*/




protected:
    void paintEvent(QPaintEvent *event) override;  // Correct declaration

private slots:
    void on_pushButton_49_clicked();  // Display Commandes
    void on_pushButton_2_clicked();   // Add or update Commande
    void on_pushButton_50_clicked();  // Delete Commande
    void on_pushButton_3_clicked();  // Show success message
    void on_pushButton_51_clicked() ; // cherche Commande
    void on_pushButton_20_clicked();
    void checkDatabaseStructure();
    void on_recherchComboBox_7_currentIndexChanged(int index);
    void on_pushButton_31_clicked() ;
    void showDashboard();


public slots:

    /*void testFunction();*/

    void on_sortComboBox_3_currentIndexChanged(int index);
    void on_pushButton_52_clicked();

    void on_pushButton_61_clicked();
    void on_pushButton_58_clicked();
    void showMainPage();
    void on_pushButton_59_clicked();
    void on_pushButton_62_clicked();
    void on_pushButton_63_clicked();




private:
    Ui::MainWindow *ui;
    UserManager *userManager;

    Commande Ctemp;  // Temporary Commande object (unused here, you might want to remove it if not needed)
    void afficherCommandesDansTable();  // Helper to display Commandes in table
};


#endif
 // MAINWINDOW_H
