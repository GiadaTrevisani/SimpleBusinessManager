#include "clientdatabasemanager.h"

ClientDatabaseManager::ClientDatabaseManager(QObject *parent) : AbstractDatabaseManager(parent)
{

}

ClientDatabaseManager::~ClientDatabaseManager()
{

}

QSqlQueryModel* ClientDatabaseManager::getModel(QString search){
    QSqlQueryModel *model = new QSqlQueryModel;
    /*
     * questo metodo ci restitusce il model della stringa cerca che gli abbiamo passato.
     * Se nella line edit (txtcerca) non c'è scritto niente, allora il programma fa una query
     * al database selezionando tutte le righe della tabella clienti.
     * se invece nella txtCerca abbiamo inserito qualcosa, ogni volta che inseriamo un carattere
     * lui fa ogni volta una query per cercare in tutti gli elementi di quella tabella, carattere
     * per carattere se esiste un elemento con quel nome. Se trova qualcosa che ci assomiglia allora
     * lo fa visualizzare sullo schermo.
     */
    if(search == ""){
        model->setQuery("SELECT * FROM clienti");
    } else {
        QString src = QString("'%") + search + QString("%'");
        QString qry = QString("SELECT * FROM clienti WHERE ClientFiscalC LIKE ") + src + QString(" OR clientName LIKE ") + src + QString(" OR clientSurname LIKE ") + src + QString(" OR clientRSoc LIKE ") + src + " OR clientTel LIKE " + src + " OR mailClient LIKE "+ src +" OR pIvaClient LIKE "+ src +" OR addressClient LIKE "+src+" OR cityClient LIKE "+src+" OR CAPClient LIKE "+src;
        model->setQuery(qry);
    }

    return model;
}

QHash<QString, QString>* ClientDatabaseManager::getElement(QString id){
    QHash<QString, QString>* resultDictionary = new QHash<QString, QString>();

    QSqlQuery query;
    query.prepare("SELECT * FROM clienti WHERE ClientFiscalC = :id");
    query.bindValue(":id", id);
    bool result = query.exec();
    resultDictionary->insert("id", id);
    if(result){
        if(query.first()){
            resultDictionary->insert("name", query.value(query.record().indexOf("clientName")).toString());
            resultDictionary->insert("surname", query.value(query.record().indexOf("clientSurname")).toString());
            resultDictionary->insert("ragioneSoc", query.value(query.record().indexOf("clientRSoc")).toString());
            resultDictionary->insert("tel", query.value(query.record().indexOf("clientTel")).toString());
            resultDictionary->insert("mail", query.value(query.record().indexOf("mailClient")).toString());
            resultDictionary->insert("piva", query.value(query.record().indexOf("pIvaClient")).toString());
            resultDictionary->insert("address", query.value(query.record().indexOf("addressClient")).toString());
            resultDictionary->insert("city", query.value(query.record().indexOf("cityClient")).toString());
            resultDictionary->insert("cap", query.value(query.record().indexOf("CAPClient")).toString());
        }
        resultDictionary->insert("error", "false");
    } else {
        resultDictionary->insert("error", "true");
    }
    return resultDictionary;
}

bool ClientDatabaseManager::updateElement(QString id, QHash<QString, QString>* data){
    /*
     * in questo metodo, quando viene chiamato nella classe ClientWidget viene passato anche l'id e il dizionario
     * della nostra tabella clienti e poi viene eseguito l'aggiornamento tramite delle query fatte al database.
     */
    QSqlQuery query;
    query.prepare("UPDATE clienti SET clientName = :name, clientSurname = :surname, clientRSoc = :ragioneSoc, clientTel = :tel, mailClient = :mail, pIvaClient = :piva, addressClient = :address, cityClient = :city, CAPClient = :cap WHERE ClientFiscalC = :id");
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

bool ClientDatabaseManager::insertElement(QString id, QHash<QString, QString>* data){
    /*
     * in questo metodo inseriamo un elemento, cioè connettendo qusto metodo con un segnale (nella classe ClientWidget.cpp)
     * facciamo una query al database di inserimento dei valori passati come dizionario nei parametri della funzione
     */
    QSqlQuery query;
    query.prepare("INSERT INTO clienti (ClientFiscalC, clientName, clientSurname, clientRSoc, clientTel, mailClient, pIvaClient, addressClient, cityClient, CAPClient) VALUES (:id, :name, :surname, :ragioneSoc, :tel, :mail, :piva, :address, :city, :cap)");
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
