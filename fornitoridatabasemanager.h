#ifndef FORNITORIDATABASEMANAGER_H
#define FORNITORIDATABASEMANAGER_H

#include "abstractdatabasemanager.h"

class fornitoridatabasemanager : AbstractDatabaseManager
{
public:
    fornitoridatabasemanager(QObject *parent = nullptr);
    ~fornitoridatabasemanager();

    QSqlQueryModel* getModel(QString search = "");
    QHash<QString, QString>* getElement(QString id);
    bool updateElement(QString id, QHash<QString, QString>* data);
    bool insertElement(QString id, QHash<QString, QString>* data);

signals:

public slots:
};

#endif // FORNITORIDATABASEMANAGER_H
