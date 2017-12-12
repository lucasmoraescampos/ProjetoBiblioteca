#include "DialogRelatorioLivros.h"
#include "ui_DialogRelatorioLivros.h"

DialogRelatorioLivros::DialogRelatorioLivros(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogRelatorioLivros)
{
    ui->setupUi(this);
    this->ListagemLivros();
}

DialogRelatorioLivros::~DialogRelatorioLivros()
{
    delete ui;
}

void DialogRelatorioLivros::ListagemLivros()
{
    try {
        TP2::Dados file("C:\\Users\\Lucas\\Desktop\\livros.txt");
        std::list<TP2::Livro>* lista = file.listarLivros();
        //Grid
        ui->tableWidgetListagem->setRowCount(0);
        while(!lista->empty()){
            TP2::Livro objeto = (*lista).front();
            QTableWidgetItem *itemTitulo = new QTableWidgetItem(objeto.getTitulo());
            QTableWidgetItem *itemAutor = new QTableWidgetItem(objeto.getAutor());
            QTableWidgetItem *itemEditora = new QTableWidgetItem(objeto.getEditora());
            QTableWidgetItem *itemISBN = new QTableWidgetItem(objeto.getISBN());
            QTableWidgetItem *itemQtd = new QTableWidgetItem(QString::number(objeto.getQuantidade()));
            int linha = ui->tableWidgetListagem->rowCount();
            ui->tableWidgetListagem->insertRow(linha);
            ui->tableWidgetListagem->setItem(linha,0,itemTitulo);
            ui->tableWidgetListagem->setItem(linha,1,itemAutor);
            ui->tableWidgetListagem->setItem(linha,2,itemEditora);
            ui->tableWidgetListagem->setItem(linha,3,itemISBN);
            ui->tableWidgetListagem->setItem(linha,4,itemQtd);
            lista->pop_front();
        }
        delete lista;
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    } catch(...){
        QMessageBox::information(this,"ERRO","ERRO NA LISTAGEM");
    }
}
