#include "fatturewidget.h"

/*
 * in questa classe abbiamo semre una line edit dove ci cercheremo le fatture da visualizzare,
 * il new funziona un po' diverso, cioè abbiamo due radiobutton di fianco al taso new dove
 * dobbiamo specificare se la fattura è fatta da un cliente o da un fonitore e nel caso che si selezioni
 * l'una o l'altra radio button, si entra in una nuova finestra, dove se ho specificato che è da
 * parte di un fornitore allora i dati del cliente saranno i dati della nostra azienda, nel caso
 * contrario i dati del fornitore saranno quelli dell'azienda e ci vengono scritti di default.
 * nella finestra sotto il layout abbiamo una tabella dove sono elencate le fatture. questa tabella
 * è associata alla line edit search, cioè attraverso un connect tutti caratteri che inseriamo verranno
 * passatu a un metodo che scrive una query al database e aggiorna la tabella.
 */

FattureWidget::FattureWidget(QWidget *parent) : QWidget(parent)
{
    add = new QPushButton("+");
    remove = new QPushButton("-");

    search = new QPushButton("Scegli Cliente o Fornitore");

    searchInvoices = new QLineEdit();
    searchInvoices->setPlaceholderText("Cerca Fattura");
    searchInvoices->setText("");
    newButton = new QPushButton();
    QGroupBox *newInvoices = new QGroupBox(tr("Aggiungi fattura"));
    QVBoxLayout *v_lay = new QVBoxLayout();
    QHBoxLayout *h_lay = new QHBoxLayout();
    radioClient = new QRadioButton(tr("per un cliente"));
    radioClient->setChecked(true);
    radioSupplier = new QRadioButton(tr("da un fornitore"));
    radioSupplier->setChecked(false);
    fatt = new QTableView();
    QGroupBox *invoicesVisualize = new QGroupBox(tr("Visualizza Fatture:"));
    checkClient = new QCheckBox(tr("Da clienti"));
    checkClient->setChecked(true);
    checkSuppliers = new QCheckBox(tr("Da fornitori"));
    checkSuppliers->setChecked(true);
    QHBoxLayout *searchNew = new QHBoxLayout();
    QHBoxLayout *h_invoices = new QHBoxLayout();
    QHBoxLayout *clientSupplier = new QHBoxLayout();
    QVBoxLayout * v_invoices = new QVBoxLayout();

    newButton->setText("NEW");
    //vertical layout for two radio button
    v_lay->addWidget(radioClient);
    v_lay->addWidget(radioSupplier);
    //horizontal layout for button new
    h_lay->addWidget(newButton);
    h_lay->addLayout(v_lay);
    //group box for button new and radio button
    //newInvoices->setFlat(true);
    newInvoices->setLayout(h_lay);
    //new horizontal layout for line edit search
    searchNew->addWidget(searchInvoices);
    //horizontal layout for horizontal layout for line edit search and for group box for radio button and button new
    h_invoices->addLayout(searchNew);
    h_invoices->addWidget(newInvoices);
    //group box for checkbox client and suppliers
    invoicesVisualize->setFlat(true);
    clientSupplier->addWidget(checkClient);
    clientSupplier->addWidget(checkSuppliers);
    invoicesVisualize->setLayout(clientSupplier);
    //add at widget layout the horizontal layout, list box and gruopbox with checkbox
    v_invoices->addLayout(h_invoices);
    v_invoices->addWidget(fatt);
    v_invoices->addWidget(invoicesVisualize);

    //layout dettaglaito di fatture
    //LE FATTURE NON SI POSSONO ELIMINARE!!!
    insert = new QPushButton();
    insert->setText("Insert");
    back = new QPushButton();
    back->setText("<- Indietro");
    back->setFixedSize(QSize(100,30));

    QLabel *fattRSocFor = new QLabel();
    QLabel *fattIndFor = new QLabel();
    QLabel *fattTelFor = new QLabel();
    QLabel *fattMailFor = new QLabel();
    QLabel *fattPIvaFor = new QLabel();
    fattRSocFor->setText("Ragione sociale: ");
    fattIndFor->setText("Indirizzo: ");
    fattTelFor->setText("Telefono: ");
    fattMailFor->setText("Mail: ");
    fattPIvaFor->setText("Partita Iva: ");
    productsTab = new QTableWidget();
    txtfattRSocFor = new QLineEdit();
    txtfattIndFor = new QLineEdit();
    txtFattTelFor = new QLineEdit();
    txtfattMailFor = new QLineEdit();
    txtfattPIvaFor = new QLineEdit();

    QLabel *fattRSocCli = new QLabel();
    QLabel *fattIndCli = new QLabel();
    QLabel *fattCapCli = new QLabel();
    QLabel *fattCityCli = new QLabel();
    QLabel *fattPIvaCli = new QLabel();
    QLabel *fattCFiscCli = new QLabel();

    fattRSocCli->setText("Ragione sociale: ");
    fattIndCli->setText("Indirizzo: ");
    fattCapCli->setText("CAP: ");
    fattCityCli->setText("Città: ");
    fattPIvaCli->setText("Partita Iva: ");
    fattCFiscCli->setText("Codice Fiscale: ");


    txtfattRSocCli = new QLineEdit();
    txtfattIndCli = new QLineEdit();
    txtFattCapCli = new QLineEdit();
    txtfattCityCli = new QLineEdit();
    txtfattPIvaCli = new QLineEdit();
    txtfattCFiscCli = new QLineEdit();

    QLabel *codFatt = new QLabel();
    QLabel *dataFatt = new QLabel();
    QLabel *importoFatt = new QLabel();
    QLabel *IvaFatt = new QLabel();
    QLabel *totFatt = new QLabel();

    txtCodFatt = new QLineEdit();
    txtDataFatt = new QLineEdit();
    txtImpFatt = new QLineEdit();
    txtIvaFatt = new QLineEdit();
    txtTotFatt = new QLineEdit();
    codFatt->setText("Codice Fattura: ");
    dataFatt->setText("Data Fattura: ");
    importoFatt->setText(("Importo: "));
    IvaFatt->setText("IVA: ");
    totFatt->setText("Totale: ");

    QHBoxLayout *h_idFatt = new QHBoxLayout();
    QHBoxLayout *h_fattRSocFor = new QHBoxLayout();
    QHBoxLayout *h_fattIndFor = new QHBoxLayout();
    QHBoxLayout *h_fattTelFor = new QHBoxLayout();
    QHBoxLayout *h_fattMailFor = new QHBoxLayout();
    QHBoxLayout *h_fattPIvaFor = new QHBoxLayout();
    QHBoxLayout *h_fattRSocCli = new QHBoxLayout();
    QHBoxLayout *h_fattIndCli = new QHBoxLayout();
    QHBoxLayout *h_fattCapCli = new QHBoxLayout();
    QHBoxLayout *h_fattCityCli = new QHBoxLayout();
    QHBoxLayout *h_fattPIvaCli = new QHBoxLayout();
    QHBoxLayout *h_fattCFiscCli = new QHBoxLayout();
    QHBoxLayout *h_telMail = new QHBoxLayout();
    QHBoxLayout *h_indCity = new QHBoxLayout();
    QVBoxLayout *v_fattFor = new QVBoxLayout();
    QVBoxLayout *v_fattCli = new QVBoxLayout();
    QHBoxLayout *h_fattForCli = new QHBoxLayout();
    QVBoxLayout *v_finalFatt = new QVBoxLayout();
    QHBoxLayout *h_fatt1 = new QHBoxLayout();
    QHBoxLayout *h_fatt2 = new QHBoxLayout();
    QGroupBox *boxFatt = new QGroupBox();

    h_fattRSocFor->addWidget(fattRSocFor);
    h_fattRSocFor->addWidget(txtfattRSocFor);
    h_fattIndFor->addWidget(fattIndFor);
    h_fattIndFor->addWidget(txtfattIndFor);
    h_fattTelFor->addWidget(fattTelFor);
    h_fattTelFor->addWidget(txtFattTelFor);
    h_fattMailFor->addWidget(fattMailFor);
    h_fattMailFor->addWidget(txtfattMailFor);
    h_fattPIvaFor->addWidget(fattPIvaFor);
    h_fattPIvaFor->addWidget(txtfattPIvaFor);

    h_fattRSocCli->addWidget(fattRSocCli);
    h_fattRSocCli->addWidget(txtfattRSocCli);
    h_fattIndCli->addWidget(fattIndCli);
    h_fattIndCli->addWidget(txtfattIndCli);
    h_fattCapCli->addWidget(fattCapCli);
    h_fattCapCli->addWidget(txtFattCapCli);
    h_fattCityCli->addWidget(fattCityCli);
    h_fattCityCli->addWidget(txtfattCityCli);
    h_fattPIvaCli->addWidget(fattPIvaCli);
    h_fattPIvaCli->addWidget(txtfattPIvaCli);
    h_fattCFiscCli->addWidget(fattCFiscCli);
    h_fattCFiscCli->addWidget(txtfattCFiscCli);

    h_telMail->addLayout(h_fattTelFor);
    h_telMail->addLayout(h_fattMailFor);

    h_indCity->addLayout(h_fattIndCli);
    h_indCity->addLayout(h_fattCityCli);

    v_fattFor->addLayout(h_idFatt);
    v_fattFor->addLayout(h_fattRSocFor);
    v_fattFor->addLayout(h_fattIndFor);
    v_fattFor->addLayout(h_telMail);
    v_fattFor->addLayout(h_fattPIvaFor);

    v_fattCli->addLayout(h_fattRSocCli);
    v_fattCli->addLayout(h_indCity);
    v_fattCli->addLayout(h_fattCapCli);
    v_fattCli->addLayout(h_fattPIvaCli);
    v_fattCli->addLayout(h_fattCFiscCli);

    h_fattForCli->addLayout(v_fattFor);
    h_fattForCli->addLayout(v_fattCli);
    h_fatt1->addWidget(codFatt);
    h_fatt1->addWidget(txtCodFatt);
    h_fatt1->addWidget(dataFatt);
    h_fatt1->addWidget(txtDataFatt);

    h_fatt2->addWidget(importoFatt);
    h_fatt2->addWidget(txtImpFatt);
    h_fatt2->addWidget(IvaFatt);
    h_fatt2->addWidget(txtIvaFatt);
    h_fatt2->addWidget(totFatt);
    h_fatt2->addWidget(txtTotFatt);

    QHBoxLayout* buttons_lay = new QHBoxLayout();
    buttons_lay->addWidget(add);
    buttons_lay->addWidget(remove);

    QVBoxLayout *fattLay = new QVBoxLayout();
    fattLay->addLayout(h_fatt1);
    fattLay->addWidget(productsTab);
    fattLay->addLayout(buttons_lay);

    fattLay->addLayout(h_fatt2);

    boxFatt->setLayout(fattLay);

    v_finalFatt->addWidget(back);
    v_finalFatt->addWidget(search);
    v_finalFatt->addLayout(h_fattForCli);
    v_finalFatt->addWidget(boxFatt);
    v_finalFatt->addWidget(insert);

    //Maschro i Layouts da Widget per usare il metodo addWidget()
    QWidget* c0 = new QWidget(); // primo stack con la vista standard
    c0->setLayout(v_invoices);

    QWidget* c1 = new QWidget(); // secondo stack con la vista dettaglio del cliente
    c1->setLayout(v_finalFatt);

    stack = new QStackedLayout();
    stack->addWidget(c0);
    stack->addWidget(c1);

    stack->setCurrentIndex(0);

    this->setLayout(stack);

    //---------------------------------------

    txtCodFatt->setEnabled(false);

    //Setup model
    db = new FattureDatabaseManager(this);
    model = db->getModel();
    fatt->setModel(model);

    fatt->setSelectionBehavior(QAbstractItemView::SelectRows);
    productsTab->setSelectionBehavior(QAbstractItemView::SelectRows);
    fatt->setSelectionMode(QAbstractItemView::SingleSelection);
    productsTab->setSelectionMode(QAbstractItemView::SingleSelection);
    productsTab->setColumnCount(2);
    productsTab->setEditTriggers(QAbstractItemView::NoEditTriggers);

    /*
     *
     */

    QObject::connect(fatt, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(InvoiceSelected(QModelIndex)));
    QObject::connect(newButton, SIGNAL(clicked(bool)), this, SLOT(newInvoiceClicked()));
    QObject::connect(insert, SIGNAL(clicked(bool)), this, SLOT(insertInvoice()));
    QObject::connect(searchInvoices, SIGNAL(textEdited(QString)), this, SLOT(searchChanged(QString)));
    QObject::connect(back, SIGNAL(clicked(bool)), this, SLOT(goToMainView()));
    QObject::connect(checkClient, SIGNAL(stateChanged(int)), this, SLOT(updateModel()));
    QObject::connect(checkSuppliers, SIGNAL(stateChanged(int)), this, SLOT(updateModel()));
    QObject::connect(this->search, SIGNAL(clicked(bool)), this, SLOT(searchCliFor()));
    QObject::connect(add, SIGNAL(clicked(bool)), this, SLOT(addProd()));
    QObject::connect(remove, SIGNAL(clicked(bool)), this, SLOT(deleteProd()));

    newORdetail = false;

    txtImpFatt->setEnabled(false);
    txtIvaFatt->setEnabled(false);
    txtTotFatt->setEnabled(false);

    prodsgiac = new QHash<QString, int>();
    txtDataFatt->setPlaceholderText("dd/mm/yyyy");
    currentID = "";
}

