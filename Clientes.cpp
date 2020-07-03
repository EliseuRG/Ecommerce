#include "Clientes.h"

TP::Clientes::Clientes()
{
    nomeArquivo = "clientes.txt";
}

void TP::Clientes::incluir( Cliente obj )
{
    if( TP::Clientes::buscar( obj.getID() ).getID() == obj.getID() )
        throw QString( "ID já cadastrado, escolha outro!" );

    std::ofstream file( nomeArquivo, std::ios::app );

    file << obj.desmontar();
    file.close();
}

void TP::Clientes::alterar( Cliente obj )
{
    if( TP::Clientes::buscar( obj.getID() ).getID() != obj.getID() )
        throw QString( "Cliente não cadastrado!" );

    std::ifstream file( nomeArquivo, std::ios::in );
    std::ofstream temp( "temp.txt", std::ios::out );
    std::string str;
    TP::Cliente aux;

    while( std::getline( file, str ) )
    {
       aux.montar( str );

       if( aux.getID() == obj.getID() )
           temp << obj.desmontar();
       else
           temp << aux.desmontar();
    }

    file.close();
    temp.close();

    remove( "clientes.txt" );
    rename( "temp.txt", "clientes.txt" );
}

std::list<TP::Cliente> TP::Clientes::listar()
{
    std::ifstream file( nomeArquivo, std::ios::in );
    std::string str;
    TP::Cliente obj;
    std::list<TP::Cliente> lista;

    while( std::getline( file, str ) )
    {
       obj.montar( str );
       lista.push_back( obj );
    }

    file.close();

    return lista;
}

void TP::Clientes::excluir( unsigned key )
{
    if( key <= 0 || key > 10000 )
        throw QString( "ID inválido!" );

    if( TP::Clientes::buscar( key ).getID() != key )
        throw QString( "Cliente não cadastrado!" );

    std::ifstream file( nomeArquivo, std::ios::in );
    std::ofstream temp( "temp.txt", std::ios::out );
    std::string str;
    TP::Cliente obj;

    while( std::getline( file, str ) )
    {
       obj.montar( str );

       if( obj.getID() != key )
           temp << obj.desmontar();
    }

    file.close();
    temp.close();

    remove( "clientes.txt" );
    rename( "temp.txt", "clientes.txt" );
}

TP::Cliente TP::Clientes::buscar( unsigned int key )
{
    if( key <= 0 || key > 10000 )
        throw QString( "ID inválido!" );

    std::ifstream file( nomeArquivo, std::ios::in );
    std::string str;
    TP::Cliente obj;

    if( std::getline( file, str) )
        obj.montar( str );

    while( obj.getID() != key && std::getline( file, str ) )
       obj.montar( str );

    file.close();

    if( obj.getID() != key )
    {
        TP::Cliente objLimpo;
        return objLimpo;
    }

    return obj;
}
