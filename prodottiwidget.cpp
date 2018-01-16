#include "prodottiwidget.h"

ProdottiWidget::ProdottiWidget(QWidget *parent) : QWidget(parent)
{
    newProduct = new QPushButton();
    txtProduct = new QLineEdit();
    txtProduct->setPlaceholderText("Cerca Prodotto");
    txtProduct->setText("");
    productList = new QTableView();
    QHBoxLayout *h_product = new QHBoxLayout();
    QVBoxLayout *v_product = new QVBoxLayout();
    QGroupBox *prod_grup = new QGroupBox(tr("Visualizza prodotti fuori commercio"));
    QVBoxLayout *v_group = new QVBoxLayout();
    visualize= new QCheckBox();

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

    //layout dettaglio di prodotti
    QLabel *IDProd = new QLabel();  //primary key
    QLabel *descProd = new QLabel();
    QLabel *pAcquisto = new QLabel();
    QLabel *pVendita = new QLabel();
    QLabel *giacenza = new QLabel();
    txtIDProd = new QLineEdit();
    txtDescProd =new QLineEdit();
    txtPAcquisto = new QLineEdit();
    txtPVendita = new QLineEdit();
    txtGiacenza = new QLineEdit();
    aggiornaProd = new QPushButton();
    togliComm = new QPushButton();
    rimettiComm = new QPushButton();
    QLabel *infoProd =new QLabel();
    QHBoxLayout *h_IDProd = new QHBoxLayout();
    QHBoxLayout *h_descProd = new QHBoxLayout();
    QHBoxLayout *h_pAcquisto = new QHBoxLayout();
    QHBoxLayout *h_pVendita = new QHBoxLayout();
    QHBoxLayout *h_giacenza = new QHBoxLayout();
    QVBoxLayout *v_divideProd1 = new QVBoxLayout();
    QVBoxLayout *v_divideProd2 = new QVBoxLayout();
    QHBoxLayout *h_finalProd = new QHBoxLayout();

    aggiornaProd->setText("AGGIORNA");
    togliComm->setText("TOGLI DAL COMMRCIO");
    rimettiComm->setText("IMMETTI IN COMMERCIO");
    infoProd->setText("Informazioni: ");
    IDProd->setText("Codice: ");
    descProd->setText("Descrizione: ");
    pAcquisto->setText("Prezzo Acquisto: ");
    pVendita->setText("Prezzo vendita: ");
    giacenza->setText("Giacenza: ");

    h_IDProd->addWidget(IDProd);
    h_IDProd->addWidget(txtIDProd);
    h_descProd->addWidget(descProd);
    h_descProd->addWidget(txtDescProd);
    h_pAcquisto->addWidget(pAcquisto);
    h_pAcquisto->addWidget(txtPAcquisto);
    h_pVendita->addWidget(pVendita);
    h_pVendita->addWidget(txtPVendita);
    h_giacenza->addWidget(giacenza);
    h_giacenza->addWidget(txtGiacenza);

    v_divideProd1->addWidget(infoProd);
    v_divideProd1->addLayout(h_IDProd);
    v_divideProd1->addLayout(h_descProd);
    v_divideProd1->addLayout(h_pAcquisto);
    v_divideProd1->addLayout(h_pVendita);
    v_divideProd1->addLayout(h_giacenza);

    v_divideProd2->addWidget(aggiornaProd);
    v_divideProd2->addWidget(togliComm);
    v_divideProd2->addWidget(rimettiComm);

    h_finalProd->addLayout(v_divideProd1);
    h_finalProd->addLayout(v_divideProd2);

    back = new QPushButton();
    back->setText("<- Indietro");
    back->setFixedSize(QSize(100,30));

    QVBoxLayout *last_v = new QVBoxLayout();
    last_v->addWidget(back);
    last_v->addLayout(h_finalProd);

    //Maschro i Layouts da Widget per usare il metodo addWidget()
    QWidget* p0 = new QWidget(); // primo stack con la vista standard
    p0->setLayout(v_product);

    QWidget* p1 = new QWidget(); // secondo stack con la vista dettaglio del cliente
    p1->setLayout(last_v);

    stack = new QStackedLayout();
    stack->addWidget(p0);
    stack->addWidget(p1);

    stack->setCurrentIndex(0);

    this->setLayout(stack);

    txtIDProd->setEnabled(false);

    //setup model
    db = new ProdottiDatabaseManager(this);
    model = db->getModel(visualize->isChecked(), txtProduct->text());
    productList->setModel(model);

    productList->setSelectionBehavior(QAbstractItemView::SelectRows);
    productList->setSelectionMode(QAbstractItemView::SingleSelection);

    QObject::connect(productList, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(productSelected(QModelIndex)));
    QObject::connect(newProduct, SIGNAL(clicked(bool)), this, SLOT(newProductClicked()));
    QObject::connect(aggiornaProd, SIGNAL(clicked(bool)), this, SLOT(updateProduct()));
    QObject::connect(txtProduct, SIGNAL(textEdited(QString)), this, SLOT(searchChanged(QString)));
    QObject::connect(back, SIGNAL(clicked(bool)), this, SLOT(goToMainView()));
    QObject::connect(togliComm, SIGNAL(clicked(bool)), this, SLOT(rimuoviCommercio()));
    QObject::connect(rimettiComm, SIGNAL(clicked(bool)), this, SLOT(immettiCommercio()));
    QObject::connect(visualize, SIGNAL(stateChanged(int)), this, SLOT(updateModel()));

    newORdetail = false;


}

