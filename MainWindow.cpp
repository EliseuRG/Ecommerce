#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEditIDCliente->setFocus();

    //ATRIBUIÇÃO DA IMAGEM - Vindo do patch do arquivo de recursos
    QPixmap cartaocliente(":/img/img/cartaocliente.png");
    ui->cartaoCliente->setPixmap(cartaocliente);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionMaster_triggered()
{
    LoginMaster janelaLoginMaster;
    janelaLoginMaster.exec();
}

void MainWindow::on_actionSair_triggered()
{
    this->close();
}

void MainWindow::on_actionSobre_triggered()
{
    Sobre janelaSobre;
    janelaSobre.exec();
}

void MainWindow::on_pushButtonEntrarCliente_clicked()
{
    try
    {
        unsigned int id = ui->lineEditIDCliente->text().toInt();

        TP::Clientes clientes;
        TP::Cliente cliente = clientes.buscar( id );

        if( cliente.getID() == id )
        {
            AreaCliente janela( this, &cliente);
            janela.exec();
        }
        else
            QMessageBox::information( this, "ATENÇÃO!", "Cliente não cadastrado!" );

    }catch (QString erro)
    {
        QMessageBox::information(this,"INFORMAÇÃO",erro);
    }
}

void MainWindow::on_pushButtonCadastrarCliente_clicked()
{
    CadastroCliente janelaCadastroCliente;
    janelaCadastroCliente.exec();
}
