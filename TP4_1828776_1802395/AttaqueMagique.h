/*
Fichier: AttaqueMagique.h
Auteur(s): Guy-Frank et Tamer Arar
Date de creation: 30 octobre 2016
Date de modification: 31 octobre 2016
Description: Attaques magiques qui sont données a des créatures magiques
*/

#ifndef ATTAQUE_MAGIQUE_H
#define ATTAQUE_MAGIQUE_H

#include <iostream>
#include <stdlib.h>
#include <typeinfo>
#include <string>
#include "Creature.h"

class AttaqueMagique
{
public:
	AttaqueMagique(unsigned int duree);		//constructeur par paramètres
	virtual ~AttaqueMagique();		//destructeur

	void modifierDuree(unsigned int duree);
	unsigned int obtenirDuree() const;

	std::string obtenirTypeAttaque() const;

	virtual void appliquerAttaque(Creature& creature) = 0;		//fonction virtuelle pure
	virtual bool estFini() const;

	friend std::ostream& operator<<(std::ostream& o, AttaqueMagique* am);
private:
	unsigned int duree_;
};

#endif // !ATTAQUE_MAGIQUE_H
