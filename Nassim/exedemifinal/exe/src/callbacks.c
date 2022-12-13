#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "function.h" //nassim
#include "election.h" //seif
#include "bv.h"	     //chaima
#include <string.h>
#include"login.h"
int cons=22;
int consm=22;
election em;
Lorder tab[100];
int n=0;
int x=3;
int y=1;
int checkN=0;
int y11=0;
Liste LM; //utilser dans la btn chercher pour passer enn param ala btn modifier
void
on_radiobtn_M_G_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=1;}
}


void
on_radiobtn_M_C_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=2;}
}


void
on_radiobtn_M_D_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=3;}
}


void
on_radio_btn_G_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=1;}
}


void
on_radio_btn_C_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=2;}
}


void
on_radio_btn_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=3;}
}

//button ajouter dans gestion Liste pour passer a la fenetre d'Ajout
void
on_btn_Ajouter_Nassim_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *ajouter;
	GtkWidget *afficher_Nassim;
	afficher_Nassim=lookup_widget(button,"GestionListeElectorale");
	gtk_widget_destroy(afficher_Nassim);
	ajouter=create_AjouterListe();
	gtk_widget_show (ajouter);
}

//button pour ajouter une liste electorale 
void
on_btn_Ajouter_Liste_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
//declarer les GTKwidget.
	GtkWidget* inputNom ;//nom de la liste
	GtkWidget* Jour; //spinbuttun pour le choix du jour.
	GtkWidget* Mois; //spinbuttun pour Le choix du mois.
	GtkWidget* Annee; //spinbuttun pour le choix de l'année.
	GtkWidget* ComboboxM; //comobox pour Le choix de la municipalité.
	GtkWidget* cinTeteListe ;
	GtkWidget* cinC1 ;
	GtkWidget* cinC2 ;
	GtkWidget* cinC3 ;
	GtkWidget* output;
	GtkWidget* outCheck;
//declarer la struct qui ajouter
        Liste L;
	int verifiA=-1;
	int veriflen=-1;
// associer les objets avec des variables
	inputNom = lookup_widget(button,"entryNomListe") ;
	Jour = lookup_widget(button,"spinJourListe") ;
	Mois = lookup_widget(button,"spinMoisListe") ;
	Annee = lookup_widget(button,"spinAnneeListe") ;
	ComboboxM = lookup_widget(button,"combobox_nassim") ;
	cinTeteListe = lookup_widget(button,"entryCinTete") ;
	cinC1 = lookup_widget(button,"entryCinC1") ;
	cinC2 = lookup_widget(button,"entryCinC2") ;
	cinC3 = lookup_widget(button,"entryCinC3") ;
	output = lookup_widget(button,"labelVerif") ;
	outCheck = lookup_widget(button,"labelCheckN") ;
// récupérer les valeurs des spin buttons 
	strcpy(L.nom_liste,gtk_entry_get_text(GTK_ENTRY(inputNom)));
	L.d.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Jour));
	L.d.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Mois));
	L.d.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Annee));
//récupérer les valeur de radiobutton
	if(x==1)
	{
	 strcpy(L.orientation,"Gauche");
	}
	else if(x==2)
	{
	 strcpy(L.orientation,"Centre");
	}
	else if(x==3)
	{
	 strcpy(L.orientation,"Droite");
	}
//recupérer lcombo
	strcpy(L.municipalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX (ComboboxM)));
// récupérer les valeurs de champ txt 
	strcpy(L.nom_tete_liste,gtk_entry_get_text(GTK_ENTRY(cinTeteListe)));
	strcpy(L.candidat_1,gtk_entry_get_text(GTK_ENTRY(cinC1)));
	strcpy(L.candidat_2,gtk_entry_get_text(GTK_ENTRY(cinC2)));
	strcpy(L.candidat_3,gtk_entry_get_text(GTK_ENTRY(cinC3)));
//appel de la function ajouter
	   verifiA=verifier(L.nom_tete_liste,L.candidat_1,L.candidat_2,L.candidat_3); //verifier l'unicité 
	   veriflen=verifier_len(L.nom_tete_liste,L.candidat_1,L.candidat_2,L.candidat_3);
	  
	if(verifiA!=1&&veriflen==1){

		if(checkN!=0){
		        ajouterListe(L);
			//traja3ni ltree view 
			GtkWidget *ajouter101;
			GtkWidget *destroy101;
			destroy101=lookup_widget(button,"AjouterListe");
			gtk_widget_destroy(destroy101);
			ajouter101=create_GestionListeElectorale();
			gtk_widget_show (ajouter101);}
		else if( checkN==0){
			GdkColor color;
			gdk_color_parse("red",&color);
			gtk_widget_modify_fg(outCheck,GTK_STATE_NORMAL,&color);
			gtk_label_set_text(GTK_LABEL(outCheck),"Check s'il vous plait !");
		}
	}
	else{
		GdkColor color;
		gdk_color_parse("red",&color);
		gtk_widget_modify_fg(output,GTK_STATE_NORMAL,&color);
		gtk_label_set_text(GTK_LABEL(output),"L'un des CIN existe deja dans une Liste ou bien NBR CIN incorrect !!");

	}
}

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar *id;
gchar *nomliste;
gchar *Jour;
gchar *Mois;
gchar *Annee;
gchar* orienta;
gchar* muni;
gchar* cinT;
gchar* cinc1;
gchar* cinc2;
gchar* cinc3;
Liste L;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model, &iter, path)){
//obtention des valeurs de la ligne selectionnee
	gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &id, 1, &nomliste, 2, &Jour, 3, &Mois, 4, &Annee, 5, &orienta, 6, &muni, 7, &cinT, 8, &cinc1, 9, &cinc2, 10, &cinc3, -1);
// copte des valeurs dans la variable p de type personne pour le passer a la fonction de suppression
	L.id=id;
	strcpy (L.nom_liste,nomliste);
	L.d.jour=Jour;
	L.d.mois=Mois;
	L.d.annee=Annee;
	strcpy (L.orientation,orienta);
	strcpy (L.municipalite,muni);
	strcpy (L.nom_tete_liste,cinT);
	strcpy (L.candidat_1,cinc1);
	strcpy (L.candidat_2,cinc2);
	strcpy (L.candidat_3,cinc3);
	
//appel de la fonction de suppression
	supprimer_Liste(L);
// mise a jour de l'affichage de la treeview
	afficher_Liste(treeview);
}
	//MiseAjourIdListe("liste.txt",&L);
}

//button Afficher dana GL pour afficher les element dans le treeview
void
on_btn_Afficher_Tree_Liste_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview_Nassim;
GtkWidget *afficher_u;
afficher_u=lookup_widget(button,"GestionListeElectorale");
treeview_Nassim=lookup_widget(afficher_u,"treeview1");
afficher_Liste(treeview_Nassim);
}

//button Modifier dans gestion Liste pour passer a la fenetre de Modifier
void
on_btn_Modifier_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter;
	GtkWidget *afficher_Nassim;
	afficher_Nassim=lookup_widget(button,"GestionListeElectorale");
	gtk_widget_destroy(afficher_Nassim);
	ajouter=create_windowModifierListe();
	gtk_widget_show (ajouter);
}

//button Retour dana la fenetre modifier pour revenir a la fenetre GL
void
on_btn_retour_modifier_nassim_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter;
	GtkWidget *afficher_Nassim;
	afficher_Nassim=lookup_widget(button,"windowModifierListe");
	gtk_widget_destroy(afficher_Nassim);
	ajouter=create_GestionListeElectorale();
	gtk_widget_show (ajouter);
}

//button Retour dana la fenetre Ajouter pour revenir a la fenetre GL
void
on_btn_Retour_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter;
	GtkWidget *afficher_Nassim;
	afficher_Nassim=lookup_widget(button,"AjouterListe");
	gtk_widget_destroy(afficher_Nassim);
	ajouter=create_GestionListeElectorale();
	gtk_widget_show (ajouter);
}

//button verifier pour verifier l'un des candidats existe dans une autre liste ou nn
void
on_btn_Verifier_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* cinTeteListe ;
	GtkWidget* cinC1 ;
	GtkWidget* cinC2 ;
	GtkWidget* cinC3 ;
	GtkWidget* output;
//declarer la struct qui ajouter
        char CT[10],C1[10],C2[10],C3[10];
	int veri;
	int veriLen;	
// associer les objets avec des variables
	cinTeteListe = lookup_widget(button,"entryCinTete") ;
	cinC1 = lookup_widget(button,"entryCinC1") ;
	cinC2 = lookup_widget(button,"entryCinC2") ;
	cinC3 = lookup_widget(button,"entryCinC3") ;
	output = lookup_widget(button,"labelVerif") ;
// récupérer les valeurs de champ txt 
	strcpy(CT,gtk_entry_get_text(GTK_ENTRY(cinTeteListe)));
	strcpy(C1,gtk_entry_get_text(GTK_ENTRY(cinC1)));
	strcpy(C2,gtk_entry_get_text(GTK_ENTRY(cinC2)));
	strcpy(C3,gtk_entry_get_text(GTK_ENTRY(cinC3)));
//appel function verif
	 veri=verifier(CT,C1,C2,C3);
	 veriLen=verifier_len(CT,C1,C2,C3);
	if(veri==1&&veriLen!=1)
	{
		GdkColor color;
		gdk_color_parse("red",&color);
		gtk_widget_modify_fg(output,GTK_STATE_NORMAL,&color);
		gtk_label_set_text(GTK_LABEL(output),"L'un des CIN existe deja dans une Liste ou bien NBR CIN incorrect !!");
	}
	else
	{
		GdkColor color;
		gdk_color_parse("green",&color);
		gtk_widget_modify_fg(output,GTK_STATE_NORMAL,&color);
		gtk_label_set_text(GTK_LABEL(output),"Vous pouvez maintenant ajouter la Liste");
	}
	
}


