#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonEmprestimos_clicked()
{
    DialogEmprestimos obj;
    obj.setModal(true);
    this->setVisible(false);
    obj.exec();
    this->setVisible(true);
}