FattureWidget::~FattureWidget(){
    delete searchInvoices;
    delete newButton;
    delete radioClient;
    delete radioSupplier;
    delete productsTab;
    delete checkClient;
    delete checkSuppliers;
    delete txtFattCapCli;
    delete txtfattCFiscCli;
    delete txtfattCityCli;
    delete txtfattIndCli;
    delete txtfattIndFor;
    delete txtfattMailFor;
    delete txtfattPIvaCli;
    delete txtfattPIvaFor;
    delete txtfattRSocCli;
    delete txtfattRSocFor;
    delete txtFattTelFor;
    delete txtidfatt;
    delete txtCodFatt;
    delete fatt;

    delete stack;
    delete back;
}

void FattureWidget::InvoiceSelected(QModelIndex idx)
{
    currentID = "";
    prodsgiac->clear();
    updateTable();
    newORdetail = false;
    disableWidgets();

    //get id from table
    QString id = model->itemData(model->index(idx.row(), 0)).value(0).toString();
    QHash<QString, QString>* data = db->getElement(id);

    if(data->value("error") == "true"){
        QMessageBox msgBox;
        msgBox.setText("C'è stato un errore, elemento non esistente");
        msgBox.exec();

        delete data;
        return;
    }

    QHash<QString, int>* prods = db->getProducts(id);

    if(prods->value("error") == 1){
        QMessageBox msgBox;
        msgBox.setText("C'è stato un errore, prodotti fattura non esistenti");
        msgBox.exec();

        delete data;
        delete prods;
        return;
    }

    bool forncli = data->value("aziendaclifor").toInt();
    if(forncli){
        ClientDatabaseManager cdb;
        QHash<QString, QString>* clidata = cdb.getElement(data->value("clifor"));

        AziendaDatabaseManager adb;

        QHash<QString, QString>* fordata = adb.getAzienda();

        txtfattRSocFor->setText(fordata->value("ragioneSoc"));
        txtfattIndFor->setText(fordata->value("address"));
        txtFattTelFor->setText(fordata->value("tel"));
        txtfattMailFor->setText(fordata->value("mail"));
        txtfattPIvaFor->setText(fordata->value("piva"));

        txtfattRSocCli->setText(clidata->value("ragioneSoc"));
        txtfattIndCli->setText(clidata->value("address"));
        txtFattCapCli->setText(clidata->value("cap"));
        txtfattCityCli->setText(clidata->value("city"));
        txtfattPIvaCli->setText(clidata->value("piva"));
        txtfattCFiscCli->setText(data->value("clifor"));
    } else {
        ClientDatabaseManager fdb;
        QHash<QString, QString>* fordata = fdb.getElement(data->value("clifor"));

        AziendaDatabaseManager adb;

        QHash<QString, QString>* clidata = adb.getAzienda();

        txtfattRSocFor->setText(fordata->value("ragioneSoc"));
        txtfattIndFor->setText(fordata->value("address"));
        txtFattTelFor->setText(fordata->value("tel"));
        txtfattMailFor->setText(fordata->value("mail"));
        txtfattPIvaFor->setText(fordata->value("piva"));

        txtfattRSocCli->setText(clidata->value("ragioneSoc"));
        txtfattIndCli->setText(clidata->value("address"));
        txtFattCapCli->setText(clidata->value("cap"));
        txtfattCityCli->setText(clidata->value("city"));
        txtfattPIvaCli->setText(clidata->value("piva"));
        txtfattCFiscCli->setText(clidata->value("fiscalcode"));
    }

    prodsgiac = prods;
    updateTable();

    txtCodFatt->setText(id);
    txtDataFatt->setText(data->value("data"));
    txtImpFatt->setText(data->value("importo"));
    txtIvaFatt->setText(data->value("totIvaFatt"));
    txtTotFatt->setText(data->value("totFatt"));

    this->stack->setCurrentIndex(1);
    delete data;
}

