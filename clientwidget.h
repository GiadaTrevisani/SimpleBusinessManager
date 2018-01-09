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
#include <QStackedLayout>

class ClientWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ClientWidget(QWidget *parent = nullptr);

signals:

public slots:

private:
    QPushButton *newClient;
    QLineEdit *txtCerca;
    QTableWidget *clientTab;

    QPushButton *aggiorna;

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
};

#endif // CLIENTWIDGET_H
