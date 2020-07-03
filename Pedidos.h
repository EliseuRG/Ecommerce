#ifndef PEDIDOS_H
#define PEDIDOS_H

#include "Pedido.h"
#include "CRUD.h"

namespace TP
{
    class Pedidos : public CRUD<Pedido>
    {
        public:
            Pedidos();
            void incluir( Pedido obj ) override;
            std::list<Pedido> listar() override;
            std::list<Pedido> listar( unsigned int key );
            Pedido buscar( unsigned int key ) override;

            //Não utilizados, estão declarados pois CRUD é abstrata
            void alterar( Pedido obj ) override;
            void excluir( unsigned int key ) override;

        private:
            std::string nomeArquivo;
    };
}
#endif // PEDIDOS_H
