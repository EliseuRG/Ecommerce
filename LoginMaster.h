#ifndef LOGINMASTER_H
#define LOGINMASTER_H

#include <QDialog>
#include <QPixmap>
#include <QMessageBox>
#include "AreaMaster.h"

namespace Ui {
class LoginMaster;
}

class LoginMaster : public QDialog
{
    Q_OBJECT

    public:
        explicit LoginMaster(QWidget *parent = nullptr);
        ~LoginMaster();

    private slots:
        void on_pushButtonEntrarMaster_clicked();

    private:
        Ui::LoginMaster *ui;
};
#endif // LOGINMASTER_H
