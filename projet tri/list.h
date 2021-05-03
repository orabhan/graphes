#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

        typedef struct liste
        {
                int valeur;
                struct liste *suivant;
        } liste ;


void ajouter_et_trier(liste **sl, int Val);
void affichage(liste *sl);
liste *rechercherElement(liste *sl, int Val);
void supprimer(liste **sl);




#endif // LIST_H_INCLUDED
