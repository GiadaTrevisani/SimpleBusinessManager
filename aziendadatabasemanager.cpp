#include "aziendadatabasemanager.h"

AziendaDatabaseManager::AziendaDatabaseManager(QObject *parent) : QObject(parent)
{

}

bool AziendaDatabaseManager::insertAzienda(QHash<QString, QString> *data)
{
    /*
     * per creare una nuova azienda, se è la prima volta che apriamo l'applicazione
     * allora sono inseriti ivalori di dafault dove si può aggornarli semplicemente
     * digitando sopra i valori da immettere, come nome azienda(ragione sociale),
     * partita iva, nome titolare, cognome titolare, codice fiscale ecc...
     * creiamo quindi la nostra azienda facendo una query al database dicendo di creare
     * la tabella se non esiste già, im modo che se accedi un'altra volta all'applicazione
     * i dati rimangono salvati. se invece nell'azienda cambia qualcosa, come il nome del titolare
     * si possono aggiornare i valori dell'azienda.
     */
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
    /*
     * in questo metodo si vede se l'azienda esiste già.
     * in questo caso, se esiste, il metodo ritorna vero
     * sennò torna falso
     */
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

    /*
     * in questo metodo si va a fare una query al database per il tasto
     * aggiorna che c'è nella home. per aggiornare basta cambiare le variabili
     * nelle line edit e poi cliccare aggiorna.
     */
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
    /*
     * questo metodo serve per visualizzare all'inizio del programma i dati della nostra azienda
     * se non sono ancora presenti dati li mette lui di default, se invece i dati sono già presenti nel database
     * fa una query e li inserisce nella window.
     */
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
