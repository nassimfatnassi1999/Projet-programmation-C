#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "election.h"


enum
{
	EIDEL,
	EENTRY2,
	EMU,
	EJOU,
	EEMOI,
	EANNE,
	COLUMNS,
};


void ajouter_election(election e)
{FILE *f=fopen("election.txt","a+");
if(f!=NULL)
{fprintf(f,"%s %s %s %s %s %s\n",e.id,e.nbr_conseiller,e.municipalite,e.del.jour,e.del.mois,e.del.annee);
fclose(f);
}
}


void supprimer(char * ELECTION, char id[15])
{
    int tr=0;
    election e;
    FILE * f=fopen(ELECTION, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s\n",e.id,e.nbr_conseiller,e.municipalite,e.del.jour,e.del.mois,e.del.annee)!=EOF)
        {
            if(strcmp(e.id,id)==0)
                tr=1;
            else
                fprintf(f,"%s %s %s %s %s %s\n",e.id,e.nbr_conseiller,e.municipalite,e.del.jour,e.del.mois,e.del.annee);
        }
    }
    fclose(f);
    fclose(f2);
    remove(ELECTION);
    rename("nouv.txt", ELECTION);
    
}



void supprimer_election(election e)
    {   election e1;
	FILE *f, *g;
	f=fopen("election.txt","r");
	g=fopen("election1.txt","w");
	if(f==NULL || g==NULL)
	  { return;
	  }
	else
	{ while(fscanf(f,"%s %s %s %s %s %s\n",e1.id,e1.nbr_conseiller,e1.municipalite,e1.del.jour,e1.del.mois,e1.del.annee)!=EOF)
	   {
if( strcmp(e.id,e1.id)!=0 || strcmp(e.nbr_conseiller,e1.nbr_conseiller)!=0 || strcmp(e.municipalite,e1.municipalite)!=0 || strcmp(e.del.jour,e1.del.jour)!=0 ||strcmp(e.del.mois,e1.del.mois)!=0 || strcmp(e.del.annee,e1.del.annee)!=0) 
fprintf(g,"%s %s %s %s %s %s\n",e1.id,e1.nbr_conseiller,e1.municipalite,e1.del.jour,e1.del.mois,e1.del.annee);
	   }
fclose(f);
fclose(g);
remove("election.txt");
rename("election1.txt","election.txt");
	}
    }

void afficher_election(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;


   char id[50];
   char nbr_conseiller[50];
   char municipalite[50];
   char jour[50];
   char mois[50];
   char annee[50];

	store=NULL;
	FILE* f=NULL;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("id", renderer, "text", EIDEL , NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("nbr conseiller", renderer, "text", EENTRY2 , NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("municipalite", renderer, "text", EMU , NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("jour", renderer, "text", EJOU , NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("mois", renderer, "text", EEMOI , NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" annee", renderer, "text", EANNE , NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	}
	
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f=fopen("election.txt","r");
	if(f==NULL)
	{return;
	}	
	else 
	{

		f=fopen("election.txt","a+");
while(fscanf(f,"%s %s %s %s %s %s\n",id,nbr_conseiller,municipalite,jour,mois,annee)!=EOF)
		{	gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter, EIDEL, id, EENTRY2, nbr_conseiller, EMU, municipalite, EJOU, jour, EEMOI, mois, EANNE, annee, -1);
		}
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
	}

}
election chercher_election( char id[])
{
	//convert l'id (textentry) char to int
	
    election e;
    int tr=0;
    FILE * f=fopen("election.txt", "r");
    if(f!=NULL)
    {
        while(tr==0&&fscanf(f,"%s %s %s %s %s %s\n",e.id,e.nbr_conseiller,e.municipalite,e.del.jour,e.del.mois,e.del.annee)!=EOF )
        {
            if(strcmp(e.id,id)==0)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
    {
       strcpy(e.id,"-1");
    }
    return e;

}





int modifier_election( char * filename,char id[],election em )
{
    int tr=0;
    election e;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s\n",e.id,e.nbr_conseiller,e.municipalite,e.del.jour,e.del.mois,e.del.annee)!=EOF )
        {
            if(strcmp(e.id, id)==0)
            {
              fprintf(f2,"%s %s %s %s %s %s\n",em.id,em.nbr_conseiller,em.municipalite,em.del.jour,em.del.mois,em.del.annee);
                tr=1;
            }
            else
                fprintf(f2,"%s %s %s %s %s %s\n",e.id,e.nbr_conseiller,e.municipalite,e.del.jour,e.del.mois,e.del.annee);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}








