/*
Fichier: Polyland.cpp
Auteur(s): Tamer Arar, Guy-Frank Essome Penda
Date de creation: 14 septembre 2016
Date de modification: 26 septembre 2016
Description: Classe qui regroupe toutes les autres classes du programme.
*/

#include "PolyLand.h"
#include "Dresseur.h"
#include "Creature.h"
#include <iostream>
using namespace std;


PolyLand::PolyLand()
	:nbCreatures_(0), nbDresseurs_(0)
{
	creatures_ = new Creature*[MAX_NOMBRE_CREATURES];
	dresseurs_ = new Dresseur*[MAX_NOMBRE_DRESSEURS];

	for (size_t i = 0; i < MAX_NOMBRE_CREATURES; i++)
		creatures_[i] = nullptr;

	for (size_t i = 0; i < MAX_NOMBRE_DRESSEURS; i++)
		dresseurs_[i] = nullptr;
}

PolyLand::~PolyLand()
{
	for (size_t i = 0; i < MAX_NOMBRE_CREATURES; i++)
		delete creatures_[i];

	for (size_t i = 0; i < MAX_NOMBRE_DRESSEURS; i++)
		delete dresseurs_[i];

	delete[] creatures_;
	delete[] dresseurs_;
}

void PolyLand::ajouterDresseur(Dresseur* dresseur)
{
	bool existe = false;

	for (size_t i = 0; i < nbDresseurs_ && !existe; i++)
	{
		if (dresseurs_[i]->obtenirNom() == dresseur->obtenirNom())
			existe = true;
	}

	if (!existe)
	{
		dresseurs_[nbDresseurs_++] = dresseur;
		cout << dresseur->obtenirNom() << " a bien été ajouté !" << endl;
	}
}
		

bool PolyLand::retirerDresseur(const std::string& nom)
{
	bool retirer = false;
	for (size_t i = 0; i < nbDresseurs_ && !retirer; i++)
	{
		if (dresseurs_[i]->obtenirNom() == nom)
		{
			dresseurs_[i]= new Dresseur;

			dresseurs_[i] = dresseurs_[--nbDresseurs_];

			retirer = true;
		}
	}
	return retirer;
}

void PolyLand::ajouterCreature(Creature* creature)
{
	bool existe = false;

	for (size_t i = 0; i < nbCreatures_ && !existe; i++)
	{
		if (creatures_[i]->obtenirNom() == creature->obtenirNom())
			existe = true;
	}

	if (!existe)
	{
		creatures_[nbCreatures_++] = new Creature(*creature);
		cout << creature->obtenirNom() << " a bien été ajouté !" << endl;
	}
}

void PolyLand::retirerCreature(const std::string& nom)
{
	for (size_t i = 0; i < nbCreatures_; i++)
	{
		if (creatures_[i]->obtenirNom() == nom)
		{
			delete creatures_[i];

			creatures_[i] = creatures_[--nbCreatures_];
		}
	}
}

Dresseur* PolyLand::choisirDresseurAleatoire()
{
	return dresseurs_[rand() % nbDresseurs_];
}

Creature* PolyLand::choisirCreatureAleatoire()
{
	return creatures_[rand() % nbCreatures_];
}

bool PolyLand::attraperCreature(Dresseur* dresseur, const Creature& creature)
{
	if (dresseur->obtenirNombreCreatures() < dresseur->obtenirNombreCreaturesMax())
	{
		return dresseur->ajouterCreature(creature);
	}
	return false;
}

bool PolyLand::relacherCreature(Dresseur* dresseur, const std::string& nom)
{
	return dresseur->retirerCreature(nom);
}


void PolyLand::infoDresseur(const std::string& nom)
{
	bool nomTrouve = false;
	for (size_t i = 0; i < nbDresseurs_; i++)
	{
		if (dresseurs_[i]->obtenirNom() == nom)
		{
			cout << "Informations sur le dresseur:" << endl;
			dresseurs_[i]->affichage();
			nomTrouve = true;
			for (size_t j = 0; j < dresseurs_[i]->obtenirNombreCreatures(); j++)
			{
				cout << "- " << j + 1 << " - ";
				dresseurs_[i]->obtenirCreatures()[j]->information();
			}
		}
		if (!nomTrouve)
			std::cout << "Dresseur introuvable!" << endl;
	}
}

