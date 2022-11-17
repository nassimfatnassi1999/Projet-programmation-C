#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include "function.h"
//function pour ajouter utilisateur
int ajouterUtilisateur(char * filename, utilisateur L)
{

    FILE * f=fopen(filename,"a");
    if(f!=NULL)
    {
        fprintf(f,"%d %d %d %s %s %d %d %d %d %d %d %d\n",L.CIN,L.Nempreinte,L.Ntelephone,L.nom,L.prenom,L.d.jour,L.d.mois,L.d.annee,L.municipalite,L.genre,L.role,-1);
        fclose(f);
        return 1;
    }
    else
        return 0;
}
//function pour modifier utilisateur
int modifierUtilisateur( char * filename,int CIN,utilisateur nouvL )
{
    int tr=0;
    utilisateur L;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt","w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d %s %s %d %d %d %d %d %d %d\n",&L.CIN,&L.Nempreinte,&L.Ntelephone,L.nom,L.prenom,&L.d.jour,&L.d.mois,&L.d.annee,&L.municipalite,&L.genre,&L.role,&L.vote)!=EOF)
        {
            if(L.CIN== CIN)
            {
                fprintf(f2,"%d %d %d %s %s %d %d %d %d %d %d %d\n",nouvL.CIN,nouvL.Nempreinte,nouvL.Ntelephone,nouvL.nom,nouvL.prenom,nouvL.d.jour,nouvL.d.mois,nouvL.d.annee,nouvL.municipalite,nouvL.genre,nouvL.role,nouvL.vote);
                tr=1;
            }
            else
                fprintf(f2,"%d %d %d %s %s %d %d %d %d %d %d %d\n",L.CIN,L.Nempreinte,L.Ntelephone,L.nom,L.prenom,L.d.jour,L.d.mois,L.d.annee,L.municipalite,L.genre,L.role,L.vote);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt",filename);
    return tr;

}

//function pour supprimer utilisateur
int supprimerUtilisateur(char * filename, int CIN)
{
    int tr=0;
    utilisateur L;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d %s %s %d %d %d %d %d %d %d\n",&L.CIN,&L.Nempreinte,&L.Ntelephone,L.nom,L.prenom,&L.d.jour,&L.d.mois,&L.d.annee,&L.municipalite,&L.genre,&L.role,&L.vote)!=EOF)
        {
            if(L.CIN== CIN)
                tr=1;
            else
                fprintf(f2,"%d %d %d %s %s %d %d %d %d %d %d %d\n",L.CIN,L.Nempreinte,L.Ntelephone,L.nom,L.prenom,L.d.jour,L.d.mois,L.d.annee,L.municipalite,L.genre,L.role,L.vote);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}
//function pour chercher utilisateur
utilisateur chercherUtilisateur(char * filename, int CIN)
{
    utilisateur L;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%d %d %d %s %s %d %d %d %d %d %d %d\n",&L.CIN,&L.Nempreinte,&L.Ntelephone,L.nom,L.prenom,&L.d.jour,&L.d.mois,&L.d.annee,&L.municipalite,&L.genre,&L.role,&L.vote)!=EOF)
        {
            if(L.CIN== CIN)
                tr=1;

        }
    }
    fclose(f);
    if(tr==0)
        L.CIN=-1;
    return L;

}
//taux de participation de electeur 
float TPE(char * filename)
{
	utilisateur L;
	int nbEvote=0,nbEtotale=0;
	float TPE;
	FILE * f=fopen(filename, "r");
        if(f!=NULL)
        {
	while(fscanf(f,"%d %d %d %s %s %d %d %d %d %d %d %d\n",&L.CIN,&L.Nempreinte,&L.Ntelephone,L.nom,L.prenom,&L.d.jour,&L.d.mois,&L.d.annee,&L.municipalite,&L.genre,&L.role,&L.vote)!=EOF)
        {
			
		nbEtotale=nbEtotale+1;
		
            if(L.vote != -1)
                {nbEvote=nbEvote+1;
		}
					
        }

		
	TPE=(float)nbEvote/nbEtotale;
	
    }
    fclose(f);
    
    return TPE;	
}

// taux de participation des hommes et des femmes 
void TPHF(char * filename, float * fe,float * h)
{
	utilisateur L;
	int nbEvote=0,nbEvoteH=0,nbEvoteF=0;
	FILE * f=fopen(filename, "r");
        if(f!=NULL)
        {
	while(fscanf(f,"%d %d %d %s %s %d %d %d %d %d %d %d\n",&L.CIN,&L.Nempreinte,&L.Ntelephone,L.nom,L.prenom,&L.d.jour,&L.d.mois,&L.d.annee,&L.municipalite,&L.genre,&L.role,&L.vote)!=EOF)
        {
            if(L.vote != -1)
        {	nbEvote=nbEvote+1;
		switch(L.genre)
		{case 0:{nbEvoteF=nbEvoteF+1;
			break;}
		case 1:{nbEvoteH=nbEvoteH+1;
			break;}	
		}
	}
	*fe=(float)nbEvoteF/nbEvote;
	*h=(float)nbEvoteH/nbEvote;
    }
    fclose(f);
}
} 
