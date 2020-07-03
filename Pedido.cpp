#include "Pedido.h"
#include <QStringList>

TP::Pedido::Pedido()
{
    idPedido = idCliente = 0;
    data = "";
    carrinho.clear();
}

TP::Pedido::Pedido( unsigned int idPedido, unsigned int idCliente, std::string data, std::list<TP::Produto> carrinho )
{
    setIDPedido( idPedido );
    setIDCliente( idCliente );
    setData( data );
    setCarrinho( carrinho );
}

float TP::Pedido::totalCompra() const
{
    float total = 0;
    std::list<TP::Produto> aux = carrinho;

    for( std::list<TP::Produto>::iterator it = aux.begin(); it != aux.end(); it++ )
        total += it->getTotal();

    return total;
}

void TP::Pedido::montar( std::string atributos )
{
    QString str = QString::fromStdString( atributos );
    QStringList lista = str.split( QLatin1Char( '|' ) );
    QStringList listaDadosPedido = lista.first().split( QLatin1Char( ';' ) );

    setIDPedido( listaDadosPedido[0].toInt() );
    setIDCliente( listaDadosPedido[1].toInt() );
    setData( listaDadosPedido[2].toStdString() );

    lista.removeFirst();
    std::list<TP::Produto> listaProduto;
    TP::Produto aux;

    for( int i = 0, size = lista.size(); i < size; i++ )
    {
        aux.montar( lista.first().toStdString() );
        listaProduto.push_back( aux );
        lista.removeFirst();
    }

    setCarrinho( listaProduto );
}

std::string TP::Pedido::desmontar() const
{
    std::string str = std::to_string( idPedido ) + ';' +
                      std::to_string( idCliente ) + ';' +
                      data + '|';

    std::string strAux;
    std::list<TP::Produto> aux = carrinho;

    for( std::list<TP::Produto>::iterator it = aux.begin(); it != aux.end(); it++ )
    {
        strAux = it->desmontar();
        strAux.pop_back();
        str += strAux + '|';
    }

    str.pop_back();
    str += '\n';

    return str;
}

QString TP::Pedido::imprimir() const
{
    QString str = "--------- DADOS DA COMPRA --------\n"
                  "ID Pedido: " + QString::number( idPedido ) + '\n' +
                  "ID Cliente: " + QString::number( idCliente ) + '\n' +
                  "Data: " + QString::fromStdString( data ) + '\n' +
                  "Total da compra: " + QString::number( totalCompra() ) + '\n' +
                  "\n          [PRODUTOS]\n";

    std::list<TP::Produto> aux = carrinho;

    for( std::list<TP::Produto>::iterator it = aux.begin(); it != aux.end(); it++ )
    {
        str += it->imprimirPedido();
        str += "\n";
    }

    return str;
}

QString TP::Pedido::imprimirSimplificado() const
{
    QString str;
    std::list<TP::Produto> aux = carrinho;

    for( std::list<TP::Produto>::iterator it = aux.begin(); it != aux.end(); it++ )
    {
        str += it->imprimirPedido() + '\n';
    }

    return str;
}

void TP::Pedido::esvaziarCarrinho()
{
    carrinho.clear();
}

void TP::Pedido::setIDPedido( unsigned int idPedido )
{
    if( idPedido <= 0 || idPedido > 10000 )
        throw QString( "ID inválido!" );

    this->idPedido = idPedido;
}

void TP::Pedido::setIDCliente( unsigned int idCliente )
{
    if( idCliente <= 0 || idCliente > 10000 )
        throw QString( "ID inválido!" );

    this->idCliente = idCliente;
}

void TP::Pedido::setData( std::string data )
{
    if( data == "" )
        throw QString( "Informe uma data!" );

    this->data = data;
}

void TP::Pedido::setCarrinho( std::list<TP::Produto> carrinho )
{
    this->carrinho = carrinho;
}

unsigned int TP::Pedido::getIDPedido() const
{
    return idPedido;
}

unsigned int TP::Pedido::getIDCliente() const
{
    return idCliente;
}

std::string TP::Pedido::getData() const
{
    return data;
}

std::list<TP::Produto> TP::Pedido::getCarrinho() const
{
    return carrinho;
}

void TP::Pedido::adicionarProdutoCarrinho( TP::Produto produto )
{
    TP::Produtos produtos;

    if(  produto.getQuantidade() > ( produtos.buscar( produto.getCodigo() ).getQuantidade() ) )
        throw QString( "Quantidade não disponível em estoque!" );

    carrinho.push_back( produto );
}

void TP::Pedido::removerProdutoCarrinho( unsigned int key )
{
    if( key <= 0 || key > 10000 )
        throw QString( "Código inválido!" );

    std::list<TP::Produto>::iterator it;

    for( it = carrinho.begin(); it->getCodigo() != key && it != carrinho.end(); it++ );

    if( it->getCodigo() == key )
        carrinho.erase( it );
    else
        throw QString( "Produto não incluído no carrinho!" );
}

bool TP::Pedido::realizarPedido()
{
    return ( idPedido != 0 && idCliente != 0 && data != "" && !carrinho.empty() );
}