void ProdottiWidget::updateModel(){
    //model->query().exec(); // aggiorna la vista
    delete model;
    model = db->getModel(visualize->isChecked(), txtProduct->text());
    productList->setModel(model);
}

void ProdottiWidget::updateProduct(){
    QHash<QString, QString>* data = new QHash<QString, QString>();

    data->insert("description", txtDescProd->text());
    data->insert("purchasePrice", txtPAcquisto->text());
    data->insert("sellingPrice", txtPVendita->text());
    data->insert("stock", txtGiacenza->text());

    //controlla che i campi siano tutti riempiti (quelli not null obbligatori)
    bool res;
    if(newORdetail){
        res = db->insertElement(txtIDProd->text(), data);
    } else {
        res = db->updateElement(txtIDProd->text(), data);
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

void ProdottiWidget::searchChanged(QString src){
    delete model;
    model = db->getModel(visualize->isChecked(), src);
    productList->setModel(model);
}

void ProdottiWidget::rimuoviCommercio()
{
    QString id = txtIDProd->text();

    db->setProduction(id, 0);

    QMessageBox msgBox;
    msgBox.setText("Prodotto rimosso dal commercio");
    msgBox.exec();
}

void ProdottiWidget::immettiCommercio()
{
    QString id = txtIDProd->text();

    db->setProduction(id, 1);

    QMessageBox msgBox;
    msgBox.setText("Prodotto immesso nel commercio");
    msgBox.exec();
}

void ProdottiWidget::goToMainView(){
    updateModel();
    this->stack->setCurrentIndex(0);
}

void ProdottiWidget::productSelected(QModelIndex idx){
    newORdetail = false;
    aggiornaProd->setText("AGGIORNA");
    txtIDProd->setEnabled(false);
    rimettiComm->show();
    togliComm->show();

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
    txtIDProd->setText(id);
    txtDescProd->setText(data->value("description"));
    txtPAcquisto->setText(data->value("purchasePrice"));
    txtPVendita->setText(data->value("sellingPrice"));
    txtGiacenza->setText(data->value("stock"));

    this->stack->setCurrentIndex(1);
    delete data;

}

void ProdottiWidget::newProductClicked(){
    newORdetail = true;
    aggiornaProd->setText("Inserisci");
    txtIDProd->setEnabled(true);
    rimettiComm->hide();
    togliComm->hide();

    txtIDProd->setText("");
    txtDescProd->setText("");
    txtPAcquisto->setText("");
    txtPVendita->setText("");
    txtGiacenza->setText("");

    this->stack->setCurrentIndex(1);
}

ProdottiWidget::~ProdottiWidget(){
    delete stack;
    delete newProduct;
    delete productList;
    delete visualize;
    delete txtProduct;
    delete txtIDProd;
    delete txtDescProd;
    delete txtPAcquisto;
    delete txtPVendita;
    delete txtGiacenza;
    delete aggiornaProd;
    delete togliComm;
    delete rimettiComm;
    delete back;
}
