#include "Produtos.h"

TP::Produtos::Produtos()
{
    nomeArquivo = "produtos.txt";
}

void TP::Produtos::incluir( Produto obj )
{
    if( TP::Produtos::buscar( obj.getCodigo() ).getCodigo() == obj.getCodigo() )
        throw QString( "Produto já cadastrado!" );

    std::ofstream file( nomeArquivo, std::ios::app );

    file << obj.desmontar();
    file.close();
}

void TP::Produtos::alterar( Produto obj )
{
    if( TP::Produtos::buscar( obj.getCodigo() ).getCodigo() != obj.getCodigo() )
        throw QString( "Produto não cadastrado!" );

    std::ifstream file( nomeArquivo, std::ios::in );
    std::ofstream temp( "temp.txt", std::ios::out );
    std::string str;
    TP::Produto aux;

    while( std::getline( file, str ) )
    {
       aux.montar( str );

       if( aux.getCodigo() == obj.getCodigo() )
           temp << obj.desmontar();
       else
           temp << aux.desmontar();
    }

    file.close();
    temp.close();

    remove( "produtos.txt" );
    rename( "temp.txt", "produtos.txt" );
}

std::list<TP::Produto> TP::Produtos::listar()
{
    std::ifstream file( nomeArquivo, std::ios::in );
    std::string str;
    TP::Produto obj;
    std::list<TP::Produto> lista;

    while( std::getline( file, str ) )
    {
       obj.montar( str );
       lista.push_back( obj );
    }

    file.close();

    return lista;
}

void TP::Produtos::excluir( unsigned int key )
{
    if( key <= 0 || key > 10000 )
        throw QString( "Código inválido!" );

    if( TP::Produtos::buscar( key ).getCodigo() != key )
        throw QString( "Produto não cadastrado" );

    std::ifstream file( nomeArquivo, std::ios::in );
    std::ofstream temp( "temp.txt", std::ios::out );
    std::string str;
    TP::Produto obj;

    while( std::getline( file, str ) )
    {
       obj.montar( str );

       if( obj.getCodigo() != key )
           temp << obj.desmontar();
    }

    file.close();
    temp.close();

    remove( "produtos.txt" );
    rename( "temp.txt", "produtos.txt" );
}

TP::Produto TP::Produtos::buscar( unsigned int key )
{
    if( key <= 0 || key > 10000)
        throw QString( "Código inválido!" );

    std::ifstream file( nomeArquivo, std::ios::in );
    std::string str;
    TP::Produto obj;

    if( std::getline( file, str) )
        obj.montar( str );

    while( obj.getCodigo() != key && std::getline( file, str ) )
       obj.montar( str );

    file.close();

    if( obj.getCodigo() != key )
    {
        TP::Produto objLimpo;
        return objLimpo;
    }

    return obj;
}
