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
        while(fscanf(f,"%d %s %d %d %d %d %d %s %s %s %s\n",&L.id,L.nom_liste,&L.d.jour,&L.d.mois,&L.d.annee,&L.orientation,&L.municipalite,L.nom_tete_liste,L.candidat_1,L.candidat_2,L.candidat_3)!=EOF)
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
        while(fscanf(f,"%d %s %d %d %d %d %d %s %s %s %s\n",&L.id,L.nom_liste,&L.d.jour,&L.d.mois,&L.d.annee,&L.orientation,&L.municipalite,L.nom_tete_liste,L.candidat_1,L.candidat_2,L.candidat_3)!=EOF)
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
        while(tr==0&& fscanf(f,"%d %s %d %d %d %d %d %s %s %s %s\n",&L.id,L.nom_liste,&L.d.jour,&L.d.mois,&L.d.annee,&L.orientation,&L.municipalite,L.nom_tete_liste,L.candidat_1,L.candidat_2,L.candidat_3)!=EOF)
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
//statistique nombre de vote de chaque liste
int nbv(char * filename,int id)
{
    int nbr_vote=0;
    utilisateur L;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(fscanf(f,"%d %d %d %s %s %d %d %d %d %d %d %d\n",&L.CIN,&L.Nempreinte,&L.Ntelephone,L.nom,L.prenom,&L.d.jour,&L.d.mois,&L.d.annee,&L.municipalite,&L.genre,&L.role,&L.vote)!=EOF)
        {
            if(L.vote==id&&L.vote!=0&&L.vote!=-1)
                nbr_vote++;
        }
    }
    fclose(f);
    return nbr_vote;
}

//remplir tab nbr de vote et id liste
void remplirtab(char * filename,char * filename2,Lorder tab[],int *n)
{
    int i,j,k,p;
    Liste Li;
    utilisateur L;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen(filename2, "r");
    if(f!=NULL&&f2!=NULL)
    {
        //ajouter les id dans un tableau
        while(fscanf(f,"%d %d %d %s %s %d %d %d %d %d %d %d\n",&L.CIN,&L.Nempreinte,&L.Ntelephone,L.nom,L.prenom,&L.d.jour,&L.d.mois,&L.d.annee,&L.municipalite,&L.genre,&L.role,&L.vote)!=EOF)
        {
            //ajouter dans le tableau les id de liste et eliminer le vote blanc
            if(L.vote!=0&&L.vote!=-1)
            {
                tab[*n].idListe=L.vote;
                (*n)++;
            }
        }
        //pour simplifier le tableau est supp l'occurence de lid liste
        for (i=0; i<(*n); i++)
        {
            for (j=i+1; j<(*n);)
            {
                if (tab[j].idListe==tab[i].idListe)
                {
                    for (k=j; k<(*n); k++)
                    {
                        tab[k].idListe=tab[k+1].idListe;
                    }
                    (*n)--;
                }
                else
                    j++;
            }
            //ajouter les nbr de vote dans un tableau
            tab[i].NbrVote=nbv("user.txt",tab[i].idListe);
        }
        //pour ajouter ne nom de la liste
        while(fscanf(f2,"%d %s %d %d %d %d %d %s %s %s %s\n",&Li.id,Li.nom_liste,&Li.d.jour,&Li.d.mois,&Li.d.annee,&Li.orientation,&Li.municipalite,Li.nom_tete_liste,Li.candidat_1,Li.candidat_2,Li.candidat_3)!=EOF)
        {
            for(i=0; i<(*n); i++)
            {
                if(tab[i].idListe==Li.id)
                {
                    strcpy(tab[i].nomListe,Li.nom_liste);
                }
            }
        }
    }
    fclose(f);
    fclose(f2);
}

//function pour print and trier le tableau dans un fichier
void printTab(Lorder tab[],int *n)
{
    int i,j,min;
    Lorder tompon;
    utilisateur L;
    FILE * f3=fopen("printTab.txt", "w");
    //tri par selection comparer
    for(i=0; i<(*n); i++)
    {
        min=i;
        for(j=i+1; j<(*n); j++)
        {
            if(tab[j].NbrVote>tab[min].NbrVote)
            {
                min=j;
            }
        }
        tompon=tab[i];
        tab[i]=tab[min];
        tab[min]=tompon;
    }
    if(f3!=NULL)
    {
        //print tab dans un fichier printTab
        for(i=0; i<(*n); i++)
        {
            fprintf(f3,"%s %d %d\n",tab[i].nomListe,tab[i].idListe,tab[i].NbrVote);
        }

        fclose(f3);
    }
}




