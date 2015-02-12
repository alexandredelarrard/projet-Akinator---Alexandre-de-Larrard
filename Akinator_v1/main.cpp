#include "mainwindow.h"
#include "personnages.h"
#include "basededonnees.h"
#include "noeud.h"
#include "arbre_classification.h"
#include <QApplication>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include "math.h"
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
// suite du projet :

// optimisation

    // - mettre indice de probabilité qui permet d'avoir des noeuds de taille 2-3 => plus rapide

// - poser 10% de questions aléatoires en plus de celles-présentes (pour apprendre)
// - gérer les erreurs possibles des personnes

// pb:
// - gestion des desctructions des vecteurs/ smart pointer
// - question sur fonction constante

QApplication a(argc, argv);
MainWindow w;
w.setWindowTitle("Akinator_v1");
w.setWindowIcon(QIcon("C:/Users/Alexandre/Pictures/akinator_mobile.png"));
w.setFixedSize(600,380);
w.show();

return a.exec();
}
