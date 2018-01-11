#ifndef CLIENTDATABASEMANAGER_H
#define CLIENTDATABASEMANAGER_H

#include "abstractdatabasemanager.h"

class ClientDatabaseManager : public AbstractDatabaseManager
{
public:
    ClientDatabaseManager(QObject *parent = nullptr);
    ~ClientDatabaseManager();

    QSqlQueryModel* getModel(QString search = "");
    QHash<QString, QString>* getElement(QString id);
    bool removeElement(QString id);
    bool updateElement(QString id, QHash<QString, QString>* data);
    bool insertElement(QString id, QHash<QString, QString>* data);

signals:

public slots:
};

#endif // CLIENTDATABASEMANAGER_H
