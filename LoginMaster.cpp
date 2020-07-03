#include "LoginMaster.h"
#include "ui_LoginMaster.h"

LoginMaster::LoginMaster(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginMaster)
{
    ui->setupUi(this);
    ui->lineEditIDMaster->setFocus();

    //ATRIBUIÇÃO DA IMAGEM - Vindo do patch do arquivo de recursos
    QPixmap cartaomaster(":/img/img/cartaomaster.png");
    ui->cartaoMaster->setPixmap(cartaomaster);
}

LoginMaster::~LoginMaster()
{
    delete ui;
}

void LoginMaster::on_pushButtonEntrarMaster_clicked()
{
    unsigned int id = ui->lineEditIDMaster->text().toInt();
    unsigned int senha = ui->lineEditSenhaMaster->text().toUInt();

    if( id == 10001 && senha == 123456)
    {
        this->close();
        AreaMaster janelaMaster;
        janelaMaster.exec();
    }
    else
    {
        QMessageBox::critical( this, "ATENÇÃO", "Você não é um usuário master!" );
    }
}
