#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <dialogEmprestimos.h>
#include <QMessageBox>
#include <Dados.h>
#include <QDate>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_pushButtonEmprestimos_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
