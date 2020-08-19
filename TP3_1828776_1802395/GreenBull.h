/*
Fichier: GreenBull.h
Auteur(s): Guy-Frank et Tamer Arar
Date de creation: 11 octobre 2016
Date de modification:  18 octobre 2016
Description: Repr�sente un objet qui rend de l'�nergie � une cr�ature
*/
#ifndef GREEN_BULL_H
#define GREEN_BULL_H

#include "ObjetMagique.h"

class GreenBull : public ObjetMagique
{
public:
	//constructeurs
	GreenBull();
	GreenBull(const std::string &nom, int bonus);
	~GreenBull(); //destructeurs

	void utiliserSur(Creature& creature) const; //rend de l'�nergie � une cr�ature

	friend std::ostream& operator<<(std::ostream& o, const GreenBull& g);
};

#endif // !GREEN_BULL_H