#include "homewidget.h"

HomeWidget::HomeWidget(QWidget *parent) : QWidget(parent)
{
    QLabel* title = new QLabel("Azienda");
    txtName = new QLineEdit();
    txtragSoc = new QLineEdit();
    txtSurname = new QLineEdit();
    txtTel = new QLineEdit();
    txtMail = new QLineEdit();
    txtPIva = new QLineEdit();
    txtFiscalC = new QLineEdit();
    txtAddress = new QLineEdit();
    txtCity = new QLineEdit();
    txtCap = new QLineEdit();

    aggiorna = new QPushButton();
    aggiorna->setText("Aggiorna");

    QVBoxLayout* v = new QVBoxLayout();
    v->addWidget(title);
    v->addWidget(txtName);
    v->addWidget(txtragSoc);
    v->addWidget(txtSurname);
    v->addWidget(txtTel);
    v->addWidget(txtMail);
    v->addWidget(txtPIva);
    v->addWidget(txtFiscalC);
    v->addWidget(txtAddress);
    v->addWidget(txtCity);
    v->addWidget(txtCap);
    v->addWidget(aggiorna);

    this->setLayout(v);

    db = new AziendaDatabaseManager();

    QObject::connect(aggiorna, SIGNAL(clicked(bool)), this, SLOT(updateAzienda()));

    this->fillAzienda();
}

void HomeWidget::updateAzienda()
{
    QHash<QString, QString>* data = new QHash<QString, QString>();

    data->insert("fiscalcode", txtFiscalC->text());
    data->insert("name", txtName->text());
    data->insert("surname", txtSurname->text());
    data->insert("ragioneSoc", txtragSoc->text());
    data->insert("tel", txtTel->text());
    data->insert("mail", txtMail->text());
    data->insert("piva", txtPIva->text());
    data->insert("address", txtAddress->text());
    data->insert("city", txtCity->text());
    data->insert("cap", txtCap->text());
    bool res = db->updateAzienda(data);
    delete data;

    if(!res){
        QMessageBox msgBox;
        msgBox.setText("C'è stato un errore nell'inserimento dei dati");
        msgBox.exec();
    }
}

void HomeWidget::fillAzienda()
{
    QHash<QString, QString>* data = db->getAzienda();

    if(data->value("error") == "true"){
        QMessageBox msgBox;
        msgBox.setText("C'è stato un errore, azienda non esistente");
        msgBox.exec();

        delete data;
        return;
    }

    txtName->setText(data->value("name"));
    txtSurname->setText(data->value("surname"));
    txtragSoc->setText(data->value("ragioneSoc"));
    txtTel->setText(data->value("tel"));
    txtMail->setText(data->value("mail"));
    txtPIva->setText(data->value("piva"));
    txtAddress->setText(data->value("address"));
    txtCity->setText(data->value("city"));
    txtCap->setText(data->value("cap"));
    txtFiscalC->setText(data->value("fiscalcode"));
}