void FattureWidget::newInvoiceClicked()
{
    currentID = "";
    prodsgiac->clear();
    updateTable();
    newORdetail = true;
    enableWidgets();

    if(radioClient->isChecked()){
        AziendaDatabaseManager adb;

        QHash<QString, QString>* fordata = adb.getAzienda();

        txtfattRSocFor->setText(fordata->value("ragioneSoc"));
        txtfattIndFor->setText(fordata->value("address"));
        txtFattTelFor->setText(fordata->value("tel"));
        txtfattMailFor->setText(fordata->value("mail"));
        txtfattPIvaFor->setText(fordata->value("piva"));

        txtfattRSocFor->setEnabled(false);
        txtfattIndFor->setEnabled(false);
        txtFattTelFor->setEnabled(false);
        txtfattMailFor->setEnabled(false);
        txtfattPIvaFor->setEnabled(false);
    } else {
        AziendaDatabaseManager adb;

        QHash<QString, QString>* clidata = adb.getAzienda();

        txtfattRSocCli->setText(clidata->value("ragioneSoc"));
        txtfattIndCli->setText(clidata->value("address"));
        txtFattCapCli->setText(clidata->value("cap"));
        txtfattCityCli->setText(clidata->value("city"));
        txtfattPIvaCli->setText(clidata->value("piva"));
        txtfattCFiscCli->setText(clidata->value("fiscalcode"));

        txtfattRSocCli->setEnabled(false);
        txtfattIndCli->setEnabled(false);
        txtFattCapCli->setEnabled(false);
        txtfattCityCli->setEnabled(false);
        txtfattPIvaCli->setEnabled(false);
        txtfattCFiscCli->setEnabled(false);
    }

    this->stack->setCurrentIndex(1);
}