void
on_btn_M_chercher_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
//declarer les GTKwidget.
	  GtkWidget* inputIDchercher ;//id a chercher
	  GtkWidget* output;
	  GtkWidget* SJ;
	  GtkWidget* SM;
	  GtkWidget* SA;
          GtkWidget* COX;
	  GtkWidget* outputEr;
// associer les objets avec des variables
	inputIDchercher = lookup_widget(button,"entry_M_id") ;
//declarer 
        char idch[10];
	int idint=atoi(idch);
	strcpy(idch,gtk_entry_get_text(GTK_ENTRY(inputIDchercher)));
//appel function chercher
	LM=chercher(idch);
	if(LM.id!=-1){
         output=lookup_widget(button,"entry_M_nom");
         gtk_entry_set_text(GTK_ENTRY(output),LM.nom_liste);
//*************************************
	 GtkSpinButton *SJ=lookup_widget(button, "spinbtn_M_J");
         gtk_spin_button_set_value(SJ,LM.d.jour);
	 GtkSpinButton *SM=lookup_widget(button, "spinbtn_M_M");
         gtk_spin_button_set_value(SM,LM.d.mois);
	 GtkSpinButton *SA=lookup_widget(button, "spinbtn_M_A");
         gtk_spin_button_set_value(SA,LM.d.annee);
//*************************************
	COX=lookup_widget(button,"cobox_M_muni");
Liste Li;
int i=-1;
int tr=0;
int trouve=0;
char gouv[20];
     	FILE *g=fopen("liste.txt","r");
while(!tr && fscanf(g,"%d %s %d %d %d %s %s %s %s %s %s\n",&Li.id,Li.nom_liste,&Li.d.jour,&Li.d.mois,&Li.d.annee,Li.orientation,Li.municipalite,Li.nom_tete_liste,Li.candidat_1,Li.candidat_2,Li.candidat_3)!=EOF)
	{
	if(idint==Li.id)
	  { tr=1;   //condition d'arret
	  }
	}
	fclose(g);

	/*if(tr==0)
	{gtk_label_set_text(GTK_LABEL(alert),"identifiant non trouvé !");
	}
	else
	{
	gtk_label_set_text(GTK_LABEL(alert),"");*/
	
	//traitement gouv
	FILE *f=fopen("gouvernorat.txt","r");
	while(!trouve && fscanf(f,"%s \n",gouv)!=EOF)
	   {i++; 
	    if(strcmp(gouv,Li.municipalite)==0)
	    trouve=1;   //condition d'arret
	   }
	gtk_combo_box_set_active(GTK_COMBO_BOX(COX),i);
//*************************************
	/* 
	 if(strcmp(LM.municipalite,"Tunis")){
         	gtk_combo_box_set_active(COX,2);}
	 else if(strcmp(LM.municipalite,"Beja")){
         	gtk_combo_box_set_active(COX,1);}
	 else if(strcmp(LM.municipalite,"Sousse")){
         	gtk_combo_box_set_active(COX,3);}*/
//*************************************
	 output=lookup_widget(button,"entry_M_cinT");
         gtk_entry_set_text(GTK_ENTRY(output),LM.nom_tete_liste);
	 output=lookup_widget(button,"entry_M_cinc1");
         gtk_entry_set_text(GTK_ENTRY(output),LM.candidat_1);
	 output=lookup_widget(button,"entry_M_cinc2");
         gtk_entry_set_text(GTK_ENTRY(output),LM.candidat_2);
	 output=lookup_widget(button,"entry_M_cinc3");
         gtk_entry_set_text(GTK_ENTRY(output),LM.candidat_3);

}
	else{
	 	
		///
	}
}




void
on_btn_M_Modifier_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
//declarer les GTKwidget.
	  GtkWidget* inputIDchercher ;//id 
	  GtkWidget* output;
	  GtkWidget* SJ;
	  GtkWidget* SM;
	  GtkWidget* SA;
          GtkWidget* COX;
	  GtkWidget* outputEr;
// associer les objets avec des variables
	inputIDchercher = lookup_widget(button,"entry_M_id") ;
//declarer 
        char idch[10];
	int idIN;
	Liste nouvL;
	int test;
	int xv;
	strcpy(idch,gtk_entry_get_text(GTK_ENTRY(inputIDchercher)));
//convert txtentry to int 
	idIN=atoi(idch);
	nouvL.id=idIN;
	GtkWidget* inputNom ;//nom de la liste
	GtkWidget* Jour; //spinbuttun pour le choix du jour.
	GtkWidget* Mois; //spinbuttun pour Le choix du mois.
	GtkWidget* Annee; //spinbuttun pour le choix de l'année.
	GtkWidget* ComboboxM; //comobox pour Le choix de la municipalité.
	GtkWidget* cinTeteListe ;
	GtkWidget* cinC1 ;
	GtkWidget* cinC2 ;
	GtkWidget* cinC3 ;
	GtkWidget* outputEM ;

// associer les objets avec des variables
	inputNom = lookup_widget(button,"entry_M_nom") ;
	Jour = lookup_widget(button,"spinbtn_M_J") ;
	Mois = lookup_widget(button,"spinbtn_M_M") ;
	Annee = lookup_widget(button,"spinbtn_M_A") ;
	ComboboxM = lookup_widget(button,"cobox_M_muni") ;
	cinTeteListe = lookup_widget(button,"entry_M_cinT") ;
	cinC1 = lookup_widget(button,"entry_M_cinc1") ;
	cinC2 = lookup_widget(button,"entry_M_cinc2") ;
	cinC3 = lookup_widget(button,"entry_M_cinc3") ;
	outputEM = lookup_widget(button,"labelER_M") ;
// récupérer les valeurs des spin buttons 
	strcpy(nouvL.nom_liste,gtk_entry_get_text(GTK_ENTRY(inputNom)));
	nouvL.d.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Jour));
	nouvL.d.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Mois));
	nouvL.d.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Annee));
//récupérer les valeur de radiobutton
	if(y==1)
	{
	 strcpy(nouvL.orientation,"Gauche");
	}
	if(y==2)
	{
	 strcpy(nouvL.orientation,"Centre");
	}
	if(y==3)
	{
	 strcpy(nouvL.orientation,"Droite");
	}
//recupérer lcombo
	strcpy(nouvL.municipalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX (ComboboxM)));
// récupérer les valeurs de champ txt 
	strcpy(nouvL.nom_tete_liste,gtk_entry_get_text(GTK_ENTRY(cinTeteListe)));
	strcpy(nouvL.candidat_1,gtk_entry_get_text(GTK_ENTRY(cinC1)));
	strcpy(nouvL.candidat_2,gtk_entry_get_text(GTK_ENTRY(cinC2)));
	strcpy(nouvL.candidat_3,gtk_entry_get_text(GTK_ENTRY(cinC3)));

		//appel function modifier
	        test=modifierListe("liste.txt",idIN,nouvL);
		if(test==1){
		 //traja3ni ltree view 
			GtkWidget *ajouter;
			GtkWidget *afficher_Nassim;
			afficher_Nassim=lookup_widget(button,"windowModifierListe");
			gtk_widget_destroy(afficher_Nassim);
			ajouter=create_GestionListeElectorale();
			gtk_widget_show (ajouter);	
		}
		else{
			GdkColor color;
		        gdk_color_parse("red",&color);
		        gtk_widget_modify_fg(outputEM,GTK_STATE_NORMAL,&color);
		        gtk_label_set_text(GTK_LABEL(outputEM),"Oups echec modification !!");
			
		    }


}


void
on_btn_stat_Nassim_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *ajouter;
	GtkWidget *afficher_Nassim;
	afficher_Nassim=lookup_widget(button,"Statistique");
	gtk_widget_destroy(afficher_Nassim);
	ajouter=create_Stat_Liste_Nassim();
	gtk_widget_show (ajouter);
}


void
on_btn_calc_NBV_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
//declarer les GTKwidget.
	  GtkWidget* inputIDchercher ;//id a chercher
	  GtkWidget* output;
//declarer des variables
	int result;
	char idch[10]; 
// associer les objets avec des variables
	inputIDchercher = lookup_widget(button,"entry_idL_nbr") ;
	strcpy(idch,gtk_entry_get_text(GTK_ENTRY(inputIDchercher)));
//appel function nbv
	result=nbv(idch);
	char resch[20];
sprintf(resch,"%d",result);
//*************************************
	/* GdkColor color;
         gdk_color_parse("green",&color);
 	 gtk_widget_modify_fg(output,GTK_STATE_NORMAL,&color);*/
	 output=lookup_widget(button,"label_R_NBR");
	 gtk_label_set_text(GTK_LABEL(output),resch);


}


void
on_treeviewNBRV_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
GtkWidget *treeview_Nassim;
gchar *nomliste;
gchar *id;
gchar *nbvote;
Liste L;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model, &iter, path)){
//obtention des valeurs de la ligne selectionnee
	gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &nomliste, 1, &id, 2, &nbvote,-1);

// mise a jour de l'affichage de la treeview
	afficher_Liste_ordre(treeview);
}
}


void
on_btn_actualiser_TreeNBRV_clicked     (GtkWidget       *button,
                                        gpointer         user_data)
{
	remplirtab(tab,&n);//les listes selon nbr de votes
	 printTab(tab,&n);//fonction pour print les liste et nbr de vote 

       
 //laffichage de etreeview
GtkWidget *treeview_Nassim;
GtkWidget *afficher_u;
afficher_u=lookup_widget(button,"Stat_Liste_Nassim");
treeview_Nassim=lookup_widget(afficher_u,"treeviewNBRV");
afficher_Liste_ordre(treeview_Nassim);
}

void
on_btn_QUITTER_A_N_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_main_quit();
}

void
on_btn_cher____clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *cherch;
	char ch[20];
	GtkWidget *treeview1_N;
	GtkWidget *afficher_N;
	afficher_N=lookup_widget(button,"GestionListeElectorale");

	treeview1_N=lookup_widget(afficher_N,"treeview1");
	cherch = lookup_widget (button ,"entry_cher_N");
	strcpy(ch, gtk_entry_get_text(GTK_ENTRY(cherch)));
	 Chercher_Nassim(treeview1_N,ch);
}

