#ifndef CLIENTE_H
#define CLIENTE_H

#include <QString>
#include "TransformarDados.h"

namespace TP
{
    class Cliente : public TransformarDados
    {
        public:
            Cliente();
            Cliente( unsigned int id, std::string nome, std::string endereco, unsigned long long telefone, unsigned long long cpf );
            void montar( std::string atributos );
            std::string desmontar() const;
            QString imprimir() const;
            void setID( unsigned int id );
            void setNome( std::string nome );
            void setEndereco( std::string endereco );
            void setTelefone( unsigned long long telefone );
            void setCPF( unsigned long long cpf );
            unsigned int getID() const;
            std::string getNome() const;
            std::string getEndereco() const;
            unsigned long long getTelefone() const;
            unsigned long long getCPF() const;

        private:
            unsigned int id;
            unsigned long long telefone,cpf;
            std::string nome,endereco;
    };
}
#endif // CLIENTE_H
