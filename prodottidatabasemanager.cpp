#include "prodottidatabasemanager.h"

ProdottiDatabaseManager::ProdottiDatabaseManager(QObject  *parent ) : AbstractDatabaseManager(parent)
{

}

ProdottiDatabaseManager::~ProdottiDatabaseManager(){

}

QSqlQueryModel* ProdottiDatabaseManager::getModel(QString search){
    QSqlQueryModel* model = new QSqlQueryModel;
    if(search == ""){
        model->setQuery("SELECT * FROM prodotti");
    } else {
        QString src = QString("%") + search + QString("%");
        QString qry = QString("SELECT * FROM prodotti WHERE IDProd LIKE ") + src + QString(" OR descProd LIKE ") + src + QString(" OR PacProd LIKE ") + src + QString(" OR PvenProd LIKE ") + src + QString(" OR giacProd LIKE ");
        model->setQuery(qry);
    }

    return model;

 }

 QHash<QString, QString>* ProdottiDatabaseManager::getElement(QString id){
     QHash<QString, QString>* resultDictionary = new QHash<QString, QString>();

     QSqlQuery query;
     query.prepare("SELECT * FROM fornitori WHERE IDProd = :id");
     query.bindValue(":id", id);
     bool result = query.exec();
     resultDictionary->insert("id", id);
     if(result){
         if(query.first()){
             resultDictionary->insert("description", query.value(query.record().indexOf("descProd")).toString());
             //prezzo di acquisto, prezzo di vendita e giacenza dobbiamo farli diventare stringhe per non fargli fare un cast che potrebbe compromettere i dati QString::number(<value>); ma dove metterlo?
             resultDictionary->insert("purchasePrice", query.value(query.record().indexOf("PacProd")).toString());
             resultDictionary->insert("sellingPrice", query.value(query.record().indexOf("PvenProd")).toString());
             resultDictionary->insert("stock", query.value(query.record().indexOf("giacProd")).toString());
         }
         resultDictionary->insert("error", "false");
     } else {
         resultDictionary->insert("error", "true");
     }
     return resultDictionary;
 }

 bool ProdottiDatabaseManager::updateElement(QString id, QHash<QString, QString>* data){
     QSqlQuery query;
     query.prepare("UPDATE prodotti SET descripion = :descProd, purchasePrice = :PacProd, sellingPrice = :PvenProd, stock = :giacProd WHERE IDProd = :id");
     query.bindValue(":id", id);
     query.bindValue(":descProd", data->value("description"));
     query.bindValue(":PacProd",data->value("purchasePrice"));
     query.bindValue(":PvenProd", data->value("sellingPrice"));
     query.bindValue(":giacProd", data->value("stock"));

     return query.exec();
 }

 bool ProdottiDatabaseManager::insertElement(QString id, QHash<QString, QString>* data){
     QSqlQuery query;
     query.prepare("INSERT INTO prodotti (IDProd, descProd, PacProd, PvenProd, giacProd ) VALUES (:id, :description, :purchaseProce, :sellingPrice, :stock)");
     query.bindValue(":id", id);
     query.bindValue(":descProd", data->value("description"));
     query.bindValue(":PacProd", data->value("purchasePrice"));
     query.bindValue(":PvenProd", data->value("sellingPrice"));
     query.bindValue(":giacProd", data->value("stock"));
     return query.exec();
 }

