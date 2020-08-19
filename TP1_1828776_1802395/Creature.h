/*
Fichier: Creature.h
Auteur(s): Guy-Frank, Tamer Arar
Date de creation: 14 septembre 2016
Date de modification: 26 septembre 2016
Description: Représente des créatures combattantes dans PolyLand
*/

#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include "Pouvoir.h"

class Creature
{
public:
	Creature();
	Creature(const std::string& nom, int attaque, int defense,
		int pointDeVie, int energie, const Pouvoir& pouvoir);
	~Creature();

	std::string obtenirNom() const;
	void setNom(const std::string& nom);

	int obtenirAttaque() const;
	void setAttaque(int attaque);
	
	int obtenirDefense() const;
	void setDefense(int defense);

	int obtenirPointDeVie() const;
	void modifierPointDeVie(int pointDeVie);

	int obtenirPointDeVieTotal() const;
	void setPointDeVieTotal(int pointDeVie);

	int obtenirEnergie() const;
	void modifierEnergie(int energie);

	int obtenirEnergieTotale() const;
	void setEnergieTotal(int energie);

	int obtenirExperience() const;
	void setExperience(int experience);

	int obtenirExperienceNecessaire() const;
	void setExperienceNecessaire(int experienceNecessaire);

	int obtenirNiveau() const;
	void setNiveau(int niveau);

	Pouvoir obtenirPouvoir() const;
	void setPouvoir(const Pouvoir& pouvoir);

	void attaquer(Creature & creature);
	int experienceGagnee(const Creature& creature);
	void information();

private:
	std::string nom_;
	int attaque_, defense_, pointDeVie_, pointDeVieTotal_,
		energie_, energieTotal_, experience_, experienceNecessaire_,
		niveau_;
	Pouvoir pouvoir_;
};

#endif