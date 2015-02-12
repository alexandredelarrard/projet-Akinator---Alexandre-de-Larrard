#include "personnages.h"
#include <string>

personnages::personnages()
{
}

personnages::personnages(std::string id,std::string prenom, std::string nom, std::string genre, std::string age, std::string vivant, std::string fiction,std::string celebre, std::string pays_origine, std::string pays_residence, std::string domaine_metier, std::string metier,
                         std::string passe_metier, std::string proche, std::string enfants, std::string groupe, std::string ecran, std::string religion)
{
    id = id;
    prenom = prenom;
    nom = nom;
    genre=genre;
    age = age;
    vivant = vivant;
    fiction=fiction;
    celebre=celebre;
    pays_origine=pays_origine;
    pays_residence=pays_residence;
    metier =metier;
    domaine_metier=domaine_metier;
    passe_metier=passe_metier;
    proche=proche;
    enfants=enfants;
    groupe=groupe;
    ecran=ecran;
    religion=religion;
}

std::string personnages::getId(){ return id;}
std::string personnages::getPrenom(){ return prenom;}
std::string personnages::getNom(){ return nom;}
std::string personnages::getGenre(){ return genre;}
std::string personnages::getAge(){return age;}
std::string personnages::getVivant(){return vivant;}
std::string personnages::getFiction(){return fiction;}
std::string personnages::getCelebre(){return celebre;}
std::string personnages::getPaysOrigine(){return pays_origine;}
std::string personnages::getPaysResidence(){return pays_residence;}
std::string personnages::getDomaineMetier(){return domaine_metier;}
std::string personnages::getMetier(){return metier;}
std::string personnages::getPasseMetier(){return passe_metier;}
std::string personnages::getProche(){return proche;}
std::string personnages::getEnfants(){return enfants;}
std::string personnages::getGroupe(){return groupe;}
std::string personnages::getEcran(){return ecran;}
std::string personnages::getReligion(){return religion;}


void personnages::setId(std::string _id){ id= _id;}
void personnages::setPrenom(std::string _prenom){prenom = _prenom;}
void personnages::setNom(std::string _nom){ nom = _nom;}
void personnages::setGenre(std::string _genre){genre = _genre;}
void personnages::setAge(std::string _age){age = _age;}
void personnages::setVivant(std::string _vivant){ vivant = _vivant;}
void personnages::setFiction(std::string _fiction){ fiction = _fiction;}
void personnages::setCelebre(std::string _celebre){ celebre = _celebre;}
void personnages::setPaysOrigine(std::string _pays_origine){pays_origine = _pays_origine;}
void personnages::setPaysResidence(std::string _pays_residence){ pays_residence = _pays_residence;}
void personnages::setDomaineMetier(std::string _domaine_metier){ domaine_metier = _domaine_metier;}
void personnages::setMetier(std::string _metier){metier=_metier;}
void personnages::setPasseMetier(std::string _passe_metier){ passe_metier = _passe_metier;}
void personnages::setProche(std::string _proche){ proche = _proche;}
void personnages::setEnfants(std::string _enfants){ enfants = _enfants;}
void personnages::setGroupe(std::string _groupe){ groupe = _groupe;}
void personnages::setEcran(std::string _ecran){ ecran = _ecran;}
void personnages::setReligion(std::string _religion){ religion = _religion;}

personnages::~personnages(){
}
