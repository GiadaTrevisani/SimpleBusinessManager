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

class FornitoriWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FornitoriWidget(QWidget *parent = nullptr);
    ~FornitoriWidget();

signals:

public slots:

private:
	QPushButton *newFornit;
    QLineEdit *txtfornit;
    QTableView *fornitlist;

    QPushButton *aggiornaFor;

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
};

#endif // FORNITORIWIDGET_H
