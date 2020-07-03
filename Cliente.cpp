#include "Cliente.h"
#include <QStringList>

TP::Cliente::Cliente()
{
    id = telefone = cpf = 0;
    nome = endereco = "";
}

TP::Cliente::Cliente( unsigned int id, std::string nome, std::string endereco, unsigned long long telefone, unsigned long long cpf )
{
    setID( id );
    setNome( nome ) ;
    setEndereco( endereco );
    setTelefone( telefone );
    setCPF( cpf );
}

void TP::Cliente::montar( std::string atributos )
{
    QString str = QString::fromStdString( atributos );
    QStringList list = str.split( QLatin1Char( ';' ) );

    setID( list[0].toInt() );
    setNome( list[1].toStdString() );
    setEndereco( list[2].toStdString() );
    setTelefone( list[3].toLongLong() );
    setCPF( list[4].toLongLong() );
}

std::string TP::Cliente::desmontar() const
{
    std::string str = std::to_string( id ) + ';' +
                      nome + ';' + endereco + ';' +
                      std::to_string( telefone ) + ';' +
                      std::to_string( cpf ) + '\n';

    return str;
}

QString TP::Cliente::imprimir() const
{
    QString str = "ID: " + QString::number( id ) + '\n' +
                  "Nome: " + QString::fromStdString( nome ) + '\n' +
                  "Endereço: " + QString::fromStdString( endereco ) + '\n' +
                  "Telefone: " + QString::number( telefone ) + '\n' +
                  "CPF: " + QString::number( cpf ) + "\n";

    return str;
}

void TP::Cliente::setID( unsigned int id )
{
    if( id <= 0 || id > 10000 )
        throw QString( "ID inválido!" );

    this->id = id;
}

void TP::Cliente::setNome( std::string nome )
{
    if( nome == "" )
        throw QString( "Informe um nome!" );

    this->nome = nome;
}

void TP::Cliente::setEndereco( std::string endereco )
{
    if( endereco == "" )
        throw QString( "Informe um endereço!" );

    this->endereco = endereco;
}

void TP::Cliente::setTelefone( unsigned long long telefone )
{
    if( telefone <= 0 || telefone > 100000000000 )
        throw QString( "Telefone inválido!" );

    this->telefone = telefone;
}

void TP::Cliente::setCPF( unsigned long long cpf )
{
    if( cpf <= 0 || cpf > 100000000000 )
        throw QString( "CPF inválido!" );

    this->cpf = cpf;
}

unsigned int TP::Cliente::getID() const
{
    return id;
}

std::string TP::Cliente::getNome() const
{
    return nome;
}

std::string TP::Cliente::getEndereco() const
{
    return endereco;
}

unsigned long long TP::Cliente::getTelefone() const
{
    return telefone;
}

unsigned long long TP::Cliente::getCPF() const
{
    return cpf;
}
