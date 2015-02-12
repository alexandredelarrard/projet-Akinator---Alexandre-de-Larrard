#include "basededonnees.h"
#include "personnages.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

BaseDeDonnees::BaseDeDonnees()
{
}

// copy a database into another variable (vector of personnages)
vector <personnages*> BaseDeDonnees::cash(vector <personnages*> johnny)
{
    vector <personnages*> tableau_personnes;

    for(unsigned int i=0;i< johnny.size();i++) // commence à 1 car la première ligne représente les libellés des variables
    {
        personnages* personne = new personnages();
        personne->setId(johnny[i]->getId());
        personne->setPrenom(johnny[i]->getPrenom());
        personne->setNom(johnny[i]->getNom());
        personne->setGenre(johnny[i]->getGenre());
        personne->setAge(johnny[i]->getAge());
        personne->setVivant(johnny[i]->getVivant());
        personne->setFiction(johnny[i]->getFiction());
        personne->setCelebre(johnny[i]->getCelebre());
        personne->setPaysOrigine(johnny[i]->getPaysOrigine());
        personne->setPaysResidence(johnny[i]->getPaysResidence());
        personne->setDomaineMetier(johnny[i]->getDomaineMetier());
        personne->setMetier(johnny[i]->getMetier());
        personne->setPasseMetier(johnny[i]->getPasseMetier());
        personne->setProche(johnny[i]->getProche());
        personne->setEnfants(johnny[i]->getEnfants());
        personne->setGroupe(johnny[i]->getGroupe());
        personne->setEcran(johnny[i]->getEcran());
        personne->setReligion(johnny[i]->getReligion());

        tableau_personnes.push_back(personne);
    }
    return tableau_personnes;
}

vector <personnages*> BaseDeDonnees::GenererBaseDeDonnees(){

    // ouverture de la bdd akinator en .txt et stockage dans un vecteur de personnes
    fstream fichier_bdd("C:/Qt/bdd_akinator.txt");
    vector <string> monTableau;
    vector <personnages*> tableau_personnes;

    if ( !fichier_bdd )
    {cout << "fichier inexistant"<< endl;}
    else
    {
        while( !fichier_bdd.eof() )
        {

            monTableau.push_back("");//creation d'une ligne vide

            getline(fichier_bdd, monTableau.back());//lecture d'une ligne du fichier

            int ligne = monTableau.size() - 1;//je recupere la taille du tableau (-1 pour la ligne 0)

            if(monTableau[ligne].empty())//si la ligne est vide
                monTableau.pop_back();//on la retire du tableau
        }

        fichier_bdd.close();
    }

    for(unsigned int i=1;i< monTableau.size();i++) // commence à 1 car la première ligne représente les libellés des variables
    {
        personnages* personne = new personnages();

        int posPoint1= monTableau[i].find(';',0);// à chaque ; on arrete de chercher des caractères, on retient la position du curseur et on passe au prochain point
        int posPoint2= monTableau[i].find(';',posPoint1+1);
        int posPoint3= monTableau[i].find(';',posPoint2+1);
        int posPoint4= monTableau[i].find(';',posPoint3+1);
        int posPoint5= monTableau[i].find(';',posPoint4+1);
        int posPoint6= monTableau[i].find(';',posPoint5+1);
        int posPoint7= monTableau[i].find(';',posPoint6+1);
        int posPoint8= monTableau[i].find(';',posPoint7+1);
        int posPoint9= monTableau[i].find(';',posPoint8+1);
        int posPoint10= monTableau[i].find(';',posPoint9+1);
        int posPoint11= monTableau[i].find(';',posPoint10+1);
        int posPoint12= monTableau[i].find(';',posPoint11+1);
        int posPoint13= monTableau[i].find(';',posPoint12+1);
        int posPoint14= monTableau[i].find(';',posPoint13+1);
        int posPoint15= monTableau[i].find(';',posPoint14+1);
        int posPoint16= monTableau[i].find(';',posPoint15+1);
        int posPoint17= monTableau[i].find(';',posPoint16+1);
        int posPoint18= monTableau[i].find(';',posPoint17+1);

        personne->setId((monTableau[i].substr(0,posPoint1)));
        personne->setPrenom(monTableau[i].substr(posPoint1+1,posPoint2-(posPoint1+1)));
        personne->setNom(monTableau[i].substr(posPoint2+1,posPoint3-(posPoint2+1)));
        personne->setGenre(monTableau[i].substr(posPoint3+1,posPoint4-(posPoint3+1)));
        personne->setAge((monTableau[i].substr(posPoint4+1,posPoint5-(posPoint4+1))));
        personne->setVivant((monTableau[i].substr(posPoint5+1,posPoint6-(posPoint5+1))));
        personne->setFiction((monTableau[i].substr(posPoint6+1,posPoint7-(posPoint6+1))));
        personne->setCelebre((monTableau[i].substr(posPoint7+1,posPoint8-(posPoint7+1))));
        personne->setPaysOrigine(monTableau[i].substr(posPoint8+1,posPoint9-(posPoint8+1)));
        personne->setPaysResidence(monTableau[i].substr(posPoint9+1,posPoint10-(posPoint9+1)));
        personne->setDomaineMetier(monTableau[i].substr(posPoint10+1,posPoint11-(posPoint10+1)));
        personne->setMetier(monTableau[i].substr(posPoint11+1,posPoint12-(posPoint11+1)));
        personne->setPasseMetier(monTableau[i].substr(posPoint12+1,posPoint13-(posPoint12+1)));
        personne->setProche((monTableau[i].substr(posPoint13+1,posPoint14-(posPoint13+1))));
        personne->setEnfants((monTableau[i].substr(posPoint14+1,posPoint15-(posPoint14+1))));
        personne->setGroupe(monTableau[i].substr(posPoint15+1,posPoint16-(posPoint15+1)));
        personne->setEcran(monTableau[i].substr(posPoint16+1,posPoint17-(posPoint16+1)));
        personne->setReligion(monTableau[i].substr(posPoint17+1,posPoint18-(posPoint17+1)));

        tableau_personnes.push_back(personne);
    }

    return tableau_personnes;
}

