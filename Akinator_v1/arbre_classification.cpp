#include "arbre_classification.h"
#include "basededonnees.h"
#include "questions.h"
#include "personnages.h"
#include "noeud.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <sstream>

int Arbre_classification::GetIndiceNode(vector<Noeud*> arbre, int getIdentifiantNoeud)
{
    int indice =0;
    int i = arbre.size();
    while(i>=0)
    {
        if(arbre[indice]->getIdentifiantNoeud() == getIdentifiantNoeud)
        {
            i=0;
            return indice;
        }
        indice ++;
        i--;
    }
}

Arbre_classification::Arbre_classification()
{
}

Noeud* Arbre_classification::InitialiserArbre(vector<personnages*> personnes)
{
    int taille_bdd = personnes.size();

    // initialisaton de l'arbre par la première question sur le genre de la personne
    Noeud* noeud_initial= new Noeud();

    noeud_initial->setVariableNoeud("Genre");
    noeud_initial->setModaliteVariableNoeud("M");
    noeud_initial->setNombreIndividu(taille_bdd);
    noeud_initial->setProfondeurNoeud(0);
    noeud_initial->setIdentifiantNoeud(1);

    return noeud_initial;
}

vector<Noeud*> Arbre_classification::ConstructionArbre(vector<personnages*> personnes)
{
    vector<Noeud*> arbre;
    Noeud* initialisation = InitialiserArbre(personnes);
    std::string selected_var;
    int tampon= 2;
    int ieme_node=1;
    BaseDeDonnees bdd;

    vector<personnages*> personnes_bdd_initiale = bdd.cash(personnes);

    // initialisation with root node gender
    arbre.push_back(initialisation);

    vector<Noeud*> creer_fils = CreationNoeudsFils(personnes, arbre[0], "Genre");

    for(unsigned int j =0; j<creer_fils.size(); j++)
    {
        arbre.push_back(creer_fils[j]);
    }

    ///////////////////////////////////boucle creation arbre/////////////////////////////////////////////////
    //if every node is terminal, we end the while, else, there are nodes to add
    while(tampon>0)
    {
        // for each new iteration, we come from the original bdd and with backward method
        // we reduce it thanks to its father features.

        personnes = bdd.cash(personnes_bdd_initiale);
        personnes= Restriction_bdd(ieme_node,arbre, personnes);

        // if the node is terminal (< x people) we keep going
        if(personnes.size() <=1)
        {
            tampon = tampon-1;
            ieme_node = ieme_node+1;
        }
        // else, we create two sons for a non terminal father
        else
        {
            int k = ieme_node;
            selected_var = SelectVariable(personnes, arbre[k]);
            vector<Noeud*> creer_fils = CreationNoeudsFils(personnes, arbre[k], selected_var);

            for(unsigned int j =0; j<creer_fils.size(); j++)
            {
                arbre.push_back(creer_fils[j]);
            }
            tampon = tampon +1;
            ieme_node =ieme_node +1;
        }
    }

    for(unsigned int i=0; i<arbre.size(); i++ )
    {
        cout << " variable = "<< arbre[i]->getVariableNoeud() << "   nombre individus = " << arbre[i]-> getNombreIndividu() << "modalite " << i+1 << " = " << arbre[i]->getModaliteVariableNoeud() << "  noeud numero " << arbre[i]->getIdentifiantNoeud()<< "  profondeur numero " << arbre[i]->getProfondeurNoeud()<< endl;
    }

    return arbre;
}


 vector<personnages*> Arbre_classification::Restriction_bdd(int ieme_node, vector<Noeud*> arbre, vector<personnages*> personnes)
 {
      BaseDeDonnees bdd;
      int indice = arbre[ieme_node]->getIdentifiantNoeud();

      // backward method,on commence au dernier noeud et on remonte de père en père.
     while(indice >1)
     {
         if(indice%2 == 1)//si indice est paire, alors c'est un oui pour la question du père, sinon c'est un non.
         {//non
             int x= GetIndiceNode(arbre,indice);
             personnes= bdd.SupprimerIndividuNonBDD(personnes, arbre[x]->getVariableNoeud(),arbre[x]->getModaliteVariableNoeud());
             indice = (indice-1)/2;
         }
         if(indice%2 == 0)
         {//oui
             int x= GetIndiceNode(arbre,indice);
             personnes= bdd.SupprimerIndividuOuiBDD(personnes, arbre[x]->getVariableNoeud(),arbre[x]->getModaliteVariableNoeud());
             indice = indice/2;
         }
     }
    return personnes;
 }

