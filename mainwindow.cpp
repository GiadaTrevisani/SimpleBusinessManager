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
    QListWidget *clientlist = new QListWidget();
    QHBoxLayout *h_client = new QHBoxLayout();
    QVBoxLayout *v_client = new QVBoxLayout();

    newClient->setText("NEW");
    h_client->addWidget(txtCerca);
    h_client->addWidget(newClient);
    v_client->addLayout(h_client);
    v_client->addWidget(clientlist);
    clienti->setLayout(v_client);

    //layout di fornitori
    QWidget *fornitori = new QWidget();
    QPushButton *newFornit = new QPushButton();
    QLineEdit *txtfornit = new QLineEdit();
    QListWidget *fornitlist = new QListWidget();
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
    QListWidget *productList = new QListWidget();
    QHBoxLayout *h_product = new QHBoxLayout();
    QVBoxLayout *v_product = new QVBoxLayout();

    newProduct->setText("NEW");
    h_product->addWidget(txtProduct);
    h_product->addWidget(newProduct);
    v_product->addLayout(h_product);
    v_product->addWidget(productList);
    prodotti->setLayout(v_product);


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
