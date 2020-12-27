#include <stdio.h>
#include <stdlib.h>
#include "LesTab.h"
#include "LesMatrc.h"
#include "LesList.h"


int main()
{
    int n,choi;
    int tab[100];
    int nbrcomp=0,nbrpermt=0;
    ListMot *tete;
    char *mot;
    char M[100][100];
    int m,i,j,lig;


    debut();
 menu:
    menu();
    buttom("Votre Choix:",1,7);
    scanf("%d",&choi);

    switch(choi)
    {
    case 1 :
        system("cls");
        color(1,7);
        menuMetho();
        buttom("Votre Choix:",1,7);
        scanf("%d",&choi);
            switch (choi)
            {
            case 1 :system("cls"); color(1,7);   menuOrdre();
                                buttom("Votre Choix:",1,7);
                                scanf("%d",&choi);
                                switch (choi)
                                {
                                case 1:system("cls"); color(1,7);
                                printf("\n veillez donner la taille de tableau : ");
                                scanf("%d",&n);
                                printf("\n \n \n");
                                        remplir1D(tab,n);
                                        system("cls"); color(1,7);
                                        TrieInser1D(tab,n,&nbrcomp,&nbrpermt,1);
                                        affiche1D(tab,n);
                                    break;
                                case 2:system("cls"); color(1,7);
                                         printf("\n veillez donner la taille de tableau : ");
                                         scanf("%d",&n);
                                         printf("\n \n \n");
                                         remplir1D(tab,n);
                                         system("cls"); color(1,7);
                                         TrieInser1D(tab,n,&nbrcomp,&nbrpermt,0);
                                         affiche1D(tab,n);
                                    break;
                                default :
                                    break;
                                }
                break;
            case 2 : system("cls"); color(1,7);menuOrdre();
                                buttom("Votre Choix:",1,7);
                                scanf("%d",&choi);
                                switch (choi)
                                {
                                case 1:system("cls"); color(1,7);
                                printf("\n veillez donner la taille de tableau : ");
                                scanf("%d",&n);
                                printf("\n \n \n");
                                        remplir1D(tab,n);
                                        system("cls"); color(1,7);
                                        TrieBull1D(tab,n,&nbrcomp,&nbrpermt,1);
                                        affiche1D(tab,n);
                                    break;
                                case 2:system("cls"); color(1,7);
                                      printf("\n veillez donner la taille de tableau : ");
                                      scanf("%d",&n);
                                      printf("\n \n \n");
                                          remplir1D(tab,n);
                                          system("cls"); color(1,7);
                                          TrieBull1D(tab,n,&nbrcomp,&nbrpermt,0);
                                          affiche1D(tab,n);
                                    break;
                                default :
                                    break;
                                }
                break;
            case 3 :system("cls"); color(1,7);menuOrdre();
                                buttom("Votre Choix:",1,7);
                                scanf("%d",&choi);
                                switch (choi)
                                {
                                case 1:system("cls"); color(1,7);
                                 printf("\n veillez donner la taille de tableau : ");
                                 scanf("%d",&n);
                                 printf("\n \n \n");
                                        remplir1D(tab,n);
                                        system("cls"); color(1,7);
                                        TrieSelec1D(tab,n,&nbrcomp,&nbrpermt,1);
                                        affiche1D(tab,n);
                                    break;
                                case 2:system("cls"); color(1,7);
                                 printf("\n veillez donner la taille de tableau : ");
                                 scanf("%d",&n);
                                 printf("\n \n \n");
                                        remplir1D(tab,n);
                                        system("cls"); color(1,7);
                                        TrieSelec1D(tab,n,&nbrcomp,&nbrpermt,0);
                                        affiche1D(tab,n);
                                    break;
                                default :
                                    break;
                                }
                break;
            default : goto menu;
                break;
            }
        system("pause");
        break;

    case 2 :
            system("cls");
            color(1,7);
            menuMatric();
            buttom("Votre Choix:",1,7);
            scanf("%d",&choi);
            switch (choi)
            {
            case 1: /** un autre switch pour choisir la methode
                        remplissage de la matrice
                        utiliser les fonction de fichier matrice qui ne marchent pas u_u
                        **/
                 break;
            case 2:system("cls");
                   color(1,7);
                   printf("\n donnez nbr de lig et col \n");scanf("%d",&n);scanf("%d",&m);
                   remplir2D(M,n,m);
                                            for (i=0;i<n;i++)
                                                {

                                                          TrieInser1D(M[i],m,&nbrcomp,&nbrpermt,1); /** on choisit la methode quon veut vc lordre **/
                                                }

                                            affiche2D(M,n,m);
                                            system("pause");
                                            break;
            case 3:
                    system("cls");
                   color(1,7);

                    printf("\n donnez nbr de lig et col \n");scanf("%d",&n);scanf("%d",&m);
                    remp2(M,n,m);
                    ecrit2(M,n,m);
                    mot = malloc(sizeof(char*)*m);
                    for(i=0;i<n-1;i++)
                        {
                            lig=i;
                            strcpy(mot,*(M+i));
                            for(j=i+1;j<n;j++)
                                {
                                    if(cmp(*(M+j),mot,m)==1)
                                    {
                                    lig=j;
                                    strcpy(mot,*(M+j));
                                    }
                                }
                        strcpy(mot,*(M+i));
                        strcpy(*(M+i),*(M+(lig)));
                        strcpy(*(M+(lig)),mot);
                    }
            printf("\n_______________________\n");
            ecrit2(M,n,m);
            system("pause");
                break;
            default:
                break;
            }
        break;

     case 3 :
         system("cls");
        color(1,7);
        printf("Veillez donner le nombre de mots de la liste : ");
        scanf("%d",&n);
        tete=creer(n);
        system("cls");
        color(1,7);
         TrieBullList(tete);
          afficheList(tete);

        break;

     case 0 :quit();
         return 0;
        break;

     default:
         break;

    }

goto menu;
}