void FattureWidget::updateModel()
{
    delete model;
    model = db->getModel(checkSuppliers->isChecked(),checkClient->isChecked(),searchInvoices->text());
    fatt->setModel(model);
}

void FattureWidget::goToMainView()
{
    updateModel();
    this->stack->setCurrentIndex(0);
}

void FattureWidget::insertInvoice()
{
    QHash<QString, QString>* d = new QHash<QString, QString>();
    d->insert("data", txtDataFatt->text());
    qDebug() << txtDataFatt->text();
    d->insert("importo", txtImpFatt->text());
     qDebug() << txtImpFatt->text();
    d->insert("totIvaFatt", txtIvaFatt->text());
     qDebug() << txtIvaFatt->text();
    d->insert("totFatt", txtTotFatt->text());
     qDebug() << txtTotFatt->text();
    if(currentID == ""){
        QMessageBox msgBox;
        msgBox.setText("Scegliere un Cliente/Fornitore");
        msgBox.exec();
        delete d;
        return;
    }
    if(radioClient->isChecked()){
        d->insert("clifor", currentID);
        qDebug() << currentID;
        d->insert("aziendaclifor", "1");
        qDebug() << d->value("aziendaclifor");
    } else {
        d->insert("clifor", currentID);
        qDebug() << currentID;
        d->insert("aziendaclifor", "0");
        qDebug() << d->value("aziendaclifor");
    }

    bool res = db->insertElement(txtCodFatt->text(), d);
    if(!res){
        QMessageBox msgBox;
        msgBox.setText("Errore nell'inserimento fattura");
        msgBox.exec();
        goToMainView();
        return;
    }

    db->insertProducts(txtCodFatt->text(), prodsgiac);
    ProdottiDatabaseManager pdb;

    QHashIterator<QString, int> i(*prodsgiac);
    while (i.hasNext()) {
        i.next();
        pdb.modGiac(i.key(), 0-i.value());
    }

    goToMainView();

    delete d;
}

