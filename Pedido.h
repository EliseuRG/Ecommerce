#ifndef PEDIDO_H
#define PEDIDO_H

#include <QString>
#include <list>
#include "Produto.h"
#include "Produtos.h"
#include "TransformarDados.h"

namespace TP
{
    class Pedido : public TransformarDados
    {
        public:
            Pedido();
            Pedido( unsigned int idPedido, unsigned int idCliente, std::string data, std::list<Produto> carrinho );
            float totalCompra() const;
            void montar( std::string atributos );
            std::string desmontar() const;
            QString imprimir() const;
            QString imprimirSimplificado() const;
            void setIDPedido( unsigned int idPedido );
            void setIDCliente( unsigned int idCliente );
            void setData( std::string data );
            void setCarrinho( std::list<Produto> produtos );
            unsigned int getIDPedido() const;
            unsigned int getIDCliente() const;
            std::string getData() const;
            std::list<Produto> getCarrinho() const;
            void adicionarProdutoCarrinho( Produto produto );
            void removerProdutoCarrinho( unsigned int key );
            void esvaziarCarrinho();
            bool realizarPedido();

        private:
            unsigned int idPedido,
                idCliente;

            std::string data;

            std::list<TP::Produto> carrinho;
    };
}
#endif // PEDIDO_H
