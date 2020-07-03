#ifndef GESTAOPEDIDO_H
#define GESTAOPEDIDO_H

#include <QDialog>
#include <QMessageBox>
#include <list>
#include "Pedido.h"
#include "Pedidos.h"
#include "Produto.h"
#include "Produtos.h"
#include "Cliente.h"
#include "Clientes.h"

namespace Ui {
class GestaoPedido;
}

class GestaoPedido : public QDialog
{
    Q_OBJECT

    public:
        explicit GestaoPedido(QWidget *parent = nullptr);
        ~GestaoPedido();

    private slots:
        void on_pushButtonGPListar_clicked();

    private:
        Ui::GestaoPedido *ui;
};
#endif // GESTAOPEDIDO_H
