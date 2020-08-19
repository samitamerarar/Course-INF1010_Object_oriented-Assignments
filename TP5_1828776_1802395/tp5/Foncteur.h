/*
Fichier: Foncteur.h
Auteur(s): Tamer Arar et Guy-Frank
Date de creation: 14 novembre 2016
Date de modification: 21 novembre 2016
Description: Regroupe tous les foncteurs de ce TP
*/

#ifndef FONCTEUR
#define FONCTEUR

#include "Dresseur.h"
#include <string>
#include <stdlib.h>

#define RAND_MIN_DEFAUT 0 //Borne minimale et borne maximale par d�faut du constructeur par d�faut 
#define RAND_MAX_DEFAUT 6 //de FoncteurGenerateurNombresAlea qui initialise l'intervalle

//Foncteur permettant d'obtenir l'attaque de la cr�ature pass�e en argument
class FoncteurObtenirAttaqueCreature
{
public:
    FoncteurObtenirAttaqueCreature() {}
    ~FoncteurObtenirAttaqueCreature() {}

    unsigned int operator() (const Creature* creature) const {
        return creature->obtenirAttaque();
    }
};

//Foncteur qui renvoie True si l'attaque d'une cr�ature 1 < cr�ature 2
class FoncteurComparerCreature
{
public:
	FoncteurComparerCreature() {}
	~FoncteurComparerCreature() {}

	bool operator() (const Creature* creature1, const Creature* creature2) const {
		return creature1->obtenirAttaque() < creature2->obtenirAttaque();
	}
};

//Foncteur qui renvoie True si le nom (ordre alphanum�rique) d'un dresseur 1 < dresseur 2
class FoncteurComparerDresseurs
{
public:
	FoncteurComparerDresseurs() {}
	~FoncteurComparerDresseurs() {}

	bool operator() (const Dresseur* dresseur1, const Dresseur* dresseur2) const {
		return dresseur1->obtenirNom() < dresseur2->obtenirNom();
	}
};

//Foncteur qui renvoie True si d�g�ts de pouvoir 1 < pouvoir 2
class FoncteurComparerPouvoirs
{
public:
	FoncteurComparerPouvoirs() {}
	~FoncteurComparerPouvoirs() {}

	bool operator() (const Pouvoir* pouvoir1, const Pouvoir* pouvoir2) const {
		return pouvoir1->obtenirNombreDeDegat() < pouvoir2->obtenirNombreDeDegat();
	}
};

//Foncteur qui renvoie True si le nom d'une cr�ature (en param�tre) = nom cr�ature de la classe
class FoncteurCreaturesDeMemeNom
{
public:
	FoncteurCreaturesDeMemeNom(const std::string& nom): nomDeReference_(nom) {}
	~FoncteurCreaturesDeMemeNom() {}

	bool operator() (const Creature* creature) const {
		return creature->obtenirNom() == nomDeReference_;
	}

private:
	std::string nomDeReference_;
};

//Foncteur qui renvoie True si une cr�ature (en param�tre) = cr�ature de la classe
class FoncteurEgalCreatures
{
public:
	FoncteurEgalCreatures(Creature* creature) : creatureReference_(creature) {}
	~FoncteurEgalCreatures() {}

	bool operator() (const Creature* creature) const {
		return *creature == *creatureReference_;
	}

private:
	Creature* creatureReference_;
};

//Foncteur qui incr�mente un compteur si la cr�ature � des points de vie entre des bornes fix�es
class FoncteurCreatureVie
{
public:
	FoncteurCreatureVie(unsigned int vieMin, unsigned int vieMax)
		:vieMaximale_(vieMax), vieMinimale_(vieMin), compteur_(0) {}
	~FoncteurCreatureVie() {}

	void operator() (const Creature* creature) {
		if (creature->obtenirPointDeVie() >= vieMinimale_ && creature->obtenirPointDeVie() <= vieMaximale_)
			compteur_++;
	}

	unsigned int obtenirCompteur() const {
		return compteur_;
	}

private:
	unsigned int vieMinimale_;
	unsigned int vieMaximale_;
	unsigned int compteur_;
};

//Foncteur qui g�n�re un nombre al�atoire d'une intervalle fix�e
class FoncteurGenerateurNombresAlea
{
public:
	FoncteurGenerateurNombresAlea(unsigned int min, unsigned int max)
		:min_(min), max_(max) {}
	FoncteurGenerateurNombresAlea() : min_(RAND_MIN_DEFAUT), max_(RAND_MAX_DEFAUT) {}
	~FoncteurGenerateurNombresAlea() {}

	unsigned int operator() () {
		return rand() % ((max_ + 1) - min_) + min_; //nombre al�atoire d'une intervalle [min_, max_]
	}

private:
	unsigned int min_; //Borne inf�rieure de l'intervalle
	unsigned int max_; //Borne sup�rieure de l'intervalle
};

#endif;