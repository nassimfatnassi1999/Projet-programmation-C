#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include"function.h"
Lorder tab[20];
int n=0;
int x=1;
int y=1;
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
//declarer la struct qui ajouter
        Liste L;
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
	if(x==2)
	{
	 strcpy(L.orientation,"Centre");
	}
	if(x==3)
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
	
	ajouterListe(L);
//traja3ni ltree view 
	GtkWidget *ajouter101;
	GtkWidget *destroy101;
	destroy101=lookup_widget(button,"AjouterListe");
	gtk_widget_destroy(destroy101);
	ajouter101=create_GestionListeElectorale();
	gtk_widget_show (ajouter101);
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
	 x=verifier(CT,C1,C2,C3);
	if(x==1)
	{
		GdkColor color;
		gdk_color_parse("red",&color);
		gtk_widget_modify_fg(output,GTK_STATE_NORMAL,&color);
		gtk_label_set_text(GTK_LABEL(output),"L'un des candidats existe deja dans une Liste !!");
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
     if(strcmp(LM.orientation,"Gauche")==0)
       {
        output=lookup_widget(button,"radiobtn_M_G");
        gtk_toggle_button_set_active(GTK_RADIO_BUTTON(output),TRUE);
       }
     if(strcmp(LM.orientation,"Centre")==0)
       {
        output=lookup_widget(button,"radiobtn_M_C");
        gtk_toggle_button_set_active(GTK_RADIO_BUTTON(output),TRUE);
       }
     else if (strcmp(LM.orientation,"Droite")==0)
            {
             output=lookup_widget(button,"radiobtn_M_D");
             gtk_toggle_button_set_active(GTK_RADIO_BUTTON(output),TRUE);
            }
//*************************************
	 COX=lookup_widget(button,"cobox_M_muni");
	 if(strcmp(LM.municipalite,"Tunis")){
         	gtk_combo_box_set_active(COX,"Tunis");}
	 else if(strcmp(LM.municipalite,"Beja")){
         	gtk_combo_box_set_active(COX,"Beja");}
	 else if(strcmp(LM.municipalite,"Sousse")){
         	gtk_combo_box_set_active(COX,"Sousse");}
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
		        gtk_label_set_text(GTK_LABEL(outputEM),"Oups echec modification l'un des Candidats existe deja!!");
			
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
	result=nbv("utilisater.txt",idch);
//*************************************
	 GdkColor color;
         gdk_color_parse("yellow",&color);
 	 gtk_widget_modify_fg(output,GTK_STATE_NORMAL,&color);
	 output=lookup_widget(button,"label_R_NBR");
         gtk_entry_set_text(GTK_ENTRY(output),result);


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
on_btn_actualiser_TreeNBRV_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{

		remplirtab(tab,&n); 

		printTab(tab,&n);

 //laffichage de etreeview
GtkWidget *treeview_Nassim;
GtkWidget *afficher_u;
afficher_u=lookup_widget(button,"Stat_Liste_Nassim");
treeview_Nassim=lookup_widget(afficher_u,"treeviewNBRV");
afficher_Liste_ordre(treeview_Nassim);
}

