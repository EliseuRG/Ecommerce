#include "Pedidos.h"

TP::Pedidos::Pedidos()
{
    nomeArquivo = "pedidos.txt";
}

void TP::Pedidos::incluir( TP::Pedido obj )
{
    if( TP::Pedidos::buscar( obj.getIDPedido() ).getIDPedido() == obj.getIDPedido() )
        throw QString( "Pedido já está cadastrado!" );

    std::ofstream file( nomeArquivo, std::ios::app );

    file << obj.desmontar();
    file.close();

    std::list<TP::Produto> carrinho = obj.getCarrinho();
    TP::Produtos estoque;
    TP::Produto produto;

    produto = estoque.buscar( carrinho.front().getCodigo() );
    produto.setQuantidade( produto.getQuantidade() - carrinho.front().getQuantidade() );
    estoque.alterar( produto );
    carrinho.pop_front();
}

std::list<TP::Pedido> TP::Pedidos::listar()
{
    std::ifstream file( nomeArquivo, std::ios::in );
    std::string str;
    TP::Pedido obj;
    std::list<TP::Pedido> lista;

    while( std::getline( file, str ) )
    {
       obj.montar( str );
       lista.push_back( obj );
    }

    file.close();

    return lista;
}

std::list<TP::Pedido> TP::Pedidos::listar( unsigned int key )
{
    if( key <= 0 || key > 10000 )
        throw QString( "Código inválido!" );

    std::ifstream file( nomeArquivo, std::ios::in );
    std::string str;
    TP::Pedido obj;
    std::list<TP::Pedido> lista;

    while( std::getline( file, str ) )
    {
       obj.montar( str );

       if( obj.getIDCliente() == key )
           lista.push_back( obj );
    }

    file.close();

    return lista;
}

TP::Pedido TP::Pedidos::buscar( unsigned int key )
{
    if( key <= 0 || key > 10000 )
        throw QString( "Código inválido!" );

    std::ifstream file( nomeArquivo, std::ios::in );
    std::string str;
    TP::Pedido obj;

    if( std::getline( file, str) )
        obj.montar( str );

    while( obj.getIDPedido() != key && std::getline( file, str ) )
       obj.montar( str );

    file.close();

    if( obj.getIDPedido() != key )
    {
        TP::Pedido objLimpo;
        return objLimpo;
    }

    return obj;
}

void TP::Pedidos::alterar(TP::Pedido obj) { }

void TP::Pedidos::excluir(unsigned int key) { }
