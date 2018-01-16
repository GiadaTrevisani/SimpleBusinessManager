#include "prodottidatabasemanager.h"

ProdottiDatabaseManager::ProdottiDatabaseManager(QObject  *parent ) : AbstractDatabaseManager(parent)
{

}

ProdottiDatabaseManager::~ProdottiDatabaseManager(){

}

QSqlQueryModel* ProdottiDatabaseManager::getModel(bool visible, QString search){
    QSqlQueryModel* model = new QSqlQueryModel;
    if(search == ""){
        if(visible){
            model->setQuery("SELECT * FROM prodotti");
        } else {
            model->setQuery("SELECT * FROM prodotti WHERE InProduzione = 1");
        }
    } else {
        QString src = QString("'%") + search + QString("%'");
        QString qry;
        if(visible){
            qry = QString("SELECT * FROM prodotti WHERE IDProd LIKE ") + src + QString(" OR descProd LIKE ") + src /*+ QString(" OR PacProd LIKE ") + src + QString(" OR PvenProd LIKE ") + src + QString(" OR giacProd LIKE ") + src+ QString(" )")*/ ;
        } else {
            qry = QString("SELECT * FROM prodotti WHERE ( InProduzione = 1 AND ( IDProd LIKE ") + src + QString(" OR descProd LIKE ") + src + QString(" ))");
        }
        model->setQuery(qry);
    }

    return model;

 }

 QHash<QString, QString>* ProdottiDatabaseManager::getElement(QString id){
     QHash<QString, QString>* resultDictionary = new QHash<QString, QString>();

     QSqlQuery query;
     query.prepare("SELECT * FROM prodotti WHERE IDProd = :id");
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
             resultDictionary->insert("inProd", query.value(query.record().indexOf("InProduction")).toString());
         }
         resultDictionary->insert("error", "false");
     } else {
         resultDictionary->insert("error", "true");
     }
     return resultDictionary;
 }

 bool ProdottiDatabaseManager::updateElement(QString id, QHash<QString, QString>* data){
     QSqlQuery query;
     query.prepare("UPDATE prodotti SET descProd = :descProd, PacProd = :PacProd, PvenProd = :PvenProd, giacProd = :giacProd WHERE IDProd = :id");
     query.bindValue(":id", id);
     query.bindValue(":descProd", data->value("description"));
     query.bindValue(":PacProd", data->value("purchasePrice").toFloat());
     query.bindValue(":PvenProd", data->value("sellingPrice").toFloat());
     query.bindValue(":giacProd", data->value("stock").toInt());

     return query.exec();
 }

 bool ProdottiDatabaseManager::insertElement(QString id, QHash<QString, QString>* data){
     QSqlQuery query;
     query.prepare("INSERT INTO prodotti (IDProd, descProd, PacProd, PvenProd, giacProd, InProduzione ) VALUES (:id, :description, :purchasePrice, :sellingPrice, :stock, 1)");
     query.bindValue(":id", id);
     query.bindValue(":description", data->value("description"));
     query.bindValue(":purchasePrice", data->value("purchasePrice").toFloat());
     query.bindValue(":sellingPrice", data->value("sellingPrice").toFloat());
     query.bindValue(":stock", data->value("stock").toInt());
     return query.exec();
 }

 bool ProdottiDatabaseManager::setProduction(QString id, int inORout)
 {
     QSqlQuery query;
     query.prepare("UPDATE prodotti SET InProduzione = :inProd WHERE IDProd = :id");
     query.bindValue(":id", id);
     query.bindValue(":inProd", inORout);

     return query.exec();
 }

 QSqlQueryModel *ProdottiDatabaseManager::getModelGiac()
 {
      QSqlQueryModel* model = new QSqlQueryModel;
      model->setQuery("SELECT * FROM prodotti WHERE giacProd > 0");
      return model;
 }

 bool ProdottiDatabaseManager::modGiac(QString id, int n)
 {
     QSqlQuery qry;
     qry.prepare("SELECT giacProd from prodotti WHERE IDProd = :id");
     qry.bindValue(":id", id);
     qry.exec();

     qry.next();
     int current = qry.value(0).toInt();
     if(current <= 0 && n <=0){
         return false;
     } else {
         if(n<=0 && (-n>current)){
             return false;
         }
         QSqlQuery query;
         query.prepare("UPDATE prodotti SET giacProd = :giac WHERE IDProd = :id");
         query.bindValue(":id", id);
         query.bindValue(":giac", current + n);

         return query.exec();
     }
 }

