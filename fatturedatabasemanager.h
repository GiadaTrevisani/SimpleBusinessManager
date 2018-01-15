#ifndef FATTUREDATABASEMANAGER_H
#define FATTUREDATABASEMANAGER_H

#include "abstractdatabasemanager.h"
#include <QDate>

class FattureDatabaseManager : public AbstractDatabaseManager
{
public:
    FattureDatabaseManager(QObject *parent = nullptr);
    ~FattureDatabaseManager(){}

    QSqlQueryModel* getModel(QString search = ""){
        return getModel(true, true, search);
    }

    QSqlQueryModel* getModel(bool forn, bool cli, QString search = "");
    QHash<QString, QString>* getElement(QString id);
    bool updateElement(QString id, QHash<QString, QString>* data);
    bool insertElement(QString id, QHash<QString, QString>* data);

    bool insertProducts(QString id, QHash<QString, int>* prods);
    QHash<QString, int>* getProducts(QString id);
};

#endif // FATTUREDATABASEMANAGER_H
