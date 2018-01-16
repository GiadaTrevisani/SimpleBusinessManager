#include "mainwindow.h"
#include <QApplication>

#include <QSqlDatabase>
#include <QSqlQuery>
#include "aziendadatabasemanager.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    /*
     * in questa classe, che esiste per tutta la durata del programma è definito
     * il database con nome db, creato con sqlite3 dove abbiamo creato anche le tabelle
     * con il comando INSERT TABLE IF NOT EXISTS, e qui nella classe main viene implementato
     * appunto questo database
     */
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database.db");
    db.open();

    QSqlQuery azienda("CREATE TABLE IF NOT EXISTS azienda( id INTEGER PRIMARY KEY, FiscalC TEXT NOT NULL, Name TEXT NOT NULL, Surname TEXT NOT NULL, RSoc TEXT, Tel TEXT NOT NULL, mail TEXT, pIva TEXT, address TEXT NOT NULL, city TEXT NOT NULL, CAP TEXT NOT NULL)");
    azienda.exec();

    QSqlQuery clienti("CREATE TABLE IF NOT EXISTS clienti( ClientFiscalC TEXT PRIMARY KEY, clientName TEXT NOT NULL, clientSurname TEXT NOT NULL, clientRSoc TEXT, clientTel TEXT NOT NULL, mailClient TEXT, pIvaClient TEXT, addressClient TEXT NOT NULL, cityClient TEXT NOT NULL, CAPClient TEXT NOT NULL)");
    clienti.exec();

    QSqlQuery fornitori("CREATE TABLE IF NOT EXISTS fornitori( FCodeFor TEXT PRIMARY KEY, nameFor TEXT NOT NULL, surnameFor TEXT NOT NULL, RSocFor TEXT NOT NULL, telFor TEXT NOT NULL, mailFor TEXT, pIvaFor TEXT NOT NULL, addressFor TEXT NOT NULL, cityFor TEXT NOT NULL, CAPFor TEXT NOT NULL)");
    fornitori.exec();

    QSqlQuery prodotti("CREATE TABLE IF NOT EXISTS prodotti( IDProd TEXT PRIMARY KEY, descProd TEXT NOT NULL, PacProd REAL NOT NULL, PvenProd REAL NOT NULL, giacProd INTEGER NOT NULL, InProduzione INTEGER NOT NULL)");
    prodotti.exec();

    QSqlQuery fatture("CREATE TABLE IF NOT EXISTS fatture( codFatt TEXT PRIMARY KEY, dataFatt DATE NOT NULL, importoFatt REAL NOT NULL, totIvaFatt REAL NOT NULL, totFatt REAL NOT NULL, idCliFor TEXT NOT NULL, aziendaForOrCli INTEGER NOT NULL)");
    fatture.exec();

    QSqlQuery prodfatt("CREATE TABLE IF NOT EXISTS prodfatt( idfatt TEXT, idprod TEXT, quant INTEGER, FOREIGN KEY(idfatt) REFERENCES fatture(codFatt), FOREIGN KEY(idprod) REFERENCES fatture(IDProd), PRIMARY KEY(idfatt, idprod) )");
    prodfatt.exec();

    /*
     * creiamo anche la nostra azienda. la prima volta che apriamo il programma dopo averlo
     * scaricato si avranno valori di default, invece una volta inseriti è possibile anche aggiornarli,
     * e se si esce dal programma e si rientra in un secondo momento i dati dell'azienda sono memorizzati
     * nel database, attraverso il comando insert.
     */
    AziendaDatabaseManager adb;

    if(!adb.isPresent()){
        QHash<QString, QString>* d = new QHash<QString, QString>();
        d->insert("fiscalcode", "fiscalcode");
        d->insert("name", "name");
        d->insert("surname", "surname");
        d->insert("ragioneSoc", "ragioneSoc");
        d->insert("tel", "tel");
        d->insert("mail", "mail");
        d->insert("piva", "piva");
        d->insert("address", "address");
        d->insert("city", "city");
        d->insert("cap", "cap");

        bool res = adb.insertAzienda(d);
        //qDebug() << "Here " << res;
        delete d;
    }

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
