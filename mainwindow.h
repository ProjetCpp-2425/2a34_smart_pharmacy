#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QMainWindow>
#include "stock.h"
#include <QMouseEvent>
#include <QPainter>
#include <QPrinter>
#include <QFileDialog>
#include <QMessageBox>
#include <QPdfWriter>
#include <QPageSize>
#include <QFont>
#include <QDebug>
#include "historique.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void mouseReleaseEvent(QMouseEvent *event);

    void on_ajoute_clicked();
    void on_delete_2_clicked();
    void on_show_clicked();
    void on_edit_clicked();

    void on_tri_clicked();

    void on_stats_clicked();

    void on_export_2Button_clicked();
    void on_Historique_clicked();
    void updateStockWarning(const QString &message);  // Add this function declaration
    void on_stockwarning_clicked();

    void on_PDF_clicked();
    void logStockHistory(const QString &action, int code, const QString &nom, const QString &type,
                         int quantiteOld, int quantiteNew, const QDate &dateExpirationOld,
                         const QDate &dateExpirationNew, const QString &user);
    void checkStockLevels();

    void on_notification_clicked();

public:
    void on_stockwarning_linkActivated(const QString &link);
    void updatestockWarning(const QString &message);

    stock fetchStockByCode(int code_stock);  // Declare the function here

private:
    Ui::MainWindow *ui;
    stock s;
    QLabel *stockWarningLabel;  // Assuming you have a QLabel for displaying stock warnings
    historique historyManager;  // Instance to manage history fetching
    stock stockInstance;  // Declare stockInstance as a member of MainWindow

};

#endif // MAINWINDOW_H
