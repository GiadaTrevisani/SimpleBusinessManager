#include "prodottiwidget.h"

ProdottiWidget::ProdottiWidget(QWidget *parent) : QWidget(parent)
{
    newProduct = new QPushButton();
    txtProduct = new QLineEdit();
    productList = new QTableWidget();
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
    txtDescProd =new QListView();
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
    rimettiComm->setText("RIMETTI IN COMMERCIO");
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

    //Maschro i Layouts da Widget per usare il metodo addWidget()
    QWidget* p0 = new QWidget(); // primo stack con la vista standard
    p0->setLayout(v_product);

    QWidget* p1 = new QWidget(); // secondo stack con la vista dettaglio del cliente
    p1->setLayout(h_finalProd);

    stack = new QStackedLayout();
    stack->addWidget(p0);
    stack->addWidget(p1);

    stack->setCurrentIndex(0);

    this->setLayout(stack);
}
