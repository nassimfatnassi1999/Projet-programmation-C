#include <stdio.h>
#include <string.h>
#include "function.h"
#include <gtk/gtk.h>

enum{

	ID,
	NOM_LISTE,
	JOUR,
	MOIS,
	ANNEE,
	ORIENTA,
	MUNI,
	CINT,
	CINC1,
	CINC2,
	CINC3,
	COLUMNS

};

//function pour generer lid auto
int genererIdListe(char * filename)
{

Liste L;
L.id=0;
FILE * f=fopen(filename, "r");
while(fscanf(f,"%d %s %d %d %d %s %s %s %s %s %s",&L.id,L.nom_liste,&L.d.jour,&L.d.mois,&L.d.annee,L.orientation,L.municipalite,L.nom_tete_liste,L.candidat_1,L.candidat_2,L.candidat_3)!=EOF);
fclose(f);

	return (L.id+1);

}
void MiseAjourIdListe(char * filename ,Liste *L)
{

L->id=1;
FILE * f=fopen(filename, "r");
while(fscanf(f,"%d %s %d %d %d %s %s %s %s %s %s",&L->id,L->nom_liste,&L->d.jour,&L->d.mois,&L->d.annee,L->orientation,L->municipalite,L->nom_tete_liste,L->candidat_1,L->candidat_2,L->candidat_3)!=EOF);
	{L->id=L->id+1;}
fclose(f);
}

void ajouterListe(Liste L)
{
   L.id=genererIdListe("liste.txt");
    FILE * f=fopen("liste.txt", "a+");

    if(f!=NULL)
    {
        fprintf(f,"%d %s %d %d %d %s %s %s %s %s %s\n",L.id,L.nom_liste,L.d.jour,L.d.mois,L.d.annee,L.orientation,L.municipalite,L.nom_tete_liste,L.candidat_1,L.candidat_2,L.candidat_3);

    }
    fclose(f);
}


//function pour chercher liste
void Chercher_Nassim(GtkWidget *liste,char ch[20])
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;


