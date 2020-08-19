/*
Fichier: CreatureMagique.h
Auteur(s): Guy-Frank et Tamer Arar
Date de creation: 11 octobre 2016
Date de modification:  18 octobre 2016
Description: Les creatures sont des etres destines au combat
*/
#ifndef CREATURE_MAGIQUE_H
#define CREATURE_MAGIQUE_H

#include "Creature.h"

class CreatureMagique : public Creature
{
public:
	CreatureMagique(const std::string& nom, unsigned int attaque,
		unsigned int defense, unsigned int pointDeVie, unsigned int energie,
		unsigned int bonus);
	CreatureMagique(const CreatureMagique& creatureMagique);

	void attaquer(const Pouvoir& pouvoir, Creature& creature);
	CreatureMagique& operator=(const CreatureMagique& creatureMagique);
private:
	unsigned int bonus_;
};

#endif // !CREATURE_MAGIQUE_H
