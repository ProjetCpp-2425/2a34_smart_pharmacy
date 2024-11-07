#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "commande.h"
#include <QVector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event) override;  // Correct declaration

private slots:
    void on_pushButton_49_clicked();  // Display commandes
    void on_pushButton_2_clicked();   // Add or update commande
    void on_pushButton_50_clicked();  // Delete commande
    void on_pushButton_3_clicked();   // Show success message

private:
    Ui::MainWindow *ui;
    Commande Ctemp;  // Temporary Commande object (unused here, you might want to remove it if not needed)
    void afficherCommandesDansTable();  // Helper to display commandes in table
};

#endif // MAINWINDOW_H
