#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ordonnance.h"
#include <QStackedWidget>

#include <QMainWindow>

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
    ordonnance Etmp;
    bool messageShown = false;
    void onValiderButtonClicked();
    QString originalNom, originalPrenom, originalStatu, originalMed;
        QDate originalDate_ord;
        int originalCin, originalTel,originalord;



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
    void on_addbutton1_clicked();
    void on_deletebutton1_clicked();
    void on_updateButton_clicked();
    void on_update2Button_clicked();
private:
    QStackedWidget *stackedWidget;

};

#endif // MAINWINDOW_H
