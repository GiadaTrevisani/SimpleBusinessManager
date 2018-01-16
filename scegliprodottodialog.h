#ifndef SCEGLIPRODOTTODIALOG_H
#define SCEGLIPRODOTTODIALOG_H

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

#include "prodottidatabasemanager.h"

namespace Ui {
class ScegliProdottoDialog;
}

class ScegliProdottoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ScegliProdottoDialog(QWidget *parent = 0);
    ~ScegliProdottoDialog();

    int getQuantity();
    QString getSelected();
public slots:
    void elementClicked(QModelIndex idx);
private:
    Ui::ScegliProdottoDialog *ui;

    ProdottiDatabaseManager* db;

    QSqlQueryModel* model;
    QString id;
};

#endif // SCEGLIPRODOTTODIALOG_H
