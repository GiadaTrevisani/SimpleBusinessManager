#include "fornitoriwidget.h"

/*
 * il layout dei fornitori è lo stesso dei clienti e dei prodotti, e anche
 * i bottoni connessi e la line edit connesse a funzioni che faranno
 * query al database sono le stesse ma eseguite per i fornitori.
 * uguale il bottone new e il doppio click su un elemento della tabella
 * che apre la lista di dettaglio dei fornitori e si può aggiornare la tabella.
 * tuttavia al contrario dei clienti, nei fornitori i campi partita iva e
 * ragione sociale sono obbligatori perchè se un fornitore mi fa una fattura
 * deve per forza vendere dei prodotti e quindi anche avere una ragione sociale
 */
FornitoriWidget::FornitoriWidget(QWidget *parent) : QWidget(parent)
{
    newFornit = new QPushButton();
    txtfornit = new QLineEdit();
    txtfornit->setPlaceholderText("Cerca Fornitore");
    txtfornit->setText("");
    fornitlist = new QTableView();
    QHBoxLayout *h_fornit = new QHBoxLayout();
    QVBoxLayout *v_fornit = new QVBoxLayout();

    newFornit->setText("NEW");
    h_fornit->addWidget(txtfornit);
    h_fornit->addWidget(newFornit);
    v_fornit->addLayout(h_fornit);
    v_fornit->addWidget(fornitlist);

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
    QLabel *forPIva = new QLabel();     //primary key
    QLabel *forFiscalC = new QLabel();  //primary key
    QLabel *forAddress = new QLabel();
    QLabel *forCity = new QLabel();
    QLabel *forCap = new QLabel();
    aggiornaFor = new QPushButton();
    txtForName = new QLineEdit();
    txtForRSoc = new QLineEdit();
    txtForSurname = new QLineEdit();
    txtForTel = new QLineEdit();
    txtForMail = new QLineEdit();
    txtForPIva = new QLineEdit();
    txtForFiscalC = new QLineEdit();
    txtForAddress = new QLineEdit();
    txtForCity = new QLineEdit();
    txtForCap = new QLineEdit();
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

    back = new QPushButton();
    back->setText("<- Indietro");
    back->setFixedSize(QSize(100,30));
    v_finalFor->addWidget(back);

    v_finalFor->addLayout(h_divideFor);
    v_finalFor->addWidget(aggiornaFor);

    //Maschro i Layouts da Widget per usare il metodo addWidget()
    QWidget* f0 = new QWidget(); // primo stack con la vista standard
    f0->setLayout(v_fornit);

    QWidget* f1 = new QWidget(); // secondo stack con la vista dettaglio del cliente
    f1->setLayout(v_finalFor);

    stack = new QStackedLayout();
    stack->addWidget(f0);
    stack->addWidget(f1);

    stack->setCurrentIndex(0);

    this->setLayout(stack);

    //-------------------------------------------------------
    txtForFiscalC->setEnabled(false);

    //setup model

    db = new FornitoriDatabaseManager(this);
    model = db->getModel(txtfornit->text());
    fornitlist->setModel(model);

    fornitlist->setSelectionBehavior(QAbstractItemView::SelectRows);
    fornitlist->setSelectionMode(QAbstractItemView::SingleSelection);

    QObject::connect(fornitlist, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(supplierSelected(QModelIndex)));
    QObject::connect(newFornit, SIGNAL(clicked(bool)), this, SLOT(newSupplierClicked()));
    QObject::connect(aggiornaFor, SIGNAL(clicked(bool)), this, SLOT(updateSupplier()));
    QObject::connect(txtfornit, SIGNAL(textEdited(QString)), this, SLOT(searchChanged(QString)));
    QObject::connect(back, SIGNAL(clicked(bool)), this, SLOT(goToMainView()));

    newOrdetail = false;
}

void FornitoriWidget::updateModel(){
    delete model;
    model = db->getModel(txtfornit->text());
    fornitlist->setModel(model);
}

void FornitoriWidget::updateSupplier(){
    QHash<QString, QString>* data= new QHash<QString, QString>();

    data->insert("name", txtForName->text());
    data->insert("surname", txtForSurname->text());
    data->insert("ragioneSoc", txtForRSoc->text());
    data->insert("tel", txtForTel->text());
    data->insert("mail", txtForMail->text());
    data->insert("piva", txtForPIva->text());
    data->insert("address", txtForAddress->text());
    data->insert("city", txtForCity->text());
    data->insert("cap", txtForCap->text());

    //controlla che i campi siamo tutti riempiti (quelli not null obbligatori)
    bool res;

    if(newOrdetail){
        res = db->insertElement(txtForFiscalC->text(), data);
    } else {
        res = db->updateElement(txtForFiscalC->text(), data);
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

void FornitoriWidget::searchChanged(QString src){
    delete model;
    model = db->getModel(src);
    fornitlist->setModel(model);
}

void FornitoriWidget::goToMainView(){
    updateModel();
    this->stack->setCurrentIndex(0);
}

void FornitoriWidget::supplierSelected(QModelIndex idx){
    newOrdetail = false;
    aggiornaFor->setText("AGGIORNA");
    txtForFiscalC->setEnabled(false);

    //prendiamo il codice dalla tabella
    QString id = model->itemData(model->index(idx.row(), 0)).value(0).toString();
    QHash<QString, QString>* data = db->getElement(id);

    if(data->value("error") == "true"){
        QMessageBox msgBox;
        msgBox.setText("C'è stato un errore, elemento non esistente");
        msgBox.exec();

        delete data;
        return;
    }

    //riempio i campi
    txtForName->setText(data->value("name"));
    txtForRSoc->setText(data->value("ragioneSoc"));
    txtForSurname->setText(data->value("surname"));
    txtForTel->setText(data->value("tel"));
    txtForMail->setText(data->value("mail"));
    txtForPIva->setText(data->value("piva"));
    txtForFiscalC->setText(id);
    txtForAddress->setText(data->value("address"));
    txtForCity->setText(data->value("city"));
    txtForCap->setText(data->value("cap"));

    this->stack->setCurrentIndex(1);
    delete data;
}
void FornitoriWidget::newSupplierClicked(){
    newOrdetail = true;
    aggiornaFor->setText("INSERISCI");
    txtForFiscalC->setEnabled(true);

    txtForName->setText("");
    txtForRSoc->setText("");
    txtForSurname->setText("");
    txtForTel->setText("");
    txtForMail->setText("");
    txtForPIva->setText("");
    txtForFiscalC->setText("");
    txtForAddress->setText("");
    txtForCap->setText("");
    txtForCity->setText("");

    this->stack->setCurrentIndex(1);
}
FornitoriWidget::~FornitoriWidget(){
    delete newFornit;
    delete txtfornit;
    delete fornitlist;
    delete aggiornaFor;
    delete txtForName;
    delete txtForSurname;
    delete txtForAddress;
    delete txtForCap;
    delete txtForCity;
    delete txtForFiscalC;
    delete txtForMail;
    delete txtForPIva;
    delete txtForRSoc;
    delete txtForTel;
    delete stack;
    delete back;
}