void FattureWidget::searchChanged(QString src)
{
    delete model;
    model = db->getModel(checkSuppliers->isChecked(),checkClient->isChecked(),src);
    fatt->setModel(model);
}

void FattureWidget::searchCliFor()
{
    ScegliCliForDialog dialog;
    dialog.setType(radioSupplier->isChecked());

    int res = dialog.exec();
    if(res){
        QString id = dialog.getSelected();
        currentID = id;
        if(radioClient->isChecked()){
            ClientDatabaseManager cdb;
            QHash<QString, QString>* cli = cdb.getElement(id);

            txtfattRSocCli->setText(cli->value("ragioneSoc"));
            txtfattIndCli->setText(cli->value("address"));
            txtFattCapCli->setText(cli->value("cap"));
            txtfattCityCli->setText(cli->value("city"));
            txtfattPIvaCli->setText(cli->value("piva"));
            txtfattCFiscCli->setText(id);
        } else {
            FornitoriDatabaseManager fdb;
            QHash<QString, QString>* forn = fdb.getElement(id);

            txtfattRSocFor->setText(forn->value("ragioneSoc"));
            txtfattIndFor->setText(forn->value("address"));
            txtFattTelFor->setText(forn->value("tel"));
            txtfattMailFor->setText(forn->value("mail"));
            txtfattPIvaFor->setText(forn->value("piva"));
        }
    }
}

