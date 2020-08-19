/*
Fichier: Dresseur.cpp
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification:  6 septembre 2016 par Maude Carrier, 24 octobre par Guy-Frank
*/
#include <iostream>

#include "Dresseur.h"

Dresseur::Dresseur() :nom_(""), equipe_("") {};

Dresseur::Dresseur(const std::string& nom, const std::string& equipe) : nom_(nom), equipe_(equipe), objetMagique_(nullptr) {}; // ajout de l'initialisation du pointeur d'objetMagique.

Dresseur::~Dresseur()
{
    delete objetMagique_;
};

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

std::vector<Creature*> Dresseur::obtenirCreatures() const
{
	return creatures_;
}

Creature* Dresseur::obtenirUneCreature(const std::string& nom) const
{
	for (unsigned int i = 0; i < creatures_.size(); i++)
	{
		if (*(creatures_[i]) == nom)
		{
			return creatures_[i];
		}

	}
	return nullptr;

}

void Dresseur::modifierCreature(std::vector<Creature*> creatures)
{
	creatures_ = creatures;
}

bool Dresseur::ajouterCreature(Creature* creature)
{
	for (unsigned int i = 0; i < creatures_.size(); i++)
	{
		if (*creatures_[i] == *creature)
		{
			return false;
		}
	}
	creatures_.push_back(creature);
	return true;
}

bool Dresseur::enleverCreature(const std::string& nom)
{
	for (unsigned int i = 0; i < creatures_.size(); i++)
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

ObjetMagique Dresseur::obtenirObjetMagique() const
{
	return *objetMagique_;
}

void Dresseur::modifierObjetMagique(const ObjetMagique & objetMagique)
{
    delete objetMagique_;
    objetMagique_ = nullptr;
	objetMagique_ = new ObjetMagique(objetMagique);
}

void Dresseur::utiliserObjetMagique(Creature* creature)
{
    objetMagique_->utiliserSur(*creature);
    delete objetMagique_;
    objetMagique_ = nullptr;
}

std::string Dresseur::obtenirEquipe() const
{
	return equipe_;
}

void Dresseur::modifierEquipe(const std::string& equipe)
{
	equipe_ = equipe;
}

std::ostream& operator<<(std::ostream& os, const Dresseur& dresseur)
{
	return os << dresseur.nom_ << " possede " << dresseur.creatures_.size() <<
        " creature(s) et appartient a l'equipe " << dresseur.equipe_ << std::endl;
}

bool Dresseur::operator==(const Dresseur& dresseur) const
{
	if (creatures_.size() == 0 && dresseur.creatures_.size() == 0)
	{
		return true;
	}
	else if (creatures_.size() == dresseur.creatures_.size())
	{
		for (unsigned int i = 0; i < creatures_.size(); i++)
		{
			for (unsigned int j = 0; j < dresseur.creatures_.size(); j++)
			{
				if (*(creatures_[i]) == *(dresseur.creatures_[j]))
				{
					break;
				}
				else if (j = dresseur.creatures_.size() - 1)
				{
					return false;
				}
			}
		}
	}
	else
	{
		return false;
	}
	return true;
}

bool Dresseur::operator==(const std::string& nom) const
{
	return (nom_ == nom);
}

bool operator==(const std::string& nom, const Dresseur& dresseur)
{
	return dresseur == nom;
}
