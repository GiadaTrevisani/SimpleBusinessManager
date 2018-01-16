#include "scegliclifordialog.h"
#include "ui_scegliclifordialog.h"

ScegliCliForDialog::ScegliCliForDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScegliCliForDialog)
{
    ui->setupUi(this);
    ui->searchTxt->setPlaceholderText("Cerca");
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    forn = true;

    cdb = new ClientDatabaseManager(this);
    fdb = new FornitoriDatabaseManager(this);

    QObject::connect(ui->searchTxt, SIGNAL(textEdited(QString)), this, SLOT(searchChanged(QString)));
    QObject::connect(ui->tableView, SIGNAL(clicked(QModelIndex)), this, SLOT(elementClicked(QModelIndex)));
    QObject::connect(ui->tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(elementClicked(QModelIndex)));
}

ScegliCliForDialog::~ScegliCliForDialog()
{
    delete ui;
}

void ScegliCliForDialog::setType(bool forn)
{
    this->forn = forn;

    if(forn){
        model = fdb->getModel();
    } else {
        model = cdb->getModel();
    }
    ui->tableView->setModel(model);
}

void ScegliCliForDialog::searchChanged(QString src)
{
    delete model;
    if(forn){
        model = fdb->getModel(src);
    } else {
        model = cdb->getModel(src);
    }
    ui->tableView->setModel(model);
}

void ScegliCliForDialog::elementClicked(QModelIndex idx)
{
    id = model->itemData(model->index(idx.row(), 0)).value(0).toString();
}

QString ScegliCliForDialog::getSelected()
{
    return id;
}
