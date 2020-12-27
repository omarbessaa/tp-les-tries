#include <stdio.h>
#include <stdlib.h>
#include "LesMatrc.h"
/*
ce fichier contient les fonctions pour trier ts les  element dune matrice avec les trois methodes

pour trier une matrice ligne par ligne on fait lappelle a les fonctions de trie dun tableau pour chaqe ligne de la matrice

*/



void TrieSelec2D(int **T,int N,int M,int *nbrcomp,int *nbrpermut)
{
   int Min,Ipos=0,Jpos,IposMin,JposMin,i=0,j;

   while (Ipos<N)
   {
       Jpos=0;
       while (Jpos<M)
        {

          Min=(T[Ipos][Jpos]);
          if (Jpos<(M-1)) {i=Ipos;j=Jpos+1;}
          else {i=Ipos;j=0;}

          while (i<N)
          {
           while(j<M)
           {

             if (Min>(T[i][j])) {Min=(T[i][j]); IposMin=i; JposMin=j;}
             j++;  (*nbrcomp)++;
           }
           j=0;i++;
          }
         permute(&T[Ipos][Jpos],&T[IposMin][JposMin]); (*nbrpermut)++;
         Jpos++;
       }
      Ipos++;
}

}


void TrieBull2D(int **T,int N,int M,int *nbrcomp,int *nbrpermut)
{
 int Fin=M,Trie,i,j;

i=0;Trie=0;
 while (Trie==0)
 {
     Trie=1;
 while (i<N)
 {
     j=0;
     if (i==(N-1) && Fin!= M)
     {
         while (j<(Fin-1))
         {
             if (T[i,j]>T[i,j+1]) {permute(&T[i,j],&T[i,j+1]); (*nbrpermut)++;Trie=0;}
             j++;
         }
     }else
     {
         while (j<M)
         {
             if (j==(M-1)) {if ((i+1)<N) {if (T[i,j]>T[i+1,0]) {permute(&T[i,j],&T[i,j+1]); (*nbrpermut)++;Trie=0;}}}
             else {if (T[i,j]>T[i,j+1]) {permute(&T[i,j],&T[i,j+1]); (*nbrpermut)++;Trie=0;}}
             j++;
         }
     }
     Fin--;
     if (Fin==1) {Fin=M;N--;}
     i++;
 }
}
}


void ecrit2 (char tab[100][100],int n,int m)
{
	int i,j;
	  for(i=0;i<n;i++)
    {
        printf("\t\t");
        for(j=0;j<m;j++)
        {
            printf("|%c",tab[i][j]);
        }
        printf("|\n");
    }
printf("\n\n\n");

}


void remp2 (char tab[100][100],int n,int m)
{
	int i,j;
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			printf("tab[%d][%d]=",i,j);
			scanf("%s",&tab[i][j]);
		}
	}
}


int cmp(char mot2[100],char mot[100],int m)//si mot2<mot return 1
{
    int i;
    if (mot[0]>mot2[0])return 1;
    else
    {
        i=1;
        while((i<m) && (mot[i]==mot2[i])) i++;
        if(i==m) return 0;
        else
            {
                if(mot[i]>mot2[i]) return 1;
                else return 0;
            }
}
}





void remplir2D(int t[100][100],int n,int m)
{
    int i,j;
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
         printf("\n T[%d][%d] =  ",i+1,j+1);
         scanf("%d",&t[i][j]);
        }
    }
}


void affiche2D(int t[100][100],int n,int m)
{
	int i,j;
	  for(i=0;i<n;i++)
    {
        printf("\t\t");
        for(j=0;j<m;j++)
        {
            printf("|%d",t[i][j]);
        }
        printf("|\n");
    }
printf("\n\n\n");
}

