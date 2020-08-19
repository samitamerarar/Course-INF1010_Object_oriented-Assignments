/*
Fichier: PolyLand.h
Auteur(s): Guy-Frank, Tamer Arar
Date de creation: 14 septembre 2016
Date de modification: 3 octobre 2016
Description: (classe) Endroit où les dresseurs se battent entre eux, avec leurs creatures
*/

#ifndef POLYLAND_H
#define POLYLAND_H

#include "Dresseur.h"
#include "Creature.h"
#include <vector>
#include <iostream>

#define MAX_DRESSEURS 100
#define MAX_CREATURES 1000
#define MAX_OBJET_MAGIQUE 100
#define MAX_POUVOIRS 10

class PolyLand
{
public:
	PolyLand();
	~PolyLand();
	
	bool ajouterDresseur(Dresseur* dresseur); // A MODIFIER... (si necessaire)
	bool ajouterCreature(const Creature& creature); // A MODIFIER... (si necessaire)

	bool retirerDresseur(const std::string& nom); // A MODIFIER... (si necessaire)
	bool retirerCreature(const std::string& nom); // A MODIFIER... (si necessaire)

	Dresseur* choisirDresseurAleatoire(); // A MODIFIER... (si necessaire)
	Creature* choisirCreatureAleatoire(); // A MODIFIER... (si necessaire)

	bool attraperCreature(Dresseur* dresseur, const Creature& creature); // A MODIFIER... (si necessaire)
	bool relacherCreature(Dresseur* dresseur, const std::string& nomCreature); // A MODIFIER... (si necessaire)
	
	void infoDresseur(const std::string& nom) const; // A MODIFIER... (si necessaire)

	//________TP2_______
	PolyLand& operator+=(Dresseur* dresseur);
	PolyLand& operator-=(Dresseur* dresseur);

	PolyLand& operator+=(Creature* creature);
	PolyLand& operator-=(Creature* creature);

	friend std::ostream& operator<<(std::ostream& o, const PolyLand& p);

private:
	//________TP2_______
	std::vector<Creature*> creatures_;
	std::vector<Dresseur*> dresseurs_;
};
#endif