vector <personnages*> BaseDeDonnees::SupprimerIndividuNonBDD(vector <personnages*> bdd, std::string variable, std::string modalite)
{

        if(variable =="Nom")
        {
            vector<personnages*>::iterator it;
            for ( it =  bdd.begin(); it !=  bdd.end(); )
            {
            if((*it)->getNom() == modalite)
            {delete * it;
                it = bdd.erase(it);
            }
            else{
                ++it;
            }}
        }

        if(variable =="Prenom")
        {
            vector<personnages*>::iterator it;
            for ( it =  bdd.begin(); it !=  bdd.end(); )
            {
            if((*it)->getPrenom() == modalite)
            {delete * it;
                 it = bdd.erase(it);
            }
            else{
                ++it;
            }}
        }

        if(variable =="Genre")
        {vector<personnages*>::iterator it;


            for ( it =  bdd.begin(); it !=  bdd.end(); )
            {
            if((*it)->getGenre() == modalite)
                 {
                    delete * it;
                    it = bdd.erase(it);

                }
            else{
               ++it;
             }
            }
        }

        if(variable =="Vivant")
        {vector<personnages*>::iterator it;
            for ( it =  bdd.begin(); it !=  bdd.end(); )
            {
           //int moda = atoi(modalite.c_str());
            if((*it)->getVivant() == modalite)
            {delete * it;
                 it = bdd.erase(it);
            }
            else{
                ++it;
            }}
        }

        if(variable =="Celebre")
        {vector<personnages*>::iterator it;
            for ( it =  bdd.begin(); it !=  bdd.end(); )
            {
            if((*it)->getCelebre() == modalite)
            {delete * it;
                 it = bdd.erase(it);
            }
            else{
                ++it;
            }}
        }

        if(variable =="Fiction")
        {vector<personnages*>::iterator it;
            for ( it =  bdd.begin(); it !=  bdd.end(); )
            {
            if((*it)->getFiction() == modalite)
            {delete * it;
                  it = bdd.erase(it);
            }
            else{
                ++it;
            }}
        }

        if(variable =="PaysOrigine")
        {vector<personnages*>::iterator it;
            for ( it =  bdd.begin(); it !=  bdd.end(); )
            {
            if((*it)->getPaysOrigine() == modalite)
            {delete * it;
                 it = bdd.erase(it);
            }
            else{
                ++it;
            }}
        }

        if(variable =="PaysResidence")
        {vector<personnages*>::iterator it;
            for ( it =  bdd.begin(); it !=  bdd.end(); )
            {
            if((*it)->getPaysResidence() == modalite)
            {delete * it;
                 it = bdd.erase(it);
            }
            else{
                ++it;
            }}
        }

        if(variable =="DomaineMetier")
        {vector<personnages*>::iterator it;
            for ( it =  bdd.begin(); it !=  bdd.end(); )
            {
            if((*it)->getDomaineMetier() == modalite)
            {delete * it;
                 it = bdd.erase(it);
            }
            else{
                ++it;
            }}
        }

        if(variable =="Metier")
        {vector<personnages*>::iterator it;
            for ( it =  bdd.begin(); it !=  bdd.end(); )
            {
            if((*it)->getMetier() == modalite)
            {delete * it;
                 it = bdd.erase(it);
            }
            else{
                ++it;
            }}
        }

        if(variable =="PasseMetier")
        {vector<personnages*>::iterator it;
            for ( it =  bdd.begin(); it !=  bdd.end(); )
            {
            if((*it)->getPasseMetier() == modalite)
            {delete * it;
                 it = bdd.erase(it);
            }
            else{
                ++it;
            }}
        }

        if(variable =="Proche")
        {vector<personnages*>::iterator it;
            for ( it =  bdd.begin(); it !=  bdd.end(); )
            {
            if((*it)->getProche() == modalite)
            {delete * it;
                 it = bdd.erase(it);
            }
            else{
                ++it;
            }}
        }

        if(variable =="Enfants")
        {vector<personnages*>::iterator it;
            for ( it =  bdd.begin(); it !=  bdd.end(); )
            {
            if((*it)->getEnfants() == modalite)
            {delete * it;
                it = bdd.erase(it);
            }
            else{
                ++it;
            }}
        }

        if(variable =="Groupe")
        {vector<personnages*>::iterator it;
            for ( it =  bdd.begin(); it !=  bdd.end(); )
            {
            if((*it)->getGroupe() == modalite)
            {delete * it;
                 it = bdd.erase(it);
            }
            else{
                ++it;
            }}
        }

        if(variable =="Ecran")
        {vector<personnages*>::iterator it;
            for ( it =  bdd.begin(); it !=  bdd.end(); )
            {
            if((*it)->getEcran() == modalite)
            {delete * it;
                 it = bdd.erase(it);
            }
            else{
                ++it;
            }}
        }

        if(variable =="Religion")
        {vector<personnages*>::iterator it;
            for ( it =  bdd.begin(); it !=  bdd.end(); )
            {
            if((*it)->getReligion() == modalite)
            {delete * it;
                 it = bdd.erase(it);
            }
            else{
                ++it;
            }}
        }

        if(variable =="Age")
        {vector<personnages*>::iterator it;
            for ( it =  bdd.begin(); it !=  bdd.end(); )
            {
            if((*it)->getAge() == modalite)
            {delete * it;
                 it = bdd.erase(it);
            }
            else{
                ++it;
            }}
        }

        else
        {
            //cout << "sortie" <<endl;
        }

        return bdd;
}

