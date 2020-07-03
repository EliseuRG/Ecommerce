#include "AreaCliente.h"
#include "ui_AreaCliente.h"

AreaCliente::AreaCliente(QWidget *parent, TP::Cliente *cliente) :
    QDialog(parent),
    ui(new Ui::AreaCliente)
{
    ui->setupUi(this);
    this->cliente = *cliente;

    try {
            TP::Pedidos pedidos;

            ui->lineEditACCID->setFocus();

            unsigned int idPedido = pedidos.listar().size() + 1;
            pedido.setIDPedido( idPedido );
            pedido.setIDCliente( cliente->getID() );
            pedido.setData( QDate::currentDate().toString().toStdString() );

            ui->lineEditACPIDPedido->setText( QString::number( idPedido ));
            ui->lineEditACPIDPedido->setDisabled(true);
            ui->lineEditACPIDCliente->setText( QString::number( cliente->getID() ) );
            ui->lineEditACPIDCliente->setDisabled(true);
            ui->dateEditACPData->setDate( QDate::currentDate() );

            TP::Produtos produtos;
            std::list<TP::Produto> listaProdutos = produtos.listar();

            for( std::list<TP::Produto>::iterator it = listaProdutos.begin(); it != listaProdutos.end(); it++ )
                ui->comboBoxACPProdutos->addItem( it->imprimirSimplificado() );

            ui->lineEditACCID->setText( QString::number( cliente->getID() ));
            ui->lineEditACCID->setDisabled(true);

            ui->lineEditACCCPF->setText( QString::number( cliente->getCPF() ));
            ui->lineEditACCCPF->setDisabled(true);

            ui->lineEditACCNome->setText( QString::fromStdString( cliente->getNome() ));
            ui->lineEditACCTelefone->setText( QString::number( cliente->getTelefone() ));
            ui->lineEditACCEndereco->setText( QString::fromStdString( cliente->getEndereco() ));

            std::list<TP::Pedido> listaPedido = pedidos.listar( cliente->getID() );
            QString str;

            for( std::list<TP::Pedido>::iterator it = listaPedido.begin(); it != listaPedido.end(); it++ )
                str += it->imprimir();

            ui->textBrowserACCListar->setText( str );

    } catch (QString erro)
    {
        QMessageBox::information( this, "ATENÇÃO!", erro );
    }
}

AreaCliente::~AreaCliente()
{
    delete ui;
}

void AreaCliente::on_pushButtonACPAdicionarCarrinho_clicked()
{
    try
    {
        QString str = ui->comboBoxACPProdutos->currentText();
        QStringList list = str.split(QLatin1Char(' '));
        unsigned int id = list.first().toInt();
        unsigned int quantidade = ui->spinBoxACPQuantidade->value();

        TP::Produto produto = produtos.buscar( id );
        produto.setQuantidade( quantidade );

        std::list<TP::Produto> listaCarrinho = pedido.getCarrinho();

        std::list<TP::Produto>::iterator it;
        for( it = listaCarrinho.begin();
             it != listaCarrinho.end() && it->getCodigo() != id; it++ );

        if( it->getCodigo() == id )
            pedido.removerProdutoCarrinho( id );

        pedido.adicionarProdutoCarrinho( produto );

        ui->textBrowserACPCarrinho->setText( pedido.imprimirSimplificado() );
        ui->lineEditACPTotal->setText( "R$ " + QString::number( pedido.totalCompra() ) );

        ui->comboBoxACPCarrinho->clear();
        listaCarrinho = pedido.getCarrinho();
        for( std::list<TP::Produto>::iterator it = listaCarrinho.begin(); it != listaCarrinho.end(); it++ )
            ui->comboBoxACPCarrinho->addItem( it->imprimirSimplificado() );
    }
    catch ( QString erro )
    {
        QMessageBox::information( this, "ATENÇÃO!", erro );
    }
}

