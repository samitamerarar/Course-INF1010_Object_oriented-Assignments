/*
Fichier: Dresseur.h
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification:  6 septembre 2016 par Maude Carrier, 24 octobre par Guy-Frank
Description: les dresseurs sont les etres capables d'attraper des creatures
*/
#ifndef DRESSEUR_H
#define DRESSEUR_H

#include <string>
#include "Creature.h"
#include <iostream>
#include <vector>

class Dresseur
{
public:
	Dresseur();
	Dresseur(const std::string& nom, const std::string& equipe);
	~Dresseur();

	std::string obtenirNom() const;
	void modifierNom(const std::string& nom);
	
	unsigned int obtenirNombreCreatures() const;

	std::vector<Creature*> obtenirCreatures() const;
	Creature* obtenirUneCreature(const std::string& nom) const;
	void modifierCreature(std::vector<Creature*> creatures);
	
	bool ajouterCreature(Creature* creature);
	bool enleverCreature(const std::string& nom);

	ObjetMagique obtenirObjetMagique() const;
	void modifierObjetMagique(const ObjetMagique& objetMagique);

	void utiliserObjetMagique(Creature* creature);

	std::string obtenirEquipe() const;
	void modifierEquipe(const std::string& equipe);

	friend std::ostream& operator<<(std::ostream& os, const Dresseur& dresseur);

	bool operator==(const Dresseur& dresseur) const;
	bool operator==(const std::string& nom) const;
	friend bool operator==(const std::string& nom, const Dresseur& dresseur);

private:
	std::string nom_;
	std::vector<Creature*> creatures_;
	std::string equipe_;
	ObjetMagique* objetMagique_;


};

#endif