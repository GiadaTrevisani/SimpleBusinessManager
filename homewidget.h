#ifndef HOMEWIDGET_H
#define HOMEWIDGET_H

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

#include <aziendadatabasemanager.h>


class HomeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit HomeWidget(QWidget *parent = nullptr);
    ~HomeWidget(){
        delete txtName;
        delete txtragSoc;
        delete txtSurname;
        delete txtTel;
        delete txtMail;
        delete txtPIva;
        delete txtFiscalC;
        delete txtAddress;
        delete txtCity;
        delete txtCap;
        delete aggiorna;
        delete db;
    }

signals:

public slots:
    void updateAzienda();
    void fillAzienda();

private:
    QLineEdit *txtName;
    QLineEdit *txtragSoc;
    QLineEdit *txtSurname;
    QLineEdit *txtTel;
    QLineEdit *txtMail;
    QLineEdit *txtPIva;
    QLineEdit *txtFiscalC;
    QLineEdit *txtAddress;
    QLineEdit *txtCity;
    QLineEdit *txtCap;

    QPushButton* aggiorna;

    AziendaDatabaseManager* db;
};

#endif // HOMEWIDGET_H
