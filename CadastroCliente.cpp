#include "CadastroCliente.h"
#include "ui_CadastroCliente.h"

CadastroCliente::CadastroCliente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CadastroCliente)
{
    ui->setupUi(this);
    ui->lineEditCCID->setFocus();
}

CadastroCliente::~CadastroCliente()
{
    delete ui;
}

void CadastroCliente::on_pushButtonCCCadastrar_clicked()
{
    try {
            cliente.setID(ui->lineEditCCID->text().toInt());
            cliente.setNome(ui->lineEditCCNome->text().toStdString().c_str());
            cliente.setCPF(ui->lineEditCCCPF->text().toLongLong());
            cliente.setTelefone(ui->lineEditCCTelefone->text().toLongLong());
            cliente.setEndereco(ui->lineEditCCEndereco->text().toStdString().c_str());
            TP::Clientes cliente_para_inserir;
            cliente_para_inserir.incluir(cliente);

            QMessageBox::information(this,"INFORMAÇÃO","Cliente cadastrado com sucesso!");

            ui->lineEditCCID->clear();
            ui->lineEditCCNome->clear();
            ui->lineEditCCCPF->clear();
            ui->lineEditCCTelefone->clear();
            ui->lineEditCCEndereco->clear();

    } catch (QString ex) {
        QMessageBox::information(this,"",ex);
    }
}
