/*
Fichier: PouvoirHallucinogene.h
Auteur(s): Guy-Frank et Tamer Arar
Date de creation: 11 octobre 2016
Date de modification:  18 octobre 2016
Description: Herite de la classe Pouvoir et donne la folie
*/
#ifndef POUVOIR_HALLUCINOGENE_H
#define POUVOIR_HALLUCINOGENE_H

#include "Pouvoir.h"

class PouvoirHallucinogene : public Pouvoir
{
public:
	//constructeurs
	PouvoirHallucinogene(const std::string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire);
	PouvoirHallucinogene(const std::string& nom, unsigned int nombreDeDegat,
		unsigned int energieNecessaire, unsigned int duree);
	~PouvoirHallucinogene(); //destructeur

	void appliquerEffetOffensif(Creature& creatureEnnemie); //change l'état de la créature vers confus

	friend std::ostream& operator<<(std::ostream& o, const PouvoirHallucinogene& pouvoir);
private:
	unsigned int duree_;
};

#endif // !POUVOIR_POISON_H