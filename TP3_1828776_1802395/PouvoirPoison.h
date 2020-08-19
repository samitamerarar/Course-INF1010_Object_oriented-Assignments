/*
Fichier: PouvoirPoison.h
Auteur(s): Guy-Frank et Tamer Arar
Date de creation: 11 octobre 2016
Date de modification:  18 octobre 2016
Description: Herite de la classe Pouvoir et empoisonne
*/
#ifndef POUVOIR_POISON_H
#define POUVOIR_POISON_H

#include "Pouvoir.h"

class PouvoirPoison : public Pouvoir
{
public:
	//constructeurs
	PouvoirPoison(const std::string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire);
	PouvoirPoison(const std::string& nom, unsigned int nombreDeDegat,
		unsigned int energieNecessaire, unsigned int duree);
	~PouvoirPoison(); //destructeur

	void appliquerEffetOffensif(Creature& creatureEnnemie); //change l'état de la créature vers empoisonné

	friend std::ostream& operator<<(std::ostream& o, const PouvoirPoison& pouvoir);
private:
	unsigned int duree_;
};

#endif // !POUVOIR_POISON_H