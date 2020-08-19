/*
Fichier: CreatureMagique.h
Auteur(s): Guy-Frank et Tamer Arar
Date de creation: 30 octobre 2016
Date de modification: 31 octobre 2016
Description: Une créature ayant une attaque magique et un bonus en plus
*/

#ifndef CREATURE_MAGIQUE_H
#define CREATURE_MAGIQUE_H

#include "Creature.h"
#include "AttaqueMagique.h"
#include "AttaqueMagiqueConfusion.h"
#include "AttaqueMagiquePoison.h"

class CreatureMagique : public Creature
{
public:
	//constructeurs
	CreatureMagique();
	CreatureMagique(unsigned int bonus, const Creature& creature);
	CreatureMagique(const CreatureMagique& cm);
	virtual~CreatureMagique();

	void modifierAttaqueMagique(AttaqueMagique* am);
	AttaqueMagique* obtenirAttaqueMagique();

	void modifierBonus(unsigned int bonus);
	unsigned int obtenirBonus() const;

	virtual void attaquer(const Pouvoir& pouvoir, Creature& creature);

	void apprendreAttaqueMagique(AttaqueMagique* am);
	void oublierAttaqueMagique();

	CreatureMagique& operator=(const CreatureMagique& cm);
	friend std::ostream& operator<<(std::ostream& o, CreatureMagique& cm);

private:
	AttaqueMagique *attaqueMagique_;
	unsigned int bonus_;
};
#endif // !CREATURE_MAGIQUE_H