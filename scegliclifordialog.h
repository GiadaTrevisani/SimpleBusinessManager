#ifndef SCEGLICLIFORDIALOG_H
#define SCEGLICLIFORDIALOG_H

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
#include <QDialog>

#include "clientdatabasemanager.h"
#include "fornitoridatabasemanager.h"

namespace Ui {
class ScegliCliForDialog;
}

class ScegliCliForDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ScegliCliForDialog(QWidget *parent = 0);
    ~ScegliCliForDialog();

    void setType(bool forn = true);
    QString getSelected();
public slots:
    void searchChanged(QString src);
    void elementClicked(QModelIndex idx);

private:
    Ui::ScegliCliForDialog *ui;
    QSqlQueryModel* model;
    FornitoriDatabaseManager* fdb;
    ClientDatabaseManager* cdb;

    QString id;

    bool forn;
};

#endif // SCEGLICLIFORDIALOG_H
