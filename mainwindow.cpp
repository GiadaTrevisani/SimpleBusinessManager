#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //creiamo le tab home, fornitori, clienti, prodotti e fatture
    //home
    HomeWidget *home = new HomeWidget(this);

    //clienti
    ClientWidget *clienti = new ClientWidget(this);

    //fornitori
    FornitoriWidget *fornitori = new FornitoriWidget(this);

    //layout di prodotti
    ProdottiWidget *prodotti = new ProdottiWidget(this);

    //layout di fatture
    FattureWidget *fatture = new FattureWidget(this);

    //agiungiamo alla schermata centrale tutti i nostri tab e visualizziamo
    QTabWidget *tw = new QTabWidget(this);
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
    //delete ui;
}
