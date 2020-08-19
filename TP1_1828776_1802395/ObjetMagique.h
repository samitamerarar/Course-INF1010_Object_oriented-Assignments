/*
Fichier: ObjetMagique.h
Auteur(s): Guy-Frank et Tamer Arar
Date de creation: 14 septembre 2016
Date de modification: 20 septembre 2016
Description: les objets magiques sont utilisables sur des créatures du monde de Polyland.
*/

#ifndef OBJETMAGIQUE_H
#define OBJETMAGIQUE_H

#include <string>

class ObjetMagique 
{
public:

	//constructeur par defaut et par parametres
	ObjetMagique();		

	ObjetMagique(const std::string& nom, int bonus);		
	
	~ObjetMagique();	//destructeur

	//methodes d'acces et modifications
	std::string obtenirNom() const;
	void setNom(const std::string& nom);

	int obtenirBonus() const;
	void setBonus(const int bonus);

	void affichage();

private:

	//Attributs
	std::string nom_;
	int bonus_;

};

#endif