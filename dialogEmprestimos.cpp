#include "dialogEmprestimos.h"
#include "ui_dialogEmprestimos.h"

DialogEmprestimos::DialogEmprestimos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEmprestimos)
{
    ui->setupUi(this);
    ui->tableWidgetListagem1->setVisible(false);
    ui->tableWidgetListagem2->setVisible(false);
    ui->pushButtonRelatorio->setEnabled(false);
    ui->pushButtonEmprestar->setEnabled(false);
    ui->pushButtonReservar->setEnabled(false);
    ui->pushButtonDevolver->setEnabled(false);
    ui->lineEditPesquisar->setEnabled(false);
    ui->pushButtonIr->setEnabled(false);
}

DialogEmprestimos::~DialogEmprestimos()
{
    delete ui;
}

void DialogEmprestimos::on_pushButtonID_clicked()
{
    try {
        bool chave = false;
        int id = ui->lineEditID->text().toInt();
        TP2::Dados fileClientes("C:\\Users\\Lucas\\Desktop\\clientes.txt"); //******************Alterar Caminho aqui*************************
        TP2::Dados fileLivros("C:\\Users\\Lucas\\Desktop\\livros.txt"); //******************Alterar Caminho aqui*************************
        std::list<TP2::Clientes>* clientes = fileClientes.listarClientes();
        std::list<TP2::Livro>* livros = fileLivros.listarLivros();
        TP2::Clientes cliente;
        while(!clientes->empty()){
            cliente = (*clientes).front();
            if(cliente.getId() == id){
                chave = true;
                break;
            }
            clientes->pop_front();
        }
        if(chave){
            ui->labelNome->setText("Nome: "+cliente.getNome());
            ui->labelTipo->setText("Tipo: "+cliente.getTipo());
            ui->labelDebito->setText("Multa: R$ "+QString::number(cliente.getMulta()));
            ui->labelInf->setText("Livros emprestados:");
            ui->tableWidgetListagem1->setVisible(false);
            ui->tableWidgetListagem2->setVisible(true);
            ui->pushButtonRelatorio->setEnabled(true);
            ui->pushButtonReservar->setEnabled(true);
            ui->pushButtonDevolver->setEnabled(true);
            ui->lineEditPesquisar->setEnabled(true);
            ui->pushButtonIr->setEnabled(true);
            ui->tableWidgetListagem2->setRowCount(0);
            TP2::Livro livro;
            while(!livros->empty()){
                livro = (*livros).front();
                if(cliente.getLivro1() == livro.getTitulo() || cliente.getLivro2() == livro.getTitulo() || cliente.getLivro3() == livro.getTitulo() || cliente.getLivro4() == livro.getTitulo() || cliente.getLivro5() == livro.getTitulo()){
                    QTableWidgetItem *itemTitulo = new QTableWidgetItem(livro.getTitulo());
                    QTableWidgetItem *itemAutor = new QTableWidgetItem(livro.getAutor());
                    QTableWidgetItem *itemEditora = new QTableWidgetItem(livro.getEditora());
                    QTableWidgetItem *itemISBN = new QTableWidgetItem(livro.getISBN());
                    int linha = ui->tableWidgetListagem2->rowCount();
                    ui->tableWidgetListagem2->insertRow(linha);
                    ui->tableWidgetListagem2->setItem(linha,0,itemTitulo);
                    ui->tableWidgetListagem2->setItem(linha,1,itemAutor);
                    ui->tableWidgetListagem2->setItem(linha,2,itemEditora);
                    ui->tableWidgetListagem2->setItem(linha,3,itemISBN);
                }
                livros->pop_front();
            }
        }
        else{
            throw QString("Id invalido!");
        }
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    } catch(...){
        QMessageBox::information(this,"ERRO","ERRO NA LISTAGEM");
    }
}

