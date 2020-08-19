/*
Fichier: Creature.h
Auteur(s): Guy-Frank, Tamer Arar
Date de creation: 14 septembre 2016
Date de modification: 3 octobre 2016
Description: (classe) Les creatures sont des etres combattantes de polyland
*/

#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include "ObjetMagique.h"
#include "Pouvoir.h"
#include <vector>

class Creature
{
public:
	Creature(); // A MODIFIER... (si necessaire)
	Creature(const std::string& nom, unsigned int attaque, 
		unsigned int defense, unsigned int pointDeVie, unsigned int energie); // A COMPLETER... (si necessaire)
	Creature(const Creature& c);
	~Creature(); // A MODIFIER... (si necessaire)
	
	std::string obtenirNom() const;
	unsigned int obtenirAttaque() const;
	unsigned int obtenirDefense() const;
	unsigned int obtenirPointDeVie() const;
	unsigned int obtenirPointDeVieTotal() const;
	unsigned int obtenirEnergie() const;
	unsigned int obtenirEnergieTotale() const;
	unsigned int obtenirExperience() const;
	unsigned int obtenirExperienceNecessaire() const;
	unsigned int obtenirNiveau() const;
	std::vector<Pouvoir*> obtenirPouvoirs() const; // A MODIFIER... (si necessaire)

	void attaquer(const Pouvoir pouvoir_, Creature & creature);// A MODIFIER... (si necessaire)
	int experienceGagnee(const Creature& creature);
	
	void modifierNom(const std::string& nom);
	void modifierAttaque(unsigned int attaque);
	void modifierDefense(unsigned int defense);
	void modifierPointDeVie(unsigned int pointDeVie);
	void modifierEnergie(unsigned int energie);
	void modifierExperience(unsigned int experience);
	void modifierNiveau(unsigned int niveau);
	void modifierPouvoirs(std::vector<Pouvoir*> pouvoirs); // A MODIFIER... (si necessaire)

	// _________TP2___________
	void apprendrePouvoir(Pouvoir* pouvoir);
	void oublierPouvoir(Pouvoir* pouvoir);

	Creature& operator=(const Creature& creature);
	bool operator==(const Creature& creature) const;
	bool operator==(const std::string nom) const;
	friend bool operator==(const std::string nom, Creature& creature);
	friend std::ostream& operator<<(std::ostream& o, const Creature& creature);

private:

	std::string nom_;
	unsigned int attaque_;
	unsigned int defense_;
	unsigned int pointDeVie_;
	unsigned int pointDeVieTotal_;
	unsigned int energie_;
	unsigned int energieTotal_;
	unsigned int experience_;
	unsigned int experienceNecessaire_;
	unsigned int niveau_;
	
	// _________TP2___________
	std::vector<Pouvoir*> pouvoirs_;


};

#endif