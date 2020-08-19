/*
Fichier: Elixir.h
Auteur(s): Guy-Frank et Tamer Arar
Date de creation: 11 octobre 2016
Date de modification:  18 octobre 2016
Description: Représente un objet qui rend de l'énergie et de la vie
équivalant au double de la valeur de bonus
*/
#ifndef ELIXIR_H
#define ELIXIR_H

#include "PotionMagique.h"

class Elixir : public PotionMagique
{
public:
	//constructeurs
	Elixir();
	Elixir(const std::string &nom, int bonus);
	~Elixir(); //destructeur

	void utiliserSur(Creature& creature) const; //rend des points de vie et energie à une créature

	friend std::ostream& operator<<(std::ostream& o, const Elixir& e);
};

#endif // !ELIXIR_H