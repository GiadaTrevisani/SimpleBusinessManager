#ifndef PRODOTTIDATABASEMANAGER_H
#define PRODOTTIDATABASEMANAGER_H

#include "abstractdatabasemanager.h"
class ProdottiDatabaseManager : AbstractDatabaseManager
{
public:
    ProdottiDatabaseManager(QObject *parent = nullptr);
    ~ProdottiDatabaseManager();

    QSqlQueryModel *getModel(QString search = ""){
        return getModel(false, search);
    }

    QSqlQueryModel *getModel(bool visible, QString search = "");
    QHash<QString, QString>* getElement(QString id);
    bool updateElement(QString id, QHash<QString, QString> *data);
    bool insertElement(QString id, QHash<QString, QString> *data);

    bool setProduction(QString id, int inORout);
};

#endif // PRODOTTIDATABASEMANAGER_H
