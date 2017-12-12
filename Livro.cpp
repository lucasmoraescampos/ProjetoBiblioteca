#include "Livro.h"

namespace TP2{

Livro::Livro():
    titulo(""),
    autor(""),
    editora(""),
    isbn(""),
    podeEmprestar(true),
    podeReservar(true),
    quantidade(0)
{

}

void Livro::montarObjeto(QString &str)
{
    try {
        QStringList strList = str.split(';');
        this->titulo = strList[0];
        this->autor = strList[1];
        this->editora = strList[2];
        this->isbn = strList[3];
        this->quantidade = strList[4].toInt();

    } catch (...) {
        throw QString("Erro no metodo materializar classe Contato");
    }
}

}
