#ifdef HAVE_CONFIG_H
#include<config.h>
#endif

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<gtk/gtk.h>
#include"login.h"

enum
{
	ID,
	NOM_LISTE,
	NBRV,
	COLUMNS,
};

int tableau_listeElV(char listeElecVote[20][50])
{

int j=0,Lid,Ljour,Lmois,Lannee;
char Lorientation[20], Lmunicipalite[20], Lnom_tete_liste[20], Lcandidat1[20], Lcandidat2[20], Lcandidat3[20];
FILE* f=fopen("liste.txt","r");
if(f!=NULL)
   {while(fscanf(f,"%d %s %d %d %d %s %s %s %s %s %s",&Lid,listeElecVote[j],&Ljour,&Lmois,&Lannee,Lorientation,Lmunicipalite,Lnom_tete_liste,Lcandidat1,Lcandidat2,Lcandidat3)!=EOF)
      {j++;
      }
   }
fclose(f);
return j;
}


int getID(char choixVote[20])
	{ 
 	int j=0,Lid,Ljour,Lmois,Lannee,idListeVote=0;
	char listeElecVote[20], Lorientation[20], Lmunicipalite[20], Lnom_tete_liste[20], Lcandidat1[20], Lcandidat2[20], Lcandidat3[20];	

	FILE *f=NULL;
	f=fopen("liste.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%d %s %d %d %d %s %s %s %s %s %s",&Lid,listeElecVote,&Ljour,&Lmois,&Lannee,Lorientation,Lmunicipalite,Lnom_tete_liste,Lcandidat1,Lcandidat2,Lcandidat3)!=EOF)
     	{
	  if(strcmp(choixVote,listeElecVote)==0)
		{
		  
		  idListeVote=Lid;
		}
	}
	fclose(f);
}
	return idListeVote;
	}




void modifier( int id )
{
    char LCIN[50], LNempreinte[50], LNtelephone[20], Lnom[20], Lprenom[20], Ljour[20], Lmois[20], Lannee[20], Lmunicipalite[20], Lgenre[20], Lrole[50], Lvote[20], cinConnect[20], nvvote[20];
    FILE *f=fopen("utilisateur.txt", "r");
    FILE *f2=fopen("nouv.txt", "w");
    FILE *f3=fopen("connected.txt", "r");

if(f3!=NULL)
{
while(fscanf(f3,"%s\n",cinConnect)!=EOF)
{}
    fclose(f3);
}


    if(f!=NULL && f2!=NULL)
    {

        while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",LCIN,LNempreinte,LNtelephone,Lnom,Lprenom,Ljour,Lmois,Lannee,Lmunicipalite,Lgenre,Lrole,Lvote)!=EOF)
        {
            if(strcmp(LCIN,cinConnect)==0)
            {   sprintf(nvvote,"%d",id);
                fprintf(f2,"%s %s %s %s %s %s %s %s %s %s %s %s\n",LCIN,LNempreinte,LNtelephone,Lnom,Lprenom,Ljour,Lmois,Lannee,Lmunicipalite,Lgenre,Lrole,nvvote);
            }
            else
                fprintf(f2,"%s %s %s %s %s %s %s %s %s %s %s %s\n",LCIN,LNempreinte,LNtelephone,Lnom,Lprenom,Ljour,Lmois,Lannee,Lmunicipalite,Lgenre,Lrole,Lvote);
 }
     }
    fclose(f);
    fclose(f2);

    remove("utilisateur.txt");
    rename("nouv.txt", "utilisateur.txt");
}

void getCin(char cinConnecter[20])
{       FILE *f=NULL;
	f=fopen("connected.txt", "r");
	if(f!=NULL)
	  {
	   while(fscanf(f,"%s\n",cinConnecter)!=EOF)
		{}
           fclose(f);
	  }
}



int verifierVote(char cinConnecter[20])
 	{
	FILE *f=NULL;
	int VerfVote=0;
	char LCIN[20], LNempreinte[20], LNtelephone[20], Lnom[20], Lprenom[20], Ljour[20], Lmois[20], Lannee[20], Lmunicipalite[20], Lgenre[20], Lrole[20], Lvote[20];
f=fopen("utilisateur.txt", "r");
	if(f!=NULL)
	  {
        while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",LCIN,LNempreinte,LNtelephone,Lnom,Lprenom,Ljour,Lmois,Lannee,Lmunicipalite,Lgenre,Lrole,Lvote)!=EOF)
	{
	if(strcmp(LCIN,cinConnecter)==0)
   	  { if(strcmp(Lvote,"-1")!=0)
 	         {
			VerfVote=1;
 	         }
	  }
	}           
fclose(f);
	  }
return VerfVote;
	}



