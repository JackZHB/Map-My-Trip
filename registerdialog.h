#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>

/**
 * @brief Register Dialog
 */

namespace Ui {
class RegisterDialog;
}

/**
 * @brief Initializing Register Dialog
 */
class RegisterDialog : public QDialog
{
    Q_OBJECT

public:

    /**
     * @brief create register dialog
     * @param
     * @return register dialog
     */
    explicit RegisterDialog(QWidget *parent = nullptr);
    ~RegisterDialog();

    /**
     * @brief get Username
     * @param
     * @return username
     */
    QString getUserName();

    /**
     * @brief get password
     * @param
     * @return password
     */
    QString getPassword();

private slots:
    /**
     * @brief invoke when accept button clicked, create new account
     * @brief on_acceptButton_clicked
     */
    void on_acceptButton_clicked();

    /**
     * @brief invoke when cancel button clicked, cancel the registration process
     * @brief on_cancelButton_clicked
     */
    void on_cancelButton_clicked();

private:
    /**
     * @brief Register dialog UI
     */

    Ui::RegisterDialog *ui;
};

#endif // REGISTERDIALOG_H
