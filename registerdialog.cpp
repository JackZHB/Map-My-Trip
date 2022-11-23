#include "registerdialog.h"
#include "ui_registerdialog.h"

#include <QMessageBox>
#include "dbhelper.h"

RegisterDialog::RegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

QString RegisterDialog::getUserName()
{
    return ui->userNameLineEdit->text();
}

QString RegisterDialog::getPassword()
{
    return ui->passwordLineEdit->text();
}

void RegisterDialog::on_acceptButton_clicked()
{
    DBHelper helper;
    helper.open();
    int userId= helper.checkUser(ui->userNameLineEdit->text(), ui->passwordLineEdit->text());
    if(userId<0) {
        helper.addUser(ui->userNameLineEdit->text(), ui->passwordLineEdit->text());
        helper.close();
        accept();
    } else {
        QMessageBox::information(this, "Error", "User exists");
        helper.close();
    }
}


void RegisterDialog::on_cancelButton_clicked()
{
    reject();
}