void DialogEmprestimos::on_pushButtonRelatorio_clicked()
{
    try {
        QString aux;
        TP2::Dados file("C:\\Users\\Lucas\\Desktop\\livros.txt");  //******************Alterar Caminho aqui****************************
        std::list<TP2::Livro>* lista = file.listarLivros();
        ui->labelInf->setText("Relação de livros para emprestimos:"); //******************Alterar Caminho aqui*************************
        ui->tableWidgetListagem1->setVisible(true);
        ui->tableWidgetListagem2->setVisible(false);
        ui->tableWidgetListagem1->setRowCount(0);
        while(!lista->empty()){
            TP2::Livro objeto = (*lista).front();
            QTableWidgetItem *itemTitulo = new QTableWidgetItem(objeto.getTitulo());
            QTableWidgetItem *itemAutor = new QTableWidgetItem(objeto.getAutor());
            QTableWidgetItem *itemEditora = new QTableWidgetItem(objeto.getEditora());
            QTableWidgetItem *itemISBN = new QTableWidgetItem(objeto.getISBN());
            QTableWidgetItem *itemQtd = new QTableWidgetItem(QString::number(objeto.getQuantidade()));
            if(objeto.getPodeEmprestar()) aux = "Sim";
            else aux = "Nao";
            QTableWidgetItem *itemEmpresta = new QTableWidgetItem(aux);
            if(objeto.getPodeReservar()) aux = "Sim";
            else aux = "Nao";
            QTableWidgetItem *itemReserva = new QTableWidgetItem(aux);
            int linha = ui->tableWidgetListagem1->rowCount();
            ui->tableWidgetListagem1->insertRow(linha);
            ui->tableWidgetListagem1->setItem(linha,0,itemTitulo);
            ui->tableWidgetListagem1->setItem(linha,1,itemAutor);
            ui->tableWidgetListagem1->setItem(linha,2,itemEditora);
            ui->tableWidgetListagem1->setItem(linha,3,itemISBN);
            ui->tableWidgetListagem1->setItem(linha,4,itemEmpresta);
            ui->tableWidgetListagem1->setItem(linha,5,itemReserva);
            ui->tableWidgetListagem1->setItem(linha,6,itemQtd);
            lista->pop_front();
        }
        delete lista;
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    } catch(...){
        QMessageBox::information(this,"ERRO","ERRO NA LISTAGEM");
    }
}

void DialogEmprestimos::on_pushButtonIr_clicked()
{
    try{
        QString aux;
        bool chave = false;
        QString busca = ui->lineEditPesquisar->text();
        TP2::Dados file("C:\\Users\\Lucas\\Desktop\\livros.txt");
        std::list<TP2::Livro>* lista = file.listarLivros();
        TP2::Livro objeto;
        while(!lista->empty()){
            objeto = (*lista).front();
            if(busca == objeto.getTitulo() || busca == objeto.getAutor() || busca == objeto.getEditora() || busca == objeto.getISBN()){
                chave = true;
                break;
            }
            lista->pop_front();
        }
        if(chave){
            ui->pushButtonEmprestar->setEnabled(true);
            ui->labelInf->setText("Livro pesquisado:");
            ui->tableWidgetListagem1->setVisible(true);
            ui->tableWidgetListagem2->setVisible(false);
            ui->lineEditPesquisar->setText(objeto.getTitulo());
            ui->tableWidgetListagem1->setRowCount(0);
            QTableWidgetItem *itemTitulo = new QTableWidgetItem(objeto.getTitulo());
            QTableWidgetItem *itemAutor = new QTableWidgetItem(objeto.getAutor());
            QTableWidgetItem *itemEditora = new QTableWidgetItem(objeto.getEditora());
            QTableWidgetItem *itemISBN = new QTableWidgetItem(objeto.getISBN());
            QTableWidgetItem *itemQtd = new QTableWidgetItem(QString::number(objeto.getQuantidade()));
            if(objeto.getPodeEmprestar()) aux = "Sim";
            else aux = "Nao";
            QTableWidgetItem *itemEmpresta = new QTableWidgetItem(aux);
            if(objeto.getPodeReservar()) aux = "Sim";
            else aux = "Nao";
            QTableWidgetItem *itemReserva = new QTableWidgetItem(aux);
            int linha = ui->tableWidgetListagem1->rowCount();
            ui->tableWidgetListagem1->insertRow(linha);
            ui->tableWidgetListagem1->setItem(linha,0,itemTitulo);
            ui->tableWidgetListagem1->setItem(linha,1,itemAutor);
            ui->tableWidgetListagem1->setItem(linha,2,itemEditora);
            ui->tableWidgetListagem1->setItem(linha,3,itemISBN);
            ui->tableWidgetListagem1->setItem(linha,4,itemEmpresta);
            ui->tableWidgetListagem1->setItem(linha,5,itemReserva);
            ui->tableWidgetListagem1->setItem(linha,6,itemQtd);
        }
        else{
            throw QString("Livro não encontrado!");
        }

    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    } catch(...){
        QMessageBox::information(this,"ERRO","ERRO NA LISTAGEM");
    }
}

void DialogEmprestimos::on_pushButtonEmprestar_clicked()
{

}
