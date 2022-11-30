#include <stdio.h>
#include <string.h>
#include"function.h"

int main()
{

    Liste L1= {-1,"bilelel",12,15,1999,1,2,"hamma","nounou","rined","lool"};
    Liste L2= {-1,"hammoooo",17,9,1999,2,3,"hello","chalbi","randa","hiiiii"};
    Liste L3= {-1,"Wissal",20,9,2022,2,3,"Neji","c1","c2","c3"};
    int x;
    Lorder tab[50];
    int n=0;

   /* x=ajouterListe("liste.txt",L3);

    if(x==1)
       printf("\najout de Liste avec succees!!!!!!!!!");
    else printf("\nechec ajout");*/

      /*x=modifierListe("liste.txt",-1,L3);

      if(x==1)
          printf("\nModification de Liste avec succes");
      else printf("\nechec Modification");*/


     /*x=supprimerListe("liste.txt",-1 );
     if(x==1)
         printf("\nSuppression de Liste avec succés");
     else
         printf("\nechec Suppression");*/


    /* L2=chercher("liste.txt",25 );
      if(L2.id==-1)
          printf("\t\t\tintrouvable\n");
      else
          printf("\t\t\ttrouve la liste a chercher!!!\n");*/

    x=nbv("user.txt",125);
    printf("le nombre de vote est egale = %d\n",x);
    remplirtab("user.txt","liste.txt",tab,&n);
    /*for(int i=0;i<n;i++){
        printf("%s : ",tab[i].nomListe);
        printf("|%d|\t",tab[i].idListe);
        printf("|%d|\t\n",tab[i].NbrVote);
    }*/
    printTab(tab,&n);

    return 0;
}