store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{

	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("id", renderer, "text", ID, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("nom_liste", renderer, "text",NOM_LISTE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("Jour", renderer, "text",JOUR, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("Mois", renderer, "text",MOIS, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("Annee", renderer, "text",ANNEE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("orientation", renderer, "text",ORIENTA, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("municipalite", renderer, "text",MUNI, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	

	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("cin_tete_liste", renderer, "text",CINT, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
	
	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("candidat_1", renderer, "text",CINC1, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	

	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("candidat_2", renderer, "text",CINC2, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	

	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("candidat_3", renderer, "text",CINC3, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
}
 store=gtk_list_store_new (COLUMNS,
	 				 G_TYPE_UINT,
					 G_TYPE_STRING,
					 G_TYPE_UINT,
					 G_TYPE_UINT,
					 G_TYPE_UINT,
					 G_TYPE_STRING, 
					 G_TYPE_STRING,
					 G_TYPE_STRING,
					 G_TYPE_STRING,
					 G_TYPE_STRING,
					 G_TYPE_STRING);
f=fopen("liste.txt","r");
Liste L;

{f=fopen("liste.txt","a+");
	while(fscanf(f,"%d %s %d %d %d %s %s %s %s %s %s",&L.id,L.nom_liste,&L.d.jour,&L.d.mois,&L.d.annee,L.orientation,L.municipalite,L.nom_tete_liste,L.candidat_1,L.candidat_2,L.candidat_3)!=EOF)
{   
      if((strcmp(ch,L.municipalite)==0) ){
	gtk_list_store_append (store, &iter); 
	gtk_list_store_set (store,&iter,ID,L.id,NOM_LISTE,L.nom_liste,JOUR,L.d.jour,MOIS,L.d.mois,ANNEE,L.d.annee,ORIENTA,L.orientation,MUNI,L.municipalite,CINT,L.nom_tete_liste,CINC1,L.candidat_1,CINC2,L.candidat_2,CINC3,L.candidat_3);
	}
	else if((strcmp(ch,L.orientation)==0) ){
	gtk_list_store_append (store, &iter); 
	gtk_list_store_set (store,&iter,ID,L.id,NOM_LISTE,L.nom_liste,JOUR,L.d.jour,MOIS,L.d.mois,ANNEE,L.d.annee,ORIENTA,L.orientation,MUNI,L.municipalite,CINT,L.nom_tete_liste,CINC1,L.candidat_1,CINC2,L.candidat_2,CINC3,L.candidat_3);
	}
}
fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store)); 
	g_object_unref (store);
}
}
//treview affichage
void afficher_Liste(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
	store=NULL;
	FILE *f;
	Liste L;
	store=gtk_tree_view_get_model(liste);

	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("id", renderer, "text", ID, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("nom_liste", renderer, "text",NOM_LISTE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("Jour", renderer, "text",JOUR, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("Mois", renderer, "text",MOIS, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("Annee", renderer, "text",ANNEE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("orientation", renderer, "text",ORIENTA, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("municipalite", renderer, "text",MUNI, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	

	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("cin_tete_liste", renderer, "text",CINT, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
	
	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("candidat_1", renderer, "text",CINC1, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	

	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("candidat_2", renderer, "text",CINC2, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	

	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("candidat_3", renderer, "text",CINC3, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	}
	 store=gtk_list_store_new (COLUMNS,
	 				 G_TYPE_UINT,
					 G_TYPE_STRING,
					 G_TYPE_UINT,
					 G_TYPE_UINT,
					 G_TYPE_UINT,
					 G_TYPE_STRING, 
					 G_TYPE_STRING,
					 G_TYPE_STRING,
					 G_TYPE_STRING,
					 G_TYPE_STRING,
					 G_TYPE_STRING);

	f=fopen("liste.txt", "r");
	if(f==NULL)
	{
		return;
	}
	else{
	
	while(fscanf(f,"%d %s %d %d %d %s %s %s %s %s %s",&L.id,L.nom_liste,&L.d.jour,&L.d.mois,&L.d.annee,L.orientation,L.municipalite,L.nom_tete_liste,L.candidat_1,L.candidat_2,L.candidat_3)!=EOF)
	{
	gtk_list_store_append (store, &iter); 
	gtk_list_store_set (store,&iter,ID,L.id,NOM_LISTE,L.nom_liste,JOUR,L.d.jour,MOIS,L.d.mois,ANNEE,L.d.annee,ORIENTA,L.orientation,MUNI,L.municipalite,CINT,L.nom_tete_liste,CINC1,L.candidat_1,CINC2,L.candidat_2,CINC3,L.candidat_3);
	}
	fclose(f);

	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store)); 
	g_object_unref (store);
	}

	
}
void supprimer_Liste(Liste Li)
{   Liste L;
FILE *f, *g;
f=fopen("liste.txt","r");
g=fopen("nouv.txt","w");
if(f==NULL || g==NULL)
 { return; }
else
{ 
while(fscanf(f,"%d %s %d %d %d %s %s %s %s %s %s\n",&L.id,L.nom_liste,&L.d.jour,&L.d.mois,&L.d.annee,L.orientation,L.municipalite,L.nom_tete_liste,L.candidat_1,L.candidat_2,L.candidat_3)!=EOF)
  {
if(Li.id!=L.id)
fprintf(g,"%d %s %d %d %d %s %s %s %s %s %s\n",L.id,L.nom_liste,L.d.jour,L.d.mois,L.d.annee,L.orientation,L.municipalite,L.nom_tete_liste,L.candidat_1,L.candidat_2,L.candidat_3);
  }
fclose(f);
fclose(g);
remove("liste.txt");
rename("nouv.txt","liste.txt");
}
    }
//function pour verifier
int verifier(char cinT[],char cinc1[],char cinc2[],char cinc3[])
{
    Liste L;
    int tr=0;
    FILE * f=fopen("liste.txt", "r");
    if(f!=NULL)
    {
        while(tr==0&&fscanf(f,"%d %s %d %d %d %s %s %s %s %s %s\n",&L.id,L.nom_liste,&L.d.jour,&L.d.mois,&L.d.annee,L.orientation,L.municipalite,L.nom_tete_liste,L.candidat_1,L.candidat_2,L.candidat_3)!=EOF)
        {
            if((strcmp(cinT,L.nom_tete_liste)==0)||(strcmp(cinc1,L.candidat_1)==0)||(strcmp(cinc2,L.candidat_2)==0)||(strcmp(cinc3,L.candidat_3)==0))
                tr=1;
        }
    }
    fclose(f);
    return tr;
}
//function pour chercher liste
Liste chercher( char id[])
{
	//convert l'id (textentry) char to int
	int idN = atoi (id);
    Liste L;
    int tr=0;
    FILE * f=fopen("liste.txt", "r");
    if(f!=NULL)
    {
        while(tr==0&&fscanf(f,"%d %s %d %d %d %s %s %s %s %s %s\n",&L.id,L.nom_liste,&L.d.jour,&L.d.mois,&L.d.annee,L.orientation,L.municipalite,L.nom_tete_liste,L.candidat_1,L.candidat_2,L.candidat_3)!=EOF )
        {
            if(L.id==idN)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
    {
       L.id=-1;
    }
    return L;

}
//function pour modifier liste
int modifierListe( char * filename,int id,Liste LM )
{
    int tr=0;
    Liste L;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %s %d %d %d %s %s %s %s %s %s\n",&L.id,L.nom_liste,&L.d.jour,&L.d.mois,&L.d.annee,L.orientation,L.municipalite,L.nom_tete_liste,L.candidat_1,L.candidat_2,L.candidat_3)!=EOF )
        {
            if(L.id==id)
            {
              fprintf(f2,"%d %s %d %d %d %s %s %s %s %s %s\n",LM.id,LM.nom_liste,LM.d.jour,LM.d.mois,LM.d.annee,LM.orientation,LM.municipalite,LM.nom_tete_liste,LM.candidat_1,LM.candidat_2,LM.candidat_3);
                tr=1;
            }
            else
                fprintf(f2,"%d %s %d %d %d %s %s %s %s %s %s\n",L.id,L.nom_liste,L.d.jour,L.d.mois,L.d.annee,L.orientation,L.municipalite,L.nom_tete_liste,L.candidat_1,L.candidat_2,L.candidat_3);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}



//function connexion
int connexion(char login[],char pass[])
{
    utilisateur L;
    char role[20];
	int r=-1;
    FILE * f=fopen("utilisateur.txt", "r");
     FILE * f2=fopen("connected.txt", "w+");


    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",L.CIN,L.Nempreinte,L.Ntelephone,L.nom,L.prenom,L.dh.jour,L.dh.mois,L.dh
.annee,L.municipalite,L.genre,L.role,L.vote)!=EOF)
        {
            if((strcmp(L.CIN,login)==0) && (strcmp(L.Nempreinte,pass)==0))
            {
                strcpy(role,L.role);
            }
        }
        if(strcmp(role,"-1")!=0){
             fprintf(f2,"%s\n",login);
        }
    }
    fclose(f);
    fclose(f2);
	if(strcmp(role,"administrateur")==0){r=1;}
	if(strcmp(role,"agentBureauVote")==0){r=2;}
	if(strcmp(role,"electeur")==0){r=3;}
    return r;
}






