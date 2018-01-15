#include "fornitoridatabasemanager.h"

FornitoriDatabaseManager::FornitoriDatabaseManager(QObject *parent) : AbstractDatabaseManager(parent)
{

}

FornitoriDatabaseManager::~FornitoriDatabaseManager()
{

}

QSqlQueryModel* FornitoriDatabaseManager::getModel(QString search){
   QSqlQueryModel* model = new QSqlQueryModel;
   if(search == ""){
       model->setQuery("SELECT * FROM fornitori");
   } else {
       QString src = QString("'%") + search + QString("%'");
       QString qry = QString("SELECT * FROM fornitori WHERE FCodeFor LIKE ") + src + QString(" OR nameFor LIKE ") + src + QString(" OR surnameFor LIKE ") + src + QString(" OR RSocFor LIKE ") + src + QString(" OR telFor LIKE ") + src + QString(" OR mailFor LIKE ") + src + QString(" OR pIvaFor LIKE ") + src + QString(" OR addressFor LIKE ") + src + QString(" OR cityFor LIKE ") + src + QString(" OR CAPFor LIKE ") + src;
       model->setQuery(qry);
   }

   return model;

}

QHash<QString, QString>* FornitoriDatabaseManager::getElement(QString id){
    QHash<QString, QString>* resultDictionary = new QHash<QString, QString>();

    QSqlQuery query;
    query.prepare("SELECT * FROM fornitori WHERE FCodeFor = :id");
    query.bindValue(":id", id);
    bool result = query.exec();
    resultDictionary->insert("id", id);
    if(result){
        if(query.first()){
            resultDictionary->insert("name", query.value(query.record().indexOf("nameFor")).toString());
            resultDictionary->insert("surname", query.value(query.record().indexOf("surnameFor")).toString());
            resultDictionary->insert("ragioneSoc", query.value(query.record().indexOf("RSocFor")).toString());
            resultDictionary->insert("tel", query.value(query.record().indexOf("telFor")).toString());
            resultDictionary->insert("mail", query.value(query.record().indexOf("mailFor")).toString());
            resultDictionary->insert("piva", query.value(query.record().indexOf("pIvaFor")).toString());
            resultDictionary->insert("address", query.value(query.record().indexOf("addressFor")).toString());
            resultDictionary->insert("city", query.value(query.record().indexOf("cityFor")).toString());
            resultDictionary->insert("cap", query.value(query.record().indexOf("CAPFor")).toString());
        }
        resultDictionary->insert("error", "false");
    } else {
        resultDictionary->insert("error", "true");
    }
    return resultDictionary;
}

bool FornitoriDatabaseManager::updateElement(QString id, QHash<QString, QString>* data){
    QSqlQuery query;
    query.prepare("UPDATE fornitori SET nameFor = :name, surnameFor = :surname, RSocFor = :ragioneSoc, telFor = :tel, mailFor = :mail, pIvaFor = :piva, addressFor = :address, cityFor = :city, CAPFor = :cap WHERE FCodeFor = :id");
    query.bindValue(":id", id);
    query.bindValue(":name", data->value("name"));
    query.bindValue(":surname",data->value("surname"));
    query.bindValue(":ragioneSoc", data->value("ragioneSoc"));
    query.bindValue(":tel", data->value("tel"));
    query.bindValue(":mail", data->value("mail"));
    query.bindValue(":piva", data->value("piva"));
    query.bindValue(":address", data->value("address"));
    query.bindValue(":city", data->value("city"));
    query.bindValue(":cap", data->value("cap"));

    return query.exec();
}

bool FornitoriDatabaseManager::insertElement(QString id, QHash<QString, QString>* data){
    QSqlQuery query;
    query.prepare("INSERT INTO fornitori (FCodeFor, nameFor, surnameFor, RSocFor, telFor, mailFor, pIvaFor, addressFor, cityFor, CAPFor) VALUES (:id, :name, :surname, :ragioneSoc, :tel, :mail, :piva, :address, :city, :cap)");
    query.bindValue(":id", id);
    query.bindValue(":name", data->value("name"));
    query.bindValue(":surname", data->value("surname"));
    query.bindValue(":ragioneSoc", data->value("ragioneSoc"));
    query.bindValue(":tel", data->value("tel"));
    query.bindValue(":mail", data->value("mail"));
    query.bindValue(":piva", data->value("piva"));
    query.bindValue(":address", data->value("address"));
    query.bindValue(":city", data->value("city"));
    query.bindValue(":cap", data->value("cap"));
    return query.exec();
}

