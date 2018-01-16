#ifndef FATTUREWIDGET_H
#define FATTUREWIDGET_H

#include <QWidget>

#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QCheckBox>
#include <QRadioButton>
#include <QListView>
#include <QTableWidget>
#include <QTableView>
#include <QStackedLayout>
#include <QModelIndex>
#include <QMessageBox>
#include <QHash>

#include <fatturedatabasemanager.h>
#include <clientdatabasemanager.h>
#include <fornitoridatabasemanager.h>
#include <aziendadatabasemanager.h>
#include "scegliclifordialog.h"
#include "scegliprodottodialog.h"

class FattureWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FattureWidget(QWidget *parent = nullptr);
    ~FattureWidget();

signals:

public slots:
    void InvoiceSelected(QModelIndex idx);
    void newInvoiceClicked();
    void updateModel();
    void goToMainView();
    void insertInvoice();
    void searchChanged(QString src);

    void searchCliFor();

    void addProd();
    void deleteProd();
    void updateTable();

private:
    void enableWidgets();
    void disableWidgets();
    QLineEdit *searchInvoices;
    QPushButton *newButton;

    QRadioButton *radioClient;
    QRadioButton *radioSupplier;

    QTableWidget *productsTab;

    QCheckBox *checkClient;
    QCheckBox *checkSuppliers;

    QLineEdit *txtfattRSocFor;
    QLineEdit *txtfattIndFor;
    QLineEdit *txtFattTelFor;
    QLineEdit *txtfattMailFor;
    QLineEdit *txtfattPIvaFor;

    QTableView *fatt;

    QPushButton *back;
    QPushButton *insert;

    QLineEdit *txtidfatt;
    QLineEdit *txtfattRSocCli;
    QLineEdit *txtfattIndCli;
    QLineEdit *txtFattCapCli;
    QLineEdit *txtfattCityCli;
    QLineEdit *txtfattPIvaCli;
    QLineEdit *txtfattCFiscCli;

    QLineEdit *txtCodFatt;
    QLineEdit *txtDataFatt;
    QLineEdit *txtImpFatt;
    QLineEdit *txtIvaFatt;
    QLineEdit *txtTotFatt;

    QStackedLayout* stack;

    FattureDatabaseManager* db;
    QSqlQueryModel* model;

    QPushButton* add;
    QPushButton* remove;
    QPushButton* search;

    bool newORdetail;

    QHash<QString, int>* prodsgiac;
    QString currentID;
};

#endif // FATTUREWIDGET_H
