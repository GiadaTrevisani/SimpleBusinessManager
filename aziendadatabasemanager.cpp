#include "aziendadatabasemanager.h"

AziendaDatabaseManager::AziendaDatabaseManager(QObject *parent) : QObject(parent)
{

}

bool AziendaDatabaseManager::insertAzienda(QHash<QString, QString> *data)
{
    QSqlQuery query;
    query.prepare("INSERT INTO azienda (id, FiscalC, Name, Surname, RSoc, Tel, mail, pIva, address, city, CAP) VALUES (:id, :fiscalcode, :name, :surname, :ragioneSoc, :tel, :mail, :piva, :address, :city, :cap)");
    query.bindValue(":id", 1);
    query.bindValue(":fiscalcode", data->value("fiscalcode"));
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

bool AziendaDatabaseManager::isPresent()
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM azienda");
    bool res = query.exec();
    if(query.next()){
        return query.value(0).toInt();
    } else {
        return false;
    }
}

bool AziendaDatabaseManager::updateAzienda(QHash<QString, QString> *data)
{
    QSqlQuery query;
    query.prepare("UPDATE azienda SET FiscalC = :fiscalcode, Name = :name, Surname = :surname, RSoc = :ragioneSoc, Tel = :tel, mail = :mail, pIva = :piva, address = :address, city = :city, CAP = :cap WHERE id = :id");
    query.bindValue(":id", 1);
    query.bindValue(":fiscalcode", data->value("fiscalcode"));
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

QHash<QString, QString> *AziendaDatabaseManager::getAzienda()
{
    QHash<QString, QString>* resultDictionary = new QHash<QString, QString>();

    QSqlQuery query;
    query.prepare("SELECT * FROM azienda WHERE id = :id");
    query.bindValue(":id", 1);
    bool result = query.exec();
    if(result){
        if(query.first()){
            resultDictionary->insert("fiscalcode", query.value(query.record().indexOf("FiscalC")).toString());
            resultDictionary->insert("name", query.value(query.record().indexOf("Name")).toString());
            resultDictionary->insert("surname", query.value(query.record().indexOf("Surname")).toString());
            resultDictionary->insert("ragioneSoc", query.value(query.record().indexOf("RSoc")).toString());
            resultDictionary->insert("tel", query.value(query.record().indexOf("Tel")).toString());
            resultDictionary->insert("mail", query.value(query.record().indexOf("mail")).toString());
            resultDictionary->insert("piva", query.value(query.record().indexOf("pIva")).toString());
            resultDictionary->insert("address", query.value(query.record().indexOf("address")).toString());
            resultDictionary->insert("city", query.value(query.record().indexOf("city")).toString());
            resultDictionary->insert("cap", query.value(query.record().indexOf("CAP")).toString());
        }
        resultDictionary->insert("error", "false");
    } else {
        resultDictionary->insert("error", "true");
    }
    return resultDictionary;
}
