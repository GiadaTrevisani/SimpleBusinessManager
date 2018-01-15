#ifndef FORNITORIWIDGET_H
#define FORNITORIWIDGET_H

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


#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QHash>
#include <QString>
#include <QModelIndex>
#include <QMap>

#include <QDebug>
#include <QMessageBox>

#include "fornitoridatabasemanager.h"

class FornitoriWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FornitoriWidget(QWidget *parent = nullptr);
    ~FornitoriWidget();

signals:

public slots:
    void supplierSelected(QModelIndex idx);
    void newSupplierClicked();
    void updateModel();
    void goToMainView();
    void updateSupplier();
    void searchChanged(QString src);

private:
	QPushButton *newFornit;
    QLineEdit *txtfornit;
    QTableView *fornitlist;

    QPushButton *aggiornaFor;
    QPushButton *back;

    QLineEdit *txtForName;
    QLineEdit *txtForRSoc;
    QLineEdit *txtForSurname;
    QLineEdit *txtForTel;
    QLineEdit *txtForMail;
    QLineEdit *txtForPIva;
    QLineEdit *txtForFiscalC;
    QLineEdit *txtForAddress;
    QLineEdit *txtForCity;
    QLineEdit *txtForCap;

    QStackedLayout* stack;

    FornitoriDatabaseManager *db;
    QSqlQueryModel *model;

    bool newOrdetail;

};

#endif // FORNITORIWIDGET_H
