#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

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

#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QHash>
#include <QString>
#include <QModelIndex>
#include <QMap>

#include <QDebug>
#include <QMessageBox>

#include "clientdatabasemanager.h"

class ClientWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ClientWidget(QWidget *parent = nullptr);
    ~ClientWidget();

signals:

public slots:
    void clientSelected(QModelIndex idx);
    void newClientClicked();
    void updateModel();
    void goToMainView();
    void updateClient();
    void searchChanged(QString src);

private:
    QPushButton *newClient;
    QLineEdit *txtCerca;
    QTableView *clientTab;

    QPushButton *aggiorna_add;

    QLineEdit *txtclientName;
    QLineEdit *txtragSoc;
    QLineEdit *txtclientSurname;
    QLineEdit *txtclientTel;
    QLineEdit *txtclientMail;
    QLineEdit *txtclientPIva;
    QLineEdit *txtclientFiscalC;        //primary key
    QLineEdit *txtclientAddress;
    QLineEdit *txtclientCity;
    QLineEdit *txtclientCap;

    QStackedLayout* stack;

    ClientDatabaseManager* db;
    QSqlQueryModel* model;

    bool newORdetail;
};

#endif // CLIENTWIDGET_H
