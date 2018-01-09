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
#include <QStackedLayout>

class FattureWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FattureWidget(QWidget *parent = nullptr);

signals:

public slots:

private:
    QLineEdit *searchInvoices;
    QPushButton *newButton;

    QRadioButton *radioClient;
    QRadioButton *radioSupplier;

    QTableWidget *invoicesList;

    QCheckBox *checkClient;
    QCheckBox *checkSuppliers;

    QLineEdit *txtfattRSocFor;
    QLineEdit *txtfattIndFor;
    QLineEdit *txtFattTelFor;
    QLineEdit *txtfattMailFor;
    QLineEdit *txtfattPIvaFor;

    QTableWidget *fatt;

    QLineEdit *txtidfatt;
    QLineEdit *txtfattRSocCli;
    QLineEdit *txtfattIndCli;
    QLineEdit *txtFattCapCli;
    QLineEdit *txtfattCityCli;
    QLineEdit *txtfattPIvaCli;
    QLineEdit *txtfattCFiscCli;

    QStackedLayout* stack;
};

#endif // FATTUREWIDGET_H
