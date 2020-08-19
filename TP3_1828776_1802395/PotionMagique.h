/*
Fichier: PotionMagique.h
Auteur(s): Guy-Frank et Tamer Arar
Date de creation: 11 octobre 2016
Date de modification:  18 octobre 2016
Description: Repr�sente un objet qui rend de la vie � une cr�ature
*/
#ifndef POTION_MAGIQUE_H
#define POTION_MAGIQUE_H

#include "ObjetMagique.h"

class PotionMagique : public ObjetMagique
{
public:
	//constructeurs
	PotionMagique();
	PotionMagique(const std::string &nom, int bonus);
	~PotionMagique(); //destructeur

	void utiliserSur(Creature& creature) const; //rend points de vie � une cr�ature

	friend std::ostream& operator<<(std::ostream& o, const PotionMagique& p);
};

#endif // !POTION_MAGIQUE_H