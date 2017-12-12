#include "DadosLivro.h"

namespace TP2{

DadosLivro::DadosLivro(QString arq):
    arquivo(arq)
{

}

std::list<Livro> *DadosLivro::listarLivros()
{
    try {
        std::ifstream arquivoLivros;
        arquivoLivros.open(arquivo.toStdString().c_str());
        if(!arquivoLivros.is_open()){
            throw QString("Arquivo de Livros nao foi aberto");
        }
        std::list<TP2::Livro> *lista = new std::list<TP2::Livro>();
        std::string linha;
        getline(arquivoLivros,linha);
        while(!arquivoLivros.eof()){
            TP2::Livro objeto;
            QString str = QString::fromStdString(linha);
            objeto.montarObjeto(str);
            lista->push_back(objeto);
            getline(arquivoLivros,linha);
        }
        arquivoLivros.close();
        //lista->sort();
        return lista;
    } catch (QString &erro) {
        throw(erro);
    }
}






}
