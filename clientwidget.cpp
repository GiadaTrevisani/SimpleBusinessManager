#include "clientwidget.h"

ClientWidget::ClientWidget(QWidget *parent) : QWidget(parent)
{
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

    QObject::connect(clientTab, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(clientSelected(QModelIndex)));
    QObject::connect(newClient, SIGNAL(clicked(bool)), this, SLOT(newClientClicked()));
    QObject::connect(aggiorna_add, SIGNAL(clicked(bool)), this, SLOT(updateClient()));
    QObject::connect(txtCerca, SIGNAL(textEdited(QString)), this, SLOT(searchChanged(QString)));
    QObject::connect(back, SIGNAL(clicked(bool)), this, SLOT(goToMainView()));

    newORdetail = false;
}

void ClientWidget::updateModel(){
    //model->query().exec(); // aggiorna la vista
    delete model;
    model = db->getModel(txtCerca->text());
    clientTab->setModel(model);
}

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

void ClientWidget::searchChanged(QString src)
{
    delete model;
    model = db->getModel(src);
    clientTab->setModel(model);
}

void ClientWidget::goToMainView(){
    updateModel();
    this->stack->setCurrentIndex(0);
}

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
