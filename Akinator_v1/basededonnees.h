#ifndef BASEDEDONNEES_H
#define BASEDEDONNEES_H
#include "personnages.h"
#include "reponses.h"
#include <iostream>
#include <fstream>
#include <vector>
#include<string>

using namespace std;

class BaseDeDonnees
{
public:
    BaseDeDonnees();// constructor
    ~BaseDeDonnees();//destructor

    vector <personnages*> GenererBaseDeDonnees();// initialize the database (output)
    vector <personnages*> cash(vector <personnages*> johnny);// recopy af a database(johnny) into another variable-> usefull for reinitialyzing the database in arbre_classification class
    vector <personnages*>  SupprimerIndividuOuiBDD(vector <personnages*>, std::string, std::string modalite); // suppress every people who said no to the question -> it remains the yes people
    vector <personnages*> SupprimerIndividuNonBDD(vector <personnages*> bdd, std::string variable, std::string modalite); // suppress every people who said yes to the question -> it remains the no people
    void AfficherPersonne(vector <personnages*>, unsigned int);
    void AfficherVariable(vector<std::string> variable);
    void AjouterReponse(personnages);
    vector <std::string> VecteurVariable(vector <personnages*> personnes, std::string );// give the whole vector of strings (output) of one variable (input) from the database (input)

};

#endif // BASEDEDONNEES_H
