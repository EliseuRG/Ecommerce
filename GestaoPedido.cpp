#include "GestaoPedido.h"
#include "ui_GestaoPedido.h"

GestaoPedido::GestaoPedido(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GestaoPedido)
{
    ui->setupUi(this);
    ui->lineEditGPID->setFocus();
}

GestaoPedido::~GestaoPedido()
{
    delete ui;
}

void GestaoPedido::on_pushButtonGPListar_clicked()
{
    ui->listWidgetGPLista->clear();
    if(ui->radioButtonGPCliente->isChecked())
    {
        if(ui->lineEditGPID->text() != "")
        {
            unsigned int id_cliente = ui->lineEditGPID->text().toUInt();
            TP::Clientes buscarCliente;

            if( buscarCliente.buscar( id_cliente ).getID() != id_cliente )
                QMessageBox::information(this,"INFORMAÇÃO","Cliente não cadastrado!");
            else
            {
                TP::Pedidos listarpedido;
                std::list <TP::Pedido> pedidos = listarpedido.listar(id_cliente);

                if(pedidos.empty())
                    ui->listWidgetGPLista->addItem( "Cliente sem pedidos" );
                else
                {
                    int tamanho = pedidos.size();

                    while(tamanho>0)
                    {
                        ui->listWidgetGPLista->addItem(pedidos.front().imprimir());
                        pedidos.pop_front();
                        tamanho--;
                    }
                }
            }
        }
        else
        {
            QMessageBox::information(this,"INFORMAÇÃO","Campo de busca vazio!");
        }
    }
    else
    {
        if(ui->radioButtonGPPedido->isChecked())
        {
            if(ui->lineEditGPID->text() != "")
            {
                int id_pedido = ui->lineEditGPID->text().toUInt();

                TP::Pedidos listarpedido;

                TP::Pedido pedido = listarpedido.buscar(id_pedido);
                if(pedido.getIDPedido() == 0)
                    QMessageBox::information(this,"INFORMAÇÃO","Pedido não existe! Informe um pedido que já foi realizado!");
                else
                    ui->listWidgetGPLista->addItem(pedido.imprimir());
            }
            else
            {
                QMessageBox::information(this,"INFORMAÇÃO","Campo de busca vazio!");
            }
        }
        else
        {
            if(ui->radioButtonGPTodos->isChecked())
            {
                TP::Pedidos listarpedido;
                std::list <TP::Pedido> pedidos = listarpedido.listar();
                if(pedidos.empty())
                    QMessageBox::information(this,"INFORMAÇÃO","Não existe nenhum pedido realizado!");
                else
                {
                    int tamanho = pedidos.size();
                    while(tamanho>0)
                    {
                        ui->listWidgetGPLista->addItem(pedidos.front().imprimir());
                        pedidos.pop_front();
                        tamanho--;
                    }
                }
            }
            else
            {
                QMessageBox::information(this,"INFORMAÇÃO","Nenhuma opção selecionada!");
            }
        }
    }
}
