/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../HaMa/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtCharts/qlineseries.h>
#include <QtCharts/qabstractbarseries.h>
#include <QtCharts/qvbarmodelmapper.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCharts/qcandlestickseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[144];
    char stringdata0[1368];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 17), // "setCenterPosition"
QT_MOC_LITERAL(29, 0), // ""
QT_MOC_LITERAL(30, 18), // "setLocationMarking"
QT_MOC_LITERAL(49, 23), // "on_pushButton_8_clicked"
QT_MOC_LITERAL(73, 24), // "on_pushButton_10_clicked"
QT_MOC_LITERAL(98, 24), // "on_pushButton_12_clicked"
QT_MOC_LITERAL(123, 24), // "on_pushButton_14_clicked"
QT_MOC_LITERAL(148, 24), // "on_pushButton_35_clicked"
QT_MOC_LITERAL(173, 24), // "on_pushButton_36_clicked"
QT_MOC_LITERAL(198, 24), // "on_pushButton_37_clicked"
QT_MOC_LITERAL(223, 24), // "on_pushButton_28_clicked"
QT_MOC_LITERAL(248, 24), // "on_pushButton_27_clicked"
QT_MOC_LITERAL(273, 24), // "on_pushButton_25_clicked"
QT_MOC_LITERAL(298, 24), // "on_pushButton_24_clicked"
QT_MOC_LITERAL(323, 21), // "on_addbutton1_clicked"
QT_MOC_LITERAL(345, 24), // "on_deletebutton1_clicked"
QT_MOC_LITERAL(370, 23), // "on_updateButton_clicked"
QT_MOC_LITERAL(394, 24), // "on_update2Button_clicked"
QT_MOC_LITERAL(419, 15), // "on_aa33_clicked"
QT_MOC_LITERAL(435, 15), // "on_aa44_clicked"
QT_MOC_LITERAL(451, 14), // "showStatistics"
QT_MOC_LITERAL(466, 16), // "on_aaa_2_clicked"
QT_MOC_LITERAL(483, 15), // "generatePDFBill"
QT_MOC_LITERAL(499, 10), // "ordonnance"
QT_MOC_LITERAL(510, 3), // "ord"
QT_MOC_LITERAL(514, 20), // "on_pwhatsapp_clicked"
QT_MOC_LITERAL(535, 22), // "on_pwhatsapp_2_clicked"
QT_MOC_LITERAL(558, 11), // "sendRequest"
QT_MOC_LITERAL(570, 18), // "on_chatbot_clicked"
QT_MOC_LITERAL(589, 19), // "afficherDescription"
QT_MOC_LITERAL(609, 11), // "QTableView*"
QT_MOC_LITERAL(621, 9), // "tableView"
QT_MOC_LITERAL(631, 24), // "on_adresseButton_clicked"
QT_MOC_LITERAL(656, 15), // "readFromArduino"
QT_MOC_LITERAL(672, 26), // "on_add_transaction_clicked"
QT_MOC_LITERAL(699, 28), // "on_pushButton_delete_clicked"
QT_MOC_LITERAL(728, 22), // "on_modif_trans_clicked"
QT_MOC_LITERAL(751, 32), // "on_pushButton_donesearch_clicked"
QT_MOC_LITERAL(784, 42), // "on_comboBox_triertrans_curren..."
QT_MOC_LITERAL(827, 5), // "index"
QT_MOC_LITERAL(833, 33), // "on_pushButton_exporterpdf_cli..."
QT_MOC_LITERAL(867, 32), // "on_pushButton_statistics_clicked"
QT_MOC_LITERAL(900, 29), // "on_pushButton_envoyer_clicked"
QT_MOC_LITERAL(930, 9), // "onSmsSent"
QT_MOC_LITERAL(940, 21), // "onCalendarDateClicked"
QT_MOC_LITERAL(962, 4), // "date"
QT_MOC_LITERAL(967, 20), // "on_addButton_clicked"
QT_MOC_LITERAL(988, 23), // "on_deleteButton_clicked"
QT_MOC_LITERAL(1012, 23), // "on_modifyButton_clicked"
QT_MOC_LITERAL(1036, 8), // "addStaff"
QT_MOC_LITERAL(1045, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(1069, 16), // "exportTableToPDF"
QT_MOC_LITERAL(1086, 9), // "sortTable"
QT_MOC_LITERAL(1096, 5), // "input"
QT_MOC_LITERAL(1102, 17), // "sortTableBySalary"
QT_MOC_LITERAL(1120, 14), // "sortTableByDOB"
QT_MOC_LITERAL(1135, 13), // "on_qr_clicked"
QT_MOC_LITERAL(1149, 16), // "on_email_clicked"
QT_MOC_LITERAL(1166, 18), // "computeSalaryStats"
QT_MOC_LITERAL(1185, 15), // "on_stat_clicked"
QT_MOC_LITERAL(1201, 10), // "saveQRCode"
QT_MOC_LITERAL(1212, 25), // "loadTableDataFromDatabase"
QT_MOC_LITERAL(1238, 8), // "afficher"
QT_MOC_LITERAL(1247, 18), // "computeSalaryState"
QT_MOC_LITERAL(1266, 14), // "on_p16_clicked"
QT_MOC_LITERAL(1281, 19), // "updateChartInLayout"
QT_MOC_LITERAL(1301, 7), // "QChart*"
QT_MOC_LITERAL(1309, 5), // "chart"
QT_MOC_LITERAL(1315, 23), // "updateChartInAzizLayout"
QT_MOC_LITERAL(1339, 16), // "on_xx1_activated"
QT_MOC_LITERAL(1356, 11) // "QModelIndex"

    },
    "MainWindow\0setCenterPosition\0\0"
    "setLocationMarking\0on_pushButton_8_clicked\0"
    "on_pushButton_10_clicked\0"
    "on_pushButton_12_clicked\0"
    "on_pushButton_14_clicked\0"
    "on_pushButton_35_clicked\0"
    "on_pushButton_36_clicked\0"
    "on_pushButton_37_clicked\0"
    "on_pushButton_28_clicked\0"
    "on_pushButton_27_clicked\0"
    "on_pushButton_25_clicked\0"
    "on_pushButton_24_clicked\0on_addbutton1_clicked\0"
    "on_deletebutton1_clicked\0"
    "on_updateButton_clicked\0"
    "on_update2Button_clicked\0on_aa33_clicked\0"
    "on_aa44_clicked\0showStatistics\0"
    "on_aaa_2_clicked\0generatePDFBill\0"
    "ordonnance\0ord\0on_pwhatsapp_clicked\0"
    "on_pwhatsapp_2_clicked\0sendRequest\0"
    "on_chatbot_clicked\0afficherDescription\0"
    "QTableView*\0tableView\0on_adresseButton_clicked\0"
    "readFromArduino\0on_add_transaction_clicked\0"
    "on_pushButton_delete_clicked\0"
    "on_modif_trans_clicked\0"
    "on_pushButton_donesearch_clicked\0"
    "on_comboBox_triertrans_currentIndexChanged\0"
    "index\0on_pushButton_exporterpdf_clicked\0"
    "on_pushButton_statistics_clicked\0"
    "on_pushButton_envoyer_clicked\0onSmsSent\0"
    "onCalendarDateClicked\0date\0"
    "on_addButton_clicked\0on_deleteButton_clicked\0"
    "on_modifyButton_clicked\0addStaff\0"
    "on_pushButton_4_clicked\0exportTableToPDF\0"
    "sortTable\0input\0sortTableBySalary\0"
    "sortTableByDOB\0on_qr_clicked\0"
    "on_email_clicked\0computeSalaryStats\0"
    "on_stat_clicked\0saveQRCode\0"
    "loadTableDataFromDatabase\0afficher\0"
    "computeSalaryState\0on_p16_clicked\0"
    "updateChartInLayout\0QChart*\0chart\0"
    "updateChartInAzizLayout\0on_xx1_activated\0"
    "QModelIndex"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      61,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,  380,    2, 0x06,    1 /* Public */,
       3,    2,  385,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,  390,    2, 0x08,    7 /* Private */,
       5,    0,  391,    2, 0x08,    8 /* Private */,
       6,    0,  392,    2, 0x08,    9 /* Private */,
       7,    0,  393,    2, 0x08,   10 /* Private */,
       8,    0,  394,    2, 0x08,   11 /* Private */,
       9,    0,  395,    2, 0x08,   12 /* Private */,
      10,    0,  396,    2, 0x08,   13 /* Private */,
      11,    0,  397,    2, 0x08,   14 /* Private */,
      12,    0,  398,    2, 0x08,   15 /* Private */,
      13,    0,  399,    2, 0x08,   16 /* Private */,
      14,    0,  400,    2, 0x08,   17 /* Private */,
      15,    0,  401,    2, 0x08,   18 /* Private */,
      16,    0,  402,    2, 0x08,   19 /* Private */,
      17,    0,  403,    2, 0x08,   20 /* Private */,
      18,    0,  404,    2, 0x08,   21 /* Private */,
      19,    0,  405,    2, 0x08,   22 /* Private */,
      20,    0,  406,    2, 0x08,   23 /* Private */,
      21,    0,  407,    2, 0x08,   24 /* Private */,
      22,    0,  408,    2, 0x08,   25 /* Private */,
      23,    1,  409,    2, 0x08,   26 /* Private */,
      26,    0,  412,    2, 0x08,   28 /* Private */,
      27,    0,  413,    2, 0x08,   29 /* Private */,
      28,    0,  414,    2, 0x08,   30 /* Private */,
      29,    0,  415,    2, 0x08,   31 /* Private */,
      30,    1,  416,    2, 0x08,   32 /* Private */,
      33,    0,  419,    2, 0x08,   34 /* Private */,
      34,    0,  420,    2, 0x08,   35 /* Private */,
      35,    0,  421,    2, 0x08,   36 /* Private */,
      36,    0,  422,    2, 0x08,   37 /* Private */,
      37,    0,  423,    2, 0x08,   38 /* Private */,
      38,    0,  424,    2, 0x08,   39 /* Private */,
      39,    1,  425,    2, 0x08,   40 /* Private */,
      41,    0,  428,    2, 0x08,   42 /* Private */,
      42,    0,  429,    2, 0x08,   43 /* Private */,
      43,    0,  430,    2, 0x08,   44 /* Private */,
      44,    0,  431,    2, 0x08,   45 /* Private */,
      45,    1,  432,    2, 0x08,   46 /* Private */,
      47,    0,  435,    2, 0x08,   48 /* Private */,
      48,    0,  436,    2, 0x08,   49 /* Private */,
      49,    0,  437,    2, 0x08,   50 /* Private */,
      50,    0,  438,    2, 0x08,   51 /* Private */,
      51,    0,  439,    2, 0x08,   52 /* Private */,
      52,    0,  440,    2, 0x08,   53 /* Private */,
      53,    1,  441,    2, 0x08,   54 /* Private */,
      54,    0,  444,    2, 0x08,   56 /* Private */,
      55,    0,  445,    2, 0x08,   57 /* Private */,
      56,    0,  446,    2, 0x08,   58 /* Private */,
      57,    0,  447,    2, 0x08,   59 /* Private */,
      58,    0,  448,    2, 0x08,   60 /* Private */,
      59,    0,  449,    2, 0x08,   61 /* Private */,
      60,    0,  450,    2, 0x08,   62 /* Private */,
      61,    0,  451,    2, 0x08,   63 /* Private */,
      62,    0,  452,    2, 0x08,   64 /* Private */,
      63,    0,  453,    2, 0x08,   65 /* Private */,
      64,    0,  454,    2, 0x08,   66 /* Private */,
      65,    0,  455,    2, 0x08,   67 /* Private */,
      66,    1,  456,    2, 0x08,   68 /* Private */,
      69,    1,  459,    2, 0x08,   70 /* Private */,
      70,    1,  462,    2, 0x08,   72 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QVariant, QMetaType::QVariant,    2,    2,
    QMetaType::Void, QMetaType::QVariant, QMetaType::QVariant,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 31,   32,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   40,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDate,   46,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   40,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 67,   68,
    QMetaType::Void, 0x80000000 | 67,   68,
    QMetaType::Void, 0x80000000 | 71,   40,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setCenterPosition((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[2]))); break;
        case 1: _t->setLocationMarking((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[2]))); break;
        case 2: _t->on_pushButton_8_clicked(); break;
        case 3: _t->on_pushButton_10_clicked(); break;
        case 4: _t->on_pushButton_12_clicked(); break;
        case 5: _t->on_pushButton_14_clicked(); break;
        case 6: _t->on_pushButton_35_clicked(); break;
        case 7: _t->on_pushButton_36_clicked(); break;
        case 8: _t->on_pushButton_37_clicked(); break;
        case 9: _t->on_pushButton_28_clicked(); break;
        case 10: _t->on_pushButton_27_clicked(); break;
        case 11: _t->on_pushButton_25_clicked(); break;
        case 12: _t->on_pushButton_24_clicked(); break;
        case 13: _t->on_addbutton1_clicked(); break;
        case 14: _t->on_deletebutton1_clicked(); break;
        case 15: _t->on_updateButton_clicked(); break;
        case 16: _t->on_update2Button_clicked(); break;
        case 17: _t->on_aa33_clicked(); break;
        case 18: _t->on_aa44_clicked(); break;
        case 19: _t->showStatistics(); break;
        case 20: _t->on_aaa_2_clicked(); break;
        case 21: _t->generatePDFBill((*reinterpret_cast< std::add_pointer_t<ordonnance>>(_a[1]))); break;
        //case 22: _t->on_pwhatsapp_clicked(); break;
        case 23: _t->on_pwhatsapp_2_clicked(); break;
        case 24: _t->sendRequest(); break;
        case 25: _t->on_chatbot_clicked(); break;
        case 26: _t->afficherDescription((*reinterpret_cast< std::add_pointer_t<QTableView*>>(_a[1]))); break;
        case 27: _t->on_adresseButton_clicked(); break;
        //case 28: _t->readFromArduino(); break;
        case 29: _t->on_add_transaction_clicked(); break;
        case 30: _t->on_pushButton_delete_clicked(); break;
        case 31: _t->on_modif_trans_clicked(); break;
        case 32: _t->on_pushButton_donesearch_clicked(); break;
        case 33: _t->on_comboBox_triertrans_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 34: _t->on_pushButton_exporterpdf_clicked(); break;
        case 35: _t->on_pushButton_statistics_clicked(); break;
        case 36: _t->on_pushButton_envoyer_clicked(); break;
        case 37: _t->onSmsSent(); break;
        case 38: _t->onCalendarDateClicked((*reinterpret_cast< std::add_pointer_t<QDate>>(_a[1]))); break;
        case 39: _t->on_addButton_clicked(); break;
        case 40: _t->on_deleteButton_clicked(); break;
        case 41: _t->on_modifyButton_clicked(); break;
        case 42: _t->addStaff(); break;
        case 43: _t->on_pushButton_4_clicked(); break;
        case 44: _t->exportTableToPDF(); break;
        case 45: _t->sortTable((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 46: _t->input(); break;
        case 47: _t->sortTableBySalary(); break;
        case 48: _t->sortTableByDOB(); break;
        case 49: _t->on_qr_clicked(); break;
        case 50: _t->on_email_clicked(); break;
        case 51: _t->computeSalaryStats(); break;
        case 52: _t->on_stat_clicked(); break;
        case 53: _t->saveQRCode(); break;
        case 54: _t->loadTableDataFromDatabase(); break;
        case 55: _t->afficher(); break;
        case 56: _t->computeSalaryState(); break;
        case 57: _t->on_p16_clicked(); break;
        case 58: _t->updateChartInLayout((*reinterpret_cast< std::add_pointer_t<QChart*>>(_a[1]))); break;
        case 59: _t->updateChartInAzizLayout((*reinterpret_cast< std::add_pointer_t<QChart*>>(_a[1]))); break;
        //case 60: _t->on_xx1_activated((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 26:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTableView* >(); break;
            }
            break;
        case 58:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QChart* >(); break;
            }
            break;
        case 59:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QChart* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(QVariant , QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::setCenterPosition)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QVariant , QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::setLocationMarking)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVariant, std::false_type>, QtPrivate::TypeAndForceComplete<QVariant, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVariant, std::false_type>, QtPrivate::TypeAndForceComplete<QVariant, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const ordonnance &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QTableView *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QDate &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QChart *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QChart *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 61)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 61;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 61)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 61;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::setCenterPosition(QVariant _t1, QVariant _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::setLocationMarking(QVariant _t1, QVariant _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
