/*
Fichier: AttaqueMagiquePoison.h
Auteur(s): Guy-Frank et Tamer Arar
Date de creation: 30 octobre 2016
Date de modification: 31 octobre 2016
Description: Attaque magique qui rend la créature attaquée empoisonnée
*/

#ifndef ATTAQUE_MAGIQUE_POISON_H
#define ATTAQUE_MAGIQUE_POISON_H

#include "AttaqueMagique.h"

class AttaqueMagiquePoison : public AttaqueMagique
{
public:
	//constructeurs
	AttaqueMagiquePoison();
	AttaqueMagiquePoison(unsigned int duree);
	virtual ~AttaqueMagiquePoison();

	virtual void appliquerAttaque(Creature& creature);
	virtual bool estFini() const;	//true si durée = 0
};

#endif // !ATTAQUE_MAGIQUE_POISON_H
