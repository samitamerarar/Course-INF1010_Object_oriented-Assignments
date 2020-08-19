/*
Fichier: PotionMagique.h
Auteur(s): Guy-Frank et Tamer Arar
Date de creation: 11 octobre 2016
Date de modification:  18 octobre 2016
Description: Représente un objet qui rend de la vie à une créature
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

	void utiliserSur(Creature& creature) const; //rend points de vie à une créature

	friend std::ostream& operator<<(std::ostream& o, const PotionMagique& p);
};

#endif // !POTION_MAGIQUE_H