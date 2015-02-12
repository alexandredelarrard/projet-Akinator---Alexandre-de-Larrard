#ifndef PERSONNAGES_H
#define PERSONNAGES_H
#include <string>


class personnages
{
private:
    std::string id; // identifiant
    std::string prenom;
    std::string nom;
    std::string genre;//H/F
    std::string age;// 5 categories every 20 years or so
    std::string vivant; // 0= non 1 = oui
    std::string fiction; // 0= non 1 = oui
    std::string celebre; // 0= non 1 = oui
    std::string pays_origine;
    std::string pays_residence;
    std::string domaine_metier;// Cinema, Sport , etc.
    std::string metier;// Chanter, Acteur, Président, etc.
    std::string passe_metier;// Chanter Rock, Acteur de films,44 eme Président, etc.
    std::string proche; // 0= non 1 = oui
    std::string enfants; // la décennie de naissance du personnage
    std::string groupe; // le continent du personnage
    std::string ecran; // film serie dessin anime
    std::string religion; // It is =0 in the database up to now.

public:
    personnages();// constructor
    personnages(std::string,std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string);// constructor
    ~personnages();// destructor

    // getters and setters
    std::string getId();
    std::string getPrenom();
    std::string getNom();
    std::string getGenre();
    std::string getAge();
    std::string getVivant();
    std::string getFiction();
    std::string getCelebre();
    std::string getPaysOrigine();
    std::string getPaysResidence();
    std::string getDomaineMetier();
    std::string getMetier();
    std::string getPasseMetier();
    std::string getProche();
    std::string getEnfants();
    std::string getGroupe();
    std::string getEcran();
    std::string getReligion();

    void setId(std::string);
    void setPrenom(std::string);
    void setNom(std::string);
    void setGenre(std::string);
    void setAge(std::string);
    void setVivant(std::string);
    void setFiction(std::string);
    void setCelebre(std::string);
    void setPaysOrigine(std::string);
    void setPaysResidence(std::string);
    void setDomaineMetier(std::string);
    void setMetier(std::string);
    void setPasseMetier(std::string);
    void setProche(std::string);
    void setEnfants(std::string);
    void setGroupe(std::string);
    void setEcran(std::string);
    void setReligion(std::string);

};

#endif // PERSONNAGES_H
