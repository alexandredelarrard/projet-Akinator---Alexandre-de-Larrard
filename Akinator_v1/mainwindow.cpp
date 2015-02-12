#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "questions.h"
#include "basededonnees.h"
#include "personnages.h"
#include "arbre_classification.h"
#include "reponses.h"
#include <iostream>
#include <sstream>

using namespace std;

string convertInt(int number)
{
    stringstream ss;//create a stringstream
    ss << number;//add number to the stream
    return ss.str();//return a string with the contents of the stream
}

// variables globales pour pouvoir être modifiées par les slots qui ne prennent pas de paramètres
// sous Qt. Possible car aucune classe n'hérite de celle-ci. L es variables ne sont donc globales que pour MainWindows
int ieme_node=2;
int compteur_question = 1;
int indice=1;
bool reponse = false;
int nombre_parties=0;
std::string compteur_str;
std::string couleur_hair;

Questions question;
personnages rep;

std::string  question_demander;
QString quest;
QString compteur;

BaseDeDonnees bdd;
vector <personnages*> personnes;
vector <Noeud*> tree;
Arbre_classification* arbre;

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd("C:/Users/Alexandre/Pictures/akinator_logo.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    this->setStyleSheet("border-color: white; ");

    ui->questions_edit->setStyleSheet("font: 9pt Courier;");

    // background des button oui/ non
    QIcon bkgnd_oui("C:/Users/Alexandre/Pictures/oui_roll.png");
    QIcon bkgnd_non("C:/Users/Alexandre/Pictures/non_roll.png");
    ui->button_Oui ->setIconSize(ui->button_Oui->size());
    ui->button_Non ->setIconSize(ui->button_Non->size());

    ui->button_Oui->setIcon(bkgnd_oui);
    ui->button_Oui->setStyleSheet("QPushButton{border: none;outline: none;}");
    ui->button_Non->setIcon(bkgnd_non);
    ui->button_Non->setStyleSheet("QPushButton{border: none;outline: none;}");

    ui->button_Rejouer ->setVisible(true);
    ui->button_Oui->setVisible(false);
    ui->button_Non->setVisible(false);
    ui->nom->setVisible(false);
    ui->prenom->setVisible(false);
    ui->button_valider->setVisible(false);

    ui->questions_edit->setPlainText(QString::fromStdString("Voulez-vous faire une partie?"));
    ui->questions_edit->setAlignment(Qt::AlignCenter);

    // Pas de connection avec les listener car celle-ci est automatique sous Qt dans le cas où les noms des fonctions
    // correspondent exactement au [nom_button]_clicked()
}

void MainWindow::on_button_Oui_clicked()
{

    if (reponse == true)
    {
        ui->questions_edit->setPlainText(QString::fromStdString("Bravo, j'ai trouvé! On se fait une nouvelle partie?" ));
        ui->questions_edit->setAlignment(Qt::AlignCenter);
        ui->button_Oui->setVisible(false);
        ui->button_Non->setVisible(false);
        ui->button_Rejouer ->setVisible(true);
        personnes[0]->setReligion(couleur_hair);
    }
    else{
        personnes = arbre->Restriction_bdd(indice, tree, personnes);
        cout << personnes.size() << "; node = " << ieme_node << endl;

        if(personnes.size() == 1)
        {reponse = true;
            compteur_question++;
            compteur_str = convertInt(compteur_question);
            compteur = QString::fromStdString(" Question n° " + compteur_str );
            ui->questions_edit->setPlainText(QString::fromStdString("Votre personnage est-il " + personnes[0]->getPrenom() + " " + personnes[0]->getNom() + " ?") + " \n" + " \n"  +  compteur);
            ui->questions_edit->setAlignment(Qt::AlignCenter);
        }
        else{
            ieme_node = 2*ieme_node;
            compteur_question++;

            indice = arbre->GetIndiceNode(tree, ieme_node);

            compteur_str = convertInt(compteur_question);
            compteur = QString::fromStdString(" Question n° " + compteur_str );

            question_demander = question.poserQuestion(tree[indice]-> getVariableNoeud(), tree[indice]->getModaliteVariableNoeud());
            quest = QString::fromStdString(question_demander);
            ui->questions_edit->setPlainText(quest + " \n" + " \n" +  compteur);
            ui->questions_edit->setAlignment(Qt::AlignCenter);
        }
    }

}