void getNomPrenom(char cinConnecter[20], char NomPrenom[30], char roleREc[20])
{
	FILE *f=NULL;
	char LCIN[20], LNempreinte[20], LNtelephone[20], Lnom[20], Lprenom[20], Ljour[20], Lmois[20], Lannee[20], Lmunicipalite[20], Lgenre[20], Lrole[20], Lvote[20];
	f=fopen("utilisateur.txt", "r");
	if(f!=NULL)
		{
        while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",LCIN,LNempreinte,LNtelephone,Lnom,Lprenom,Ljour,Lmois,Lannee,Lmunicipalite,Lgenre,Lrole,Lvote)!=EOF)
	{ if(strcmp(LCIN,cinConnecter)==0)
 	  {strcpy(NomPrenom,Lnom);
	   strcat(NomPrenom," ");
	   strcat(NomPrenom,Lprenom);
	   strcpy(roleREc,Lrole);
	  }
	}
fclose(f);
		}
}




int tableau_listeElecvote(char listeElec[20][50])
{int j=0;
	char eid[20],conseiller[20], emunicipalite[20], edeljour[20], edelmois[20], annee[20];
	char chaine[30]="Election ";
FILE* f=fopen("election.txt","r");
if(f==NULL)
{return;}
else

   {while(fscanf(f,"%s %s %s %s %s %s\n",eid,conseiller,emunicipalite,edeljour,edelmois,annee)!=EOF)
      { 
	strcat(chaine,annee); 
	strcpy(listeElec[j],chaine);	
	j++;
	strcpy(chaine,"Election ");
      } 
fclose(f);
}
return j;
}


void CalculVotes()
{
	int Lid,Ljour,Lmois,Lannee;
	char Lorientation[20], listeElecVote[20], Lmunicipalite[20], Lnom_tete_liste[20], Lcandidat1[20], Lcandidat2[20], Lcandidat3[20], ident[20];
	FILE *f=NULL;
	f=fopen("liste.txt","r");
	FILE *g=NULL;
	g=fopen("vote.txt","w");

	if(f!=NULL && g!=NULL)
	{
while(fscanf(f,"%d %s %d %d %d %s %s %s %s %s %s",&Lid,listeElecVote,&Ljour,&Lmois,&Lannee,Lorientation,Lmunicipalite,Lnom_tete_liste,Lcandidat1,Lcandidat2,Lcandidat3)!=EOF)
	{ 
	  fprintf(g,"%d %s %d \n",Lid, listeElecVote, 0);


	}
	  fprintf(g,"%d %s %d \n",0, "Vote_Blanc", 0);
fclose(f);
fclose(g);
}
}





int calculerLeVote(char Lident[10])
{
	int i=0;
	char LCIN[20], LNempreinte[20], LNtelephone[20], Lnom[20], Lprenom[20], Ljour[20], Lmois[20], Lannee[20], Lmunicipalite[20], Lgenre[20], Lrole[20], Lvote[20];
FILE *f=NULL;
f=fopen("utilisateur.txt", "r");
	if(f!=NULL)
	      {
        while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",LCIN,LNempreinte,LNtelephone,Lnom,Lprenom,Ljour,Lmois,Lannee,Lmunicipalite,Lgenre,Lrole,Lvote)!=EOF)
	{
	if(strcmp(Lident,Lvote)==0)
	   {i++;
	   }
        }
fclose(f);
	       }
return i;
}		



void trierVote()
{
 int i=0,j,x,permut;
    calVot aux;
    calVot T[50];
    FILE *f=fopen("vote.txt", "r");
    FILE *f2=fopen("vote2.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %s %d\n",&T[i].idVote,T[i].NomListeVote,&T[i].nbreVote)!=EOF)
        {i++;}


       do
	{
	permut=0;
	for(j=0;j<i-1;j++)

	  { 
	if(T[j+1].nbreVote>T[j].nbreVote)
	   { aux=T[j];
	     T[j]=T[j+1];
	     T[j+1]=aux ;
	     permut=1;
	   }
	  }
	}
       while (permut==1);


    for(j=0; j<i; j++)
    {
      fprintf(f2,"%d %s %d \n",T[j].idVote,T[j].NomListeVote,T[j].nbreVote);
    }

    fclose(f);
    fclose(f2);
    remove("vote.txt");
    rename("vote2.txt", "vote.txt");
}
}



void afficher_VOTE(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
	store=NULL;
	FILE *f;
char nom_liste[30];
int id,nbrV ;

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
	column = gtk_tree_view_column_new_with_attributes("Nombre_Vote", renderer, "text",NBRV, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	
	}
	 store=gtk_list_store_new (COLUMNS,
	 				 G_TYPE_UINT,
					 G_TYPE_STRING,
					 G_TYPE_UINT);

	f=fopen("vote.txt", "r");
	if(f==NULL)
	{
		return;
	}
	else{
	
	while(fscanf(f,"%d %s %d\n",&id,nom_liste,&nbrV)!=EOF)
	{
	gtk_list_store_append (store, &iter); 
	gtk_list_store_set (store,&iter,ID,id,NOM_LISTE,nom_liste,NBRV,nbrV,-1);
	}
	fclose(f);

	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store)); 
	g_object_unref (store);
	}

	
}
