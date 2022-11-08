#include <stdio.h>
#include <string.h>
#include "fonctionBV.h"

int main()
{    bureauVote bv1={52,200,3,2,"Ariana","Mnihla","ecole primaire Sahnoun",06217744,"youssfi","Bilel",3,216554,2,5,2022};
     bureauVote bv2={71,300,4,3,"Ariana","Mnihla","ecole primaire bel gassem",06321426,"Fathalli","Seif",2,214546,6,5,2022};

     int x ;

   x=ajouterListe("bv.txt", bv2);

    if(x==1)
        printf("\najout de Liste avec succees!!!!!!!!!");
    else printf("\nechec ajout");

 /*x=modifierListe("bv.txt",71,bv2);
    if(x==1)
        printf("\nModification debureau de vote avec succes");
    else printf("\nechec Modification");*/
 /*x=supprimer("bv.txt",71);
    if(x==1)
        printf("\nSuppression de bureau de vote avec succes");
    else printf("\nechec Suppression");*/
bv2=chercher("bv.txt",71);

    if(bv2.id==-1)
    {
        printf("introuvable");
    }else if (bv2.id!=-1)
     {
         printf("existe!!!\n");
    }
    return 0;
}

