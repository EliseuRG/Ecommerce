#ifndef PRODUTOS_H
#define PRODUTOS_H

#include "Produto.h"
#include "CRUD.h"

namespace TP
{
    class Produtos : public CRUD<Produto>
    {
        public:
            Produtos();
            void incluir( Produto obj ) override;
            void alterar( Produto obj ) override;
            std::list<Produto> listar() override;
            void excluir( unsigned int key ) override;
            Produto buscar( unsigned int key ) override;

        private:
            std::string nomeArquivo;
    };
}
#endif // PRODUTOS_H
