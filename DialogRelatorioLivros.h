#ifndef DIALOGRELATORIOLIVROS_H
#define DIALOGRELATORIOLIVROS_H

#include <QDialog>
#include <Dados.h>
#include <Livro.h>
#include <QMessageBox>

namespace Ui {
class DialogRelatorioLivros;
}

class DialogRelatorioLivros : public QDialog
{
    Q_OBJECT

public:
    explicit DialogRelatorioLivros(QWidget *parent = 0);
    ~DialogRelatorioLivros();

     void ListagemLivros();

private:
    Ui::DialogRelatorioLivros *ui;
};

#endif // DIALOGRELATORIOLIVROS_H