void
on_checkbutton_A_N_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{checkN=1;}
}



void
on_ListeToHome_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *GestionListeElectorale;
	GtkWidget *interfaceCondidat;
char cinConnecter[20], NomPrenom[30], roleREc[20];
	getCin(cinConnecter);
	getNomPrenom(cinConnecter, NomPrenom, roleREc);

	if(strcmp(roleREc,"condidat")==0)
	{
	GestionListeElectorale=lookup_widget(objet,"GestionListeElectorale");
	gtk_widget_destroy(GestionListeElectorale);
	interfaceCondidat=lookup_widget(objet,"interfaceCondidat");
	interfaceCondidat=create_interfaceCondidat();
	gtk_widget_show(interfaceCondidat);
	}
	else
	{
	GestionListeElectorale=lookup_widget(objet,"GestionListeElectorale");
	gtk_widget_destroy(GestionListeElectorale);
	GtkWidget *AdminHome;
	AdminHome=lookup_widget(objet,"AdminHome");
	AdminHome=create_AdminHome();
	gtk_widget_show(AdminHome);
	}
}













///////////////////////////////// Interface BUreau de Vote-CHAIMAMATOUSSI- ///////////////////////////////////////////////





int salle=2, cliquer=0;
checkModif=0;
BV bvModif;

void
on_afficherbv_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *ajout;
	GtkWidget *affiche;
	GtkWidget *treeview;

	ajout=lookup_widget(objet,"ajoutBV");

	gtk_widget_destroy(ajout);
	affiche=lookup_widget(objet,"afficherBV");
	affiche=create_afficherBV();
	
	gtk_widget_show(affiche);
	
	treeview=lookup_widget(affiche,"treeviewBV");
	afficher_bv(treeview);
	
}




void
on_ajouterbv_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
	BV bv;
	char sallebv[10];
	char cE[10];
	char cO[10];
	char agentbv[50];
	int a,b,erreur=0,idNum,TestId=0,Testbt=0;

	sprintf(sallebv,"%d",salle);

	GtkWidget *id, *capElec, *capObserv, *gouv, *deleg, *idAg, *alert;
	GtkWidget *ajoutBV;

	strcpy(bv.gouvernorat,"vide");
	strcpy(bv.delegation,"vide");
	strcpy(bv.IDagent.idAg,"vide");
	

	ajoutBV=lookup_widget(objet,"ajoutBV");
	id=lookup_widget(objet,"idbv");
	capElec=lookup_widget(objet,"elecbv");
	capObserv=lookup_widget(objet,"obsbv");
	gouv=lookup_widget(objet,"gouvernoratajbv");
	deleg=lookup_widget(objet,"delegation");
	idAg=lookup_widget(objet,"idagentbv");


	strcpy(bv.id,gtk_entry_get_text(GTK_ENTRY(id)));
	a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(capElec));
	b=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(capObserv));
	sprintf(cE,"%d",a);
	sprintf(cO,"%d",b);
	strcpy(bv.capElecteurs,cE);
	strcpy(bv.capObservateurs,cO);
	strcpy(bv.gouvernorat,gtk_combo_box_get_active_text(GTK_COMBO_BOX(gouv)));
	strcpy(bv.IDagent.idAg,gtk_combo_box_get_active_text(GTK_COMBO_BOX(idAg)));
	strcpy(bv.salle,sallebv);


////////////////  TEST DE SAISIE  ////////////////

   	 idNum=atoi(bv.id);
	
	if((idNum<10000000)||(idNum>99999999))
	{
	GtkWidget *alert1bv;
	alert1bv=lookup_widget(objet,"alert1bv");
	gtk_label_set_text(GTK_LABEL(alert1bv),"❌ Il faut saisir un ID comporte 8 numéro !");
	TestId=0;
	}
	else
	{
	GtkWidget *alert1bv;
	alert1bv=lookup_widget(objet,"alert1bv");
	gtk_label_set_text(GTK_LABEL(alert1bv)," ");
	TestId=1;
	}

	
	if(cliquer==0)
	{GtkWidget *alert2bv;
	alert2bv=lookup_widget(objet,"alert2bv");
	gtk_label_set_text(GTK_LABEL(alert2bv),"ℹ Cliquer sur le bouton pour afficher les délegations");
	Testbt=0;
	}
	else
	{
	strcpy(bv.delegation,gtk_combo_box_get_active_text(GTK_COMBO_BOX(deleg)));
	GtkWidget *alert2bv;
	alert2bv=lookup_widget(objet,"alert2bv");
	gtk_label_set_text(GTK_LABEL(alert2bv)," ");
	Testbt=1;
	}

	if((Testbt==1) && (TestId==1))
	{

	ajouter_bv(bv);
	supprimerAgent("agent.txt", bv.IDagent.idAg);
	supprimerDelegation("delegation.txt", bv.delegation);
	gtk_widget_destroy(ajoutBV);
	ajoutBV=create_ajoutBV();
	gtk_widget_show(ajoutBV);
	alert=lookup_widget(ajoutBV,"alertajbv");
	gtk_label_set_text(GTK_LABEL(alert),"Opération Réussie");

	}
	else{
	GtkWidget *alert3bv;
	alert3bv=lookup_widget(objet,"alert3bv");
	gtk_label_set_text(GTK_LABEL(alert3bv),"Echec d'ajout !");
	}






}






void
on_retourbv_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajout, *affiche;
affiche=lookup_widget(objet,"afficherBV");

gtk_widget_destroy(affiche);
ajout=create_ajoutBV();
gtk_widget_show(ajout);
}




void
on_bt_clicked                          (GtkWidget       *objet,
                                        gpointer         user_data)
{int i,n,m;
BV bv;

char delegat[50][50],gouver[30];
cliquer=1;
GtkWidget *delegation,*gouvernorat;
delegation=lookup_widget(objet,"delegation");
gouvernorat=lookup_widget(objet,"gouvernoratajbv");

strcpy(gouver,gtk_combo_box_get_active_text(GTK_COMBO_BOX(gouvernorat)));
m=tableau_delegation(delegat, gouver);
for(i=0;i<m;i++)
{gtk_combo_box_append_text(GTK_COMBO_BOX(delegation),_(delegat[i]));
}
}







void
on_salle3_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
salle=3;
}


void
on_salle2_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
salle=2;
}


void
on_salle1_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
salle=1;
}


void
on_treeviewBV_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar* id;
	gchar* capElecteurs;
	gchar* capObservateurs;
	gchar* salle;
	gchar* gouvernorat;
	gchar* delegation;
	gchar* idAg;

	BV bv;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if(gtk_tree_model_get_iter(model, &iter, path))
	{ 
gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &id, 1, &capElecteurs, 2, &capObservateurs, 3, &salle, 4, &gouvernorat, 5, &delegation, 6, &idAg, -1);
	strcpy(bv.id,id);
	strcpy(bv.capElecteurs,capElecteurs);
	strcpy(bv.capObservateurs,capObservateurs);
	strcpy(bv.salle,salle);
	strcpy(bv.gouvernorat,gouvernorat);
	strcpy(bv.delegation,delegation);
	strcpy(bv.IDagent.idAg,idAg);

	supprimer_bv(bv);

	afficher_bv(treeview);

	 
	}
}


void
on_supprimerbv_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *affiche, *supprimer,*treeview;

	affiche=lookup_widget(objet,"afficherBV");
	gtk_widget_destroy(affiche);

	supprimer=lookup_widget(objet,"supprimerbuv");
	supprimer=create_supprimerbuv();
	
	gtk_widget_show(supprimer);
	treeview=lookup_widget(supprimer,"treeview2BV");
	afficher_bv(treeview);
	
}


void
on_retouraffichebv_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *affiche, *supprimer, *treeview;
supprimer=lookup_widget(objet,"supprimerbuv");

gtk_widget_destroy(supprimer);
affiche=create_afficherBV();
gtk_widget_show(affiche);
	treeview=lookup_widget(affiche,"treeviewBV");
	afficher_bv(treeview);

}


void
on_supprimerfinal_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{char suppI[20],gouvSup[30],delegt[30],idagn[20];
int t;
	GtkWidget *idsupp,*alertsupp,*supprimerbuv;
	GtkWidget *treeview;

	supprimerbuv=lookup_widget(objet,"supprimerbuv");
	idsupp=lookup_widget(objet,"supprimerbvid");
	alertsupp=lookup_widget(objet,"alertsupp");
	strcpy(suppI,gtk_entry_get_text(GTK_ENTRY(idsupp)));


	t=supprimer_idbv(suppI);
if(t==1)
{
	gtk_label_set_text(GTK_LABEL(alertsupp),"Opération Réussie");
	

}
else
{
	gtk_label_set_text(GTK_LABEL(alertsupp),"identifiant non trouvé !");
}


	treeview=lookup_widget(supprimerbuv,"treeview2BV");
	afficher_bv(treeview);

}


void
on_quitterbv_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{gtk_main_quit();

}