vector <personnages*> BaseDeDonnees::SupprimerIndividuOuiBDD(vector <personnages*> bdd, std::string variable, std::string modalite)
{

        if(variable =="Nom")
        {vector<personnages*>::iterator it;
            for ( it =  bdd.begin(); it !=  bdd.end(); )
            {
            if((*it)->getNom() != modalite)
            {delete * it;
                it = bdd.erase(it);
            }
            else{
                ++it;
            }
            }
        }

        if(variable =="Prenom")
        {vector<personnages*>::iterator it;
            for ( it =  bdd.begin(); it !=  bdd.end(); )
            {
            if((*it)->getPrenom() != modalite)
            {delete * it;
                 it = bdd.erase(it);
            }
            else{
                ++it;
            }}
        }

        if(variable =="Genre")
        {vector<personnages*>::iterator it;
            for ( it =  bdd.begin(); it !=  bdd.end(); )
            {
            if((*it)->getGenre() != modalite)
            {delete * it;
                 it = bdd.erase(it);
            }
            else{
                ++it;
            }
        }}

        if(variable =="Vivant")
        {vector<personnages*>::iterator it;
            for ( it =  bdd.begin(); it !=  bdd.end(); )
            {
           //int moda = atoi(modalite.c_str());
            if((*it)->getVivant() != modalite)
            {delete * it;
                 it = bdd.erase(it);
            }
            else{
                ++it;
            }}
        }

        if(variable =="Celebre")
        {vector<personnages*>::iterator it;
            for ( it =  bdd.begin(); it !=  bdd.end(); )
            {
            if((*it)->getCelebre() != modalite)
            {delete * it;
                 it = bdd.erase(it);
            }
            else{
                ++it;
            }}
        }

        if(variable =="Fiction")
        {vector<personnages*>::iterator it;
            for ( it =  bdd.begin(); it !=  bdd.end(); )
            {
            if((*it)->getFiction() != modalite)
            {delete * it;
                  it = bdd.erase(it);
            }
            else{
                ++it;
            }}
        }

        if(variable =="PaysOrigine")
        {vector<personnages*>::iterator it;
            for ( it =  bdd.begin(); it !=  bdd.end(); )
            {
            if((*it)->getPaysOrigine() != modalite)
            {delete * it;
                 it = bdd.erase(it);
            }
            else{
                ++it;
            }}
        }

        if(variable =="PaysResidence")
        {vector<personnages*>::iterator it;
            for ( it =  bdd.begin(); it !=  bdd.end(); )
            {
            if((*it)->getPaysResidence() != modalite)
            {delete * it;
                 it = bdd.erase(it);
            }
            else{
                ++it;
            }}
        }

        if(variable =="DomaineMetier")
        {vector<personnages*>::iterator it;
            for ( it =  bdd.begin(); it !=  bdd.end(); )
            {
            if((*it)->getDomaineMetier() != modalite)
            {delete * it;
                 it = bdd.erase(it);
            }
            else{
                ++it;
            }}
        }

        if(variable =="Metier")
        {vector<personnages*>::iterator it;
            for ( it =  bdd.begin(); it !=  bdd.end(); )
            {
            if((*it)->getMetier() != modalite)
            {delete * it;
                 it = bdd.erase(it);
            }
            else{
                ++it;
            }}
        }

        if(variable =="PasseMetier")
        {vector<personnages*>::iterator it;
            for ( it =  bdd.begin(); it !=  bdd.end(); )
            {
            if((*it)->getPasseMetier() != modalite)
            {delete * it;
                 it = bdd.erase(it);
            }
            else{
                ++it;
            }}
        }

        if(variable =="Proche")
        {vector<personnages*>::iterator it;
            for ( it =  bdd.begin(); it !=  bdd.end(); )
            {
            if((*it)->getProche() != modalite)
            {delete * it;
                 it = bdd.erase(it);
            }
            else{
                ++it;
            }}
        }

        if(variable =="Enfants")
        {vector<personnages*>::iterator it;
            for ( it =  bdd.begin(); it !=  bdd.end(); )
            {
            if((*it)->getEnfants() != modalite)
            {delete * it;
                it = bdd.erase(it);
            }
            else{
                ++it;
            }}
        }

        if(variable =="Groupe")
        {vector<personnages*>::iterator it;
            for ( it =  bdd.begin(); it !=  bdd.end(); )
            {
            if((*it)->getGroupe() != modalite)
            {delete * it;
                 it = bdd.erase(it);
            }
            else{
                ++it;
            }}
        }

        if(variable =="Ecran")
        {vector<personnages*>::iterator it;
            for ( it =  bdd.begin(); it !=  bdd.end(); )
            {
            if((*it)->getEcran() != modalite)
            {delete * it;
                 it = bdd.erase(it);
            }
            else{
                ++it;
            }}
        }

        if(variable =="Religion")
        {vector<personnages*>::iterator it;
            for ( it =  bdd.begin(); it !=  bdd.end(); )
            {
            if((*it)->getReligion() != modalite)
            {delete * it;
                 it = bdd.erase(it);
            }
            else{
                ++it;
            }}
        }

        if(variable =="Age")
        {vector<personnages*>::iterator it;
            for ( it =  bdd.begin(); it !=  bdd.end(); )
            {
            if((*it)->getAge() != modalite)
            {delete * it;
                 it = bdd.erase(it);
            }
            else{
                ++it;
            }}
        }

        else
        {
            //cout << "sortie" <<endl;
        }

return bdd;
}

