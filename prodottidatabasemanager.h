#ifndef PRODOTTIDATABASEMANAGER_H
#define PRODOTTIDATABASEMANAGER_H

#include "abstractdatabasemanager.h"
class ProdottiDatabaseManager : AbstractDatabaseManager
{
public:
    ProdottiDatabaseManager(QObject *parent = nullptr);
    ~ProdottiDatabaseManager();

    QSqlQueryModel *getModel(QString search = "");
    QHash<QString, QString>* getElement(QString id);
    bool updateElement(QString id, QHash<QString, QString> *data);
    bool insertElement(QString id, QHash<QString, QString> *data);
};

#endif // PRODOTTIDATABASEMANAGER_H
