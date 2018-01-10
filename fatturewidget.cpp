#include "fatturewidget.h"

FattureWidget::FattureWidget(QWidget *parent) : QWidget(parent)
{
    searchInvoices = new QLineEdit();
    searchInvoices->setPlaceholderText("Cerca Fattura");
    newButton = new QPushButton();
    QGroupBox *newInvoices = new QGroupBox(tr("Aggiungi fattura"));
    QVBoxLayout *v_lay = new QVBoxLayout();
    QHBoxLayout *h_lay = new QHBoxLayout();
    radioClient = new QRadioButton(tr("per un cliente"));
    radioClient->setChecked(true);
    radioSupplier = new QRadioButton(tr("da un fornitore"));
    radioSupplier->setChecked(false);
    invoicesList = new QListView();
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
    v_invoices->addWidget(invoicesList);
    v_invoices->addWidget(invoicesVisualize);

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
    fatt = new QTableWidget();
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

    QVBoxLayout *fattLay = new QVBoxLayout();
    fattLay->addLayout(h_fatt1);
    fattLay->addWidget(fatt);
    fattLay->addLayout(h_fatt2);

    boxFatt->setLayout(fattLay);

    v_finalFatt->addLayout(h_fattForCli);
    v_finalFatt->addWidget(boxFatt);

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
}

FattureWidget::~FattureWidget(){
    delete searchInvoices;
    delete newButton;
    delete radioClient;
    delete radioSupplier;
    delete invoicesList;
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
    delete fatt;

    delete stack;
}
