#include "CreatureMagique.h"

CreatureMagique::CreatureMagique(): attaqueMagique_(nullptr), bonus_(0)
{
	nom_ = "";
	attaque_ = 0;
	defense_ = 0;
	pointDeVie_ = 0;
	energie_ = 0;
	experience_ = 0;
	niveau_ = 1;
	energieTotal_ = 0;
	experienceNecessaire_ = 0;
	pointDeVieTotal_ = 0;
}

CreatureMagique::CreatureMagique(unsigned int bonus, const Creature & creature) : Creature(creature),
	attaqueMagique_(nullptr), bonus_(bonus)
{
}

CreatureMagique::CreatureMagique(const CreatureMagique & cm)
{
	nom_ = cm.nom_;
	attaque_ = cm.attaque_;
	defense_ = cm.defense_;
	pointDeVie_ = cm.pointDeVie_;
	energie_ = cm.energie_;
	experience_ = cm.experience_;
	niveau_ = cm.niveau_;
	energieTotal_ = cm.energieTotal_;
	experienceNecessaire_ = cm.experienceNecessaire_;
	pointDeVieTotal_ = cm.pointDeVieTotal_;
	bonus_ = cm.bonus_;

	if (cm.attaqueMagique_ != nullptr)
	{
		if (cm.attaqueMagique_->obtenirTypeAttaque() == typeid(AttaqueMagiquePoison).name())
			attaqueMagique_ = new AttaqueMagiquePoison();
		else
			attaqueMagique_ = new AttaqueMagiqueConfusion();

		*attaqueMagique_ = *cm.attaqueMagique_;
	}	
}

CreatureMagique::~CreatureMagique()
{
	delete attaqueMagique_;
}

void CreatureMagique::modifierAttaqueMagique(AttaqueMagique * am)
{
	*attaqueMagique_ = *am;
}

AttaqueMagique * CreatureMagique::obtenirAttaqueMagique()
{
	return attaqueMagique_;
}

void CreatureMagique::modifierBonus(unsigned int bonus)
{
	bonus_ = bonus;
}

unsigned int CreatureMagique::obtenirBonus() const
{
	return bonus_;
}

void CreatureMagique::attaquer(const Pouvoir & pouvoir, Creature& creature)
{
	if (pointDeVie_ + bonus_ < pointDeVieTotal_)		//ajoute le bonus au point de vie de la créature
		pointDeVie_ += bonus_;

	if (!attaqueMagique_->estFini())					//effet de l'attaque magique est appliqué à l'adversaire
		attaqueMagique_->appliquerAttaque(creature);

	Creature::attaquer(pouvoir, creature);				//attaque normale
}

void CreatureMagique::apprendreAttaqueMagique(AttaqueMagique * am)
{
	if (attaqueMagique_ == nullptr)
		attaqueMagique_ = am;
	else
	{
		delete attaqueMagique_;
		modifierAttaqueMagique(am);
	}
}

void CreatureMagique::oublierAttaqueMagique()
{
	if (attaqueMagique_ != nullptr)
	{
		delete attaqueMagique_;
		attaqueMagique_ = nullptr;
	}
}

CreatureMagique & CreatureMagique::operator=(const CreatureMagique & cm)
{
	Creature::operator=(cm);

	if (cm.attaqueMagique_ != nullptr)
	{
		oublierAttaqueMagique();	//libérer la mémoire allouée à l'attaque magique

		if (cm.attaqueMagique_->obtenirTypeAttaque() == typeid(AttaqueMagiquePoison).name())
			attaqueMagique_ = new AttaqueMagiquePoison();
		else
			attaqueMagique_ = new AttaqueMagiqueConfusion();

		*attaqueMagique_ = *cm.attaqueMagique_;
	}
	
	bonus_ = cm.bonus_;

	return *this;
}

std::ostream & operator<<(std::ostream & o, CreatureMagique & cm)
{
	return o << static_cast<Creature&>(cm)	//appel de l'operateur<< de la classe Creature
		<< std::endl << "Cette créature de la " << cm.obtenirTypeCreature() << " a aussi une attaque magique de type "
		<< cm.obtenirAttaqueMagique()->obtenirTypeAttaque() << " qui a une durée de " << cm.obtenirAttaqueMagique()->obtenirDuree()
		<< std::endl;
}
