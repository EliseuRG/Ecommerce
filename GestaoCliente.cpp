#include "GestaoCliente.h"
#include "ui_GestaoCliente.h"

GestaoCliente::GestaoCliente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GestaoCliente)
{
    ui->setupUi(this);
    ui->lineEditGCGID->setFocus();
    ui->lineEditGCNID->setFocus();
}

GestaoCliente::~GestaoCliente()
{
    delete ui;
}

void GestaoCliente::on_pushButtonGCNGravar_clicked()
{
    try {
            cliente.setID(ui->lineEditGCNID->text().toInt());
            cliente.setNome(ui->lineEditGCNNome->text().toStdString().c_str());
            cliente.setCPF(ui->lineEditGCNCPF->text().toLongLong());
            cliente.setTelefone(ui->lineEditGCNTelefone->text().toLongLong());
            cliente.setEndereco(ui->lineEditGCNEndereco->text().toStdString().c_str());
            TP::Clientes cliente_para_inserir;
            cliente_para_inserir.incluir(cliente);

            QMessageBox::information(this,"INFORMAÇÃO","Cliente cadastrado com sucesso!");

            ui->lineEditGCNID->clear();
            ui->lineEditGCNNome->clear();
            ui->lineEditGCNCPF->clear();
            ui->lineEditGCNTelefone->clear();
            ui->lineEditGCNEndereco->clear();

    }catch (QString erro)
    {
        QMessageBox::information(this,"INFORMAÇÃO",erro);
    }
}

void GestaoCliente::on_pushButtonGCGExcluir_clicked()
{
    try {
        int id_cliente = ui->lineEditGCGID->text().toUInt();
        TP::Clientes excluir_cliente;
        excluir_cliente.excluir(id_cliente);
        QMessageBox::information(this,"INFORMAÇÃO","Cliente excluido com sucesso!");
        ui->listWidgetGCGLista->clear();
        TP::Clientes listar_cliente;
        std::list <TP::Cliente> temp = listar_cliente.listar();
        int tamanho = temp.size();
        while(tamanho>0)
        {
            ui->listWidgetGCGLista->addItem(temp.front().imprimir());
            temp.pop_front();
            tamanho--;
        }
    }catch (QString erro)
    {
        QMessageBox::information(this,"INFORMAÇÃO",erro);
    }
}

void GestaoCliente::on_pushButtonGCGListar_clicked()
{
    ui->listWidgetGCGLista->clear();
    if(ui->lineEditGCGID->text()=="")
    {
        TP::Clientes listar_cliente;
        std::list <TP::Cliente> temp = listar_cliente.listar();
        int tamanho = temp.size();
        while(tamanho>0)
        {
            ui->listWidgetGCGLista->addItem(temp.front().imprimir());
            temp.pop_front();
            tamanho--;
        }
    }
    else
    {
        int id_cliente = ui->lineEditGCGID->text().toUInt();
        TP::Clientes listar_clientes;
        TP::Cliente temp = listar_clientes.buscar(id_cliente);
        if(temp.getNome()!= "")
        {
            ui->listWidgetGCGLista->addItem(temp.imprimir());
        }
        else
        {
            QMessageBox::information(this,"INFORMAÇÃO","Produto não encontrado!");
        }
    }
}