void
on_rechercherBV_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
	{ 
	char idrech[20];
	char gouv[20];
	BV bv;
	int i=-1, trouve=0,tr=0 , capE=0, capO=0;
	GtkWidget *idbvv, *gouvernoratv, *delegationv, *idagentbvv, *alert, *elecbvv, *obsbvv, *radio1, *radio2, *radio3;


	idbvv=lookup_widget(objet, "idbvv");
	gouvernoratv=lookup_widget(objet, "gouvernoratv");
	delegationv=lookup_widget(objet, "delegationv");
	idagentbvv=lookup_widget(objet, "idagentbvv");
	alert=lookup_widget(objet, "alertRech");
	elecbvv=lookup_widget(objet, "elecbvv");
	obsbvv=lookup_widget(objet, "obsbvv");
	radio1=lookup_widget(objet, "radio1");
	radio2=lookup_widget(objet, "radio2");
	radio3=lookup_widget(objet, "radio3");

	strcpy(idrech,gtk_entry_get_text(GTK_ENTRY(idbvv)));

	FILE *g=fopen("bureauV.txt","r");
while(!tr && fscanf(g,"%s %s %s %s %s %s %s\n",bv.id,bv.capElecteurs,bv.capObservateurs,bv.salle,bv.gouvernorat,bv.delegation,bv.IDagent.idAg)!=EOF)
	{
	if(strcmp(idrech,bv.id)==0)
	  { tr=1;   //condition d'arret
	  }
	}
	fclose(g);

	if(tr==0)
	{gtk_label_set_text(GTK_LABEL(alert),"identifiant non trouvé !");
	}
	else
	{
	gtk_label_set_text(GTK_LABEL(alert),"");
	bvModif=bv;
	//traitement gouv
	FILE *f=fopen("gouvernorat.txt","r");
	while(!trouve && fscanf(f,"%s \n",gouv)!=EOF)
	   {i++; 
	    if(strcmp(gouv,bv.gouvernorat)==0)
	    trouve=1;   //condition d'arret
	   }
	gtk_combo_box_set_active(GTK_COMBO_BOX(gouvernoratv),i);


	//traitement electeur
	capE=atoi(bv.capElecteurs);
	gtk_spin_button_set_value(elecbvv,capE);


	//traitement observateur
	capO=atoi(bv.capObservateurs);
	gtk_spin_button_set_value(obsbvv,capO);


	//traitement salle
	if(strcmp(bv.salle,"1")==0)
	{gtk_toggle_button_set_active(GTK_RADIO_BUTTON(radio1),TRUE);
	}
	else if(strcmp(bv.salle,"2")==0)
	{gtk_toggle_button_set_active(GTK_RADIO_BUTTON(radio2),TRUE);
	}
	else if(strcmp(bv.salle,"3")==0)
	{gtk_toggle_button_set_active(GTK_RADIO_BUTTON(radio3),TRUE);
	}


	fclose(f);
	}

	
          

}


void
on_affTomod_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
	{GtkWidget *afficherBV, *modifierBV;
	afficherBV=lookup_widget(objet,"afficherBV");

	gtk_widget_destroy(afficherBV);
	modifierBV=lookup_widget(objet,"modifierBV");
	modifierBV=create_modifierBV();
	
	gtk_widget_show(modifierBV);
	
	}


void
on_modToaff_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
	{GtkWidget *afficherBV, *modifierBV ,*treeview;
	modifierBV=lookup_widget(objet,"modifierBV");

	gtk_widget_destroy(modifierBV);
	afficherBV=lookup_widget(objet,"afficherBV");
	afficherBV=create_afficherBV();
	
	gtk_widget_show(afficherBV);
	treeview=lookup_widget(afficherBV,"treeviewBV");
	afficher_bv(treeview);

	}







void
on_trierBVMunic_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *treeview, *afficherBV;
	trierMunicipalite("bureauV.txt");
	afficherBV=lookup_widget(objet,"afficherBV");
	treeview=lookup_widget(afficherBV,"treeviewBV");
	afficher_bv(treeview);
}


void
on_deleg_clicked                          (GtkWidget       *objet,
                                        gpointer         user_data)
{int i,n,m;
BV bv;
char agent[50][50],delegat[50][50],gouver[30];
GtkWidget *idagentbv,*delegation,*gouvernorat;
idagentbv=lookup_widget(objet,"idagentbvv");
delegation=lookup_widget(objet,"delegationv");
gouvernorat=lookup_widget(objet,"gouvernoratv");
n=tableau_agent(agent);

for(i=0;i<n;i++)
{gtk_combo_box_append_text(GTK_COMBO_BOX(idagentbv),_(agent[i]));
}

strcpy(gouver,gtk_combo_box_get_active_text(GTK_COMBO_BOX(gouvernorat)));
m=tableau_delegation(delegat, gouver);
for(i=0;i<m;i++)
{gtk_combo_box_append_text(GTK_COMBO_BOX(delegation),_(delegat[i]));
}
}

void
on_confirmAjout_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
BV bv,bv2;
	char sallebv[10];
	char cE[10];
	char cO[10];
	char agentbv[50];
	int a,b,erreur=0;

	sprintf(sallebv,"%d",salle);

	GtkWidget *id, *capElec, *capObserv, *gouv, *deleg, *idAg, *alertCheck;
	GtkWidget *modifierBV;
	GtkWidget *alertnidbv,*labelngouv,*labelndelg;
	

	modifierBV=lookup_widget(objet,"modifierBV");
	id=lookup_widget(objet,"idbvv");
	capElec=lookup_widget(objet,"elecbvv");
	capObserv=lookup_widget(objet,"obsbvv");
	gouv=lookup_widget(objet,"gouvernoratv");
	deleg=lookup_widget(objet,"delegationv");
	idAg=lookup_widget(objet,"idagentbvv");
	alertCheck=lookup_widget(objet,"alertCheck");



	strcpy(bv.id,gtk_entry_get_text(GTK_ENTRY(id)));
	a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(capElec));
	b=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(capObserv));
	sprintf(cE,"%d",a);
	sprintf(cO,"%d",b);
	strcpy(bv.capElecteurs,cE);
	strcpy(bv.capObservateurs,cO);
	strcpy(bv.gouvernorat,gtk_combo_box_get_active_text(GTK_COMBO_BOX(gouv)));
	strcpy(bv.delegation,gtk_combo_box_get_active_text(GTK_COMBO_BOX(deleg)));
	strcpy(bv.IDagent.idAg,gtk_combo_box_get_active_text(GTK_COMBO_BOX(idAg)));
	strcpy(bv.salle,sallebv);


	if(checkModif!=1)
	{	gtk_label_set_text(GTK_LABEL(alertCheck),"Confirmer la modification");
	}
	else{
	gtk_label_set_text(GTK_LABEL(alertCheck),"Opération Réussie");
	supprimer_bv(bvModif);
	ajouter_bv(bv);
	supprimerAgent("agent.txt", bv.IDagent.idAg);
	supprimerDelegation("delegation.txt", bv.delegation);
	}
	gtk_widget_destroy(modifierBV);

	modifierBV=create_modifierBV();
	
	gtk_widget_show(modifierBV);
	

}


void
on_check_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{checkModif=1;}
}


void
on_quitterAff_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_main_quit();
}


void
on_quitterSupp_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_main_quit();
}


void
on_quitterMod_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_main_quit();
}





void
on_trierElect_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *treeview, *afficherBV;
	trierElecteurs("bureauV.txt");
	afficherBV=lookup_widget(objet,"afficherBV");
	treeview=lookup_widget(afficherBV,"treeviewBV");
	afficher_bv(treeview);
}



void
on_TrierSalle_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *treeview, *afficherBV;
	trierSalle("bureauV.txt");
	afficherBV=lookup_widget(objet,"afficherBV");
	treeview=lookup_widget(afficherBV,"treeviewBV");
	afficher_bv(treeview);
}

////////////////////FIN Interface BUreau de Vote -CHAIMA MATOUSSI-/////////////////////////////////////


void
on_btn_Connexion_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{	
	GtkWidget *WindowLogin;
	GtkWidget *entryLogin;
	GtkWidget *entryPass;
	GtkWidget *output;
	char login[20];
	char Motdepasse[20];
	int cnx=0;
	WindowLogin=lookup_widget(objet,"WindowLogin");
	entryLogin=lookup_widget(objet,"entryLogin");
	entryPass=lookup_widget(objet,"entryPass");
	entryPass=lookup_widget(objet,"labelErreurConnexion");
//************************************************************************
	strcpy(login,gtk_entry_get_text(GTK_ENTRY(entryLogin)));
	strcpy(Motdepasse,gtk_entry_get_text(GTK_ENTRY(Motdepasse)));
//************************************************************************
	cnx=connexion(login,Motdepasse);
	if(cnx==1)
	{
			//admin y7el kol chy
	}
	else if(cnx==3)
	{
		GtkWidget *ajouter;
		GtkWidget *afficher_Nassim;
		afficher_Nassim=lookup_widget(objet,"WindowLogin");
		gtk_widget_destroy(afficher_Nassim);
		ajouter=create_GestionListeElectorale();
		gtk_widget_show (ajouter);
	}
	else{
	  	 GdkColor color;
		gdk_color_parse("red",&color);
		gtk_widget_modify_fg(output,GTK_STATE_NORMAL,&color);
		gtk_label_set_text(GTK_LABEL(output),"Login ou Mot de passe incorrect !");
	}



}


void
on_fenetreAjoutBV_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *AjouterListe, *ajoutBV;
	AjouterListe=lookup_widget(objet,"AjouterListe");
	ajoutBV=lookup_widget(objet,"ajoutBV");
	gtk_widget_destroy(AjouterListe);
	ajoutBV=create_ajoutBV();
	gtk_widget_show(ajoutBV);
}


void
on_bvToAdmin_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *ajoutBV, *AdminHome;
	ajoutBV=lookup_widget(objet,"ajoutBV");
	gtk_widget_destroy(ajoutBV);
	AdminHome=create_AdminHome();
	gtk_widget_show(AdminHome);
}



////////////////////////////////////////////////////////Seif fathallah///////////////////////////////////////////////////////////
void
on_nbrmod1_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{consm=22;}
}


void
on_nbrmodel2_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{consm=40;}
}


void
on_nbrmodel3_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{consm=60;}
}




void
on_afficherel_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
   GtkWidget *ajout;
	GtkWidget *affiche;
	GtkWidget *treeview;

	ajout=lookup_widget(objet,"windowel");

	gtk_widget_destroy(ajout);
	affiche=lookup_widget(objet,"windowafficherel");
	affiche=create_windowafficherel();
	
	gtk_widget_show(affiche);

	treeview=lookup_widget(affiche,"treeviewaffel");
	afficher_election(treeview);
}


void
on_quitteraj_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_main_quit();
}


