#ifndef DADOS_H
#define DADOS_H

#include "Clientes.h"
#include <Livro.h>
#include <list>
#include<fstream>

namespace TP2{

class Dados
{
public:
    QString arquivo;
    Dados(QString arq);
    std::list<TP2::Livro>* listarLivros();
    std::list<TP2::Clientes>* listarClientes();

};

}

#endif // DADOSLIVRO_H
