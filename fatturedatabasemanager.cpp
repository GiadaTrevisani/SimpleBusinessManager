#include "fatturedatabasemanager.h"

FattureDatabaseManager::FattureDatabaseManager(QObject *parent) : AbstractDatabaseManager(parent)
{

}

QSqlQueryModel* FattureDatabaseManager::getModel(bool forn, bool cli, QString search){
    QSqlQueryModel *model = new QSqlQueryModel;
    if(search == ""){
        QString qry = "SELECT * FROM fatture";
        if(!(forn && cli)){
            if(forn || cli){
                qry = qry + QString(" WHERE ");
                if(forn){
                    qry = qry + QString("aziendaForOrCli = 0");
                } else {
                    qry = qry + QString("aziendaForOrCli = 1");
                }
            }
        }
        model->setQuery(qry);
    } else {
        QString src = QString("'%") + search + QString("%'");
        QString qry = "SELECT * FROM fatture WHERE ";
        if(!(forn && cli)){
            if(forn || cli){
                if(forn){
                    qry = qry + QString("aziendaForOrCli = 0 AND ( ");
                } else {
                    qry = qry + QString("aziendaForOrCli = 1 AND ( ");
                }
            }
        }
        qry = qry + QString("codFatt LIKE ") + src + QString(" OR dataFatt LIKE ") + src + QString(" OR idCliFor LIKE ") + src;
        if(!(forn && cli) && (forn || cli)){
            qry = qry + QString(" )");
        }
        model->setQuery(qry);
    }

    return model;
}

QHash<QString, QString>* FattureDatabaseManager::getElement(QString id){
    QHash<QString, QString>* resultDictionary = new QHash<QString, QString>();

    QSqlQuery query;
    query.prepare("SELECT * FROM fatture WHERE codFatt = :id");
    query.bindValue(":id", id);
    bool result = query.exec();
    resultDictionary->insert("id", id);
    if(result){
        if(query.first()){
            resultDictionary->insert("data", query.value(query.record().indexOf("dataFatt")).toString());
            resultDictionary->insert("importo", query.value(query.record().indexOf("importoFatt")).toString());
            resultDictionary->insert("totIvaFatt", query.value(query.record().indexOf("totIvaFatt")).toString());
            resultDictionary->insert("totFatt", query.value(query.record().indexOf("totFatt")).toString());
            resultDictionary->insert("clifor", query.value(query.record().indexOf("idCliFor")).toString());
            resultDictionary->insert("aziendaclifor", query.value(query.record().indexOf("aziendaForOrCli")).toString());
        }
        resultDictionary->insert("error", "false");
    } else {
        resultDictionary->insert("error", "true");
    }
    return resultDictionary;
}

bool FattureDatabaseManager::updateElement(QString id, QHash<QString, QString>* data){
    QSqlQuery query;
    query.prepare("UPDATE fatture SET dataFatt = :data, importoFatt = :importo, totIvaFatt = :totIvaFatt, totFatt = :totFatt, idCliFor = :clifor, aziendaForOrCli = :aziendaclifor WHERE codFatt = :id");
    query.bindValue(":id", id);
    query.bindValue(":data", QDate::fromString(data->value("data")));
    query.bindValue(":importo", data->value("importo").toFloat());
    query.bindValue(":totIvaFatt", data->value("totIvaFatt").toFloat());
    query.bindValue(":totFatt", data->value("totFatt").toFloat());
    query.bindValue(":clifor", data->value("idCliFor"));
    query.bindValue(":aziendaclifor", data->value("aziendaForOrCli").toInt());

    return query.exec();
}

bool FattureDatabaseManager::insertElement(QString id, QHash<QString, QString>* data){
    QSqlQuery query;
    query.prepare("INSERT INTO fatture (codFatt, dataFatt, importoFatt, totIvaFatt, totFatt, idCliFor, aziendaForOrCli) VALUES (:id, :data, :importo, :totIvaFatt, :totFatt, :clidor, :aziendaclifor)");
    query.bindValue(":id", id);
    query.bindValue(":data", QDate::fromString(data->value("data")));
    query.bindValue(":importo", data->value("importo").toFloat());
    query.bindValue(":totIvaFatt", data->value("totIvaFatt").toFloat());
    query.bindValue(":totFatt", data->value("totFatt").toFloat());
    query.bindValue(":clifor", data->value("clifor"));
    query.bindValue(":aziendaclifor", data->value("aziendaclifor").toInt());

    return query.exec();
}

bool FattureDatabaseManager::insertProducts(QString id, QHash<QString, int> *prods)
{
    QHashIterator<QString, int> i(*prods);
    while (i.hasNext()) {
        i.next();
        QSqlQuery query;
        query.prepare("INSERT INTO prodfatt (idfatt, idprod, quant) VALUES (:id, :prod, :quant)");
        query.bindValue(":id", id);
        query.bindValue(":prod", i.key());
        query.bindValue(":quant", i.value());

        if(!query.exec()){
            return false;
        }
    }
    return true;
}

QHash<QString, int> *FattureDatabaseManager::getProducts(QString id)
{
    QHash<QString, int>* resultDictionary = new QHash<QString, int>();
    QSqlQuery query;
    query.prepare("SELECT idprod, quant FROM prodfatt WHERE idfatt = :id");
    query.bindValue(":id", id);

    bool result = query.exec();
    if(result){
        while (query.next()) {
            resultDictionary->insert(query.value(query.record().indexOf("idprod")).toString(), query.value(query.record().indexOf("quant")).toInt());
        }
        resultDictionary->insert("error", 0);
    } else {
        resultDictionary->insert("error", 1);
    }
    return resultDictionary;
}



