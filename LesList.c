#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LesList.h"


typedef struct ListMot ListMot;
struct ListMot
{
    char mot[50];
    ListMot *suiv;
};


ListMot* creer(int N)
{
    ListMot *p,*prec,*tete=NULL;
    int i;
    if (N>0)
    {
        tete=malloc(sizeof(ListMot));
        printf("Donner Le Premier Mot : ");
        scanf("%s",tete->mot);
        printf("\n");
        tete->suiv=NULL;
        prec=tete;

        for (i=0;i<N-1;i++)
        {
         p=malloc(sizeof(ListMot));
         printf("Donner Le %d iem Mot : ",i+2);
         scanf("%s",p->mot);
         printf("\n");
         p->suiv=NULL;
         prec->suiv=p;
         prec=p;
         p=NULL;
        }
    }
    return tete;
}


void TrieBullList(ListMot **tete)
{
    char ch1[50],ch2[50];
    ListMot *prec,*p,*s,*F=NULL;
    int Trie=0;

    while (!Trie)
    {
      Trie=1;
      p=*tete;
      prec=*tete;
      s=(*tete)->suiv; //s != NULL

          if (toupper(p->mot[0])>toupper(s->mot[0])) {p->suiv=s->suiv; s->suiv=p; *tete=s; prec=s; Trie=0;}
          else {p=s;}

          while(p->suiv != F)
          {
              s=p->suiv;
              if (toupper(p->mot[0])>toupper(s->mot[0])) {p->suiv=s->suiv; s->suiv=p; prec->suiv=s; prec=s; Trie=0;}
              else {prec=p; p=s;}
          }
        F=p;
    }
    return tete;
}


void afficheList(ListMot *tete)
{
    ListMot *p;

    p=tete;
    printf("\n \n\n");
    while(p!=NULL)
    {
        printf("%s   ",p->mot);
        p=p->suiv;
    }
    printf("\n");
}