vector <std::string> BaseDeDonnees::VecteurVariable(vector <personnages*> personnes, std::string variable)
{
    vector <std::string> vecteur;

        //return the vector from the database, linked to "variable"
        if(variable == "Id"){for(unsigned int j=0;j<personnes.size();j++){vecteur.push_back((personnes[j]->getId()));}}
        if(variable == "Prenom"){for(unsigned int j=0;j<personnes.size();j++){vecteur.push_back(personnes[j]->getPrenom());}}
        if(variable == "Nom"){for(unsigned int j=0;j<personnes.size();j++){vecteur.push_back(personnes[j]->getNom());}}
        if(variable == "Genre"){for(unsigned int j=0;j<personnes.size();j++){vecteur.push_back(personnes[j]->getGenre());}}
        if(variable == "Age"){for(unsigned int j=0;j<personnes.size();j++){vecteur.push_back((personnes[j]->getAge()));}}
        if(variable == "Vivant"){for(unsigned int j=0;j<personnes.size();j++){vecteur.push_back((personnes[j]->getVivant()));}}
        if(variable == "Fiction"){for(unsigned int j=0;j<personnes.size();j++){vecteur.push_back((personnes[j]->getFiction()));}}
        if(variable == "Celebre"){for(unsigned int j=0;j<personnes.size();j++){vecteur.push_back(personnes[j]->getCelebre());}}
        if(variable == "PaysOrigine"){for(unsigned int j=0;j<personnes.size();j++){vecteur.push_back(personnes[j]->getPaysOrigine());}}
        if(variable == "PaysResidence"){for(unsigned int j=0;j<personnes.size();j++){vecteur.push_back(personnes[j]->getPaysResidence());}}
        if(variable == "DomaineMetier"){for(unsigned int j=0;j<personnes.size();j++){vecteur.push_back(personnes[j]->getDomaineMetier());}}
        if(variable == "Metier"){for(unsigned int j=0;j<personnes.size();j++){vecteur.push_back(personnes[j]->getMetier());}}
        if(variable == "PasseMetier"){for(unsigned int j=0;j<personnes.size();j++){vecteur.push_back(personnes[j]->getPasseMetier());}}
        if(variable == "Proche"){for(unsigned int j=0;j<personnes.size();j++){vecteur.push_back(personnes[j]->getProche());}}
        if(variable == "Enfants"){for(unsigned int j=0;j<personnes.size();j++){vecteur.push_back(personnes[j]->getEnfants());}}
        if(variable == "Groupe"){for(unsigned int j=0;j<personnes.size();j++){vecteur.push_back(personnes[j]->getGroupe());}}
        if(variable == "Ecran"){for(unsigned int j=0;j<personnes.size();j++){vecteur.push_back(personnes[j]->getEcran());}}
        if(variable == "Religion"){for(unsigned int j=0;j<personnes.size();j++){vecteur.push_back(personnes[j]->getReligion());}}

    return vecteur;

}


