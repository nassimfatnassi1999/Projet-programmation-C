#include <stdio.h>
#include <string.h>
#include"function.h"

int main()
{

     Liste L1={21,"bilelel",12,15,1999,1,2,"hamma","nounou","rined","lool"};
     Liste L2={25,"hammoooo",17,9,1999,2,3,"hello","chalbi","randa","hiiiii"};
     int x;
     //saisir(&L1);

     x=ajouterListe("liste.txt",L2);

    if(x==1)
        printf("\najout de Liste avec succees!!!!!!!!!");
    else printf("\nechec ajout");

  /*  x=modifierListe("liste.txt",10,L2);

    if(x==1)
        printf("\nModification de Liste avec succes");
    else printf("\nechec Modification");*/


   /* x=supprimerListe("liste.txt",20 );
    if(x==1)
        printf("\nSuppression de Liste avec succés");
    else
        printf("\nechec Suppression");*/


  /* L2=chercher("liste.txt",25 );
    if(L2.id==-1)
        printf("\t\t\tintrouvable\n");
    else
        printf("\t\t\ttrouve la liste a chercher!!!\n");*/
    return 0;
}

