/*
Fichier: Pouvoir.h
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification:  18 octobre 2016
Description: La classe Pouvoir correspond aux differents attaques 
*/
#ifndef POUVOIR_H
#define POUVOIR_H

#include <string>
#include <iostream>

#include "Creature.h"
#include "TypeEtat.h"

class Creature;

class Pouvoir
{
public:
	Pouvoir();
	Pouvoir(const std::string& nom, 
		unsigned int nombreDeDegat, unsigned int energieNecessaire);
	~Pouvoir();

	unsigned int obtenirNombreDeDegat() const;
	unsigned int obtenirEnergieNecessaire() const;
	std::string obtenirNom() const;
    TypeEtat obtenirType() const; //renvoie le type, qui caractérise l'effet du pouvoir (ex: empoisonner)

	void modifierNombreDeDegat(unsigned int nombreDegat);
	void modifierEnergieNecessarie(unsigned int energieNecessaire);
	void modifierNom(const std::string& nom);

	Pouvoir(const Pouvoir& pouvoir);
	Pouvoir& operator=(const Pouvoir& pouvoir);

	bool operator==(const Pouvoir& pouvoir) const;

	friend std::ostream& operator<<(std::ostream& os, const Pouvoir& pouvoir);

    void appliquerEffetOffensif(Creature& creatureEnnemie); //ne fait rien
    void appliquerEffetDefensif(Creature& creatureAllie);  //ne fait rien
protected:
	std::string nom_;
	unsigned int nombreDeDegat_ ;
	unsigned int energieNecessaire_;
    TypeEtat type_;
};

#endif