void
on_treeviewaffel_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar* id;
        gchar* nbr_conseiller;
        gchar* municipalite;
	gchar* jour0;
	gchar* mois0;
	gchar* annee0;

	election e;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if(gtk_tree_model_get_iter(model, &iter, path))
	{ 
gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &id, 1, &nbr_conseiller, 2, &municipalite, 3, &jour0, 4, &mois0, 5, &annee0, -1);
	strcpy(e.id,id);
	strcpy(e.nbr_conseiller,nbr_conseiller);
	strcpy(e.municipalite,municipalite);
	strcpy(e.del.jour0,jour0);
	strcpy(e.del.mois0,mois0);
	strcpy(e.del.annee0,annee0);
	

	supprimer_election(e);

	afficher_election(treeview);

	 
	}
}


void
on_retoureel_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajout, *affiche;
affiche=lookup_widget(objet,"windowafficherel");

gtk_widget_destroy(affiche);
ajout=create_windowel();
gtk_widget_show(ajout);
}


void
on_modier_aff_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *ajouter;
	GtkWidget *afficher_m;
	afficher_m=lookup_widget(button,"windowafficherel");
	gtk_widget_destroy(afficher_m);
	ajouter=create_modifeel();
	gtk_widget_show (ajouter);
}


void
on_quitteraff_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_main_quit();
}


void
on_chmedel_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
//declarer les GTKwidget.
	  GtkWidget* inputIDchercher ;//id a chercher
	  GtkWidget* output;
	  GtkWidget* SJ;
	  GtkWidget* SM;
	  GtkWidget* SA;
          GtkWidget* COX;
	  GtkWidget* outputEr;
	  GtkWidget *ra1,*ra2,*ra3;
	  GtkWidget *compt;
// associer les objets avec des variables
	inputIDchercher = lookup_widget(button,"idmodel") ;
	ra1=lookup_widget(button, "nbrmod1");
	ra2=lookup_widget(button, "nbrmodel2");
	ra3=lookup_widget(button, "nbrmodel3");
	compt=lookup_widget(button, "nbrmodcons");
//declarer 
        char idch[50];
	int  j1, m1, a1;
	strcpy(idch,gtk_entry_get_text(GTK_ENTRY(inputIDchercher)));
//appel function chercher_election
	em=chercher_election(idch);
	if(strcmp(em.id,"-1")!=0)

	{
	GtkWidget *erreurModification;
erreurModification= lookup_widget (button ,"labelch_erreurmod");
GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(erreurModification,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(erreurModification),"Cette election existe !");
gtk_widget_show (erreurModification);

	j1 = atoi (em.del.jour0);
	 m1 = atoi (em.del.mois0);
	 a1 = atoi (em.del.annee0);
         

	 SJ=lookup_widget(button, "jourmodel");
         gtk_spin_button_set_value(SJ,j1);
	 SM=lookup_widget(button, "moismodel");
         gtk_spin_button_set_value(SM,m1);
	 SA=lookup_widget(button, "enneemodel");
         gtk_spin_button_set_value(SA,a1);
	output=lookup_widget(button,"conseilermodel");
     if(strcmp(em.nbr_conseiller,"22")==0)
       {
        
        gtk_toggle_button_set_active(GTK_RADIO_BUTTON(ra1),TRUE);
	
        // gtk_entry_set_text(GTK_ENTRY(compt),em.nbr_conseiller);
       }
     else if(strcmp(em.nbr_conseiller,"40")==0)
       {
        
        gtk_toggle_button_set_active(GTK_RADIO_BUTTON(ra2),TRUE);
       //  gtk_entry_set_text(GTK_ENTRY(compt),em.nbr_conseiller);
       }
      //if (strcmp(em.nbr_conseiller,"60")==0)
           else {
             
             gtk_toggle_button_set_active(GTK_RADIO_BUTTON(ra3),TRUE);
	
        // gtk_entry_set_text(GTK_ENTRY(compt),em.nbr_conseiller);
            }
//*************************************
	 COX=lookup_widget(button,"municipalitemodel");
	 if(strcmp(em.municipalite,"Ariana")==0){
         	gtk_combo_box_set_active(COX,0);}
	 else if(strcmp(em.municipalite,"Beja")==0){
         	gtk_combo_box_set_active(COX,1);}
	else if(strcmp(em.municipalite,"Jendouba")==0){
         	gtk_combo_box_set_active(COX,2);}
	 else if(strcmp(em.municipalite,"Mahdia")==0){
         	gtk_combo_box_set_active(COX,3);}
	 else if(strcmp(em.municipalite,"Sousse")==0){
         	gtk_combo_box_set_active(COX,4);}
         
//*************************************
	

	}
	else{
	 	
		//outputEr=lookup_widget(button,"labelch_erreurmod");
               // gtk_entry_set_text(GTK_ENTRY(outputEr),"Cette election n'existe pas !");
	GtkWidget *erreurModification;
erreurModification= lookup_widget (button ,"labelch_erreurmod");
GdkColor color;
gdk_color_parse("red",&color);
gtk_widget_modify_fg(erreurModification,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(erreurModification),"Cette election n'existe pas ");
gtk_widget_show (erreurModification);

	}

}


void
on_model_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
char conseiller[50];
char joure[50];
char moise[50];
char an[50];
int j,m,a;
/*//declarer les GTKwidget.
	  GtkWidget* inputIDchercher ;
	  GtkWidget* output;
	  GtkWidget* SJ;
	  GtkWidget* SM;
	  GtkWidget* SA;
          GtkWidget* COX;
	  GtkWidget* outputEr;
// associer les objets avec des variables
	inputIDchercher = lookup_widget(button,"idmodel") ;
//declarer 
       char idch[10];
	//int idIN;
	election emod;
	int test;
	strcpy(idch,gtk_entry_get_text(GTK_ENTRY(inputIDchercher)));
//convert txtentry to int 
	//idIN=atoi(idch);
	//nouvL.id=idIN;
	//GtkWidget* inputNom ;nom de la liste
	GtkWidget* Jour; //spinbuttun pour le choix du jour.
	GtkWidget* Mois; //spinbuttun pour Le choix du mois.
	GtkWidget* Annee; //spinbuttun pour le choix de l'année.
	GtkWidget* Comboboxmod; //comobox pour Le choix de la municipalité.
	GtkWidget* conseillermod ;
	
// associer les objets avec des variables
	
	Jour = lookup_widget(button,"jourmodel") ;
	Mois = lookup_widget(button,"moisdmodel") ;
	Annee = lookup_widget(button,"enneemodel") ;
	Comboboxmod = lookup_widget(button,"municipalitemodel") ;
	conseillermod = lookup_widget(button,"conseillermodel") ;
	
// récupérer les valeurs des spin buttons 
	sprintf(jourem,"%d",jm);
	sprintf(moisem,"%d",mm);
	sprintf(anm,"%d",am);
	//strcpy(nouvL.nom_liste,gtk_entry_get_text(GTK_ENTRY(inputNom)));
	jm=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Jour));
	mm=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Mois));
	am=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Annee));
	strcpy(emod.del.jour,jourem);
	strcpy(emod.del.mois,moisem);
	strcpy(emod.del.annee,anm);
//récupérer les valeur de radiobutton
	if(consm==22)
	{
	 
         strcpy(emod.nbr_conseiller,gtk_entry_get_text(GTK_ENTRY(conseillermod)));
	}
	if(consm==40)
	{
	 strcpy(emod.nbr_conseiller,gtk_entry_get_text(GTK_ENTRY(conseillermod)));
	}
	if(consm==60)
	{
	 strcpy(emod.nbr_conseiller,gtk_entry_get_text(GTK_ENTRY(conseillermod)));
	}
//recupérer lcombo
	strcpy(emod.municipalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX (Comboboxmod)));
//appel function modifier

	test=modifier_election("election.txt",idch,emod);
/traja3ni lajouter 
	GtkWidget *ajouter;
	GtkWidget *afficher_m;
	afficher_m=lookup_widget(button,"modifeel");
	gtk_widget_destroy(afficher_m);
	ajouter=create_windowafficherel();
	gtk_widget_show (ajouter);
*/
election em1;
GtkWidget *id , *municipalite ,*jour, *mois, *annee , *alert, *alert1;
GtkWidget *window;
window=lookup_widget(button,"modifeel");

id=lookup_widget(button,"idmodel");
municipalite=lookup_widget(button,"municipalitemodel");
jour=lookup_widget(button,"jourmodel");
mois=lookup_widget(button,"moismodel");
annee=lookup_widget(button,"enneemodel");
j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
alert=lookup_widget(button,"nbrmodcons");
alert1=lookup_widget(button,"labelajoutermodel");




sprintf(conseiller,"%d",consm);
sprintf(joure,"%d",j);
sprintf(moise,"%d",m);
sprintf(an,"%d",a);


strcpy(em1.nbr_conseiller,conseiller);
strcpy(em1.id,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(em1.municipalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(municipalite)));

gtk_label_set_text(GTK_LABEL(alert),em1.nbr_conseiller);
GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(alert1,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(alert1),"modification avec succés");
strcpy(em1.del.jour0,joure);
strcpy(em1.del.mois0,moise);
strcpy(em1.del.annee0,an);
supprimer_election(em);

ajouter_election("election.txt",em1);




}


void
on_retoure_aff_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *ajout;
	GtkWidget *affiche;
	GtkWidget *treeview;

	ajout=lookup_widget(button,"modifeel");

	gtk_widget_destroy(ajout);
	affiche=lookup_widget(button,"seifafficher");
	affiche=create_seifafficher();
	
	gtk_widget_show(affiche);

	treeview=lookup_widget(affiche,"treeview2affseif");
	afficher_election(treeview);
}


void
on_quittermod_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_main_quit();
}






void
on_nbhel1_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{cons=22;}
}


void
on_nbrel2_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{cons=40;}
}


void
on_nbhel3_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{cons=60;}
}


void
on_confirmerel_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
election e;
char conseiller[50];
char joure[50];
char moise[50];
char an[50];
int j,m,a;
int verif=-1;