vector<Noeud*> Arbre_classification::CreationNoeudsFils(vector<personnages*> personnes, Noeud* pere, std::string variable_etudiee)
{
    int nombre_modalites_variable_etudiee;
    vector<std::string> modalites_sortie_variable_etudiee;

    int profondeur_fils = pere->getProfondeurNoeud() +1;

    BaseDeDonnees bdd;

    vector<std::string> vecteur_etudie = bdd.VecteurVariable(personnes,variable_etudiee);

    modalites_sortie_variable_etudiee = modalites_variables(vecteur_etudie);
    nombre_modalites_variable_etudiee = modalites_sortie_variable_etudiee.size();

         vector<Noeud*> fils;
         double tampon = 1;
         std::string modalite_retenue;
         int nombre_retenu;

        for(int i=0; i<nombre_modalites_variable_etudiee; i++)
        {
            int nombre_individus=0;


            for(unsigned int j=0; j< personnes.size(); j++)
            {// we compt the number of people who have  the modality i equal to the studyed modality
                if(bdd.VecteurVariable(personnes, variable_etudiee)[j] == modalites_sortie_variable_etudiee[i])
                {nombre_individus++;}
            }
            // we select the node which has the population closest to half of the size of the database
            if(tampon>fabs(((double)nombre_individus/(double)personnes.size())-0.5))
            {
                tampon = fabs(((double)nombre_individus/(double)personnes.size())-0.5);
                nombre_retenu = nombre_individus;
                modalite_retenue = modalites_sortie_variable_etudiee[i];
            }

        }
        // then we add them to the vector of nods: fils
         fils.push_back(new Noeud(variable_etudiee, modalite_retenue, nombre_retenu, profondeur_fils, 2*(pere->getIdentifiantNoeud())));
         fils.push_back(new Noeud(variable_etudiee, modalite_retenue, personnes.size() - nombre_retenu, profondeur_fils, 2*(pere->getIdentifiantNoeud()) +1 ));
        return fils;

}

std::string Arbre_classification::SelectVariable(vector<personnages*> personnes, Noeud* pere)
{
    vector<std::string> variables_names;
    double tampon=1;
    int numero_variable = 0;

    variables_names.push_back("Prenom");
    variables_names.push_back("Nom");
    variables_names.push_back("Genre");
    variables_names.push_back("Vivant");
    variables_names.push_back("Fiction");
    variables_names.push_back("Celebre");
    variables_names.push_back("PaysOrigine");
    variables_names.push_back("PaysResidence");
    variables_names.push_back("DomaineMetier");
    variables_names.push_back("Metier");
    variables_names.push_back("PasseMetier");
    variables_names.push_back("Proche");
    variables_names.push_back("Enfants");
    variables_names.push_back("Groupe");
    variables_names.push_back("Ecran");
    variables_names.push_back("Religion");
    variables_names.push_back("Age");

    vector<Noeud*> creer_fils;

    // test for the best variable with the closest split of half of the database size
    for(unsigned int i=0; i< variables_names.size(); i++)
    {
        creer_fils  = CreationNoeudsFils(personnes, pere, variables_names[i]);

        if(tampon> fabs(BestSplit(personnes.size(),creer_fils)-0.5))
        {
            tampon = fabs(BestSplit(personnes.size(),creer_fils)-0.5);
            numero_variable = i;
        }

        // Then suppress them because they where only used to detect the best variable.
        for(vector<Noeud*>::iterator it = creer_fils.begin(); it< creer_fils.end(); it++)
        {
            delete(*it);
        }
    }
    cout << "variable selectionnee " << variables_names[numero_variable] <<endl;
    return variables_names[numero_variable];
}

double Arbre_classification::BestSplit(int taille_echantillon, vector<Noeud*> noeud)
{
    return (double)noeud[0]->getNombreIndividu()/(double)taille_echantillon;
}

int Arbre_classification::nombre_modalite(vector<std::string> variable)
{

    if(variable.size()==0)
    {
        cerr<<  "erreur totale, pas de variable" << endl;
    }

    vector<std::string> modalites;
    unsigned int i=1;
    modalites.push_back(variable[0]);
    int nombre_modalite=1;

    while(i<variable.size())
    {
        if(DansTableau(modalites, variable[i])==false)
        {
            nombre_modalite++;
        }
        i++;
    }
    return nombre_modalite;
}

vector<std::string> Arbre_classification::modalites_variables(vector<std::string> variable)
{
    vector<std::string> modalites;
    modalites.push_back(variable[0]);
    unsigned int i=1;

    if(variable.size()==0)
    {// si le tableau de variable est vide, alors une erreur s'est produite
        cerr<<  "erreur totale, pas de variable" << endl;
    }

    while(i<variable.size())
    {
        if(DansTableau(modalites, variable[i])==false)
        { // si le i eme element de la variable n'est pas dans le tableau des modalites, alors on le rajoute
            modalites.push_back(variable[i]);
        }
        i++;
    }

    return modalites;
}

bool Arbre_classification::DansTableau(vector<std::string> modalites, std::string variable)
{
    // permet de savoir si l'element variable est dans le vecteur de string
    bool reponse= false;

    for(unsigned int j=0; j<modalites.size();j++)
    {
        if(modalites[j]==variable)
        {
            reponse = true;
        }
    }
    return reponse;
}

Arbre_classification::~Arbre_classification()
{
}
