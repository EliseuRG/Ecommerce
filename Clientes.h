#ifndef CLIENTES_H
#define CLIENTES_H

#include "Cliente.h"
#include "CRUD.h"

namespace TP
{
    class Clientes : public CRUD<Cliente>
    {
        public:
            Clientes();
            void incluir( Cliente obj ) override;
            void alterar( Cliente obj ) override;
            std::list<Cliente> listar() override;
            void excluir( unsigned int key ) override;
            Cliente buscar( unsigned int key ) override;

        private:
            std::string nomeArquivo;
    };
}
#endif // CLIENTES_H
