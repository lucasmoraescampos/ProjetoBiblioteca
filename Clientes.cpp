#include "Clientes.h"

namespace TP2{

Clientes::Clientes():
    id(0),
    nome(""),
    tipo(""),
    multa(0),
    qtdReservas(0),
    livro1(""),
    livro2(""),
    livro3(""),
    livro4(""),
    livro5(""),
    dia(0)
{

}

void Clientes::montarObjeto(QString &str)
{
    try {
        QStringList strList = str.split(';');
        this->id = strList[0].toInt();
        this->nome = strList[1];
        this->tipo = strList[2];
        this->multa = strList[3].toDouble();
        this->qtdReservas = strList[4].toInt();
        this->livro1 = strList[5];
        this->livro2 = strList[6];
        this->livro3 = strList[7];
        if(this->tipo == "prof"){
            this->livro4 = strList[8];
            this->livro5 = strList[9];
        }
    } catch (...) {
        throw QString("Erro no metodo materializar classe Contato");
    }
}

QString Clientes::desmontarObjeto() const
{
    QString saida = QString::number(this->id);
    saida += ";";
    saida += this->nome;
    saida += ";";
    saida += this->tipo;
    saida += ";";
    saida += QString::number(this->multa);
    saida += ";";
    saida += QString::number(this->qtdReservas);
    saida += ";";
    saida += this->livro1;
    saida += ";";
    saida += this->livro2;
    saida += ";";
    saida += this->livro3;
    if(this->tipo == "prof"){
        saida += ";";
        saida += this->livro4;
        saida += ";";
        saida += this->livro5;
    }
    return saida;
}

}
