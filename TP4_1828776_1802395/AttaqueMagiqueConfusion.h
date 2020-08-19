/*
Fichier: AttaqueMagiqueConfusion.h
Auteur(s): Guy-Frank et Tamer Arar
Date de creation: 30 octobre 2016
Date de modification: 31 octobre 2016
Description: Attaque magique qui rend la créature attaquée confuse
*/

#ifndef ATTAQUE_MAGIQUE_CONFUSION_H
#define ATTAQUE_MAGIQUE_CONFUSION_H

#include "AttaqueMagique.h"

class AttaqueMagiqueConfusion : public AttaqueMagique
{
public:
	AttaqueMagiqueConfusion();
	AttaqueMagiqueConfusion(unsigned int duree);
	virtual ~AttaqueMagiqueConfusion();

	virtual void appliquerAttaque(Creature& creature);
	virtual bool estFini() const;		//true si durée = 0
};

#endif // !ATTAQUE_MAGIQUE_CONFUSION_H
#pragma once
