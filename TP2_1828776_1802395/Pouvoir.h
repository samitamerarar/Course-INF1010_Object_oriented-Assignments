/*
Fichier: Pouvoir.h
Auteur(s): Guy-Frank, Tamer Arar
Date de creation: 14 septembre 2016
Date de modification: 3 octobre 2016
Description: (classe) Les pouvoirs appartiennent aux créatures et celles-ci peuvent s'en servir pour attaquer
*/

#ifndef POUVOIR_H
#define POUVOIR_H

#include <string>
#include <iostream>
class Pouvoir
{
public:
	Pouvoir();
	Pouvoir(const Pouvoir& pouvoir);
	Pouvoir(const std::string& nom, 
		unsigned int nombreDeDegat, unsigned int energieNecessaire);
	~Pouvoir();

	unsigned int obtenirNombreDeDegat() const;
	unsigned int obtenirEnergieNecessaire() const;
	std::string obtenirNom() const;

	void modifierNombreDeDegat(unsigned int nombreDegat);
	void modifierEnergieNecessarie(unsigned int energieNecessaire);
	void modifierNom(const std::string& nom);

	//________TP2________
	Pouvoir& operator=(const Pouvoir& pouvoir);

	bool operator==(const std::string& nom) const;

	friend std::ostream& operator<<(std::ostream& os, const Pouvoir& pouvoir);

private:
	std::string nom_;
	unsigned int nombreDeDegat_ ;
	unsigned int energieNecessaire_;
};

#endif