#include "fornitoriwidget.h"

FornitoriWidget::FornitoriWidget(QWidget *parent) : QWidget(parent)
{
    newFornit = new QPushButton();
    txtfornit = new QLineEdit();
    fornitlist = new QTableWidget();
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
}
