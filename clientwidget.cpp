#include "clientwidget.h"

ClientWidget::ClientWidget(QWidget *parent) : QWidget(parent)
{
    /*
     * in questa classe creiamo la window principale dei clienti, dove io mi trovo una line edit cerca
     * dove inserendo dei caratteri, con il connect posso cercarli dentro il mio database (guarda query
     * nel metodo getModel nella classe ClientiDatabaseManager) e visualizzarli nella client tab subito sotto.
     * se non cerco niente, nella tabella ho tutti i miei elementi, dal primo all'ultimo.
     * in alto a destra di fianco alla line edit cerca ho il bottone new, cliccando li sopra posso
     * aggiungere al database un cliente che verra visualizzato nella tableView appena inserito.
     * Cliccando sul tasto new si apre una finestra sopra quella attuale di clienti (reso possibile attraverso
     * il comadno stack e inserendo iol comando setcuirrentindex al widget del mio new) dove io posso aggiungere
     * un cliente (tutto specificato nella funzione NewClientClicked).
     * sotto invece nella table view invece ho l'elenco di tutti i miei clienti della line edit ricerca
     * e doppiocliccando su un elemento si aggiunge una finestra di dettaglio sopra quella dei clienti (comando stack->setcurrentindex)
     * dove viene visualizzato ogni elemento del cliente cliccato. c'è anche la possibilità di modifica. in pratica
     * la finestra di dettaglio è la stessa che usiamo per un nuovo cliente, solo che nella new il bottone
     * per salvare si chiama AGGIUNGI e le line edit sono vuote, invece nell'update il bottone si chiama
     * AGGIORNA e nelle line edit ci sono i campi riempiti e per aggiornarli basta scriverci sopra e cliccare sul bottone.
     * In più se ci sono dei campi che non si possono modificare nel codice inseriamo il comando setenable false.
     *
     */
    newClient = new QPushButton();
    txtCerca = new QLineEdit();
    txtCerca->setPlaceholderText("Cerca Cliente");
    txtCerca->setText("");
    clientTab = new QTableView();
    QHBoxLayout *h_client = new QHBoxLayout();
    QVBoxLayout *v_client = new QVBoxLayout();

    newClient->setText("NEW");
    h_client->addWidget(txtCerca);
    h_client->addWidget(newClient);
    v_client->addLayout(h_client);
    v_client->addWidget(clientTab);

    /*
     * da qua in poi inseriamo il layout della finestra di dettaglio che si aprirà
     * con il comando stack->setcurrentIndex al doppioclick di un elemento di un determinato
     * cliente. in questa finestra è possibile modificare un cliente riempioendo le line
     * edit con queello che si vuole cambiare e cliccare su aggiorna
     */

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
    QLabel *clientFiscalC = new QLabel(); //primary key
    QLabel *clientAddress = new QLabel();
    QLabel *clientCity = new QLabel();
    QLabel *clientCap = new QLabel();
    aggiorna_add = new QPushButton();
    back = new QPushButton();
    txtclientName = new QLineEdit();
    txtragSoc = new QLineEdit();
    txtclientSurname = new QLineEdit();
    txtclientTel = new QLineEdit();
    txtclientMail = new QLineEdit();
    txtclientPIva = new QLineEdit();
    txtclientFiscalC = new QLineEdit();
    txtclientAddress = new QLineEdit();
    txtclientCity = new QLineEdit();
    txtclientCap = new QLineEdit();
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
    aggiorna_add->setText("AGGIORNA");
    back->setText("<- Indietro");
    back->setFixedSize(QSize(100,30));

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

    v_finalClient->addWidget(back);
    v_finalClient->addLayout(h_divide);
    v_finalClient->addWidget(aggiorna_add);

    //--------------------------------

    //Maschero i Layouts da Widget per usare il metodo addWidget()
    QWidget* c0 = new QWidget(); // primo stack con la vista standard
    c0->setLayout(v_client);

    QWidget* c1 = new QWidget(); // secondo stack con la vista dettaglio del cliente
    c1->setLayout(v_finalClient);

    stack = new QStackedLayout();
    stack->addWidget(c0);
    stack->addWidget(c1);

    stack->setCurrentIndex(0);

    this->setLayout(stack);

    //---------------------------------------

    txtclientFiscalC->setEnabled(false);

    //Setup model
    db = new ClientDatabaseManager(this);
    model = db->getModel(txtCerca->text());
    clientTab->setModel(model);

    clientTab->setSelectionBehavior(QAbstractItemView::SelectRows);
    clientTab->setSelectionMode(QAbstractItemView::SingleSelection);
    /*
     * di seguito vengono definiti i connect, cioè ad un dato segnale corrisponde
     * una risposta o invocazione di un metodo*/
    /*
     * 1° connect se si doppioclicca un cliente nella tabella dei clienti viene
     * chiamato il metodo clientSelected che aprirà attraverso lo stack la finestra di
     * dettaglio su quel cliente.
     */

    QObject::connect(clientTab, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(clientSelected(QModelIndex)));
    /*
     * 2°connect: se io clicco su il bottone newclient in questa finestra di fianco alla search line edit
     * mi chiama la funzione newClientClicked dove io posso inserire un nuovo cliente. nel caso io mi sia sbagliata
     * a cliccare su new è possibile tornare insietro senza modificare niente.
     */
    QObject::connect(newClient, SIGNAL(clicked(bool)), this, SLOT(newClientClicked()));
    /*
     *3° connect: se siamo nell finestra di dettaglio e vogliamo aggiornare un cliente
     * basta riscrivere sopra il campo che voglio cambiare il nuovo valore e cliccare
     * su aggiorna. quando clicco l'evento connect chiama la funzione updateClient
     * dove va ad aggiornare il database attraverso la query fornita dalla funzione
     */
    QObject::connect(aggiorna_add, SIGNAL(clicked(bool)), this, SLOT(updateClient()));
    /*
     *4°connect: se cerchiamo un cliente nella line edit cerca, ad ogni carattere che inseriamo
     * viene chiamato il metodo serachChanged dove si fa una query al database che cerca parole
     * simili ai caratteri inseriti tra tutti gli alementi qstring dei clienti(tutti in questpo caso)
     */
    QObject::connect(txtCerca, SIGNAL(textEdited(QString)), this, SLOT(searchChanged(QString)));
    /*
     *5° connect: se clicco il pulsante back ("->") chiama la funzione goToMainView e torna
     * attraverso il comando stack_>setCurrentIndex alla finestra principale
     */
    QObject::connect(back, SIGNAL(clicked(bool)), this, SLOT(goToMainView()));

    newORdetail = false;
}


