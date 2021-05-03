#include <stdio.h>
#include <stdlib.h>
#include "tas.h"


void initTas(int nb, Tas *T)
{
  (*T).t=(int *)malloc(sizeof(int)*nb);
  (*T).max=nb;
  (*T).n=0;
}
/********************************************************/
void erreur(int x)
{
  printf("Erreur (%d)\n",x);
  exit(x);
}

void swap(int *a, int *b)
{
  int t=*a; *a=*b; *b=t;
}

/********************************************************/
void imprime(Tas T)
{
  int i;
  for(i=0;i<T.n;i++)
    printf("%d ",T.t[i]);
  printf("\n");
}

void imprimearbre(Tas T)
{
  int i,j,k;
  j=0;
  k=1;
  for(i=0;i<T.n;i++)
    {
      printf("%d ",T.t[i]);
      if (i==j)
        {
          printf("\n");
          k*=2;
          j+=k;
        }
    }
  printf("\n\n");
}
/**********************************************************/

int maximum(Tas T)
{
  return T.t[0];
}

void insere(int v, Tas *T)
{
  int i=(*T).n;
  if (i==(*T).max)
    erreur(-1);
  (*T).t[i]=v;
  while ((i>0) && ((*T).t[i]>=(*T).t[(i-1)/2]))
    {
      swap(&((*T).t[i]),&((*T).t[(i-1)/2]));
      i=(i-1)/2;
    }
  (*T).n++;
}

void supprime(Tas *T)
{
  int i,cont;

  if ((*T).n==0)
    erreur(-2);
  (*T).n--;
  (*T).t[0]=(*T).t[(*T).n];
  i=0;
  do
    {
      cont=0;
      if (2*i+2<(*T).n)
        {
          if (((*T).t[2*i+1]>=(*T).t[2*i+2])&&((*T).t[i]<=(*T).t[2*i+1]))
            {
              swap(&((*T).t[i]),&((*T).t[2*i+1]));
              cont=1;
              i=2*i+1;
            }
          else
            if (((*T).t[2*i+1]<=(*T).t[2*i+2])&&((*T).t[i]<=(*T).t[2*i+2]))
              {
                swap(&((*T).t[i]),&((*T).t[2*i+2]));
                cont=1;
                i=2*i+2;
              }
        }
      else
        if (2*i+1<(*T).n)
          if ((*T).t[i]<=(*T).t[2*i+1])
            {
              swap(&((*T).t[i]),&((*T).t[2*i+1]));
              cont=1;
              i=2*i+1;
            }
    }
  while (cont);
}

/*********************************************************
  Tri par tas (Heapsort)
*********************************************************/
void heapsort(int *tab, int nb)
{
  Tas T;
  int i;

  initTas(nb,&T);
  for(i=0;i<nb;i++)
    insere(tab[i],&T);
  for(i=nb-1;i>=0;i--)
    {
      tab[i]=maximum(T);
      supprime(&T);
    }
  free(T.t);
}
/************************************************************/
void printtab(int *A, int nb)
{
  int i;
  for(i=0;i<nb;i++)
    printf("%d ",A[i]);
  printf("\n");
}


void recherche_elementtas(int *ff,Tas *T,int *J,int *m2){

int i;
int j=0;

for (i=0;i<(*T).n;i++){
    if(*ff==(*T).t[i])
    J[j]=i;
    j++;
}
m2=&j;
};




