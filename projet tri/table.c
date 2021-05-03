

#include <stdio.h>
#include "table.h"
#include <conio.h>
#include <malloc.h>
//tri par shell

void triShell(int tableau[], const int longueur)
{
   int pas, i, j, memoire;
   pas = 0;

   // Calcul du pas
   while(pas<longueur)
   {
      pas = 3*pas+1;
   }

   while(pas!=0) // tant que le pas est > 0
   {
      pas = pas/3;
      for(i=pas; i<longueur; i++)
      {
         memoire = tableau[i]; // valeur à décaler éventuellement
         j = i;

         while((j>(pas-1)) && (tableau[j-pas]>memoire))
         { // échange des valeurs
            tableau[j] = tableau[j-pas];
            j = j-pas;
         }
         tableau[j] = memoire;
      }
   }
}



//tri rapide
void echanger(int tableau[], int a, int b)
{
    int temp = tableau[a];
    tableau[a] = tableau[b];
    tableau[b] = temp;
}

void quickSort(int tableau[], int debut, int fin)
{
    int gauche = debut-1;
    int droite = fin+1;
    const int pivot = tableau[debut];

    /* Si le tableau est de longueur nulle, il n'y a rien à faire. */
    if(debut >= fin)
        return;

    /* Sinon, on parcourt le tableau, une fois de droite à gauche, et une
      autre de gauche à droite, à la recherche d'éléments mal placés,
       que l'on permute. Si les deux parcours se croisent, on arrête. */
   while(1)
   {
        do droite--; while(tableau[droite] > pivot);
        do gauche++; while(tableau[gauche] < pivot);

        if(gauche < droite)
            echanger(tableau, gauche, droite);
        else break;
    }

    /* Maintenant, tous les éléments inférieurs au pivot sont avant ceux
       supérieurs au pivot. On a donc deux groupes de cases à trier. On utilise
       pour cela... la méthode quickSort elle-même ! */
    quickSort(tableau, debut, droite);
    quickSort(tableau, droite+1, fin);
}




////////////////////////////////////////
void tri_insertion(int tab[], int taille)
{
   int i, j;
   for (i = 1; i < taille; ++i) {
       int elem = tab[i];
       for (j = i; j > 0 && tab[j-1] > elem; j--)
           tab[j] = tab[j-1];
       tab[j] = elem;
   }
}
///////////////////////////////////////////////////
void fusion(int tableau[],int deb1,int fin1,int fin2)
        {
        int *table1;
        int deb2=fin1+1;
        int compt1=deb1;
        int compt2=deb2;
        int i;

        table1=(int *)malloc((fin1-deb1+1)*sizeof(int));

        //on recopie les éléments du début du tableau
        for(i=deb1;i<=fin1;i++)
            {
            table1[i-deb1]=tableau[i];
            }

        for(i=deb1;i<=fin2;i++)
            {
            if (compt1==deb2) //c'est que tous les éléments du premier tableau ont été utilisés
                {
                break; //tous les éléments ont donc été classés
                }
            else if (compt2==(fin2+1)) //c'est que tous les éléments du second tableau ont été utilisés
                {
                tableau[i]=table1[compt1-deb1]; //on ajoute les éléments restants du premier tableau
                compt1++;
                }
            else if (table1[compt1-deb1]<tableau[compt2])
                {
                tableau[i]=table1[compt1-deb1]; //on ajoute un élément du premier tableau
                compt1++;
                }
            else
                {
                tableau[i]=tableau[compt2]; //on ajoute un élément du second tableau
                compt2++;
                }
            }
        free(table1);
        }


void tri_fusion_bis(int tableau[],int deb,int fin)
        {
        if (deb!=fin)
            {
            int milieu=(fin+deb)/2;
            tri_fusion_bis(tableau,deb,milieu);
            tri_fusion_bis(tableau,milieu+1,fin);
            fusion(tableau,deb,milieu,fin);
            }
        }

void tri_fusion(int tableau[],int longueur)
     {
     if (longueur>0)
            {
            tri_fusion_bis(tableau,0,longueur-1);
            }
     }
//////////////////////////////////////////////////////////////////////////////////////////////////////////



void initTdy(int m1, Td *T)
{
  (*T).h=(int *)malloc(sizeof(int)*m1);
  (*T).a=m1;
}
///////////////////////////////////////////////////////////////
void ajouterTd(Td *T,int q){
    int i;
    i=(*T).a;
    i++;
    (*T).a=i;
    (*T).h[i]=q;
    }
//////////////////////////////////////////////////////////////
void recher(int *ff,Td *T,int *J,int *m2){
int i;
int j=0;

for (i=0;i<(*T).a;i++){
    if(*ff==(*T).h[i])
    J[j]=i;
    j++;
}
m2=&j;
};
///////////////////////////////////////////////////////////////////////////
void suppr(int ff,Td *T)
{       int k;
        int m2;

        int J[(*T).a];
        int v=(*T).a;
        int j=0;
        recher(&ff,T,J,&m2);
     for(k=0;k<(*T).a;k++){
         do{
         if(J[j]==k){
                   (*T).h[k]=(*T).h[v-1];
                    (*T).a=(*T).a-1;
         }
         j++;
         }while(j<=m2);
     }
     }
