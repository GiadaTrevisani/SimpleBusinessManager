#ifndef CLIENTDATABASEMANAGER_H
#define CLIENTDATABASEMANAGER_H

#include "abstractdatabasemanager.h"


/*
 * includiamo la classe astratta, quindi dovremo implementare
 * i metodi e nel caso in cui ne volessimo aggiungere un alto
 * possiamo farlo, ma sarà specificato in questa classe
 * non nella classe astratta. quindi le altre classi non possono
 * definire questo metodo, ma implementarne uno nuovo.
 */
class ClientDatabaseManager : public AbstractDatabaseManager
{
public:
    ClientDatabaseManager(QObject *parent = nullptr);
    ~ClientDatabaseManager();

    QSqlQueryModel* getModel(QString search = "");
    QHash<QString, QString>* getElement(QString id);
    bool updateElement(QString id, QHash<QString, QString>* data);
    bool insertElement(QString id, QHash<QString, QString>* data);
};

#endif // CLIENTDATABASEMANAGER_H
