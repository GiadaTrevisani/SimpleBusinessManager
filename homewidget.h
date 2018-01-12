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


class HomeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit HomeWidget(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // HOMEWIDGET_H
