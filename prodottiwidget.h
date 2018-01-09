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
#include <QStackedLayout>

class ProdottiWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ProdottiWidget(QWidget *parent = nullptr);

signals:

public slots:

private:
    QStackedLayout* stack;

    QPushButton *newProduct;
    QLineEdit *txtProduct;
    QTableWidget *productList;
    QCheckBox *visualize;

    QLineEdit *txtIDProd;
    QListView *txtDescProd;
    QLineEdit *txtPAcquisto;
    QLineEdit *txtPVendita;
    QLineEdit *txtGiacenza;
    QPushButton *aggiornaProd;
    QPushButton *togliComm;
    QPushButton *rimettiComm;
};

#endif // PRODOTTIWIDGET_H
