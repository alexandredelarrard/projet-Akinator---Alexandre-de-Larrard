#include "noeud.h"
#include "basededonnees.h"

Noeud::Noeud()
{
}

Noeud::Noeud(std::string _variable, std::string _modalite_variable, int _nombre_individu, int _profondeur, int _identifiant_noeud)
{
    variable = _variable;
    modalite_variable = _modalite_variable;
    nombre_individu = _nombre_individu;
    profondeur= _profondeur;
    identifiant_noeud=_identifiant_noeud;
//    BaseDeDonnees bdd;
//    personnes = bdd.cash(_personnes);
}

int Noeud::getNombreIndividu()
{return nombre_individu;}

std::string Noeud::getVariableNoeud()
{return variable;}

std::string Noeud::getModaliteVariableNoeud()
{return modalite_variable;}

int Noeud::getProfondeurNoeud()
{return profondeur;}

int Noeud::getIdentifiantNoeud()
{return identifiant_noeud;}

//vector<personnages*> Noeud::getBddNoeud()
//{
//    return personnes;
//}

void Noeud::setVariableNoeud(std::string _variable)
{variable=_variable;}

void Noeud::setModaliteVariableNoeud(std::string _modalite_variable)
{modalite_variable=_modalite_variable;}

void Noeud::setNombreIndividu(int _nombre_individu)
{nombre_individu=_nombre_individu;}

void Noeud::setProfondeurNoeud(int _profondeur)
{profondeur = _profondeur;}

void Noeud::setIdentifiantNoeud(int _identifiant_noeud)
{identifiant_noeud=_identifiant_noeud;}

//void Noeud::setBddNoeud(vector<personnages *> _personnes)
//{
//    BaseDeDonnees bdd;
//    personnes = bdd.cash(_personnes);
//}

Noeud::~Noeud(){
}
