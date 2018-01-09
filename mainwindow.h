#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QTabWidget>

#include "homewidget.h"
#include "clientwidget.h"
#include "fornitoriwidget.h"
#include "prodottiwidget.h"
#include "fatturewidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
     Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
