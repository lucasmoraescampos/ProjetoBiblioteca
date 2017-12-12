#ifndef DIALOGEMPRESTIMOS_H
#define DIALOGEMPRESTIMOS_H

#include <QDialog>
#include <QInputDialog>
#include <Dados.h>
#include <QMessageBox>

namespace Ui {
class DialogEmprestimos;
}

class DialogEmprestimos : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEmprestimos(QWidget *parent = 0);
    ~DialogEmprestimos();

private slots:
    void on_pushButtonID_clicked();

    void on_pushButtonRelatorio_clicked();

    void on_pushButtonIr_clicked();

    void on_pushButtonEmprestar_clicked();

private:
    Ui::DialogEmprestimos *ui;
};

#endif // DIALOGEMPRESTIMOS_H