GtkWidget *id , *municipalite ,*jour, *mois, *annee, *alert ,*alert1,*alert2;
GtkWidget *window;
window=lookup_widget(button,"windowel");

id=lookup_widget(button,"idel");
municipalite=lookup_widget(button,"municipaliteel");
GtkWidget *calendar;

calendar=lookup_widget(button,"calendaraj");
gtk_calendar_get_date (GTK_CALENDAR(calendar),
                       &a,
                       &m,
                       &j);
m=m+1;
//jour=lookup_widget(objet,"jourel");
//mois=lookup_widget(objet,"moisel");
//annee=lookup_widget(objet,"enneeel");
//j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
//m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
//a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
alert=lookup_widget(button,"alertel");
alert1=lookup_widget(button,"labelconseilleraj");
alert2=lookup_widget(button,"label189seifvid");

sprintf(conseiller,"%d",cons);
sprintf(joure,"%d",j);
sprintf(moise,"%d",m);
sprintf(an,"%d",a);


strcpy(e.nbr_conseiller,conseiller);
strcpy(e.id,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(e.municipalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(municipalite)));
//gtk_label_set_text(GTK_LABEL(alert),"ajout avec succés");
gtk_label_set_text(GTK_LABEL(alert1),e.nbr_conseiller);

strcpy(e.del.jour0,joure);
strcpy(e.del.mois0,moise);
strcpy(e.del.annee0,an);

verif=verifier_seif(e.id, e.del.annee0);

if(y11==1 && !verif){
ajouter_election("election.txt",e);
GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(alert,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(alert),"ajout avec succés");
gtk_label_set_text(GTK_LABEL(alert2),"");}

else {
GdkColor color;
gdk_color_parse("red",&color);
gtk_widget_modify_fg(alert,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(alert),"echec d'ajoutée");
GdkColor color1;
gdk_color_parse("red",&color1);
gtk_widget_modify_fg(alert2,GTK_STATE_NORMAL,&color1);
gtk_label_set_text(GTK_LABEL(alert2),"verifier votre identifiant");
}


}


void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar* id;
        gchar* nbr_conseiller;
        gchar* municipalite;
	gchar* jour0;
	gchar* mois0;
	gchar* annee0;

	election e;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if(gtk_tree_model_get_iter(model, &iter, path))
	{ 
gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &id, 1, &nbr_conseiller, 2, &municipalite, 3, &jour0, 4, &mois0, 5, &annee0, -1);
	strcpy(e.id,id);
	strcpy(e.nbr_conseiller,nbr_conseiller);
	strcpy(e.municipalite,municipalite);
	strcpy(e.del.jour0,jour0);
	strcpy(e.del.mois0,mois0);
	strcpy(e.del.annee0,annee0);
	

	//Chercher_MUL(tree,idch1)

	afficher_election(treeview);

	 
	}
}



void
on_retour_ajel_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

 	GtkWidget *ajout;
	GtkWidget *affiche;
	GtkWidget *treeview;

	ajout=lookup_widget(button,"RechercheM");

	gtk_widget_destroy(ajout);
	affiche=lookup_widget(button,"windowel");
	affiche=create_windowel();
	
	gtk_widget_show(affiche);
}


void
on_Rechajmul_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
	 char idch1[50];
	  GtkWidget* output0;
	  GtkWidget* outputEr;
	  GtkWidget* tree;
	  GtkWidget *window;;
// associer les objets avec des variables
	output0= lookup_widget(button,"recherchemaj") ;
	outputEr=lookup_widget(button, "labelrchM");
	tree=lookup_widget(button,"treeviewcherchermul");
	window=lookup_widget(button,"RechercheM");
//declarer 
       

	strcpy(idch1,gtk_entry_get_text(GTK_ENTRY(output0)));
//appel function chercher_election
	Chercher_MUL(tree,idch1);
	//afficher_election(tree);
	/*if(strcmp(em.id,"-1")!=0)

	{
	outputEr=lookup_widget(button, "labelrchM");

gtk_label_set_text(GTK_LABEL(outputEr),"Cette election existe !");
gtk_widget_show (outputEr);*/

	/*//afficher_election(tree);
	GtkWidget *cherch;
	char ch[20];
	GtkWidget *treeview1_N;
	GtkWidget *afficher_N;
	window=lookup_widget(button,"RechercheM");

	treeview1_N=lookup_widget(afficher_N,"treeviewcherchermul");
	cherch = lookup_widget (button ,"entry_cher_N");
	strcpy(ch, gtk_entry_get_text(GTK_ENTRY(cherch)));
	 Chercher_Nassim(treeview1_N,ch);*/



}


void
on_CHercherM_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
 	GtkWidget *ajout;
	GtkWidget *affiche;
	GtkWidget *treeview;

	ajout=lookup_widget(button,"windowel");

	gtk_widget_destroy(ajout);
	affiche=lookup_widget(button,"RechercheM");
	affiche=create_RechercheM();
	
	gtk_widget_show(affiche);

	treeview=lookup_widget(affiche,"treeviewaffel");
	afficher_election(treeview);
}


void
on_checkbuttonaj_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y11=1;}
}


void
on_supel_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *ajout;
	GtkWidget *affiche;
	GtkWidget *treeview;

	ajout=lookup_widget(button,"windowel");

	gtk_widget_destroy(ajout);
	affiche=lookup_widget(button,"seifafficher");
	affiche=create_seifafficher();
	
	gtk_widget_show(affiche);
	treeview=lookup_widget(affiche,"treeview2affseif");
	afficher_election(treeview);
}


void
on_quittercherche_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_main_quit();
}


void
on_accher_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{

	
       
 //laffichage de etreeview
GtkWidget *treeview;
GtkWidget *afficher;
afficher=lookup_widget(button,"RechercheM");
treeview=lookup_widget(afficher,"treeviewcherchermul");
afficher_election(treeview);
}





void
on_ElectTOAdmiin_clicked               (GtkWidget      *objet,
                                        gpointer         user_data)
{
	GtkWidget *windowel;
	GtkWidget *interfaceAdmin;

	windowel=lookup_widget(objet,"windowel");
	gtk_widget_destroy(windowel);

	interfaceAdmin=lookup_widget(objet,"interfaceAdmin");
	interfaceAdmin=create_interfaceAdmin();	
	gtk_widget_show(interfaceAdmin);
int n,i;
	char listeElec[20][50];
	GtkWidget *ListElection;
	ListElection=lookup_widget(interfaceAdmin,"ListElection");
	n=tableau_listeElecvote(listeElec);

	for(i=0;i<n;i++)
             {gtk_combo_box_append_text(GTK_COMBO_BOX(ListElection),_(listeElec[i]));
             }

}










///////////////////////////////////    Partie LOGIN    ///////////////////////////////////////////////////












void
on_connexionlogin_clicked              (GtkWidget      *objet,
                                        gpointer         user_data)
{
	int tr=0,r=0;   
	char cin[50], motdp[50], LCIN[50], LNempreinte[50], LNtelephone[20], Lnom[20], Lprenom[20], Ljour[20], Lmois[20], Lannee[20], Lmunicipalite[20], Lgenre[20], Lrole[50], Lvote[20], role[50], ch[50], cinConnecter[20];

	GtkWidget *loginCin, *loginMdp, *alertLOgin, *login, *interfaceCondidat, *interfaceElecteur, *interfaceAdmin, *interfaceReclamation, *nomPrenomElec, *connecterReclam;
	
	loginCin=lookup_widget(objet,"loginCin");
	loginMdp=lookup_widget(objet,"loginMdp");
	alertLOgin=lookup_widget(objet,"alertLOgin");
	login=lookup_widget(objet,"login");
	interfaceCondidat=lookup_widget(objet,"interfaceCondidat");
	interfaceElecteur=lookup_widget(objet,"interfaceElecteur");
	interfaceAdmin=lookup_widget(objet,"interfaceAdmin");
	interfaceReclamation=lookup_widget(objet,"interfaceReclamation");
	
	
	
	strcpy(cin,gtk_entry_get_text(GTK_ENTRY(loginCin)));
	strcpy(motdp,gtk_entry_get_text(GTK_ENTRY(loginMdp)));
   
	FILE *f, *g;
	f=fopen("utilisateur.txt","r");
	g=fopen("connected.txt","w");

    if(f!=NULL)
    { 
	while(!tr && (fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",LCIN,LNempreinte,LNtelephone,Lnom,Lprenom,Ljour,Lmois,Lannee,Lmunicipalite,Lgenre,Lrole,Lvote)!=EOF))
	   {
	if( (strcmp(cin,LCIN)==0) && (strcmp(motdp,LNempreinte)==0) )
		{	gtk_label_set_text(GTK_LABEL(alertLOgin)," ");
		tr=1;
		strcpy(role,Lrole);
	fprintf(g,"%s\n",LCIN);



		}

	   }
fclose(f);
fclose(g);
    }

if(strcmp(role,"administrateur")==0)
{
	gtk_widget_destroy(login);
	interfaceAdmin=create_interfaceAdmin();
	gtk_widget_show(interfaceAdmin);
int n,i;
	char listeElec[20][50];
	GtkWidget *ListElection;
	ListElection=lookup_widget(interfaceAdmin,"ListElection");
	n=tableau_listeElecvote(listeElec);

	for(i=0;i<n;i++)
             {gtk_combo_box_append_text(GTK_COMBO_BOX(ListElection),_(listeElec[i]));
             }
	

}
else if((strcmp(role,"agentBureauVote")==0) || (strcmp(role,"observateur")==0))
{
	gtk_widget_destroy(login);
	interfaceReclamation=create_interfaceReclamation();
	gtk_widget_show(interfaceReclamation);
	connecterReclam=lookup_widget(interfaceReclamation,"connecterReclam");
	getCin(cinConnecter);
	gtk_label_set_text(GTK_LABEL(connecterReclam),cinConnecter);
}
else if(strcmp(role,"electeur")==0)
{	if(strcmp(Lvote,"-1")!=0)
	{
	GtkWidget *cinvoteexiste;
	cinvoteexiste=lookup_widget(objet,"cinvoteexiste");
	gtk_label_set_text(GTK_LABEL(cinvoteexiste),"Le porteur de cette carte d'identité nationale a déjà voté");
	}
	else
	{
	GtkWidget *cinvoteexiste;
	cinvoteexiste=lookup_widget(objet,"cinvoteexiste");
	gtk_label_set_text(GTK_LABEL(cinvoteexiste)," ");
	gtk_widget_destroy(login);
	interfaceElecteur=create_interfaceElecteur();
	gtk_widget_show(interfaceElecteur);
	nomPrenomElec=lookup_widget(interfaceElecteur,"nomPrenomElec");
	strcpy(ch,Lnom);
	strcat(ch," ");
	strcat(ch,Lprenom);
	gtk_label_set_text(GTK_LABEL(nomPrenomElec),ch);
	int n,i;
	char listeElecVote[20][50];
	GtkWidget *comboListeVote;
	comboListeVote=lookup_widget(interfaceElecteur,"comboListeVote");
	n=tableau_listeElV(listeElecVote);

	strcpy(listeElecVote[n],"VOTE_BLANCHE");

	for(i=0;i<n+1;i++)
             {gtk_combo_box_append_text(GTK_COMBO_BOX(comboListeVote),_(listeElecVote[i]));
             }
	}
}
else if(strcmp(role,"condidat")==0)
{
	gtk_widget_destroy(login);
	interfaceCondidat=create_interfaceCondidat();
	gtk_widget_show(interfaceCondidat);
	GtkWidget *CondidatCin;
	CondidatCin=lookup_widget(interfaceCondidat,"CondidatCin");
	getCin(cinConnecter);
	gtk_label_set_text(GTK_LABEL(CondidatCin),cinConnecter);
}
else
{
	gtk_label_set_text(GTK_LABEL(alertLOgin),"login ou mot de passe incorrecte");
}


}

void
on_quitterlogin_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
	gtk_main_quit();
}


void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
	gtk_main_quit();
}





