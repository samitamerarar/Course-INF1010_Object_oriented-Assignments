/*
Fichier: EtatCreature.h
Auteur(s): Philippe Troclet, Guy-Frank et Tamer Arar
Date de creation: 30 septembre 2016
Date de modification:  18 octobre 2016
Description: Caractèrise l'état d'une créature, et l'impact qu'à ce dernier sur la 
                dite créature
*/
#ifndef ETAT_CREATURE_H
#define ETAT_CREATURE_H

#include <iostream>

#include "Creature.h"  
#include "TypeEtat.h"

//déclaration anticipée nécessaire à cause des inclusions circulaires
//class Creature;

class EtatCreature
{
public:
	//constructeurs
    EtatCreature(const std::string& nom);
    EtatCreature(const std::string& nom, unsigned int duree);
    ~EtatCreature(); //destructeur

    void appliquerEtat(Creature& creature); //à appliquer sur la créature qui possède ce pouvoir
    bool peutAttaquer() const; //détermine si l'état de la créature lui permet d'attaquer
    bool estFini() const; //si vrai, informe la créature qu'elle peut retourner à l'état normal

    std::string obtenirNom() const;
    TypeEtat obtenirType() const;

    friend std::ostream& operator<<(std::ostream& o, const EtatCreature& etatCreature);
private:
    std::string nom_;
protected:
    unsigned int duree_;
    TypeEtat type_;
};
#endif // !ETAT_CREATURE_H