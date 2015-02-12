#ifndef NOEUD_H
#define NOEUD_H
#include <string.h>
#include "personnages.h"
#include <vector>
#include <string>

using namespace std;

class Noeud
{
private:
    std::string variable;
    std::string modalite_variable;
    int nombre_individu;
    int profondeur;
    int identifiant_noeud;
   //vector<personnages*> personnes;

public:// a node has : a variable (genre, age, prenom, ...) a modality (M, F for genre), a number of people who has this modality from the database
    // a deepness, an id (usefull to know whose son/father is every node.
    Noeud();// constructor
    Noeud(std::string variable, std::string modalite_variable, int  nombre_individu, int profondeur, int identifiant_noeud);// constructor
    ~Noeud();// destructor

    //getters and setters
    std::string getVariableNoeud();
    std::string getModaliteVariableNoeud();
    int getNombreIndividu();
    int getProfondeurNoeud();
    int getIdentifiantNoeud();
   // vector<personnages*> getBddNoeud();

    void setVariableNoeud(std::string variable);
    void setModaliteVariableNoeud(std::string modalite_variable);
    void setNombreIndividu(int nombre_individu);
    void setProfondeurNoeud(int profondeur);
    void setIdentifiantNoeud(int identifiant_noeud);
   // void setBddNoeud(vector<personnages*> personnes);

};

#endif // NOEUD_H
