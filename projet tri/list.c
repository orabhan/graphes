

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "list.h"
/******************************************************************************/

void ajouter_et_trier(liste **sl, int Val)
{
        liste *tmp = NULL;
        liste *csl = *sl;
        liste *element = malloc(sizeof(liste));
        if(!element) exit(EXIT_FAILURE);
        element->valeur = Val;
        while(csl && csl->valeur < Val)
          {
             tmp = csl;
             csl = csl->suivant;
          }
        element->suivant = csl;
        if(tmp) tmp->suivant = element;
        else *sl = element;
}
/******************************************************************************/

void affichage(liste *sl)
{
       while(sl)
          {
             printf("%d\n",sl->valeur);
             sl = sl->suivant;
          }
}
/******************************************************************************/

liste *rechercherElement(liste *sl, int Val)
{
    liste *tmp=sl;
    /* Tant que l'on n'est pas au bout de la liste */
    while(tmp != NULL)
    {
        if(tmp->valeur == Val)
        {
            /* Si l'élément a la valeur recherchée, on renvoie son adresse */
            return tmp;
       }
        tmp = tmp->suivant;
    }
    return NULL;
}
/*******************************************************************************/

void supprimer(liste **sl)
{
        liste *tmp;
        while(*sl)
          {
             tmp = (*sl)->suivant;
             free(*sl);
             *sl = tmp;
          }
}
/*******************************************************************************/
