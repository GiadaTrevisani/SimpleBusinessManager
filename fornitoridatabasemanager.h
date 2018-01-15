#ifndef FORNITORIDATABASEMANAGER_H
#define FORNITORIDATABASEMANAGER_H

#include "abstractdatabasemanager.h"

class FornitoriDatabaseManager : AbstractDatabaseManager
{
public:
    FornitoriDatabaseManager(QObject *parent = nullptr);
    ~FornitoriDatabaseManager();

    QSqlQueryModel* getModel(QString search = "");
    QHash<QString, QString>* getElement(QString id);
    bool updateElement(QString id, QHash<QString, QString>* data);
    bool insertElement(QString id, QHash<QString, QString>* data);
};

#endif // FORNITORIDATABASEMANAGER_H
