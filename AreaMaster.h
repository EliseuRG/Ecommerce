#ifndef AREAMASTER_H
#define AREAMASTER_H

#include <QDialog>
#include <QMessageBox>
#include "GestaoCliente.h"
#include "GestaoProduto.h"
#include "GestaoPedido.h"

namespace Ui {
class AreaMaster;
}

class AreaMaster : public QDialog
{
    Q_OBJECT

    public:
        explicit AreaMaster(QWidget *parent = nullptr);
        ~AreaMaster();

    private slots:
        void on_pushButtonGMCliente_clicked();
        void on_pushButtonGMPedido_clicked();
        void on_pushButtonGMProduto_clicked();
        void on_pushButtonGMFazerLogoff_clicked();

    private:
        Ui::AreaMaster *ui;
};
#endif // AREAMASTER_H