void
on_voterFinale_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{	char choixVote[20], charr[20];
	int n=0,id=0;
	FILE *f=NULL;
	GtkWidget *comboListeVote, *popUpVote, *interfaceElecteur;
	
	interfaceElecteur=lookup_widget(objet,"interfaceElecteur");
	popUpVote=lookup_widget(objet,"popUpVote");

	comboListeVote=lookup_widget(objet,"comboListeVote");
	strcpy(choixVote,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboListeVote)));

	id=getID(choixVote);

	modifier(id);

	gtk_widget_hide(interfaceElecteur);
	popUpVote=create_popUpVote();
	gtk_widget_show(popUpVote);
	GtkWidget *alertVote;
	alertVote=lookup_widget(popUpVote,"alertVote");
	gtk_label_set_text(GTK_LABEL(alertVote),choixVote);

}




void
on_annulerVote_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *popUpVote, *interfaceElecteur;
	char cin[50], motdp[50], LCIN[50], LNempreinte[50], LNtelephone[20], Lnom[20], Lprenom[20], Ljour[20], Lmois[20], Lannee[20], Lmunicipalite[20], Lgenre[20], Lrole[50], Lvote[20], role[50], ch[50], cinConnecter[20], NomPrenom[30], roleREc[20];
	popUpVote=lookup_widget(objet,"popUpVote");
	interfaceElecteur=lookup_widget(objet,"interfaceElecteur");
	interfaceElecteur=create_interfaceElecteur();
	gtk_widget_show(interfaceElecteur);

	gtk_widget_destroy(popUpVote);
	modifier(-1);
	getCin(cinConnecter);	
	getNomPrenom(cinConnecter, NomPrenom, roleREc);
	GtkWidget *nomPrenomElec;
	nomPrenomElec=lookup_widget(interfaceElecteur,"nomPrenomElec");
	gtk_label_set_text(GTK_LABEL(nomPrenomElec),NomPrenom);

int n,i;
	char listeElecVote[20][50], cinConnect[20];
	GtkWidget *comboListeVote;
	comboListeVote=lookup_widget(interfaceElecteur,"comboListeVote");
	n=tableau_listeElV(listeElecVote);

	strcpy(listeElecVote[n],"VOTE_BLANCHE");

	for(i=0;i<n+1;i++)
             {gtk_combo_box_append_text(GTK_COMBO_BOX(comboListeVote),_(listeElecVote[i]));
             }

}


void
on_confirmerVote_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{	GtkWidget *login, *interfaceElecteur, *popUpVote;

	interfaceElecteur=lookup_widget(objet,"interfaceElecteur");	
	gtk_widget_destroy(interfaceElecteur);
	popUpVote=lookup_widget(objet,"popUpVote");
	gtk_widget_destroy(popUpVote);


	login=lookup_widget(objet,"login");
	login=create_login();
	gtk_widget_show(login);

}


void
on_retourLogin_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *login, *interfaceReclamation;
	interfaceReclamation=lookup_widget(objet,"interfaceReclamation");

	gtk_widget_destroy(interfaceReclamation);
	login=create_login();
	gtk_widget_show(login);
}


void
on_quitterREclaV_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
	gtk_main_quit();
}


void
on_voteREcLogin_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{	char cinConnecter[20], NomPrenom[30], roleREc[20];
	GtkWidget *InterditAccesVote;
	InterditAccesVote=lookup_widget(objet,"InterditAccesVote");

	int v;
	getCin(cinConnecter);
	v=verifierVote(cinConnecter);
	if(v==1)
	{	gtk_label_set_text(GTK_LABEL(InterditAccesVote),"Ce personne a déja voté !");
	}
	else
	{
	GtkWidget *interfaceElecteur, *interfaceReclamation;
	interfaceReclamation=lookup_widget(objet,"interfaceReclamation");

	gtk_widget_destroy(interfaceReclamation);
	interfaceElecteur=create_interfaceElecteur();
	gtk_widget_show(interfaceElecteur);
	getNomPrenom(cinConnecter, NomPrenom, roleREc);
	GtkWidget *nomPrenomElec;
	nomPrenomElec=lookup_widget(interfaceElecteur,"nomPrenomElec");
	gtk_label_set_text(GTK_LABEL(nomPrenomElec),NomPrenom);

int n,i;
	char listeElecVote[20][50];
	GtkWidget *comboListeVote;
	comboListeVote=lookup_widget(interfaceElecteur,"comboListeVote");
	n=tableau_listeElV(listeElecVote);

	strcpy(listeElecVote[n],"VOTE_BLANCHE");

	for(i=0;i<n+1;i++)
             {gtk_combo_box_append_text(GTK_COMBO_BOX(comboListeVote),_(listeElecVote[i]));
             }
	}
}


void
on_ObsREcLogin_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{	GtkWidget *page404, *InterditAccesObs;
	page404=lookup_widget(objet,"page404");
	InterditAccesObs=lookup_widget(objet,"InterditAccesObs");
	gtk_label_set_text(GTK_LABEL(page404),"  ");
	gtk_label_set_text(GTK_LABEL(InterditAccesObs),"  ");
	char cinConnecter[20], NomPrenom[30], roleREc[20];
	getCin(cinConnecter);	
	getNomPrenom(cinConnecter, NomPrenom, roleREc);
	if(strcmp(roleREc, "agentBureauVote")==0)
	{ 	gtk_label_set_text(GTK_LABEL(page404),"Cette page n'est pas encore prête !");
	}
	else
	{	gtk_label_set_text(GTK_LABEL(InterditAccesObs),"Vous n'avez pas le droit d'accès à cette page !");
	}
}


void
on_RecREcLogin_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{	GtkWidget *page404, *InterditAccesObs;
	page404=lookup_widget(objet,"page404");
	InterditAccesObs=lookup_widget(objet,"InterditAccesObs");
	gtk_label_set_text(GTK_LABEL(page404),"  ");
	gtk_label_set_text(GTK_LABEL(InterditAccesObs),"  ");
	char cinConnecter[20], NomPrenom[30], roleREc[20];
	getCin(cinConnecter);	
	getNomPrenom(cinConnecter, NomPrenom, roleREc);
	if(strcmp(roleREc, "observateur")==0)
	{ 	gtk_label_set_text(GTK_LABEL(page404),"Cette page n'est pas encore prête !");
	}
	else
	{	gtk_label_set_text(GTK_LABEL(InterditAccesObs),"Vous n'avez pas le droit d'accès à cette page !");
	}
}


void
on_listeElecCond_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *GestionListeElectorale, *interfaceCondidat;
	interfaceCondidat=lookup_widget(objet,"interfaceCondidat");

	gtk_widget_destroy(interfaceCondidat);
	GestionListeElectorale=create_GestionListeElectorale();
	gtk_widget_show(GestionListeElectorale);
}


void
on_VoteCond_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
char cinConnecter[20], NomPrenom[30], roleREc[20];
	GtkWidget *AlertVoteCond;
	AlertVoteCond=lookup_widget(objet,"AlertVoteCond");

	int v;
	getCin(cinConnecter);
	v=verifierVote(cinConnecter);
	if(v==1)
	{	gtk_label_set_text(GTK_LABEL(AlertVoteCond),"Ce personne a déja voté !");
	}
	else
	{
	GtkWidget *interfaceElecteur, *interfaceCondidat;
	interfaceCondidat=lookup_widget(objet,"interfaceCondidat");

	gtk_widget_destroy(interfaceCondidat);
	interfaceElecteur=create_interfaceElecteur();
	gtk_widget_show(interfaceElecteur);
	getNomPrenom(cinConnecter, NomPrenom, roleREc);
	GtkWidget *nomPrenomElec;
	nomPrenomElec=lookup_widget(interfaceElecteur,"nomPrenomElec");
	gtk_label_set_text(GTK_LABEL(nomPrenomElec),NomPrenom);

int n,i;
	char listeElecVote[20][50];
	GtkWidget *comboListeVote;
	comboListeVote=lookup_widget(interfaceElecteur,"comboListeVote");
	n=tableau_listeElV(listeElecVote);

	strcpy(listeElecVote[n],"VOTE_BLANCHE");

	for(i=0;i<n+1;i++)
             {gtk_combo_box_append_text(GTK_COMBO_BOX(comboListeVote),_(listeElecVote[i]));
             }
	}

}


