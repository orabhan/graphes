#ifndef ABR_H_INCLUDED
#define ABR_H_INCLUDED

typedef struct Arbre
{
	int Noeud;
	struct Arbre * SAG;
	struct Arbre * SAD;
} Arbre;


Arbre * ajouter1(Arbre * Racine,int valeur);
Arbre * RechercheNoeud(Arbre * Racine,  int valeur);
Arbre * SupprimerNoeud(Arbre * Racine, int valeur);
void visiter_inordre(Arbre * Racine);
void AfficherArbre(Arbre * Racine);

#endif // ABR_H_INCLUDED
