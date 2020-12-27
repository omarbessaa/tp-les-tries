#ifndef LESTAB_H_INCLUDED
#define LESTAB_H_INCLUDED
#include "LesTab.c"

void permute(int *a,int *b);
void TrieSelec1D(int *T,int N,int *nbrcomp,int *nbrpermut,int const Min);
void TrieInser1D(int *T,int N,int *nbrcomp,int *nbrpermut,int const Min);
void TrieBull1D(int *T,int N,int *nbrcomp,int *nbrpermut,int const Min);
void affiche1D(int t[100],int n);
void remplir1D(int t[100],int n);

#endif // LESTAB_H_INCLUDED
