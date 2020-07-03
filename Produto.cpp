#include "Produto.h"
#include <QStringList>

TP::Produto::Produto()
{
    codigo = quantidade = preco = 0;
    descricao = "";
}

TP::Produto::Produto( unsigned int codigo, std::string descricao, int quantidade, float preco )
{
    setCodigo( codigo );
    setDescricao( descricao );
    setQuantidade( quantidade );
    setPreco( preco );
}

void TP::Produto::montar( std::string atributos )
{
    QString str = QString::fromStdString( atributos );
    QStringList list = str.split( QLatin1Char( ';' ) );

    setCodigo( list[0].toInt() );
    setDescricao( list[1].toStdString() );
    setQuantidade( list[2].toInt() );
    setPreco( list[3].toFloat() );
}

std::string TP::Produto::desmontar() const
{
    std::string str = std::to_string( codigo ) + ';' +
                      descricao + ';' +
                      std::to_string( quantidade ) + ';' +
                      std::to_string( preco ) + '\n';

    return str;
}

QString TP::Produto::imprimir() const
{
    QString str = "Código: " + QString::number( codigo ) + '\n' +
                  "Descrição: " + QString::fromStdString( descricao ) + '\n' +
                  "Quantidade: " + QString::number( quantidade ) + " unidades\n" +
                  "Preço unitário: R$ " + QString::number( preco ) + "\n";

    return str;
}

QString TP::Produto::imprimirSimplificado() const
{
    QString str = QString::number( codigo ) + " | " +
                  QString::fromStdString( descricao ) + " | " +
                  QString::number( quantidade ) + " | "  +
                  "R$ " + QString::number( preco );

    return str;
}

QString TP::Produto::imprimirPedido() const
{
    QString str = "Código: " + QString::number( codigo ) + '\n' +
                  "Descrição: " + QString::fromStdString( descricao ) + '\n' +
                  "Quantidade: " + QString::number( quantidade ) + " unidades\n" +
                  "Preço unitário: R$ " + QString::number( preco ) + '\n' +
                  "Preço total: R$ " + QString::number( preco * quantidade ) + "\n";

    return str;
}

void TP::Produto::setCodigo( unsigned int codigo )
{
    if( codigo <= 0 || codigo > 10000 )
        throw QString( "Código inválido!" );

    this->codigo = codigo;
}

void TP::Produto::setDescricao( std::string descricao )
{
    if( descricao == "" )
        throw QString( "Informe uma descrição!" );

    this->descricao = descricao;
}

void TP::Produto::setQuantidade( int quantidade )
{
    if( quantidade < 0 || quantidade > 100000 )
        throw QString( "Quantidade inválida" );

    this->quantidade = quantidade;
}

void TP::Produto::setPreco( float preco )
{
    if( preco <= 0 || preco > 100000 )
        throw QString( "Preço inválido!" );

    this->preco = preco;
}

unsigned int TP::Produto::getCodigo() const
{
    return codigo;
}

std::string TP::Produto::getDescricao() const
{
    return descricao;
}

int TP::Produto::getQuantidade() const
{
    return quantidade;
}

float TP::Produto::getPreco() const
{
    return preco;
}

float TP::Produto::getTotal() const
{
    return quantidade * preco;
}
