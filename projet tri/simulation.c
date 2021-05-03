#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "abr.h"
#include "list.h"
#include "table.h"
#include "tas.h"
#include <windows.h>
#include "avl.h"

/////////////////////////////////////////////////////////////////////////////////////
//tri tableau
void resultat3(int *B,int N,int d){
    switch(d)
			{
			case 1:{
			    tri_insertion(B,N);

				break;
				}
			case 2:tri_fusion_bis(B,0,N-1);

			break;
			case 3:quickSort(B,0,N-1);

			break;
			case 4:triShell(B,N);

break;
default:
break;
}}


////////////////////////////////////////////////////////////////////////////////////
void mode(int *A,int N)
{
    int g,i,r;

     printf("\nchoisir une mode pour simuler: \n\n 1-automatique\n 2-manuelle\n " );

     do
     {
         fflush(stdin);
         printf("->");
       scanf("%d",&g);
       if(g!=1 && g!=2){
        printf("votre choix %d invalide  entrer 1 ou 2 \n ",g);}
     }while((g!=1) && (g!=2));






     if(g==2)
     {
     printf("-Entrez les valeurs valeurs pour commencer le tri:\n");

     for(i=0;i<=N-1;i++)
         {

         scanf("%d",&r);
         A[i]=r;

         }
     }
     else
     {
             for(i=0;i<=N-1;i++)
            {
             A[i]=rand()%1000;
            }
     }


     printf("l'ensemble est :    ");

     printf("~~  ");
 for(i=0;i<=N-1;i++)
     {

         printf("%d  ",A[i]);
     }
     printf("~~");

}
/////////////////////////////////////////////////////////////////////////////////////////
void resultat2(int *T){
 int c;
  int i=0;


    printf("\n***********   M E N U   ***********\n                                  *\n 1-->Tableau                      *\n 2-->Liste chain%ces               *\n 3-->arbre binaire de recherche   *\n 4-->AVL(ADELSON-VELSKII et LANDI)*\n 5-->Tas                          *\n***********************************\n",130 );
    printf("-Choisir les structures de donn%ces pour la simulation\nentrez 0 pour passer %c l'%ctape suivante:  ",130,133,130);
  do
    {
        fflush(stdin);
        scanf("%d",&c);
        if(c<6&& c>0){
        T[i]=c;
        i=i+1;
        printf("\n-Choisir d'autres structures  \nentrez 0 pour passer %C l'%ctape suivante: ",133,130);
        }
        else{
            if(c!=0)
printf("-entrer des valeurs comprises entre 0 et 6:  ");
            }
    }while (c!=0);

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






////////////////////////////////////////////////////////////////////
void remplissage(int *A, int N)
{
int i;
srand(time(NULL));
    for(i=0;i<N;i++)
    {
        A[i]=rand();//%(10000) ;
    }
}


////////////////////////////////////////////////////////////////////
double temp_dexecution_tableau(int N,int d)
{
clock_t start;
    int *A=(int *)malloc(N*sizeof(int));
    remplissage(A,N);
double t;
start = clock();
resultat3(A,N,d);

t = (double)(clock()-start)/(double)CLOCKS_PER_SEC;
return t;
}
/////////////////////////////////////////////////////////////////////////

double temp_dexecution_liste(int N)
{
clock_t start;
    int *A=(int*)malloc(N*sizeof(int)),j;
    remplissage(A,N);
    double t;


    start = clock();
     		liste *liste1=NULL;
		for(j=0;j<N;j++){
		ajouter_et_trier(&liste1,A[j]);
		}


 t = (double)(clock()-start)/(double)CLOCKS_PER_SEC;
 return t;
}
//////////////////////////////////////////////////////
double temp_dexecution_ABR(int N)
{
clock_t start;
    int *A=(int *)malloc(N*sizeof(int)),j;
    remplissage(A,N);
    int valeur;
    double t;
Arbre * Racine;
Racine=NULL;
    start = clock();

	for(j=0;j<N;j++){
	    valeur=A[j];
		Racine=ajouter1(Racine,valeur);}

    t = (double)(clock()-start)/(double)CLOCKS_PER_SEC;
return t;
   }

////////////////////////////////////////////////////////

double temp_dexecution_AVL(int N)
{
clock_t start;
    int *A=(int *)malloc(N*sizeof(int)),j;
    remplissage(A,N);
    node *DHH;
    DHH=NULL;
    double t;

    start = clock();

	for(j=0;j<N;j++){
	    DHH=insert(A[j],DHH);}
        Inorder( DHH);
    t= (double)(clock()-start)/(double)CLOCKS_PER_SEC;
return t;
   }
///////////////////////////////////////////////////////
double temp_dexecution_TAS(int N)
{
clock_t start;

int *A=(int *)malloc(N*sizeof(int));

    remplissage(A,N);
    double t;


start = clock();
  heapsort(A,N);


    t = (double)(clock()-start)/(double)CLOCKS_PER_SEC;
return t;
   }

///////////////////////////////////////////////////////////

////////////////////PLOTSTRUCTURES////////////////////////

/////////////////////////////////////////////////////////

void plotstructuretableau(int d)
{
int N;


 		char    gnu[FILENAME_MAX] = "tri_plot1.plt";
		char    DTABL[FILENAME_MAX] = "TABL";

        FILE    *fp;
        fp = fopen(gnu,"w");
fprintf(fp,"  set xlabel \"taille de tableau N\" \n\n");
fprintf(fp,"  set ylabel \"Temp d'execution (ms) \" \n\n");
fprintf(fp," set zeroaxis lt 8\n");
fprintf(fp," set grid\n\n");
fprintf(fp," plot  \"%s\" with lines \n\n",DTABL);
fprintf(fp," reset");
fclose(fp);
fp = fopen(DTABL,"w");
for (N=10;N<=100000;N=N+10000)
{
    fprintf(fp," %d   %.3f \n",N,temp_dexecution_tableau(N,d)*1000);}
fclose(fp);
}
/////////////////////////////////////////////////////////

void plotstructureliste()
{
int N;

		FILE    *fp;
 		char    gnu[FILENAME_MAX] = "tri_plot2.plt";
		char    DLISTE[FILENAME_MAX] = "LISTE";
		fp = fopen(gnu,"w");

fprintf(fp,"  set xlabel \"taille de tableau N\" \n\n");
fprintf(fp,"  set ylabel \"Temp d'execution (ms) \" \n\n");
fprintf(fp," set zeroaxis lt 8\n");
fprintf(fp," set grid\n\n");
fprintf(fp," plot  \"%s\" with lines \n\n",DLISTE);
fprintf(fp," reset");
fclose(fp);
fp= fopen(DLISTE,"w");
for (N=10;N<=10000;N=N+3000)
{
    fprintf(fp," %d   %.3f \n",N,temp_dexecution_liste(N)*1000);}
fclose(fp);
}
////////////////////////////////////////////////////////////
void plotstructureABR()
{
int N;

		FILE    *fp;
 		char    gnu[FILENAME_MAX] = "tri_plot3.plt";
		char    DABR[FILENAME_MAX] = "ABR";
		fp = fopen(gnu,"w");

fprintf(fp,"  set xlabel \"taille de tableau N\" \n\n");
fprintf(fp,"  set ylabel \"Temp d'execution (ms) \" \n\n");
fprintf(fp," set zeroaxis lt 8\n");
fprintf(fp," set grid\n\n");
 fprintf(fp," plot  \"%s\" with lines \n\n",DABR);
fprintf(fp," reset");
fclose(fp);
fp= fopen(DABR,"w");
for (N=10;N<=100000;N=N+50000)
{
    fprintf(fp," %d   %.3f \n",N,temp_dexecution_ABR(N)*10000);}
fclose(fp);
}
////////////////////////////////////////////////////////////
void plotstructureAVL()
{
int N;

		FILE    *fp;
 		char    gnu[FILENAME_MAX] = "tri_plot4.plt";
		char    DAVL[FILENAME_MAX] = "AVL";
		fp = fopen(gnu,"w");

fprintf(fp,"  set xlabel \"taille de tableau N\" \n\n");
fprintf(fp,"  set ylabel \"Temp d'execution (ms) \" \n\n");
fprintf(fp," set zeroaxis lt 8\n");
fprintf(fp," set grid\n\n");
 fprintf(fp," plot  \"%s\" with lines \n\n",DAVL);
fprintf(fp," reset");
fclose(fp);
fp= fopen(DAVL,"w");
for (N=10;N<=3500;N=N+50)
{
    fprintf(fp," %d   %.3f \n",N,temp_dexecution_AVL(N)*1000);}
fclose(fp);
}
////////////////////////////////////////////////////////////
void plotstructureTAS()
{
int N;

		FILE    *fp;
 		char    gnu[FILENAME_MAX] = "tri_plot5.plt";
		char    DTAS[FILENAME_MAX] = "TAS";
		fp = fopen(gnu,"w");

fprintf(fp,"  set xlabel \"taille de tableau N\" \n\n");
fprintf(fp,"  set ylabel \"Temp d'execution (ms) \" \n\n");
fprintf(fp," set zeroaxis lt 8\n");
fprintf(fp," set grid\n\n");
fprintf(fp," plot  \"%s\" with lines \n\n",DTAS);
fprintf(fp," reset");
fclose(fp);
fp = fopen(DTAS,"w");
for (N=1;N<=100000;N=N+1000)
{
    fprintf(fp," %d   %.3f \n",N,temp_dexecution_TAS(N)*1000);}
fclose(fp);
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
void resultat1(int *T,int N)
{
    double start;
    Tas P;
    int i=0;
    int d5;
    int valeur,d,j;
    Arbre * Racine;
	liste *liste1=NULL;
	Racine=NULL;
	int A[N];
	int B[N];
	double tempsexe;
        node *DHH;
        DHH=NULL;
        printf("\n2-LE MODE DE SIMULATION\n********************************************************************************\n");
        mode(A,N);
 printf("\n\n3-RESULTATS DE TRI\n********************************************************************************\n");

do
{
    switch(T[i])
   {
  case 1:{ printf("\n********   TABLEAU   ********\n");

 printf("******************************\nchoisir un tri:              * \nchoix-->1- tri par insertion *\nchoix-->2-tri par fusion     *\nchoix-->3-tri rapide         *\nchoix-->4-tri par shell      *\n******************************\n ");
    start=clock();
 do{

		scanf("%d",&d);
		if(d<1 && d>4)
		printf("entrer une valeur entre 1 et 4\n");
		}while(d<1 && d>4);
		printf("avant le tri : ");
   for(j = 0; j < N; j++) printf("%d ", A[j]);
    printf("\n");
    for(j = 0; j < N; j++){B[j]=A[j];}
resultat3(B,N,d);
tempsexe = (double)(clock()-start)/(double)CLOCKS_PER_SEC;
printf("apr%cs le tri : ",130);
    for(j = 0; j < N; j++) printf("%d ", B[j]);
    printf("\n");
    printf("\n\n                                         %f ms",tempsexe*1000);
  break;}
  case 2 :{  printf("\n********   LISTE    ********\n");

printf("apr%cs le tri: \n",130);

start=clock();

for(j=0;j<N;j++){
		ajouter_et_trier(&liste1,A[j]);}
		affichage(liste1);
tempsexe = (double)(clock()-start)/(double)CLOCKS_PER_SEC;


printf("\n  %f ms",tempsexe*1000);
  break;}
  case 3 :{printf("\n********   ABR   ********\n");

start=clock();
for(j=0;j<N;j++){
    valeur=A[j];
		Racine=ajouter1(Racine,valeur);}
		printf("affichage de l'arbre:\nracine-fg-fd: \n");
        AfficherArbre(Racine);
printf("\napr%cs le tri: \n",130);
visiter_inordre(Racine);
tempsexe = (double)(clock()-start)/(double)CLOCKS_PER_SEC;
printf("\n\n                                     %f ms",tempsexe*1000);
  break;}

  case 4 :{printf("\n********   AVL   ********\n");
start=clock();
for (j=0;j<N;j++)
    {

        DHH=insert(A[j],DHH);

    }
    printf("\napr%cs le tri:\n",130);
Inorder(DHH);
tempsexe = (double)(clock()-start)/(double)CLOCKS_PER_SEC;
printf("\n\n                                     %f ms",tempsexe*1000);
  break;}
  case 5:{printf("\n********   TAS   ********\n");

initTas(N,&P);
start=clock();

    printf("avant le tri:\n");
  printtab(A,N);
  heapsort(A,N);
  tempsexe = (double)(clock()-start)/(double)CLOCKS_PER_SEC;
  printf("apr%cs le tri:\n",130);
  printtab(A,N);
printf("\n\n                                                 %f ms",tempsexe*1000);
  break;}
  default:
  break;
}

       i=i+1;
    }while (T[i]!=0);
    printf("\n-FIN DE SIMULATION~~\n");
    printf("\n4-les graphes :\n");
  i=0;
printf("\n********   PLOT   ********\n");

 printf("********************************************************************************\nentrer un choix:              \nchoix-->1- entrer 1 pour ploter les graphes de structures choisis\n\n \nchoix-->2-appuyer sur une autre touche pour quitter      \n********************************************************************************\n");
scanf("%d",&d5);
if(d5==1){
do
{
    switch(T[i])
   {
  case 1:plotstructuretableau(d);
  system("start tri_plot1.plt ");
        break;
  case 2:plotstructureliste();
  system("start tri_plot2.plt");
            break;
  case 3: plotstructureABR();
  system("start tri_plot3.plt");
            break;
  case 4:plotstructureAVL();
  system("start tri_plot4.plt ");
        break;
  case 5:plotstructureTAS();
  system("start tri_plot5.plt ");
            break;
default:
  break;
}

       i=i+1;
    }while (T[i]!=0);}
}

////////////////////////////////////////////////////////////////////////////////////////
int main()
{
int T[6];
int N=0;

   printf("\t\t********************       ++++++++++++++++++++++\n");
          printf("\t\t* ENSA Khouribga   *       +   TC: section 2    +\n");
          printf("\t\t********************       ++++++++++++++++++++++\n\n");
          printf("\t\t********************       ++++++++++++++++++++++\n");
          printf("\t\t* mati%cre:algo avc *       + Prof: IMAD HAFIDI  +\n",130);
          printf("\t\t********************       ++++++++++++++++++++++\n\n");
          printf("\t\t*************************************************\n");
          printf("\t\t*      PROJET TRI                               *\n");
          printf("\t\t*                                               *\n");
          printf("\t\t*************************************************\n\n");
          printf("\t\t*************************************************\n");
          printf("\t\t*          R%calis%c Par:                         *\n",130,130);
          printf("\t\t*          Rabhani Oussama       N:99           *\n");
          printf("\t\t*          Bassam Ouizgane       N:97           *\n");
          printf("\t\t*                                               *\n");
          printf("\t\t*                                               *\n");
          printf("\t\t*************************************************\n\n");
          printf("\t\t******************ETAPES*************************\n");
          printf("\t\t* 1---->choisir les structures à simuler        *\n");
          printf("\t\t* 2---->choisir le mode de simulation           *\n");
          printf("\t\t* 3---->entrer l'ensemble des valeurs à trier   *\n");
          printf("\t\t*************************************************\n\n");
printf("1-LES STRUCURES DE DONNEES\n********************************************************************************\n");


resultat2(T);
printf("\n-combien des valeurs voulez vous triez:  ");
scanf("%d",&N);
resultat1(T,N);
getch();
return 0;
}

