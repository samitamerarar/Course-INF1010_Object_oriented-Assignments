/*
Fichier: AttaqueMagiqueConfusion.h
Auteur(s): Maude Carrier
Date de creation: 11 octobre 2016
Date de modification: 21 novembre 2016 par Tamer Arar et Guy-Frank
Description: Cette attaque magique rend la cr�ature qui la re�oit tellement confuse qu'elle en perd des points de vie
*/
#ifndef ETAT_CONFUS_H
#define ETAT_CONFUS_H

#include <stdlib.h>

#include "AttaqueMagique.h"
#include "Foncteur.h"

#define MIN_DUREE_CONFUSION 3

class AttaqueMagiqueConfusion : public AttaqueMagique
{
public:
    AttaqueMagiqueConfusion(); // � MODIFIER
	AttaqueMagiqueConfusion(unsigned int duree); // � MODIFIER
    virtual ~AttaqueMagiqueConfusion(); 

    virtual void appliquerAttaque(Creature& Creature); // � MODIFIER

    virtual bool estFini() const;

	virtual std::string obtenirTypeAttaque() const;

private:
	FoncteurGenerateurNombresAlea generateurAleatoire_;
};
#endif 




