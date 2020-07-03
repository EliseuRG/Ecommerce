#ifndef CADASTROCLIENTE_H
#define CADASTROCLIENTE_H

#include <QDialog>
#include <QMessageBox>
#include "Cliente.h"
#include "Clientes.h"

namespace Ui {
class CadastroCliente;
}

class CadastroCliente : public QDialog
{
    Q_OBJECT

    public:
        explicit CadastroCliente(QWidget *parent = nullptr);
        ~CadastroCliente();

    private slots:
        void on_pushButtonCCCadastrar_clicked();

    private:
        Ui::CadastroCliente *ui;
        TP::Cliente cliente;
};
#endif // CADASTROCLIENTE_H
