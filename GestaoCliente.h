#ifndef GESTAOCLIENTE_H
#define GESTAOCLIENTE_H

#include <QDialog>
#include <QPixmap>
#include <QMessageBox>
#include "Cliente.h"
#include "Clientes.h"

namespace Ui {
class GestaoCliente;
}

class GestaoCliente : public QDialog
{
    Q_OBJECT

    public:
        explicit GestaoCliente(QWidget *parent = nullptr);
        ~GestaoCliente();

    private slots:
        void on_pushButtonGCNGravar_clicked();
        void on_pushButtonGCGExcluir_clicked();
        void on_pushButtonGCGListar_clicked();

    private:
        Ui::GestaoCliente *ui;
        TP::Cliente cliente;
};
#endif // GESTAOCLIENTE_H
