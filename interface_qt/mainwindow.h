#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QStackedWidget>
#include"transactions.h"

#include <QMainWindow>
#include <QNetworkReply>
#include "arduino_ma.h"
#include<QTimer>


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
    transactions Ttmp;





private slots:
    void on_pushButton_8_clicked();
    void on_pushButton_10_clicked(); // For salary button*
    void on_pushButton_12_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_35_clicked();
    void on_pushButton_36_clicked();
    void on_pushButton_37_clicked();
    void on_pushButton_28_clicked();
    void on_pushButton_27_clicked();
    void on_pushButton_25_clicked();
    void on_pushButton_24_clicked();


    void on_add_transaction_clicked();

    void on_pushButton_delete_clicked();



    void on_modif_trans_clicked();

    void on_pushButton_donesearch_clicked();




    void on_comboBox_triertrans_currentIndexChanged(int index);

    void on_pushButton_exporterpdf_clicked();





    void on_pushButton_statistics_clicked();

   // void on_showCalendarButton_clicked();

    void on_pushButton_envoyer_clicked();  // Slot pour envoyer le SMS
        void onSmsSent();
         void onCalendarDateClicked(const QDate &date);
void readFromArduino();  // Déclaration de la méthode readFromArduino
private:
    QStackedWidget *stackedWidget;
     void sendSms(const QString& toPhoneNumber, const QString& message);  // Fonction pour envoyer le SMS
     void populateCalendarWithTransactions();
     QTimer timer;  // Déclaration de QTimer pour lire périodiquement les données
         //Arduino *arduino;  // Déclaration de l'objet Arduino
        // QString code; // Variable pour stocker le code saisi
};
#endif // MAINWINDOW_H
