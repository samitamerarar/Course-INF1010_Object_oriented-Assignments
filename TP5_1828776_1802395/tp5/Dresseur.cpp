/*
Fichier: Dresseur.cpp
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification: 6 septembre 2016 par Maude Carrier
*/

#include "Dresseur.h"
#include "Foncteur.h"
#include <algorithm>


Dresseur::Dresseur() :nom_(""), equipe_("") {};

Dresseur::Dresseur(const std::string& nom, const std::string& equipe) : nom_(nom), equipe_(equipe) {};

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

std::list<Creature*> Dresseur::obtenirCreatures() const
{
	return creatures_;
}

Creature* Dresseur::obtenirUneCreature(const std::string& nom) const

{
	//Chercher la créature dans la liste
	auto creature = std::find_if(creatures_.begin(), creatures_.end(), FoncteurCreaturesDeMemeNom(nom));
	//Retourner la créature si elle a été retrouvée
	if (creature != creatures_.end())
		return *creature;

	return nullptr;
}

void Dresseur::modifierCreature(std::list<Creature*> creatures) //A Compléter
{
	creatures_ = creatures;
}

bool Dresseur::ajouterCreature(Creature* creature)
{
	FoncteurEgalCreatures comparaison(creature);
	auto position_creature = find_if(creatures_.begin(), creatures_.end(), comparaison);
	if (position_creature != creatures_.end())
		return false;

	creatures_.push_back(creature);
	return true;
}

bool Dresseur::enleverCreature(const std::string& nom)
{
	FoncteurCreaturesDeMemeNom foncteurComparaison(nom);
	auto position = find_if(creatures_.begin(), creatures_.end(), foncteurComparaison);
	if (position == creatures_.end())
		return false;

	creatures_.erase(position);

	return true;
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

std::string Dresseur::obtenirEquipe() const
{
	return equipe_;
}

void Dresseur::modifierEquipe(const std::string& equipe)
{
	equipe_ = equipe;
}

bool Dresseur::operator==(const Dresseur& dresseur) const //A compléter
{
	if (creatures_.size() == 0 && dresseur.creatures_.size() == 0)
		return true;
	else if (creatures_.size() != dresseur.creatures_.size())
		return false;

	/*Complétez moi! Vérifiez l'égalité entre les créatures via
	find_if*/

	//Définir les bornes de recherche
	auto debut = creatures_.begin();
	auto fin = creatures_.end();

	//Compteur pour les nombres de créatures égales dans les deux listes
	int compteur = 0;

	for each(Creature* creature in dresseur.creatures_)
	{
		auto creatureTrouvee = std::find_if(debut, fin, FoncteurEgalCreatures(creature));

		//Incrementer le compteur chanque fois qu'une créature
		//est présente dans les deux listes 
		if (creatureTrouvee != fin)
			compteur++;
	}

	//Retourner true si le nombre des créatures présentes dans
	//les deux liste est égal au nombre total de créature dans
	//une des listes
	if (compteur == creatures_.size())
		return true;

	return false;
}

bool Dresseur::operator==(const std::string& nom) const
{
	return (nom_ == nom);
}

bool operator==(const std::string& nom, const Dresseur& dresseur)
{
	return dresseur == nom;
}

std::ostream& operator<<(std::ostream& os, const Dresseur& dresseur)
{
	return os << dresseur.nom_ << " possede " << dresseur.creatures_.size()
		<< " creature(s) et appartient a l'equipe " << dresseur.equipe_ << std::endl << std::endl;
}