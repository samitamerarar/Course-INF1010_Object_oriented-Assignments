/*
Fichier: Dresseur.h
Auteur(s): Guy-Frank, Tamer Arar
Date de creation: 14 septembre 2016
Date de modification: 3 octobre 2016
Description: (classe) Les dresseurs utilisent les creatures pour combattre avec d'autres dresseurs
*/

#ifndef DRESSEUR_H
#define DRESSEUR_H

#include <string>
#include <vector>
#include <iostream>
#include "Creature.h"

class Dresseur
{
public:
	Dresseur();
	Dresseur(const std::string& nom, const std::string& equipe);
	~Dresseur();

	std::string obtenirNom() const;
	void modifierNom(const std::string& nom);
	
	unsigned int obtenirNombreCreatures() const; // A MODIFIER... (si necessaire)

	std::vector<Creature*> obtenirCreatures() const; // Renvoie un vecteur de pointeurs au lieu de tableau de pointeurs
	void modifierCreatures(std::vector<Creature*> creatures); // A un vecteur de pointeurs comme paramètre

	Creature* obtenirUneCreature(const std::string& nom) const;

	ObjetMagique obtenirObjetMagique() const;
	void modifierObjetMagique(const ObjetMagique& objetMagique);

	void utiliserObjetMagique(Creature* creature);
	
	bool ajouterCreature(const Creature& creature); // A MODIFIER... (si necessaire)
	bool enleverCreature(const std::string& nom); // A MODIFIER... (si necessaire)

	friend std::ostream& operator<<(std::ostream& o, const Dresseur& dresseur);

	bool operator==(const Dresseur& dresseur) const;

	bool operator==(const std::string& nom) const;

	friend bool operator==(const std::string& nom, Dresseur& dresseur);

private:
	std::string nom_;	
	ObjetMagique objetMagique_;

	// ___TP2____
	std::string equipe_;
	std::vector<Creature*> creatures_;

};

#endif