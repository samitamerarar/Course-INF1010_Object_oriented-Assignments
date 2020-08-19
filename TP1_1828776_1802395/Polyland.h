/*
Fichier: Polyland.h
Auteur(s): Tamer Arar, Guy-Frank Essome Penda
Date de creation: 14 septembre 2016
Date de modification: 26 septembre 2016
Description: Classe qui regroupe toutes les autres classes du programme.
*/

#ifndef POLYLAND_H
#define POLYLAND_H

#define MAX_NOMBRE_DRESSEURS 100
#define MAX_NOMBRE_CREATURES 1000

#include <string>
#include"Dresseur.h"

class PolyLand
{
public:
	PolyLand();
	~PolyLand();

	void ajouterDresseur(Dresseur* dresseur);
	bool retirerDresseur(const std::string& nom);

	void ajouterCreature(Creature* creature);
	void retirerCreature(const std::string& nom);

	Dresseur* choisirDresseurAleatoire();
	Creature* choisirCreatureAleatoire();

	bool attraperCreature(Dresseur* dresseur, const Creature& creature);
	bool relacherCreature(Dresseur* dresseur, const std::string& nom);

	void infoDresseur(const std::string& nom);
private:	
	Dresseur** dresseurs_;
	Creature** creatures_;
	int nbDresseurs_, nbCreatures_;
};

#endif // !POLYLAND_H
