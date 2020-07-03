#ifndef PRODUTO_H
#define PRODUTO_H

#include <QString>
#include "TransformarDados.h"

namespace TP
{
    class Produto : public TransformarDados
    {
        public:
            Produto();
            Produto( unsigned int codigo, std::string descricao, int quantidade, float preco );
            void montar( std::string atributos );
            std::string desmontar() const;
            QString imprimir() const;
            QString imprimirSimplificado() const;
            QString imprimirPedido() const;
            void setCodigo( unsigned int codigo );
            void setDescricao( std::string descricao );
            void setQuantidade( int quantidade );
            void setPreco( float preco );
            unsigned int getCodigo() const;
            std::string getDescricao() const;
            int getQuantidade() const;
            float getPreco() const;
            float getTotal() const;

        private:
            unsigned int codigo;
            int quantidade;
            float preco;
            std::string descricao;
    };
}
#endif // PRODUTO_H