void AreaCliente::on_pushButtonACPERemoverCarrinho_clicked()
{
    try
    {
        QString str = ui->comboBoxACPCarrinho->currentText();
        QStringList list = str.split(QLatin1Char(' '));
        unsigned int id = list.first().toInt();

        pedido.removerProdutoCarrinho( id );

        ui->textBrowserACPCarrinho->setText( pedido.imprimirSimplificado() );
        ui->lineEditACPTotal->setText( "R$ " + QString::number( pedido.totalCompra() ) );

        ui->comboBoxACPCarrinho->clear();
        std::list<TP::Produto> listaCarrinho = pedido.getCarrinho();
        for( std::list<TP::Produto>::iterator it = listaCarrinho.begin(); it != listaCarrinho.end(); it++ )
            ui->comboBoxACPCarrinho->addItem( it->imprimirSimplificado() );
    }
    catch ( QString erro )
    {
        QMessageBox::information( this, "ATENÇÃO!", erro );
    }
}

void AreaCliente::on_pushButtonACPFinalizarPedido_clicked()
{
    if( pedido.realizarPedido() )
    {
        pedidos.incluir( pedido );

        std::list<TP::Pedido> listaPedido = pedidos.listar( cliente.getID() );
        QString str;

        for( std::list<TP::Pedido>::iterator it = listaPedido.begin(); it != listaPedido.end(); it++ )
            str += it->imprimir();

        ui->textBrowserACCListar->setText( str );

        QMessageBox::information( this, "INFORMAÇÃO!", "Pedido realizado com sucesso!" );

        pedido.setIDPedido( pedido.getIDPedido() + 1 );
        ui->lineEditACPIDPedido->setText( QString::number( pedido.getIDPedido() ));

        TP::Produtos produtos;
        std::list<TP::Produto> listaProdutos = produtos.listar();

        pedido.esvaziarCarrinho();
        ui->comboBoxACPProdutos->clear();
        ui->comboBoxACPCarrinho->clear();
        ui->textBrowserACPCarrinho->clear();
        ui->lineEditACPTotal->clear();
        ui->spinBoxACPQuantidade->setValue(1);

        for( std::list<TP::Produto>::iterator it = listaProdutos.begin(); it != listaProdutos.end(); it++ )
            ui->comboBoxACPProdutos->addItem( it->imprimirSimplificado() );
    }
    else
        QMessageBox::information( this, "INFORMAÇÃO!", "Pedido não realizado\nEscolha algum produto!" );
}

void AreaCliente::on_pushButtonACPEsvaziarCarrinho_clicked()
{
    try
    {
        pedido.esvaziarCarrinho();

        ui->textBrowserACPCarrinho->setText( pedido.imprimirSimplificado() );
        ui->lineEditACPTotal->setText( "R$ " + QString::number( pedido.totalCompra() ) );

        ui->comboBoxACPCarrinho->clear();
        std::list<TP::Produto> listaCarrinho = pedido.getCarrinho();
        for( std::list<TP::Produto>::iterator it = listaCarrinho.begin(); it != listaCarrinho.end(); it++ )
            ui->comboBoxACPCarrinho->addItem( it->imprimirSimplificado() );

        std::list<TP::Pedido> listaPedido = pedidos.listar( cliente.getID() );
        QString str;

        for( std::list<TP::Pedido>::iterator it = listaPedido.begin(); it != listaPedido.end(); it++ )
            str += it->imprimir();

        ui->textBrowserACCListar->setText( str );
    }
    catch ( QString erro)
    {
        QMessageBox::information( this, "ATENÇÃO!", erro );
    }
}

void AreaCliente::on_pushButtonACCAlterar_clicked()
{
    try
    {
        cliente.setNome( ui->lineEditACCNome->text().toStdString() );
        cliente.setEndereco( ui->lineEditACCEndereco->text().toStdString() );
        cliente.setTelefone( ui->lineEditACCTelefone->text().toLongLong() );

        TP::Clientes clientes;
        clientes.alterar( cliente );
        QMessageBox::information( this, "INFORMAÇÃO!", "Dados alterados com sucesso!" );
    }
    catch ( QString erro )
    {
        QMessageBox::information( this, "ATENÇÃO!", erro );
    }
}
