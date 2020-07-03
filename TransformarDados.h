#ifndef TRANSFORMARDADOS_H
#define TRANSFORMARDADOS_H

#include <string>

namespace TP
{
    class TransformarDados
    {
        public:
            virtual void montar( std::string atributos ) = 0;
            virtual std::string desmontar() const = 0;
    };
}
#endif // TRANSFORMARDADOS_H
