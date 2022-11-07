#include <stdio.h>
#include <string.h>
#include "function.h"
//function pour ajouter liste
int ajouterListe(char * filename, Liste L)
{

    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %s %d %d %d %d %d %s %s %s %s\n",L.id,L.nom_liste,L.d.jour,L.d.mois,L.d.annee,L.orientation,L.municipalite,L.nom_tete_liste,L.candidat_1,L.candidat_2,L.candidat_3);
        fclose(f);
        return 1;
    }
    else
        return 0;
}
//function pour modifier liste
int modifierListe( char * filename,int id,Liste nouvL )
{
    int tr=0;
    Liste L;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %s %d %d %d %d %d %s %s %s %s\n",&L.id,&L.nom_liste,&L.d.jour,&L.d.mois,&L.d.annee,&L.orientation,&L.municipalite,&L.nom_tete_liste,&L.candidat_1,&L.candidat_2,&L.candidat_3)!=EOF)
        {
            if(L.id== id)
            {
                fprintf(f2,"%d %s %d %d %d %d %d %s %s %s %s\n",nouvL.id,nouvL.nom_liste,nouvL.d.jour,nouvL.d.mois,nouvL.d.annee,nouvL.orientation,nouvL.municipalite,nouvL.nom_tete_liste,nouvL.candidat_1,nouvL.candidat_2,nouvL.candidat_3);
                tr=1;
            }
            else
                fprintf(f2,"%d %s %d %d %d %d %d %s %s %s %s\n",L.id,L.nom_liste,L.d.jour,L.d.mois,L.d.annee,L.orientation,L.municipalite,L.nom_tete_liste,L.candidat_1,L.candidat_2,L.candidat_3);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}
//function pour supprimer liste
int supprimerListe(char * filename, int id)
{
    int tr=0;
    Liste L;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %s %d %d %d %d %d %s %s %s %s\n",&L.id,&L.nom_liste,&L.d.jour,&L.d.mois,&L.d.annee,&L.orientation,&L.municipalite,&L.nom_tete_liste,&L.candidat_1,&L.candidat_2,&L.candidat_3)!=EOF)
        {
            if(L.id==id)
                tr=1;
            else
                fprintf(f2,"%d %s %d %d %d %d %d %s %s %s %s\n",L.id,L.nom_liste,L.d.jour,L.d.mois,L.d.annee,L.orientation,L.municipalite,L.nom_tete_liste,L.candidat_1,L.candidat_2,L.candidat_3);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}
//function pour chercher liste
Liste chercher(char * filename, int id)
{
    Liste L;
    int tr;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%d %s %d %d %d %d %d %s %s %s %s\n",&L.id,L.nom_liste,&L.d.jour,&L.d.mois,&L.d.annee,&L.orientation,&L.municipalite,&L.nom_tete_liste,&L.candidat_1,&L.candidat_2,&L.candidat_3)!=EOF)
        {
            if(L.id== id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        L.id=-1;
    return L;

}


