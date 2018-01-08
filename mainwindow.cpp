#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //creiamo le tab home, fornitori, clienti, prodotti e fatture
    QWidget *home = new QWidget();

    //layout di clienti
    QWidget *clienti = new QWidget();
    QPushButton *newClient = new QPushButton();
    QLineEdit *txtCerca = new QLineEdit();
    QTabWidget *clientTab = new QTabWidget();
    QHBoxLayout *h_client = new QHBoxLayout();
    QVBoxLayout *v_client = new QVBoxLayout();

    newClient->setText("NEW");
    h_client->addWidget(txtCerca);
    h_client->addWidget(newClient);
    v_client->addLayout(h_client);
    v_client->addWidget(clientTab);
    clienti->setLayout(v_client);

    //secondo layout visualizzazione in dettagilio di clienti
    QLabel *infoClient = new QLabel();
    infoClient->setText("Informazioni cliente");
    QLabel *sedeClient = new QLabel();
    sedeClient->setText("Sede cliente");
    QLabel *clientRagSoc = new QLabel();
    QLabel *clientName = new QLabel();
    QLabel *clientSurname = new QLabel();
    QLabel *clientTel = new QLabel();
    QLabel *clientMail = new QLabel();
    QLabel *clientPIva = new QLabel();
    QLabel *clientFiscalC = new QLabel();
    QLabel *clientAddress = new QLabel();
    QLabel *clientCity = new QLabel();
    QLabel *clientCap = new QLabel();
    QPushButton *aggiorna = new QPushButton();
    QLineEdit *txtclientName = new QLineEdit();
    QLineEdit *txtragSoc = new QLineEdit();
    QLineEdit *txtclientSurname = new QLineEdit();
    QLineEdit *txtclientTel = new QLineEdit();
    QLineEdit *txtclientMail = new QLineEdit();
    QLineEdit *txtclientPIva = new QLineEdit();
    QLineEdit *txtclientFiscalC = new QLineEdit();
    QLineEdit *txtclientAddress = new QLineEdit();
    QLineEdit *txtclientCity = new QLineEdit();
    QLineEdit *txtclientCap = new QLineEdit();
    QVBoxLayout *v_finalClient = new QVBoxLayout();
    QHBoxLayout *h_divide = new QHBoxLayout();
    QVBoxLayout *v_divide1 = new QVBoxLayout();
    QVBoxLayout *v_divide2 = new QVBoxLayout();
    QHBoxLayout *h_ragSoc = new QHBoxLayout();
    QHBoxLayout *h_nameC= new QHBoxLayout();
    QHBoxLayout *h_surnameC= new QHBoxLayout();
    QHBoxLayout *h_telC= new QHBoxLayout();
    QHBoxLayout *h_mailC= new QHBoxLayout();
    QHBoxLayout *h_addressC= new QHBoxLayout();
    QHBoxLayout *h_pIvaC= new QHBoxLayout();
    QHBoxLayout *h_cityC= new QHBoxLayout();
    QHBoxLayout *h_capC= new QHBoxLayout();
    QHBoxLayout *h_codeFC= new QHBoxLayout();

    clientRagSoc->setText("Ragione sociale: ");
    clientName->setText("Nome: ");
    clientSurname->setText("Cognome: ");
    clientTel->setText("Telefono: ");
    clientMail->setText("Mail: ");
    clientAddress->setText("Indirizzo: ");
    clientPIva->setText("Partita iva: ");
    clientFiscalC->setText("Codice fiscale: ");
    clientCity->setText("Città: ");
    clientCap->setText("Cap: ");
    aggiorna->setText("AGGIORNA");
    txtragSoc->setText("___________");
    txtclientName->setText("____________");
    txtclientSurname->setText("____________");
    txtclientTel->setText("____________");
    txtclientMail->setText("____________");
    txtclientAddress->setText("____________");
    txtclientPIva->setText("____________");
    txtclientFiscalC->setText("____________");
    txtclientCity->setText("____________");
    txtclientCap->setText("___________");

    h_ragSoc->addWidget(clientRagSoc);
    h_ragSoc->addWidget(txtragSoc);
    h_nameC->addWidget(clientName);
    h_nameC->addWidget(txtclientName);
    h_surnameC->addWidget(clientSurname);
    h_surnameC->addWidget(txtclientSurname);
    h_mailC->addWidget(clientMail);
    h_mailC->addWidget(txtclientMail);
    h_codeFC->addWidget(clientFiscalC);
    h_codeFC->addWidget(txtclientFiscalC);


    h_pIvaC->addWidget(clientPIva);
    h_pIvaC->addWidget(txtclientPIva);
    h_telC->addWidget(clientTel);
    h_telC->addWidget(txtclientTel);
    h_cityC->addWidget(clientCity);
    h_cityC->addWidget(txtclientCity);
    h_addressC->addWidget(clientAddress);
    h_addressC->addWidget(txtclientAddress);
    h_capC->addWidget(clientCap);
    h_capC->addWidget(txtclientCap);

    v_divide1->addWidget(infoClient);
    v_divide1->addLayout(h_ragSoc);
    v_divide1->addLayout(h_nameC);
    v_divide1->addLayout(h_surnameC);
    v_divide1->addLayout(h_codeFC);
    v_divide1->addLayout(h_mailC);

    v_divide2->addWidget(sedeClient);
    v_divide2->addLayout(h_pIvaC);
    v_divide2->addLayout(h_telC);
    v_divide2->addLayout(h_cityC);
    v_divide2->addLayout(h_addressC);
    v_divide2->addLayout(h_capC);

    h_divide->addLayout(v_divide1);
    h_divide->addLayout(v_divide2);

    v_finalClient->addLayout(h_divide);
    v_finalClient->addWidget(aggiorna);

    //layout di fornitori
    QWidget *fornitori = new QWidget();
    QPushButton *newFornit = new QPushButton();
    QLineEdit *txtfornit = new QLineEdit();
    QTabWidget *fornitlist = new QTabWidget();
    QHBoxLayout *h_fornit = new QHBoxLayout();
    QVBoxLayout *v_fornit = new QVBoxLayout();

    newFornit->setText("NEW");
    h_fornit->addWidget(txtfornit);
    h_fornit->addWidget(newFornit);
    v_fornit->addLayout(h_fornit);
    v_fornit->addWidget(fornitlist);
    fornitori->setLayout(v_fornit);



    //secondo layout visualizzazione in dettagilio dei Fornitori
    QLabel *infoFor = new QLabel();
    infoFor->setText("Informazioni Fornitore");
    QLabel *sedeFor = new QLabel();
    sedeFor->setText("Sede Fornitore");
    QLabel *forRagSoc = new QLabel();
    QLabel *forName = new QLabel();
    QLabel *forSurname = new QLabel();
    QLabel *forTel = new QLabel();
    QLabel *forMail = new QLabel();
    QLabel *forPIva = new QLabel();
    QLabel *forFiscalC = new QLabel();
    QLabel *forAddress = new QLabel();
    QLabel *forCity = new QLabel();
    QLabel *forCap = new QLabel();
    QPushButton *aggiornaFor = new QPushButton();
    QLineEdit *txtForName = new QLineEdit();
    QLineEdit *txtForRSoc = new QLineEdit();
    QLineEdit *txtForSurname = new QLineEdit();
    QLineEdit *txtForTel = new QLineEdit();
    QLineEdit *txtForMail = new QLineEdit();
    QLineEdit *txtForPIva = new QLineEdit();
    QLineEdit *txtForFiscalC = new QLineEdit();
    QLineEdit *txtForAddress = new QLineEdit();
    QLineEdit *txtForCity = new QLineEdit();
    QLineEdit *txtForCap = new QLineEdit();
    QVBoxLayout *v_finalFor = new QVBoxLayout();
    QHBoxLayout *h_divideFor = new QHBoxLayout();
    QVBoxLayout *v_divideFor1 = new QVBoxLayout();
    QVBoxLayout *v_divideFor2 = new QVBoxLayout();
    QHBoxLayout *h_ForRSoc = new QHBoxLayout();
    QHBoxLayout *h_ForNameC= new QHBoxLayout();
    QHBoxLayout *h_ForSurnameC= new QHBoxLayout();
    QHBoxLayout *h_ForTelC= new QHBoxLayout();
    QHBoxLayout *h_ForMailC= new QHBoxLayout();
    QHBoxLayout *h_ForAddressC= new QHBoxLayout();
    QHBoxLayout *h_ForPIvaC= new QHBoxLayout();
    QHBoxLayout *h_ForCityC= new QHBoxLayout();
    QHBoxLayout *h_ForCapC= new QHBoxLayout();
    QHBoxLayout *h_ForCodeFC= new QHBoxLayout();

    forRagSoc->setText("Ragione sociale: ");
    forName->setText("Nome: ");
    forSurname->setText("Cognome: ");
    forTel->setText("Telefono: ");
    forMail->setText("Mail: ");
    forAddress->setText("Indirizzo: ");
    forPIva->setText("Partita iva: ");
    forFiscalC->setText("Codice fiscale: ");
    forCity->setText("Città: ");
    forCap->setText("Cap: ");
    aggiornaFor->setText("AGGIORNA");
    txtForRSoc->setText("___________");
    txtForName->setText("____________");
    txtForSurname->setText("____________");
    txtForTel->setText("____________");
    txtForMail->setText("____________");
    txtForAddress->setText("____________");
    txtForPIva->setText("____________");
    txtForFiscalC->setText("____________");
    txtForCity->setText("____________");
    txtForCap->setText("___________");

    h_ForRSoc->addWidget(forRagSoc);
    h_ForRSoc->addWidget(txtForRSoc);
    h_ForNameC->addWidget(forName);
    h_ForNameC->addWidget(txtForName);
    h_ForSurnameC->addWidget(forSurname);
    h_ForSurnameC->addWidget(txtForSurname);
    h_ForMailC->addWidget(forMail);
    h_ForMailC->addWidget(txtForMail);
    h_ForCodeFC->addWidget(forFiscalC);
    h_ForCodeFC->addWidget(txtForFiscalC);


    h_ForPIvaC->addWidget(forPIva);
    h_ForPIvaC->addWidget(txtForPIva);
    h_ForTelC->addWidget(forTel);
    h_ForTelC->addWidget(txtForTel);
    h_ForCityC->addWidget(forCity);
    h_ForCityC->addWidget(txtForCity);
    h_ForAddressC->addWidget(forAddress);
    h_ForAddressC->addWidget(txtForAddress);
    h_ForCapC->addWidget(forCap);
    h_ForCapC->addWidget(txtForCap);

    v_divideFor1->addWidget(infoFor);
    v_divideFor1->addLayout(h_ForRSoc);
    v_divideFor1->addLayout(h_ForNameC);
    v_divideFor1->addLayout(h_ForSurnameC);
    v_divideFor1->addLayout(h_ForCodeFC);
    v_divideFor1->addLayout(h_ForMailC);

    v_divideFor2->addWidget(sedeFor);
    v_divideFor2->addLayout(h_ForPIvaC);
    v_divideFor2->addLayout(h_ForTelC);
    v_divideFor2->addLayout(h_ForCityC);
    v_divideFor2->addLayout(h_ForAddressC);
    v_divideFor2->addLayout(h_ForCapC);

    h_divideFor->addLayout(v_divideFor1);
    h_divideFor->addLayout(v_divideFor2);

    v_finalFor->addLayout(h_divideFor);
    v_finalFor->addWidget(aggiornaFor);

    //layout di prodotti
    QWidget *prodotti = new QWidget();
    QPushButton *newProduct = new QPushButton();
    QLineEdit *txtProduct = new QLineEdit();
    QTabWidget *productList = new QTabWidget();
    QHBoxLayout *h_product = new QHBoxLayout();
    QVBoxLayout *v_product = new QVBoxLayout();
    QGroupBox *prod_grup = new QGroupBox(tr("Visualizza prodotti fuori commercio"));
    QVBoxLayout *v_group = new QVBoxLayout();
    QCheckBox *visualize= new QCheckBox();

    visualize->setText("Visualizza");
    visualize->setChecked(false);
    prod_grup->setFlat(true);
    v_group->addWidget(visualize);
    prod_grup->setLayout(v_group);
    newProduct->setText("NEW");
    h_product->addWidget(txtProduct);
    h_product->addWidget(newProduct);
    v_product->addLayout(h_product);
    v_product->addWidget(productList);
    v_product->addWidget(prod_grup);
    prodotti->setLayout(v_product);

    //layout dettaglio di prodotti
    QLabel *IDProd = new QLabel();
    QLabel *descProd = new QLabel();
    QLabel *pAcquisto = new QLabel();
    QLabel *pVendita = new QLabel();
    QLabel *giacenza = new QLabel();
    QLineEdit *txtIDProd = new QLineEdit();
    QListView *txtDescProd =new QListView();
    QLineEdit *txtPAcquisto = new QLineEdit();
    QLineEdit *txtPVendita = new QLineEdit();
    QLineEdit *txtGiacenza = new QLineEdit();
    QPushButton *aggiornaProd = new QPushButton();
    QPushButton *togliComm = new QPushButton();
    QPushButton *rimettiComm = new QPushButton();
    QLabel *infoProd =new QLabel();
    QHBoxLayout *h_IDProd = new QHBoxLayout();
    QHBoxLayout *h_descProd = new QHBoxLayout();
    QHBoxLayout *h_pAcquisto = new QHBoxLayout();
    QHBoxLayout *h_pVendita = new QHBoxLayout();
    QHBoxLayout *h_giacenza = new QHBoxLayout();
    QVBoxLayout *v_divideProd1 = new QVBoxLayout();
    QVBoxLayout *v_divideProd2 = new QVBoxLayout();
    QHBoxLayout *h_finalProd = new QHBoxLayout();

    aggiornaProd->setText("AGGIORNA");
    togliComm->setText("TOGLI DAL COMMRCIO");
    rimettiComm->setText("RIMETTI IN COMMERCIO");
    infoProd->setText("Informazioni: ");
    IDProd->setText("Codice: ");
    descProd->setText("Descrizione: ");
    pAcquisto->setText("Prezzo Acquisto: ");
    pVendita->setText("Prezzo vendita: ");
    giacenza->setText("Giacenza: ");

    txtIDProd->setText("___________");
    txtPAcquisto->setText("____________");
    txtPVendita->setText("____________");
    txtGiacenza->setText("____________");

    h_IDProd->addWidget(IDProd);
    h_IDProd->addWidget(txtIDProd);
    h_descProd->addWidget(descProd);
    h_descProd->addWidget(txtDescProd);
    h_pAcquisto->addWidget(pAcquisto);
    h_pAcquisto->addWidget(txtPAcquisto);
    h_pVendita->addWidget(pVendita);
    h_pVendita->addWidget(txtPVendita);
    h_giacenza->addWidget(giacenza);
    h_giacenza->addWidget(txtGiacenza);

    v_divideProd1->addWidget(infoProd);
    v_divideProd1->addLayout(h_IDProd);
    v_divideProd1->addLayout(h_descProd);
    v_divideProd1->addLayout(h_pAcquisto);
    v_divideProd1->addLayout(h_pVendita);
    v_divideProd1->addLayout(h_giacenza);

    v_divideProd2->addWidget(aggiornaProd);
    v_divideProd2->addWidget(togliComm);
    v_divideProd2->addWidget(rimettiComm);

    h_finalProd->addLayout(v_divideProd1);
    h_finalProd->addLayout(v_divideProd2);



    //layout di fatture
    QLineEdit *searchInvoices = new QLineEdit();
    QPushButton *newButton = new QPushButton();
    QGroupBox *newInvoices = new QGroupBox(tr("Aggiungi fattura"));
    QVBoxLayout *v_lay = new QVBoxLayout();
    QHBoxLayout *h_lay = new QHBoxLayout();
    QRadioButton *radioClient = new QRadioButton(tr("per un cliente"));
    radioClient->setChecked(false);
    QRadioButton *radioSupplier = new QRadioButton(tr("da un fornitore"));
    radioSupplier->setChecked(false);
    QTabWidget *invoicesList = new QTabWidget();
    QGroupBox *invoicesVisualize = new QGroupBox(tr("Visualizza Fatture:"));
    QCheckBox *checkClient = new QCheckBox(tr("Da clienti"));
    checkClient->setChecked(true);
    QCheckBox *checkSuppliers = new QCheckBox(tr("Da fornitori"));
    checkSuppliers->setChecked(true);
    QHBoxLayout *searchNew = new QHBoxLayout();
    QHBoxLayout *h_invoices = new QHBoxLayout();
    QHBoxLayout *clientSupplier = new QHBoxLayout();
    QVBoxLayout * v_invoices = new QVBoxLayout();    
    QWidget *fatture = new QWidget();

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
    v_invoices->addWidget(invoicesList);
    v_invoices->addWidget(invoicesVisualize);

    fatture->setLayout(v_invoices);

    //layout dettaglaito di fatture
    //LE FATTURE NON SI POSSONO ELIMINARE!!!
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

    QLineEdit *txtfattRSocFor = new QLineEdit();
    QLineEdit *txtfattIndFor = new QLineEdit();
    QLineEdit *txtFattTelFor = new QLineEdit();
    QLineEdit *txtfattMailFor = new QLineEdit();
    QLineEdit *txtfattPIvaFor = new QLineEdit();
    txtfattRSocFor->setText("____________");
    txtfattIndFor->setText("____________");
    txtFattTelFor->setText("____________");
    txtfattMailFor->setText("____________");
    txtfattPIvaFor->setText("____________");

    QLabel *fattRSocCli = new QLabel();
    QLabel *fattIndCli = new QLabel();
    QLabel *fattCapCli = new QLabel();
    QLabel *fattCityCli = new QLabel();
    QLabel *fattPIvaCli = new QLabel();
    QLabel *fattCFiscCli = new QLabel();
    QTabWidget *fatt = new QTabWidget();
    fattRSocCli->setText("Ragione sociale: ");
    fattIndCli->setText("Indirizzo: ");
    fattCapCli->setText("CAP: ");
    fattCityCli->setText("Città: ");
    fattPIvaCli->setText("Partita Iva: ");
    fattCFiscCli->setText("Codice Fiscale: ");


    QLineEdit *txtfattRSocCli = new QLineEdit();
    QLineEdit *txtfattIndCli = new QLineEdit();
    QLineEdit *txtFattCapCli = new QLineEdit();
    QLineEdit *txtfattCityCli = new QLineEdit();
    QLineEdit *txtfattPIvaCli = new QLineEdit();
    QLineEdit *txtfattCFiscCli = new QLineEdit();
    txtfattRSocCli->setText("____________");
    txtfattIndCli->setText("____________");
    txtFattCapCli->setText("____________");
    txtfattCityCli->setText("____________");
    txtfattPIvaCli->setText("____________");
    txtfattCFiscCli->setText("____________");

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

    v_finalFatt->addLayout(h_fattForCli);
    v_finalFatt->addWidget(fatt);




    //agiungiamo alla schermata centrale tutti i nostri tab e visualizziamo
    QTabWidget *tw = new QTabWidget();
    tw->addTab(home, "Home");
    tw->addTab(fornitori, "Fornitori");
    tw->addTab(clienti, "Clienti");
    tw->addTab(prodotti, "Prodotti");
    tw->addTab(fatture, "Fatture");
    this->setCentralWidget(tw);


    //ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
