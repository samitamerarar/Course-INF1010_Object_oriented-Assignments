/*
Fichier: AttaqueMagiquePoison.h
Auteur(s): Maude Carrier
Date de creation: 11 octobre 2016
Date de modification: 21 novembre 2016 par Tamer Arar et Guy-Frank
Description: La cr�ature qui re�oit cette attaque perd de l'�nergie due au poison
*/
#ifndef ETAT_EMPOISONNE_H
#define ETAT_EMPOISONNE_H

#include "AttaqueMagique.h"
#include "Foncteur.h"


#define MIN_DUREE_POISON 2

class AttaqueMagiquePoison : public AttaqueMagique
{
public:
    AttaqueMagiquePoison(); // � MODIFIER
	AttaqueMagiquePoison(unsigned int duree); // � MODIFIER
    virtual ~AttaqueMagiquePoison();

    virtual void appliquerAttaque(Creature& Creature); // � MODIFIER

    virtual bool estFini() const;
	
	virtual std::string obtenirTypeAttaque() const;

private:
	FoncteurGenerateurNombresAlea generateurAleatoire_;
};
#endif // !ETAT_EMPOISONNE_H