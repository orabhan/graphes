
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "abr.h"



 Arbre * ajouter1(Arbre * Racine,int valeur)
{
	if (Racine!=NULL)
	{
		if (Racine->Noeud>valeur)
		{
			Racine->SAG=ajouter1(Racine->SAG,valeur);
		}
		else
		{
			Racine->SAD=ajouter1(Racine->SAD,valeur);
		}
	}
	else
	{
		Racine=(Arbre *)malloc(sizeof(Arbre));
		Racine->Noeud=valeur;
		Racine->SAD=NULL;
		Racine->SAG=NULL;
	}
return Racine;
}
/////////////////////////////////////////////////////////////////

Arbre * RechercheNoeud(Arbre * Racine,  int valeur)
{
	if (Racine!=NULL)
	{
		if (Racine->Noeud>valeur)
		{
			Racine=RechercheNoeud(Racine->SAG,valeur);
		}
		else
		{
			if (Racine->Noeud<valeur)
			{
				Racine=RechercheNoeud(Racine->SAD,valeur);
			}
		}
		return Racine;
	}
}
/////////////////////////////////////////////////////////////////
Arbre * SupprimerNoeud(Arbre * Racine, int valeur)
{
	Arbre * NoeudASupprimer;
	if (Racine->Noeud==valeur) // on a trouvé l'élément à supprimer
	{
		NoeudASupprimer=Racine;
		if (NoeudASupprimer->SAG==NULL) //si ya pa de SAG, on retourne SAD
			return NoeudASupprimer->SAD;
		else
		{
			Racine=NoeudASupprimer->SAG; //sinon on recherche dans SAG l'endroit pour insérer le SAD
				while (Racine->SAD!=NULL)
				{
					Racine=Racine->SAD;
				}
				Racine->SAD=NoeudASupprimer->SAD;
			return NoeudASupprimer->SAG;
		}
		free(NoeudASupprimer);
	}
	else
	{
		if (Racine->Noeud>valeur)
		{
			Racine->SAG=SupprimerNoeud(Racine->SAG,valeur);
		}
		else
		{
			Racine->SAD=SupprimerNoeud(Racine->SAD,valeur);
		}
	}
	return Racine;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
void visiter_inordre(Arbre * Racine)
{
	if (Racine!=NULL)
	{
		visiter_inordre(Racine->SAG);
		printf("%d ",Racine->Noeud);
		visiter_inordre(Racine->SAD);
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
void AfficherArbre(Arbre * Racine)
{
	if (Racine!=NULL)
	{
		printf("%d ",Racine->Noeud);
		if (Racine->SAD!=NULL || Racine->SAG!=NULL)
		{
			AfficherArbre(Racine->SAG);
			AfficherArbre(Racine->SAD);
		}
	}
}

