#ifndef DADOSLIVRO_H
#define DADOSLIVRO_H
#include <QString>
#include <Livro.h>
#include <list>
#include<fstream>

namespace TP2{

class DadosLivro
{
public:
    QString arquivo;
    DadosLivro(QString arq);
    std::list<TP2::Livro>* listarLivros();
};

}

#endif // DADOSLIVRO_H
