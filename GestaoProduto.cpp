#include "GestaoProduto.h"
#include "ui_GestaoProduto.h"

GestaoProduto::GestaoProduto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GestaoProduto)
{
    ui->setupUi(this);
    ui->lineEditGPNCodigo->setFocus();
    ui->lineEditGPACodigo->setFocus();
    ui->lineEditGPGCodigo->setFocus();
}

GestaoProduto::~GestaoProduto()
{
    delete ui;
}

void GestaoProduto::on_pushButtonGPNCadastrar_clicked()
{
    try {
            TP::Produto produto;
            produto.setCodigo(ui->lineEditGPNCodigo->text().toUInt());
            produto.setDescricao(ui->lineEditGPNDescricao->text().toStdString().c_str());
            produto.setPreco(ui->lineEditGPNPreco->text().toFloat());

            if( ui->lineEditGPNQuantidade->text().toUInt() <= 0 )
                throw QString("Quantidade inválida!");

            produto.setQuantidade(ui->lineEditGPNQuantidade->text().toUInt());
            TP::Produtos incluir_produto;
            incluir_produto.incluir(produto);
            QMessageBox::information(this,"INFORMAÇÃO","Produto cadastrado com sucesso!");
            ui->lineEditGPNCodigo->clear();
            ui->lineEditGPNDescricao->clear();
            ui->lineEditGPNPreco->clear();
            ui->lineEditGPNQuantidade->clear();
    }catch (QString erro)
    {
        QMessageBox::information(this,"INFORMAÇÃO",erro);
    }
}

void GestaoProduto::on_pushButtonGPABuscar_clicked()
{
    try {
            int codigo_produto = ui->lineEditGPACodigo->text().toUInt();
            TP::Produtos buscar_produto;
            produto = buscar_produto.buscar(codigo_produto);
            ui->lineEditGPADescricao->setText(QString::fromStdString(produto.getDescricao()));
            ui->lineEditGPAQuantidade->setText(QString::number(produto.getQuantidade()));
            ui->lineEditGPAPreco->setText(QString::number(produto.getPreco()));
            if(ui->lineEditGPADescricao->text()=="")
            {
                QMessageBox::information(this,"INFORMAÇÃO","Produto nao encontrado!");
            }
    }catch (QString erro)
    {
        QMessageBox::information(this,"INFORMAÇÃO",erro);
    }
}

void GestaoProduto::on_pushButtonGPAAlterar_clicked()
{
    try {
            produto.setDescricao(ui->lineEditGPADescricao->text().toStdString().c_str());
            produto.setPreco(ui->lineEditGPAPreco->text().toFloat());

            if( ui->lineEditGPAQuantidade->text().toInt() <= 0 )
                throw QString("Quantidade inválida!");

            produto.setQuantidade(ui->lineEditGPAQuantidade->text().toInt());
            TP::Produtos alterar_produto;
            alterar_produto.alterar(produto);
            QMessageBox::information(this,"INFORMAÇÃO","Produto alterado com sucesso!");
            ui->listWidgetGPGLista->clear();
            TP::Produtos listar_produto;
            std::list <TP::Produto> temp = listar_produto.listar();
            int tamanho = temp.size();
            while(tamanho>0)
            {
                ui->listWidgetGPGLista->addItem(temp.front().imprimir());
                temp.pop_front();
                tamanho--;
            }
    }catch (QString erro)
    {
        QMessageBox::information(this,"INFORMAÇÃO",erro);
    }
}

void GestaoProduto::on_pushButtonGPGExcluir_clicked()
{
    try {
            int id_produto = ui->lineEditGPGCodigo->text().toUInt();
            TP::Produtos excluir_produto;
            excluir_produto.excluir(id_produto);
            QMessageBox::information(this,"INFORMAÇÃO","Produto excluido com sucesso!");
            ui->listWidgetGPGLista->clear();
            TP::Produtos listar_produto;
            std::list <TP::Produto> temp = listar_produto.listar();
            int tamanho = temp.size();
            while(tamanho>0)
            {
                ui->listWidgetGPGLista->addItem(temp.front().imprimir());
                temp.pop_front();
                tamanho--;
            }
    }catch (QString erro)
    {
        QMessageBox::information(this,"INFORMAÇÃO",erro);
    }
}

void GestaoProduto::on_pushButtonGPGListar_clicked()
{
    ui->listWidgetGPGLista->clear();
    if(ui->lineEditGPGCodigo->text()=="")
    {
        TP::Produtos listar_produto;
        std::list <TP::Produto> temp = listar_produto.listar();
        int tamanho = temp.size();
        while(tamanho>0)
        {
            ui->listWidgetGPGLista->addItem(temp.front().imprimir());
            temp.pop_front();
            tamanho--;
        }
    }
    else
    {
        int id_produto = ui->lineEditGPGCodigo->text().toUInt();
        TP::Produtos listar_produto;
        TP::Produto temp = listar_produto.buscar(id_produto);
        if(temp.getDescricao()!= "")
        {
            ui->listWidgetGPGLista->addItem(temp.imprimir());
        }
        else
        {
            QMessageBox::information(this,"INFORMAÇÃO","Produto não encontrado!");
        }
    }
}
