#ifndef PRODOTTIWIDGET_H
#define PRODOTTIWIDGET_H

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

#include "prodottidatabasemanager.h"

class ProdottiWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ProdottiWidget(QWidget *parent = nullptr);
    ~ProdottiWidget();

signals:

public slots:

    void productSelected(QModelIndex idx);
    void newProductClicked();
    void updateModel();
    void goToMainView();
    void updateProduct();
    void searchChanged(QString src);

private:
    QStackedLayout* stack;

    QPushButton *newProduct;
    QLineEdit *txtProduct;
    QTableView *productList;
    QCheckBox *visualize;

    QLineEdit *txtIDProd;
    QLineEdit *txtDescProd;
    QLineEdit *txtPAcquisto;
    QLineEdit *txtPVendita;
    QLineEdit *txtGiacenza;
    QPushButton *aggiornaProd;
    QPushButton *togliComm;
    QPushButton *rimettiComm;

    ProdottiDatabaseManager *db;
    QSqlQueryModel* model;

    bool newORdetail;
};

#endif // PRODOTTIWIDGET_H
