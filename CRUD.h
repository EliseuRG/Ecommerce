#ifndef CRUD_H
#define CRUD_H

#include <fstream>
#include <stdio.h>
#include <list>

namespace TP
{
    template<class T>
    class CRUD
    {
        public:
            virtual void incluir( T obj ) = 0;
            virtual void alterar( T obj ) = 0;
            virtual std::list<T> listar() = 0;
            virtual void excluir( unsigned int key ) = 0;
            virtual T buscar( unsigned int key ) = 0;
    };
}
#endif // CRUD_H