void FattureWidget::addProd()
{
    ScegliProdottoDialog dialog;
    int res = dialog.exec();
    if(res){
        QString id = dialog.getSelected();
        int n = dialog.getQuantity();

        if(!prodsgiac->contains(id)){
            ProdottiDatabaseManager pdb;
            QHash<QString, QString>* d = pdb.getElement(id);
            if(n > d->value("stock").toInt()){
                QMessageBox msgBox;
                msgBox.setText("Il prodotto selezionato non è disponibile in queste quantità!");
                msgBox.exec();
            } else {
                prodsgiac->insert(id, n);
            }
            delete d;
        } else {
            QMessageBox msgBox;
            msgBox.setText("Il prodotto è già presente");
            msgBox.exec();
        }
    }
    updateTable();
}

void FattureWidget::deleteProd()
{
    QModelIndexList l = productsTab->selectionModel()->selectedRows();
    if(l.size() > 0){
        int row = l.at(0).row();
        QString id = productsTab->item(row,0)->text();
        prodsgiac->remove(id);
        updateTable();
    }
}
/*
 * metodo per aggiornare la tabella tutte le volte che viene inserito un carattere dalla
 * line edit search. prima co la funzione clear pulisce la tabella, poi chiama un'altro metodo
 * per settare le righe e per settare le colonne.
 */
