#ifndef CLIENTES_H
#define CLIENTES_H

#include "TransformarDados.h"
#include "Livro.h"
#include <list>

namespace TP2{

class Clientes : public TransformarDados
{
private:
    int id;
    QString nome;
    QString tipo;
    double multa;
    int qtdReservas;
    QString livro1;
    QString livro2;
    QString livro3;
    QString livro4;
    QString livro5;
    int dia;
public:
    Clientes();
    int getId()const{return this->id;}
    QString getNome()const{return this->nome;}
    QString getTipo()const{return this->tipo;}
    double getMulta()const{return this->multa;}
    int getQtdReservas(){return this->qtdReservas;}
    QString getLivro1()const{return this->livro1;}
    QString getLivro2()const{return this->livro2;}
    QString getLivro3()const{return this->livro3;}
    QString getLivro4()const{return this->livro4;}
    QString getLivro5()const{return this->livro5;}
    int getDia()const{return this->dia;}
    void setId(int id){this->id = id;}
    void setNome(QString nome){this->nome = nome;}
    void setQtdReservas(bool n){this->qtdReservas = n;}
    void setLivro1(QString livro){this->livro1 = livro;}
    void setLivro2(QString livro){this->livro2 = livro;}
    void setLivro3(QString livro){this->livro3 = livro;}
    void setLivro4(QString livro){this->livro4 = livro;}
    void setLivro5(QString livro){this->livro5 = livro;}
    void setDia(int dia){this->dia = dia;}
    void montarObjeto(QString &str);
    QString desmontarObjeto()const;
};

}

#endif // CLIENTES_H
