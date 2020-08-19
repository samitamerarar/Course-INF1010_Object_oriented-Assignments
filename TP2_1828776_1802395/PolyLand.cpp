/*
Fichier: PolyLand.cpp
Auteur(s): Guy-Frank, Tamer Arar
Date de creation: 14 septembre 2016
Date de modification: 3 octobre 2016
Description: (classe) Endroit où les dresseurs se battent entre eux, avec leurs creatures
*/

#include "PolyLand.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

PolyLand::PolyLand() {}


PolyLand::~PolyLand()
{}

bool PolyLand::ajouterDresseur(Dresseur* dresseur)
{
	if (dresseurs_.size() >= MAX_DRESSEURS)
		return false;

	for (size_t i = 0; i < dresseurs_.size(); i++)
	{
		if (*dresseurs_[i] == *dresseur || *dresseurs_[i] == dresseur->obtenirNom())
			return false;
	}

	dresseurs_.push_back(dresseur);

	return true;
}

bool PolyLand::ajouterCreature(const Creature& creature)
{
	if (creatures_.size() > MAX_CREATURES)
		return false;

	for (size_t i = 0; i < creatures_.size(); i++)
	{
		if (*creatures_[i] == creature)
			return false;
	}

	creatures_.push_back(new Creature());
	*creatures_[creatures_.size() - 1] = creature;

	return true;
}

bool PolyLand::retirerDresseur(const std::string& nom)
{
	for (size_t i = 0; i < dresseurs_.size(); i++)
	{
		if (*dresseurs_[i] == nom)
		{
			dresseurs_[i] = dresseurs_[dresseurs_.size() - 1];
			dresseurs_.pop_back();
			
			return true;
		}
	}
	return false;
}

bool PolyLand::retirerCreature(const std::string& nom) // A MODIFIER... (si necessaire)
{
	for (size_t i = 0; i < creatures_.size(); i++)
	{
		if (*creatures_[i] == nom)
		{
			creatures_[i] = creatures_[creatures_.size() - 1];
			creatures_.pop_back();

			return true;
		}
	}
	return false;
}

Dresseur* PolyLand::choisirDresseurAleatoire() // A MODIFIER... (si necessaire)
{
	if (dresseurs_.size() > 0) 
    {
		unsigned int indice = rand() % dresseurs_.size();
		return dresseurs_[indice];
	}
	else 
    {
		return nullptr;
	}
}

Creature* PolyLand::choisirCreatureAleatoire() // A MODIFIER... (si necessaire)
{
	if (creatures_.size() > 0) 
    {
		unsigned int indice = rand() % creatures_.size();
		return creatures_[indice];
	}
	else {
		return nullptr;
	}
}

bool PolyLand::attraperCreature(Dresseur* dresseur,const Creature& creature) // A MODIFIER... (si necessaire)
{
	return dresseur->ajouterCreature(creature);
}

bool PolyLand::relacherCreature(Dresseur* dresseur, const std::string& nomCreature)
{
	return dresseur->enleverCreature(nomCreature);
}

PolyLand & PolyLand::operator+=(Dresseur * dresseur)
{
	if (this->ajouterDresseur(dresseur))
		std::cout << dresseur->obtenirNom() << " a bien ete ajoute !" << std::endl;
	else
		std::cout << dresseur->obtenirNom() << " n'a pas ete ajoute !" << std::endl;
		return *this;
}

PolyLand & PolyLand::operator-=(Dresseur * dresseur)
{
	if (this->retirerDresseur(dresseur->obtenirNom()))
		return *this;
}

PolyLand & PolyLand::operator+=(Creature * creature)
{
	if (this->ajouterCreature(*creature))
		std::cout << creature->obtenirNom() << " a bien ete ajoute !" << std::endl;
	
	return *this;
}

PolyLand & PolyLand::operator-=(Creature * creature)
{
	if (this->retirerCreature(creature->obtenirNom()))
		return *this;
}

std::ostream& operator<<(std::ostream& o, const PolyLand& p)
{
	for (size_t i = 0; i < p.dresseurs_.size(); i++)
		o << *p.dresseurs_[i];

	return o;
}