#include "AreaMaster.h"
#include "ui_AreaMaster.h"

AreaMaster::AreaMaster(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AreaMaster)
{
    ui->setupUi(this);
}

AreaMaster::~AreaMaster()
{
    delete ui;
}

void AreaMaster::on_pushButtonGMCliente_clicked()
{
    GestaoCliente janelaCliente;
    janelaCliente.exec();
}

void AreaMaster::on_pushButtonGMPedido_clicked()
{
    GestaoPedido janelaPedido;
    janelaPedido.exec();
}

void AreaMaster::on_pushButtonGMProduto_clicked()
{
    GestaoProduto janelaProduto;
    janelaProduto.exec();
}

void AreaMaster::on_pushButtonGMFazerLogoff_clicked()
{
    this->close();
}
