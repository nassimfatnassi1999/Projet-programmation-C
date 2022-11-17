#include <stdio.h>
#include <string.h>
#include "function.h"

int main()
{
     utilisateur L1={13481348,11,1,"Hama","Hama",1,1,1,17,9,1999,1};
     utilisateur L3={1117582,77,50504,"nassoum","nassim",10,6,1,27,12,1999,2};
     utilisateur L4={10,15,10,"nohhhhhe","nahhhhhhm",10,10,10,10,10,10,3};
     utilisateur              L5 ;

     float Px,Py;
     float x,y ;
	//Px=&x;
	//Py=&y;
     float T=1;
/*
     T=TPE("utilisateur.txt");
     printf("\n le taux de participation de electeur est egale a %f ",T);
*/      TPHF("utilisateur.txt",&x,&y);
     printf("\n le taux de participation des femmes est egale a %f ",x);
     printf("\n le taux de participation des hommes est egale a %f ",y);
    
/*
   x=ajouterUtilisateur("utilisateur.txt",L4);

    if(x==1)
        printf("\najout de Lutilisateur avec succees!!!!!!!!!");
    else printf("\nechec ajout"); 
*/
/*
    x=modifierUtilisateur("utilisateur.txt",1117582,L1);
    if(x==1)
        printf("\nModification de lutisateur avec succes");
    else printf("\nechec Modification"); 
*/
/* x=supprimerUtilisateur("utilisateur.txt",1117582);
    if(x==1)
        printf("\nSuppression de utilisateur avec succes");
    else printf("\nechec Suppression"); 
*/
/* 	L5=chercher("utilisateur.txt",13481348);
    	if(L5.CIN ==-1)
    	{
        	printf("introuvable");
	 }else if (L5.CIN!=-1)
     {
         printf("existe!!!\n");
    }*/
    return 0;
}
