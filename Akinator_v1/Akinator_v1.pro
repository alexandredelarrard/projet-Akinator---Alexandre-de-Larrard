#-------------------------------------------------
#
# Project created by QtCreator 2014-11-11T22:40:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Akinator_v1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    personnages.cpp \
    questions.cpp \
    arbre_classification.cpp \
    basededonnees.cpp \
    noeud.cpp

HEADERS  += mainwindow.h \
    personnages.h \
    questions.h \
    arbre_classification.h \
    basededonnees.h \
    noeud.h

FORMS    += mainwindow.ui
