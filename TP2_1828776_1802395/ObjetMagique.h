/*
Fichier: ObjetMagique.h
Auteur(s): Guy-Frank, Tamer Arar
Date de creation: 14 septembre 2016
Date de modification: 3 octobre 2016
Description: (classe) Les objets magiques sont utilisés sur des creatures pour augmenter leurs attributs.
*/

#ifndef OBJETMAGIQUE_H
#define OBJETMAGIQUE_H

#include <ostream>
#include <string>

class ObjetMagique
{
public:
	ObjetMagique();
	ObjetMagique(const std::string &nom, int bonus);
	~ObjetMagique();

	std::string obtenirNom() const;
	int obtenirBonus() const;

	void modifierNom(const std::string& nom);
	void modifierBonus(int bonus);

	friend std::ostream& operator<<(std::ostream& o, const ObjetMagique& om);

private:
	std::string nom_;
	int bonus_;
};

#endif
