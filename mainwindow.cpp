#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //creiamo le tab home, fornitori, clienti, prodotti e fatture
    //home
    HomeWidget *home = new HomeWidget();

    //clienti
    ClientWidget *clienti = new ClientWidget();

    //fornitori
    FornitoriWidget *fornitori = new FornitoriWidget();

    //layout di prodotti
    ProdottiWidget *prodotti = new ProdottiWidget();

    //layout di fatture
    FattureWidget *fatture = new FattureWidget();

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