void MainWindow::on_button_Non_clicked()
{
    if (reponse == true)
    {
        ui->questions_edit->setPlainText(QString::fromStdString("Désolé je ne connais pas votre personnage. Pourriez-vous me l'indiquer?" ));
        ui->questions_edit->setAlignment(Qt::AlignCenter);
        ui->nom->setVisible(true);
        ui->prenom->setVisible(true);
        ui->button_Oui->setVisible(false);
        ui->button_Non->setVisible(false);
        ui->button_valider->setVisible(true);

    }
    else{

        personnes = arbre->Restriction_bdd(indice+1,tree, personnes);
        cout << personnes.size() << "; node = " << ieme_node << endl;

        if(personnes.size() == 1)
        {
            reponse = true;
            compteur_question++;
            compteur_str = convertInt(compteur_question);
            compteur = QString::fromStdString(" Question n° " + compteur_str );

            ui->questions_edit->setPlainText(QString::fromStdString("Votre personnage est-il " + personnes[0]->getPrenom() + " " + personnes[0]->getNom() + " ?") + " \n" + " \n" +  compteur);
            ui->questions_edit->setAlignment(Qt::AlignCenter);

        }
        else{
            ieme_node = 2*(ieme_node +1);
            compteur_question++;

            indice = arbre->GetIndiceNode(tree, ieme_node);

            compteur_str = convertInt(compteur_question);
            compteur = QString::fromStdString(" Question n° " + compteur_str );

            question_demander = question.poserQuestion(tree[indice]-> getVariableNoeud(), tree[indice]->getModaliteVariableNoeud());
            quest = QString::fromStdString(question_demander);

            ui->questions_edit->setPlainText(quest+ " \n" +  " \n" + compteur);
            ui->questions_edit->setAlignment(Qt::AlignCenter);
        }

    }
}

void MainWindow::on_button_Rejouer_clicked()
{
    nombre_parties++;
    ui->button_Rejouer ->setVisible(false);
    ui->button_Oui->setVisible(true);
    ui->button_Non->setVisible(true);

    ieme_node=2;
    compteur_question = 1;
    indice=1;
    reponse = false;

    personnes = bdd.GenererBaseDeDonnees();
    if(nombre_parties==1)
    {tree = arbre->ConstructionArbre(personnes);}

    question_demander = question.poserQuestion(tree[indice]-> getVariableNoeud(), tree[indice]->getModaliteVariableNoeud());
    quest = QString::fromStdString(question_demander);
    compteur_str = convertInt(compteur_question);

    compteur = QString::fromStdString(" Question n° " + compteur_str );
    ui->questions_edit->setPlainText(quest + " \n" + " \n"  +  compteur);
    ui->questions_edit->setAlignment(Qt::AlignCenter);
}

void MainWindow::on_button_valider_clicked()
{
    ui->questions_edit->setPlainText(QString::fromStdString("Merci bien ;). On s'en refait une?"));
    ui->nom->setVisible(false);
    ui->prenom->setVisible(false);
    ui->button_valider->setVisible(false);
    ui->button_Rejouer ->setVisible(true);

    QString nom_new = ui->nom->QTextEdit::toPlainText();
    QString prenom_new = ui->prenom->QTextEdit::toPlainText();
    std::string name = nom_new.toLocal8Bit().constData();
    std::string surname = prenom_new.toLocal8Bit().constData();


    // La personne inconnue dans la bdd aura le même profil que ceux déjà présent, il suffit donc d'ajouter son nom et prenom pour avoir un nouveau membre
    rep.setNom(name);
    rep.setPrenom(surname);
    rep.setEnfants(personnes[0]->getEnfants());
    rep.setVivant(personnes[0]->getVivant());
    rep.setReligion(personnes[0]->getReligion());
    rep.setFiction(personnes[0]->getFiction());
    rep.setPaysResidence(personnes[0]->getPaysResidence());
    rep.setPaysOrigine(personnes[0]->getPaysOrigine());
    rep.setPasseMetier(personnes[0]->getPasseMetier());
    rep.setMetier(personnes[0]->getMetier());
    rep.setDomaineMetier(personnes[0]->getDomaineMetier());
    rep.setCelebre(personnes[0]->getCelebre());
    rep.setGenre(personnes[0]->getGenre());
    rep.setAge(personnes[0]->getAge());
    rep.setProche(personnes[0]->getProche());
    bdd.AjouterReponse(rep);
}

MainWindow::~MainWindow()
{
    delete ui;
}

