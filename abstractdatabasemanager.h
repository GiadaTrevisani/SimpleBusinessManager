#ifndef ABSTRACTDATABASEMANAGER_H
#define ABSTRACTDATABASEMANAGER_H

#include <QObject>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QHash>
#include <QString>
#include <QSqlRecord>
#include <QDebug>

/*
 * creiamo una classe astratta (padre dove specifichiamo i metodi che devono implementare
 * le classi figlie. tutte le classi figlie implementano questi metodi.
 */
class AbstractDatabaseManager : public QObject //Classe Virtuale pura
{
    Q_OBJECT
public:
    explicit AbstractDatabaseManager(QObject *parent = nullptr);

    virtual QSqlQueryModel* getModel(QString search = "") = 0;
    virtual QHash<QString, QString>* getElement(QString id) = 0;
    virtual bool updateElement(QString id, QHash<QString, QString>* data) = 0;
    virtual bool insertElement(QString id, QHash<QString, QString>* data) = 0;

signals:

public slots:
};

#endif // ABSTRACTDATABASEMANAGER_H
