#ifndef AZIENDADATABASEMANAGER_H
#define AZIENDADATABASEMANAGER_H

#include <QObject>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QHash>
#include <QString>
#include <QSqlRecord>
#include <QDebug>

class AziendaDatabaseManager : public QObject
{
    Q_OBJECT
public:
    explicit AziendaDatabaseManager(QObject *parent = nullptr);

    QHash<QString, QString>* getAzienda();
    bool updateAzienda(QHash<QString, QString>* data);
    bool insertAzienda(QHash<QString, QString>* data);

    bool isPresent();


signals:

public slots:
};

#endif // AZIENDADATABASEMANAGER_H
