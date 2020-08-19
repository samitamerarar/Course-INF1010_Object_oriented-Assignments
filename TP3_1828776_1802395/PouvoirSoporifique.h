/*
Fichier: PouvoirSoporifique.h
Auteur(s): Guy-Frank et Tamer Arar
Date de creation: 11 octobre 2016
Date de modification:  18 octobre 2016
Description: Herite de la classe Pouvoir et endort
*/
#ifndef POUVOIR_SOPORIFIQUE_H
#define POUVOIR_SOPORIFIQUE_H

#include "Pouvoir.h"

class PouvoirSoporifique : public Pouvoir
{
public:
	//constructeurs
	PouvoirSoporifique(const std::string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire);
	PouvoirSoporifique(const std::string& nom, unsigned int nombreDeDegat,
		unsigned int energieNecessaire, unsigned int duree);
	~PouvoirSoporifique(); //destructeur

	void appliquerEffetOffensif(Creature& creatureEnnemie); //change l'état de la créature vers endormi

	friend std::ostream& operator<<(std::ostream& o, const PouvoirSoporifique& pouvoir);
private:
	unsigned int duree_;
};

#endif // !POUVOIR_SOPORIFIQUE_H