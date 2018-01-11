#include "mainwindow.h"
#include <QApplication>

#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database.db");
    db.open();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
