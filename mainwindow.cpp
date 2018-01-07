#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //creiamo le tab home, fornitori, clienti, prodotti e fatture
    QWidget *home = new QWidget();
    QWidget *fatture = new QWidget();

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
