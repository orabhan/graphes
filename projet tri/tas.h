#ifndef TAS_H_INCLUDED
#define TAS_H_INCLUDED

struct tas
{
  int n;
  int max;
  int *t;
};

typedef struct tas Tas;


void initTas(int nb, Tas *T);
void erreur(int x);
void swap(int *a, int *b);
void imprime(Tas T);
void imprimearbre(Tas T);
int maximum(Tas T);
void insere(int v, Tas *T);
void supprime(Tas *T);
void heapsort(int *tab, int nb);
void printtab(int *A, int nb);
void recherche_elementtas(int *ff,Tas *T,int *J,int *m2);


#endif // TAS_H_INCLUDED

