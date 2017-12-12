#ifndef LIVRO_H
#define LIVRO_H

#include "TransformarDados.h"

namespace TP2{

class Livro : public TransformarDados
{
private:
    QString titulo;
    QString autor;
    QString editora;
    QString isbn;
    bool podeEmprestar;
    bool podeReservar;
    int quantidade;
public:
    Livro();
    QString getTitulo()const{return this->titulo;}
    QString getAutor()const{return this->autor;}
    QString getEditora()const{return this->editora;}
    QString getISBN()const{return this->isbn;}
    int getQuantidade()const{return this->quantidade;}
    bool getPodeEmprestar()const{return this->podeEmprestar;}
    bool getPodeReservar()const{return this->podeReservar;}
    void setTitulo(QString titulo){this->titulo = titulo;}
    void setAutor(QString autor){this->autor = autor;}
    void setEditora(QString editora){this->editora = editora;}
    void setISBN(QString isbn){this->isbn = isbn;}
    void montarObjeto(QString &str);
};

}

#endif // LIVRO_H
