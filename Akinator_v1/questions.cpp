#include "questions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Questions::Questions()
{
}

Questions:: Questions(std::string variable, std::string restriction)
{
    variable = variable;
    restriction = restriction;
}

std::string Questions::getVariable()
{
    return variable;
}

std::string Questions::getRestriction()
{
    return restriction;
}

void Questions::setVariable(std::string _variable)
{
    variable = _variable;
}

void Questions::setRestriction(std::string _restriction)
{
    restriction =_restriction;
}

std::string Questions::poserQuestion(std::string variable, std::string restriction)
{
    std::string question_reponse;

    if(variable =="Prenom"){question_reponse = "Le prenom de votre personnage est t'il " + restriction + " ?"; }
    else if(variable == "Nom"){question_reponse = "Le nom de votre personnage est il " + restriction + " ?";}
    else if(variable == "Genre"){if(restriction == "F"){question_reponse = "Votre personnage est-il une femme?";}
        else{question_reponse = "Votre personnage est il un homme ?";}}
    else if(variable == "Celebre"){question_reponse = "Votre personnage est il celebre ?";}
    else if(variable == "Vivant"){
                     if(restriction == "0"){ question_reponse = "Votre personnage est il décédé?";}
                     else{question_reponse = "Votre personnage est-il en vie ?";}}
    else if(variable == "Age"){question_reponse = "Votre personnage a t-il entre " + restriction + " ans ? ";}
    else if(variable == "PaysOrigine"){question_reponse = "Votre personnage est-il originaire de " + restriction + " ? ";}
   // pays residence = first letter of prenom
    else if(variable == "PaysResidence")
    {question_reponse = "Le prenom de votre personnage commence t-il par la lettre " + restriction + "?";}
    else if(variable == "Fiction"){
                    if(restriction == "1"){ question_reponse = "Votre personnage est-il immaginaire ?";}
                    else{question_reponse = "Votre personnage a-t-il existé? " ;}}
    else if(variable == "DomaineMetier"){
        if((restriction == "Cinema")||(restriction =="Sport")){question_reponse = "Votre personnage est-il dans le domaine du " + restriction + " ?" ;}
        else{question_reponse = "Votre personnage est-il dans le domaine de la " + restriction + " ?" ;}}
    else if(variable == "Metier"){question_reponse = "Votre personnage est-il un(e) " + restriction + " ?" ;}
    else if(variable == "PasseMetier"){question_reponse = "Votre personnage est-il un(e) " + restriction + " ?" ;}
    else if(variable == "Proche"){question_reponse = "Votre personnage est-il un proche ? ";}
    else if(variable == "Enfants"){question_reponse = "Votre personnage est-il né pendant la décénie suivante:  " + restriction + "?";}
   // decenie de naissance
    else if(variable == "Groupe"){question_reponse = "Votre personnage est-il "+ restriction +"?";}
  // groupe = continent
    else if(variable == "Ecran"){
        if(restriction==""){question_reponse = "Votre personnage est-il connu en premier lieu en dehors du fait d'être apparu à l'écran?";}
        else{question_reponse = "Votre personnage a-t-il joué dans " + restriction + " ?";}}
    else if(variable == "Religion"){question_reponse = "Votre personnage est il " + restriction + " ?";}
    else { cout << "Erreur dans la variable de restriction" << endl;}

    return question_reponse;

}

 Questions::~Questions()
 {}
