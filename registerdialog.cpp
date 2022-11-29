#include "registerdialog.h"
#include "ui_registerdialog.h"

#include <QMessageBox>
#include "dbhelper.h"

/**
 * @brief create register dialog
 * @param
 * @return register dialog
 */
RegisterDialog::RegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
}

/**
 * @brief close register dialog
 */
RegisterDialog::~RegisterDialog()
{
    delete ui;
}

/**
 * @brief get Username
 * @param
 * @return username
 */
QString RegisterDialog::getUserName()
{
    return ui->userNameLineEdit->text();
}

/**
 * @brief get password
 * @param
 * @return password
 */
QString RegisterDialog::getPassword()
{
    return ui->passwordLineEdit->text();
}

/**
 * @brief invoke when accept button clicked, create new account
 * @brief on_acceptButton_clicked
 */
void RegisterDialog::on_acceptButton_clicked()
{
    DBHelper helper;
    helper.open();
    int userId= helper.checkUser(ui->userNameLineEdit->text(), ui->passwordLineEdit->text());
    if(userId<0) {
        helper.addUser(ui->userNameLineEdit->text(), ui->passwordLineEdit->text());
        helper.addProfile(helper.checkUser(ui->userNameLineEdit->text(), ui->passwordLineEdit->text()),ui->userNameLineEdit->text(),0,"","","");
        helper.close();
        accept();
    } else {
        QMessageBox::information(this, "Error", "User exists");
        helper.close();
    }
}

/**
 * @brief invoke when cancel button clicked, cancel the registration process
 * @brief on_cancelButton_clicked
 */
void RegisterDialog::on_cancelButton_clicked()
{
    reject();
}