void
on_retourLogCond_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *login, *interfaceCondidat;
	interfaceCondidat=lookup_widget(objet,"interfaceCondidat");

	gtk_widget_destroy(interfaceCondidat);
	login=create_login();
	gtk_widget_show(login);
}


void
on_QuitterCondVote_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
	gtk_main_quit();
}


void
on_quitterInterAdm_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
	gtk_main_quit();
}


void
on_choisirElect_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{	char anneeEl[20], cinConnecter[20], NomPrenom[20], roleREc[20];
	GtkWidget *ListElection, *alertElecVote, *AdminHome, *interfaceAdmin, *nomPrenomAdmin;
	ListElection=lookup_widget(objet,"ListElection");
	alertElecVote=lookup_widget(objet,"alertElecVote");
	strcpy(anneeEl,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ListElection)));
	if(strcmp(anneeEl,"Election 2022")==0)
	{
	interfaceAdmin=lookup_widget(objet,"interfaceAdmin");
	gtk_widget_destroy(interfaceAdmin);
	AdminHome=create_AdminHome();
	gtk_widget_show(AdminHome);
	getCin(cinConnecter);	
	getNomPrenom(cinConnecter, NomPrenom, roleREc);
	nomPrenomAdmin=lookup_widget(AdminHome,"nomPrenomAdmin");
gtk_label_set_text(GTK_LABEL(nomPrenomAdmin),NomPrenom);
	
	}
	else
	{gtk_label_set_text(GTK_LABEL(alertElecVote),"Il faut choisir l'élection municipale en cours!");}

}



void
on_button4_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *windowel, *interfaceAdmin;
	interfaceAdmin=lookup_widget(objet,"interfaceAdmin");
	gtk_widget_destroy(interfaceAdmin);
	windowel=create_windowel();
	gtk_widget_show(windowel);
}


void
on_AdminVote_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{	GtkWidget *alertVoteAdmin;
	char cinConnecter[20], NomPrenom[20], roleREc[20];
	alertVoteAdmin=lookup_widget(objet,"alertVoteAdmin");
gtk_label_set_text(GTK_LABEL(alertVoteAdmin)," ");
	int v;
	getCin(cinConnecter);
	v=verifierVote(cinConnecter);
	if(v==1)
	{	gtk_label_set_text(GTK_LABEL(alertVoteAdmin),"Vous avez déja voté !");
	}
	else
	{
	GtkWidget *interfaceElecteur, *alertVoteAdmin, *AdminHome;
	AdminHome=lookup_widget(objet,"AdminHome");

	gtk_widget_destroy(AdminHome);
	interfaceElecteur=create_interfaceElecteur();
	gtk_widget_show(interfaceElecteur);

	getNomPrenom(cinConnecter, NomPrenom, roleREc);
	GtkWidget *nomPrenomElec;
	nomPrenomElec=lookup_widget(interfaceElecteur,"nomPrenomElec");
	gtk_label_set_text(GTK_LABEL(nomPrenomElec),NomPrenom);
int n,i;
	char listeElecVote[20][50];
	GtkWidget *comboListeVote;
	comboListeVote=lookup_widget(interfaceElecteur,"comboListeVote");
	n=tableau_listeElV(listeElecVote);

	strcpy(listeElecVote[n],"VOTE_BLANCHE");

	for(i=0;i<n+1;i++)
             {gtk_combo_box_append_text(GTK_COMBO_BOX(comboListeVote),_(listeElecVote[i]));
             }
	}
}


void
on_AdminUtil_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
	/*GtkWidget *AdminHome, *MOHAMED;
	AdminHome=lookup_widget(objet,"AdminHome");
	gtk_widget_destroy(AdminHome);
	MOHAMED=create_MOHAMED();
	gtk_widget_show(MOHAMED);*/
}


void
on_AdminLISTELEC_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{	GtkWidget *AdminHome, *GestionListeElectorale;
	AdminHome=lookup_widget(objet,"AdminHome");
	gtk_widget_destroy(AdminHome);
	GestionListeElectorale=create_GestionListeElectorale();
	gtk_widget_show(GestionListeElectorale);

}


void
on_AdminBV_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *AdminHome, *ajoutBV;
	AdminHome=lookup_widget(objet,"AdminHome");
	gtk_widget_destroy(AdminHome);
	ajoutBV=create_ajoutBV();
	gtk_widget_show(ajoutBV);
int i=0;
char agent[50][50];
GtkWidget *idagentbv;
idagentbv=lookup_widget(ajoutBV,"idagentbv");
n=tableau_agent(agent);

for(i=0;i<n;i++)
{gtk_combo_box_append_text(GTK_COMBO_BOX(idagentbv),_(agent[i]));
}
GtkWidget *gouvernoratajbv;
gouvernoratajbv=lookup_widget(ajoutBV,"gouvernoratajbv");
gtk_combo_box_set_active(GTK_COMBO_BOX(gouvernoratajbv),0);


}


void
on_quitterHomeAdmin_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
	gtk_main_quit();
}










//////////////////////////////////   FIN PARTIE LOGIN   /////////////////////////////////////////////////////////




void
on_button5_clicked                     (GtkWidget	*objet,
                                        gpointer         user_data)
{ 	 int Lid, nb ,nombrTotal,parc=0,fin=0, nbn,Lidn;
	char listeElecVote[30], Lident[10], listeElecVoten[30];

	//creation fichier VOTE
	CalculVotes();

	FILE *f=NULL;
	f=fopen("vote.txt","r");
	FILE *g=NULL;
	g=fopen("nouv.txt","a");

	if(f!=NULL && g!=NULL)
	{
	while(fscanf(f,"%d %s %d \n",&Lid, listeElecVote, &nb )!=EOF)
	   { sprintf(Lident,"%d",Lid);
	     nombrTotal=calculerLeVote(Lident);
	     fprintf(g,"%d %s %d \n",Lid, listeElecVote, nombrTotal);
	     nombrTotal=0;		
	   }
fclose(f);
fclose(g);
    remove("vote.txt");
    rename("nouv.txt", "vote.txt");
	}
trierVote();
	GtkWidget *AdminHome;
	GtkWidget *Dashboard;
	GtkWidget *treeview;
	GtkWidget *premierGangant, *DeuxiemeGagnat, *TRoisiemeGang;

	AdminHome=lookup_widget(objet,"AdminHome");

	gtk_widget_destroy(AdminHome);
	Dashboard=lookup_widget(objet,"Dashboard");
	Dashboard=create_Dashboard();
	
	gtk_widget_show(Dashboard);
	
	treeview=lookup_widget(Dashboard,"treeviewStatis");
	premierGangant=lookup_widget(Dashboard,"premierGangant");
	DeuxiemeGagnat=lookup_widget(Dashboard,"DeuxiemeGagnat");
	TRoisiemeGang=lookup_widget(Dashboard,"TRoisiemeGang");
	afficher_VOTE(treeview);

	FILE *k=NULL;
	k=fopen("vote.txt","r");
	if(k!=NULL)
	{
		while(!fin && fscanf(k,"%d %s %d \n",&Lidn, listeElecVoten, &nbn )!=EOF)
		{parc++;
		if(parc==1)
		{ gtk_label_set_text(GTK_LABEL(premierGangant),listeElecVoten);}
		else if(parc==2)
		{gtk_label_set_text(GTK_LABEL(DeuxiemeGagnat),listeElecVoten);}
		else if(parc==3)
		{gtk_label_set_text(GTK_LABEL(TRoisiemeGang),listeElecVoten); }
		else 
		{fin=1;}
		}
		fclose(k);
	}
}

















void
on_QuitterStatVoter_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
	gtk_main_quit();
}


void
on_retourStatHome_clicked              (GtkWidget	*objet,
                                        gpointer         user_data)
{
	GtkWidget *AdminHome;
	GtkWidget *Dashboard;

	Dashboard=lookup_widget(objet,"Dashboard");

	gtk_widget_destroy(Dashboard);
	AdminHome=lookup_widget(objet,"AdminHome");
	AdminHome=create_AdminHome();
	
	gtk_widget_show(AdminHome);
}


void
on_treeview2affseif_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar* id;
        gchar* nbr_conseiller;
        gchar* municipalite;
	gchar* jour0;
	gchar* mois0;
	gchar* annee0;

	election e;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if(gtk_tree_model_get_iter(model, &iter, path))
	{ 
gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &id, 1, &nbr_conseiller, 2, &municipalite, 3, &jour0, 4, &mois0, 5, &annee0, -1);
	strcpy(e.id,id);
	strcpy(e.nbr_conseiller,nbr_conseiller);
	strcpy(e.municipalite,municipalite);
	strcpy(e.del.jour0,jour0);
	strcpy(e.del.mois0,mois0);
	strcpy(e.del.annee0,annee0);
	

	//supprimer_election(e);

	afficher_election(treeview);
}
}




void
on_retourseifaj_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
	



 	GtkWidget *ajout;
	GtkWidget *affiche;
	
	ajout=lookup_widget(button,"seifafficher");

	gtk_widget_destroy(ajout);
	affiche=lookup_widget(button,"windowel");
	affiche=create_windowel();
	
	gtk_widget_show(affiche);
	
}


void
on_modseifaj_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *ajout;
	GtkWidget *affiche;
	
	ajout=lookup_widget(button,"windowel");

	gtk_widget_destroy(ajout);
	affiche=lookup_widget(button,"modifeel");
	affiche=create_modifeel();
	
	gtk_widget_show(affiche);
	
}


void
on_quiseif_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_main_quit();
}

