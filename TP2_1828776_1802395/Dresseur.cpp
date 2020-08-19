/*
Fichier: Dresseur.cpp
Auteur(s): Guy-Frank, Tamer Arar
Date de creation: 14 septembre 2016
Date de modification: 3 octobre 2016
Description: (classe) Les dresseurs utilisent les creatures pour combattre avec d'autres dresseurs
*/

#include "Dresseur.h"
#include <iostream>

Dresseur::Dresseur() :nom_(""), equipe_("") {}

Dresseur::Dresseur(const std::string& nom, const std::string& equipe)
	:nom_(nom), equipe_(equipe) {}


Dresseur::~Dresseur()
{
}

std::string Dresseur::obtenirNom() const
{
	return nom_;
}

void Dresseur::modifierNom(const std::string& nom)
{
	nom_ = nom;
}

unsigned int Dresseur::obtenirNombreCreatures() const
{
	return creatures_.size();
}

std::vector<Creature*> Dresseur::obtenirCreatures() const // A MODIFIER... (si necessaire)
{
	return creatures_;
}

void Dresseur::modifierCreatures(std::vector<Creature*> creatures) // A MODIFIER... (si necessaire)
{
	creatures_ = creatures;
}

ObjetMagique Dresseur::obtenirObjetMagique() const
{
	return objetMagique_;
}

void Dresseur::modifierObjetMagique(const ObjetMagique & objetMagique)
{
	objetMagique_ = objetMagique;
}

void Dresseur::utiliserObjetMagique(Creature* creature)
{

	if ((creature->obtenirPointDeVieTotal() - creature->obtenirPointDeVie()) >= objetMagique_.obtenirBonus()) {
		creature->modifierPointDeVie(creature->obtenirPointDeVie() + objetMagique_.obtenirBonus());
	}
	else {
		creature->modifierPointDeVie(creature->obtenirPointDeVieTotal());
	}
	if ((creature->obtenirEnergieTotale() - creature->obtenirEnergie()) > objetMagique_.obtenirBonus()) {
		creature->modifierEnergie(creature->obtenirEnergie() + objetMagique_.obtenirBonus());
	}
	else {
		creature->modifierEnergie(creature->obtenirEnergieTotale());
	}
}

bool Dresseur::ajouterCreature(const Creature& creature)
{
	for (size_t i = 0; i < creatures_.size(); i++)
	{
		if (*creatures_[i] == creature.obtenirNom())
			return false;
	}
	creatures_.push_back(new Creature());
	*creatures_.back() = creature;
	return true;
}

bool Dresseur::enleverCreature(const std::string& nom)
{
	for (size_t i = 0; i < creatures_.size(); i++)
	{
		if (*creatures_[i] == nom)
		{
			creatures_[i] = creatures_.back();
			creatures_.pop_back();

			return true;
		}
	}
	return false;
}

// ___TP2___

Creature* Dresseur::obtenirUneCreature(const std::string& nom) const
{
	for (size_t i = 0; i < creatures_.size(); i++)
	{
		if (*creatures_[i] == nom)
			return creatures_[i];
	}

	return nullptr;
}

std::ostream& operator<<(std::ostream& os, const Dresseur& dresseur)
{
	return os << dresseur.nom_ << " possede " << dresseur.creatures_.size() << " creature(s) " <<
		"et appartient à l'equipe de " << dresseur.equipe_ << std::endl;
}

//Compare le vecteur de creatures d'un dresseur avec celui d'un autre dresseur
bool Dresseur::operator==(const Dresseur& dresseur) const  
{
	if (creatures_.size() == dresseur.creatures_.size() && !creatures_.empty())
	{
		int taille = 0;
		for (size_t i = 0; i < creatures_.size(); i++)
		{
			for (size_t j = 0; j < creatures_.size(); j++)
			{
				if (*creatures_[i] == *dresseur.creatures_[j])
					taille++;
			}
		}
		return (taille == creatures_.size());
	}
	else
		return false;
}

bool Dresseur::operator==(const std::string& nom) const
{
	return (nom_ == nom);
}

bool operator==(const std::string& nom, Dresseur& dresseur)
{
	return (dresseur == nom);
}