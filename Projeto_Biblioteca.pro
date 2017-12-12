#-------------------------------------------------
#
# Project created by QtCreator 2016-12-03T17:03:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Projeto_Biblioteca
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Livro.cpp \
    dialogEmprestimos.cpp \
    Clientes.cpp \
    Dados.cpp

HEADERS  += mainwindow.h \
    Livro.h \
    TransformarDados.h \
    dialogEmprestimos.h \
    Clientes.h \
    Dados.h

FORMS    += mainwindow.ui \
    dialogEmprestimos.ui
