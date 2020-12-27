#ifndef LESMATRC_H_INCLUDED
#define LESMATRC_H_INCLUDED
#include "LesMatrc.c"


void TrieSelec2D(int **T,int N,int M,int *nbrcomp,int *nbrpermut); //,int const Min)
void TrieBull2D(int **T,int N,int M,int *nbrcomp,int *nbrpermut);
void ecrit2 (char tab[100][100],int n,int m);
void remp2 (char tab[100][100],int n,int m);
int cmp(char mot2[100],char mot[100],int m);
void affiche2D(int t[100][100],int n,int m);
void remplir2D(int t[100][100],int n,int m);

#endif // LESMATRC_H_INCLUDED
