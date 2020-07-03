#ifndef AREACLIENTE_H
#define AREACLIENTE_H

#include <QDialog>
#include <QMessageBox>
#include "Cliente.h"
#include "Clientes.h"
#include "Pedido.h"
#include "Pedidos.h"
#include "Produto.h"
#include "Produtos.h"

namespace Ui {
class AreaCliente;
}

class AreaCliente : public QDialog
{
    Q_OBJECT

    public:
        explicit AreaCliente(QWidget *parent = nullptr, TP::Cliente *cliente = nullptr);
        ~AreaCliente();

    private slots:
        void on_pushButtonACPAdicionarCarrinho_clicked();
        void on_pushButtonACPERemoverCarrinho_clicked();
        void on_pushButtonACPFinalizarPedido_clicked();
        void on_pushButtonACPEsvaziarCarrinho_clicked();
        void on_pushButtonACCAlterar_clicked();

    private:
        Ui::AreaCliente *ui;
        TP::Cliente cliente;
        TP::Pedido pedido;
        TP::Pedidos pedidos;
        TP::Produtos produtos;
};
#endif // AREACLIENTE_H
