/*
Fichier: Dresseur.h
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification: 21 novembre 2016 par Tamer Arar et Guy-Frank
Description: les dresseurs sont les etres capables d'attraper des creatures
*/
#ifndef DRESSEUR_H
#define DRESSEUR_H

#include <string>
#include <iostream>
#include <list>

#include "Creature.h"
#include "ObjetMagique.h"

class Dresseur
{
public:
	Dresseur();
	Dresseur(const std::string& nom, const std::string& equipe);
	~Dresseur();

	std::string obtenirNom() const;
	void modifierNom(const std::string& nom);

	unsigned int obtenirNombreCreatures() const;

	std::list<Creature*> obtenirCreatures() const;

	//Tester si la cr�ature est pr�sente
	Creature* obtenirUneCreature(const std::string& nom) const;
	void modifierCreature(std::list<Creature*>  creatures);

	bool ajouterCreature(Creature* creature);
	bool enleverCreature(const std::string& nom);

	ObjetMagique obtenirObjetMagique() const;
	void modifierObjetMagique(const ObjetMagique& objetMagique);

	void utiliserObjetMagique(Creature* creature);

	std::string obtenirEquipe() const;
	void modifierEquipe(const std::string& equipe);

	friend std::ostream& operator<<(std::ostream& os, const Dresseur& dresseur);

	//D�terminer si les m�mes dresseurs poss�dent les m�mes cr�atures 
	bool operator==(const Dresseur& dresseur) const;
	bool operator==(const std::string& nom) const;
	friend bool operator==(const std::string& nom, const Dresseur& dresseur);

	//Appliquer un foncteur unaire � toutes les cr�atures du conteneur
	template<typename FoncteurUnaire>
	void appliquerFoncteurUnaire(FoncteurUnaire& foncteur)
	{
		foncteur = std::for_each(creatures_.begin(), creatures_.end(), foncteur);
	}

	//Supprimer les �l�ments du conteneur selon un foncteur = true
	template<typename FoncteurUnaire>
	void supprimerElements(FoncteurUnaire foncteur)
	{
		creatures_.remove_if(foncteur);
	}

	//Selon l'ordre �tabli par le foncteur, retourner la cr�ature max
	template<typename FoncteurUnaire>
	Creature* obtenirCreatureMax(FoncteurUnaire foncteur)
	{
		return *std::max_element(creatures_.begin(), creatures_.end(), foncteur);
	}

private:
	std::string nom_;
	std::string equipe_;
	ObjetMagique objetMagique_;
	// � COMPL�TER !! cr�atures
	std::list<Creature*> creatures_;
};

#endif