void FattureWidget::updateTable()
{
    productsTab->clear();
    productsTab->setRowCount(0);
    productsTab->setColumnCount(2);

    QHashIterator<QString, int> i(*prodsgiac);
    ProdottiDatabaseManager pdbm;
    float imponibile = 0;
    while (i.hasNext()) {
        i.next();
        productsTab->insertRow ( productsTab->rowCount() );
        productsTab->setItem   ( productsTab->rowCount()-1,
                                 0,
                                 new QTableWidgetItem(i.key()));
        productsTab->setItem   ( productsTab->rowCount()-1,
                                 1,
                                 new QTableWidgetItem(QString::number(i.value())));
        QHash<QString, QString>* d = pdbm.getElement(i.key());
        if(radioClient->isChecked()){
            imponibile += d->value("sellingPrice").toFloat() * (float)i.value();
        } else {
            imponibile += d->value("purchasePrice").toFloat() * (float)i.value();
        }
        delete d;
    }
    float iva = 0.22*imponibile;
    float totale = imponibile + iva;

    txtImpFatt->setText(QString::number(imponibile));
    txtIvaFatt->setText(QString::number(iva));
    txtTotFatt->setText(QString::number(totale));
}

void FattureWidget::enableWidgets()
{
    insert->show();
    add->show();
    remove->show();
    search->show();
    txtfattRSocFor->setEnabled(true);
    txtfattIndFor->setEnabled(true);
    txtFattTelFor->setEnabled(true);
    txtfattMailFor->setEnabled(true);
    txtfattPIvaFor->setEnabled(true);

    txtfattRSocCli->setEnabled(true);
    txtfattIndCli->setEnabled(true);
    txtFattCapCli->setEnabled(true);
    txtfattCityCli->setEnabled(true);
    txtfattPIvaCli->setEnabled(true);
    txtfattCFiscCli->setEnabled(true);

    txtCodFatt->setEnabled(true);
    txtDataFatt->setEnabled(true);

    txtfattRSocFor->setText("");
    txtfattIndFor->setText("");
    txtFattTelFor->setText("");
    txtfattMailFor->setText("");
    txtfattPIvaFor->setText("");

    txtfattRSocCli->setText("");
    txtfattIndCli->setText("");
    txtFattCapCli->setText("");
    txtfattCityCli->setText("");
    txtfattPIvaCli->setText("");
    txtfattCFiscCli->setText("");

    txtCodFatt->setText("");
    txtDataFatt->setText("");
    txtImpFatt->setText("");
    txtIvaFatt->setText("");
    txtTotFatt->setText("");
}

void FattureWidget::disableWidgets()
{
    insert->hide();
    add->hide();
    remove->hide();
    search->hide();
    txtfattRSocFor->setEnabled(false);
    txtfattIndFor->setEnabled(false);
    txtFattTelFor->setEnabled(false);
    txtfattMailFor->setEnabled(false);
    txtfattPIvaFor->setEnabled(false);

    txtfattRSocCli->setEnabled(false);
    txtfattIndCli->setEnabled(false);
    txtFattCapCli->setEnabled(false);
    txtfattCityCli->setEnabled(false);
    txtfattPIvaCli->setEnabled(false);
    txtfattCFiscCli->setEnabled(false);

    txtCodFatt->setEnabled(false);
    txtDataFatt->setEnabled(false);
}
