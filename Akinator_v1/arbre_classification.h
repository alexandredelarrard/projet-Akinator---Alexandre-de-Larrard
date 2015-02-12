#ifndef ARBRE_CLASSIFICATION_H
#define ARBRE_CLASSIFICATION_H
#include "questions.h"
#include "personnages.h"
#include "noeud.h"
#include <string.h>
#include <vector>

using namespace std;

class Arbre_classification
{
public:
    Arbre_classification();// constructor
    ~Arbre_classification();// desctructor

    Noeud* InitialiserArbre(vector<personnages*> personnes);// create the root of the tree -> always the question: "are you a man?"
    vector<Noeud*> ConstructionArbre(vector<personnages*> personnes); // create the whole tree(output) from a database (input)
    vector<Noeud*> CreationNoeudsFils(vector<personnages*> personnes, Noeud* pere, std::string variable_etudiee);// create two nods (sons) for a father (input: pere)

    vector<personnages*> Restriction_bdd(int ieme_node, vector<Noeud*> arbre, vector<personnages*> personnes);// erase people from the database (input: personnes), with the backward method
    std::string SelectVariable(vector<personnages*> personnes,Noeud* pere); // give the best variable from a father, which enables to create two nods sons. The best variable is close to the best split of population between those two nods (sons)
    double BestSplit(int taille_echantillon, vector<Noeud*> noeud);

    bool test_noeud_terminal();// if the node has less than x people (node->getnombre individus) we won't create  any sons for it
    int GetIndiceNode(vector<Noeud*> arbre, int getIdentifiantNoeud);// enable to make the link between indice and Identifiant Noeud.
                                                                     // as there are terminal nods, the indice(ieme node in the tree) differ from the identifiant Noeud (2*identifiant noeud(père) for node son Yes, 2*identifiant noeud(père) +1 for node son No)
                                                                     // Another solution would be to create nodes At Null.
    int nombre_modalite(vector<std::string>);// Number of modality for a variable
    vector<std::string> modalites_variables(vector<std::string>);// output: vector  of modalities for input: a variable
    bool DansTableau(vector<std::string>, std::string);// output: true false say if a modality(input string) is already in a vector of strings (input)

};

#endif // ARBRE_CLASSIFICATION_H
