#include "clientwidget.h"

ClientWidget::ClientWidget(QWidget *parent) : QWidget(parent)
{
    newClient = new QPushButton();
    txtCerca = new QLineEdit();
    txtCerca->setPlaceholderText("Cerca Cliente");
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
    aggiorna = new QPushButton();
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
    aggiorna->setText("AGGIORNA");

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

    //Maschro i Layouts da Widget per usare il metodo addWidget()
    QWidget* c0 = new QWidget(); // primo stack con la vista standard
    c0->setLayout(v_client);

    QWidget* c1 = new QWidget(); // secondo stack con la vista dettaglio del cliente
    c1->setLayout(v_finalClient);

    stack = new QStackedLayout();
    stack->addWidget(c0);
    stack->addWidget(c1);

    stack->setCurrentIndex(0);

    this->setLayout(stack);
}

ClientWidget::~ClientWidget(){
    delete newClient;
    delete txtCerca;
    delete clientTab;
    delete newClient;
    delete aggiorna;
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


}
