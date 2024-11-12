#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QStackedWidget>
#include"transactions.h"

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

private:
    QStackedWidget *stackedWidget;

};
#endif // MAINWINDOW_H
