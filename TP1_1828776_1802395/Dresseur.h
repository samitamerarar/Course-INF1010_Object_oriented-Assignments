/*
Fichier: Dresseur.h
Auteur(s): Guy-Frank, Tamer Arar
Date de creation: 31 aout 2016
Date de modification: 4 septembre 2016
Description: les dresseurs sont les etres capables d'attraper des creatures
*/

#ifndef DRESSEUR_H
#define DRESSEUR_H

#include <string>
#include "Creature.h"
#include "ObjetMagique.h"

#define MAX_NOMBRE_CREATURES 2

class Dresseur
{
public:
    Dresseur();
    Dresseur(const std::string& nom);
    ~Dresseur();

    std::string obtenirNom() const;
    void modifierNom(const std::string& nom);

    ObjetMagique obtenirObjetMagique() const;
    void modifierObjetMagique(const ObjetMagique& objetMagique);

    void utiliserObjetMagique(Creature* creature);
	unsigned int obtenirNombreCreaturesMax() const;

	unsigned int obtenirNombreCreatures() const;

    Creature** obtenirCreatures() const;
    void modifierCreature(Creature** creatures);

    bool ajouterCreature(const Creature& creature);
    bool retirerCreature(const std::string& nom);

    void affichage() const;

private:
    std::string nom_;
    Creature** creatures_;
    unsigned int nombreCreatures_;
    unsigned int nombreCreaturesMax_;
    ObjetMagique objetMagique_;

};

#endif