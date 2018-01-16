#include "scegliprodottodialog.h"
#include "ui_scegliprodottodialog.h"

ScegliProdottoDialog::ScegliProdottoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScegliProdottoDialog)
{
    ui->setupUi(this);
    ui->quantity->setMinimum(1);
    db = new ProdottiDatabaseManager(this);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    model = db->getModelGiac();
    ui->tableView->setModel(model);

    QObject::connect(ui->tableView, SIGNAL(clicked(QModelIndex)), this, SLOT(elementClicked(QModelIndex)));
    QObject::connect(ui->tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(elementClicked(QModelIndex)));
}

ScegliProdottoDialog::~ScegliProdottoDialog()
{
    delete ui;
}

int ScegliProdottoDialog::getQuantity()
{
    return ui->quantity->value();
}

QString ScegliProdottoDialog::getSelected()
{
    return id;
}

void ScegliProdottoDialog::elementClicked(QModelIndex idx)
{
    id = model->itemData(model->index(idx.row(), 0)).value(0).toString();
}