/*
 * deallochiamo il model vecchio e ne facciamo uno nuovo creando un nuovo database
 */
void ClientWidget::updateModel(){
    //model->query().exec(); // aggiorna la vista
    delete model;
    model = db->getModel(txtCerca->text());
    clientTab->setModel(model);
}

/*
 * creiamo un dizionario di nome data vuoto e inseriamo le stringhe dentro le edit line
 */
void ClientWidget::updateClient(){
    QHash<QString, QString>* data = new QHash<QString, QString>();

    data->insert("name", txtclientName->text());
    data->insert("surname", txtclientSurname->text());
    data->insert("ragioneSoc", txtragSoc->text());
    data->insert("tel", txtclientTel->text());
    data->insert("mail", txtclientMail->text());
    data->insert("piva", txtclientPIva->text());
    data->insert("address", txtclientAddress->text());
    data->insert("city", txtclientCity->text());
    data->insert("cap", txtclientCap->text());

    //controlla che i campi siano tutti riempiti (quelli not null obbligatori)
    bool res;
    if(newORdetail){
        res = db->insertElement(txtclientFiscalC->text(), data);
    } else {
        res = db->updateElement(txtclientFiscalC->text(), data);
    }

    this->stack->setCurrentIndex(0);
    delete data;
    updateModel();

    if(!res){
        QMessageBox msgBox;
        msgBox.setText("C'è stato un errore nell'inserimento dei dati");
        msgBox.exec();
    }
}


/*
 * dealloco anche qui il model e poi lo rialloco con il database
 */
void ClientWidget::searchChanged(QString src)
{
    delete model;
    model = db->getModel(src);
    clientTab->setModel(model);
}

/*
 * chiamo la funzione update model che dealloca e rialloca tutto il database
 *e poi ritorno alla finestra principale
 */
void ClientWidget::goToMainView(){
    updateModel();
    this->stack->setCurrentIndex(0);
}

/*
 * newORdetail se è vero sono nella modalità nuovo cliente e quindi cambiano i bottoni
 * e le line edit
 */
void ClientWidget::clientSelected(QModelIndex idx){
    newORdetail = false;
    aggiorna_add->setText("AGGIORNA");
    txtclientFiscalC->setEnabled(false);

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
    //riempi i campi
    txtclientName->setText(data->value("name"));
    txtragSoc->setText(data->value("ragioneSoc"));
    txtclientSurname->setText(data->value("surname"));
    txtclientTel->setText(data->value("tel"));
    txtclientMail->setText(data->value("mail"));
    txtclientPIva->setText(data->value("piva"));
    txtclientFiscalC->setText(id);
    txtclientAddress->setText(data->value("address"));
    txtclientCity->setText(data->value("city"));
    txtclientCap->setText(data->value("cap"));

    this->stack->setCurrentIndex(1);
    delete data;
}

void ClientWidget::newClientClicked()
{
    newORdetail = true;
    aggiorna_add->setText("Inserisci");
    txtclientFiscalC->setEnabled(true);

    txtclientName->setText("");
    txtragSoc->setText("");
    txtclientSurname->setText("");
    txtclientTel->setText("");
    txtclientMail->setText("");
    txtclientPIva->setText("");
    txtclientFiscalC->setText("");
    txtclientAddress->setText("");
    txtclientCity->setText("");
    txtclientCap->setText("");

    this->stack->setCurrentIndex(1);
}

ClientWidget::~ClientWidget(){
    delete newClient;
    delete txtCerca;
    delete clientTab;
    delete newClient;
    delete aggiorna_add;
    delete txtclientName;
    delete txtclientSurname;
    delete txtclientAddress;
    delete txtclientCap;
    delete txtclientCity;
    delete txtclientFiscalC;
    delete txtclientMail;
    delete txtclientPIva;
    delete txtclientTel;
    delete txtragSoc;

    delete model;
    delete back;
}
