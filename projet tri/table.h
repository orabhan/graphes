#ifndef TABLE_H_INCLUDED
#define TABLE_H_INCLUDED
typedef struct tableaudynamiqque{
int a;
int *h;
}Td;

void triShell(int tableau[], const int longueur);
void echanger(int tableau[], int a, int b);
void quickSort(int tableau[], int debut, int fin);
void tri_insertion(int tab[], int taille);
void fusion(int tableau[],int deb1,int fin1,int fin2);
void tri_fusion_bis(int tableau[],int deb,int fin);
void tri_fusion(int tableau[],int longueur);


void initTdy(int m1, Td *T);
void ajouterTd(Td *T,int q);
void recher(int *ff,Td *T,int *J,int *m2);
void suppr(int ff,Td *T);


#endif // TABLE_H_INCLUDED