void BaseDeDonnees::AfficherPersonne(vector <personnages*> personnes, unsigned int i)
{ // display every caractéristics of a personne -> used to check if database was well loaded
    if(i >= (personnes.size()))
    {
        cout << "taille de la base depassee" << endl;
    }

    else{
    cout<<  "\n"
            "ID: " << personnes[i]->getId() << "\n"
            "Prenom: " << personnes[i]->getPrenom() << "\n"
            "Nom: " << personnes[i]->getNom() << "\n"
            "Genre: " << personnes[i]->getGenre() << "\n"
            "Age: " << personnes[i]->getAge() << "\n"
            "Vivant (oui=1/non=0): " << personnes[i]->getVivant() << "\n"
            "Fiction (oui=1/non=0): " << personnes[i]->getFiction() << "\n"
            "Celebre (oui=1/non=0): " << personnes[i]->getCelebre() << "\n"
            "Pays d'Origine: " << personnes[i]->getPaysOrigine() << "\n"
            "Pays de Residence: " << personnes[i]->getPaysResidence() << "\n"
            "Domaine metier: " << personnes[i]->getDomaineMetier() << "\n"
            "Metier: " << personnes[i]->getMetier() << "\n"
            "Metier passe: " << personnes[i]->getPasseMetier() << "\n"
            "Proche : " << personnes[i]->getProche() << "\n"
            "Nombre d'enfants: " << personnes[i]->getEnfants() << "\n"
            "Appartenance a un groupe: " << personnes[i]->getGroupe() << "\n"
            "Apparu a l'ecran: " << personnes[i]->getEcran() << "\n"
            "Religion: " << personnes[i]->getReligion() << "\n" << endl;

    }
}

void BaseDeDonnees::AjouterReponse(personnages reponse)
{
    ofstream fichier_bdd;
    fichier_bdd.open("C:/Qt/bdd_akinator.txt", std::ios::app);

    std::string line =";" + reponse.getPrenom() + ";"+reponse.getNom() + ";" + reponse.getGenre() + ";" + reponse.getAge()+ ";" + reponse.getVivant() + ";" + reponse.getFiction() + ";" + reponse.getCelebre() +";" + reponse.getPaysOrigine() + ";" + reponse.getPaysResidence() + ";" + reponse.getDomaineMetier()+ ";" + reponse.getMetier() + ";" + reponse.getPasseMetier() + ";"+  reponse.getProche() + ";" + reponse.getEnfants() + ";" + reponse.getGroupe() + ";" + reponse.getEcran() +";" + reponse.getReligion();
    fichier_bdd << line << std::endl;

    fichier_bdd.close();

}


void BaseDeDonnees::AfficherVariable(vector<std::string> variable)
{
    for(unsigned int i=0; i<variable.size();i++)
    {
        cout << variable[i] << endl;
    }
}

BaseDeDonnees::~BaseDeDonnees(){}
