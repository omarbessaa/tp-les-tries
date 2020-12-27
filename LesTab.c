#include <stdio.h>
#include <stdlib.h>
#include "LesTab.h"
/*
ce fichier source contient les fonctions des 3 methode de trie pour les tableaux

l'ordre est decroisant si Min=0 , croisant sinon


*/


void permute(int *a,int *b)
{
    int X;

    X=*a;
    *a=*b;
    *b=X;
}


void TrieSelec1D(int *T,int N,int *nbrcomp,int *nbrpermut,int const Min)
{
  int i,PosMin,Pos; //PosMax

  i=1;  Pos=0; PosMin=Pos; //PosMax=Pos;

  if (Min)
  {

        while (i<N)
        {
            while(i<N)
            {
              if (T[i]<T[PosMin]) {PosMin=i; (*nbrcomp)++;}
            i++;
            }
            if (PosMin != Pos) {permute(&T[Pos],&T[PosMin]); (*nbrpermut)++;}
         Pos++; PosMin=Pos; i=Pos+1;
        }
}
else
{
         while (i<N)
        {
            while(i<N)
            {
              if (T[i]>T[PosMin]) {PosMin=i; (*nbrcomp)++;}
            i++;
            }
            if (PosMin != Pos) {permute(&T[Pos],&T[PosMin]); (*nbrpermut)++;}
         Pos++; PosMin=Pos; i=Pos+1;
        }
}
}


void TrieBull1D(int *T,int N,int *nbrcomp,int *nbrpermut,int const Min)
{
    int trie=0;
    int i=0;

if (Min)
{


    while (trie==0)
    {
        trie=1;i=0;
     while (i<(N-1))
    {
        if (T[i]>T[i+1]) {permute(&T[i],&T[i+1]); (*nbrpermut)++; trie=0;}
        i++; (*nbrcomp)++;
    }
    N--;
    }
}else
{
     while (trie==0)
    {
        trie=1;i=0;
     while (i<(N-1))
    {
        if (T[i]<T[i+1]) {permute(&T[i],&T[i+1]); (*nbrpermut)++; trie=0;}
        i++; (*nbrcomp)++;
    }
    N--;
    }
}
}


void TrieInser1D(int *T,int N,int *nbrcomp,int *nbrpermut,int const Min)
{
    int i=1,j;


  if (Min)
  {

    while (i<N)
    {
        if (T[i]<T[i-1])
        {
                permute(&T[i],&T[i-1]);
              (*nbrpermut)++; j=i-1;
              while (j>0 && T[j]<T[j-1])
              {
                 permute(&T[j],&T[j-1]);
                 j--;
                 (*nbrcomp)++;
              }
        }
              (*nbrcomp)++;
              i++;
    }
  }else
  {
         while (i<N)
    {
        if (T[i]>T[i-1])
        {
                permute(&T[i],&T[i-1]);
              (*nbrpermut)++; j=i-1;
              while (j>0 && T[j]>T[j-1])
              {
                 permute(&T[j],&T[j-1]);
                 j--;
                 (*nbrcomp)++;
              }
        }
              (*nbrcomp)++;
              i++;
  }
}
}




void remplir1D(int t[100],int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        printf("\n T[%d] =  ",i+1);
        scanf("%d",&t[i]);
    }
}

void affiche1D(int t[100],int n)
{
    int i;

    printf("\n \n \n");

    for (i=0;i<n;i++)
    {
      printf("%d   ",t[i]);
    }
     printf("\n \n \n");
}
