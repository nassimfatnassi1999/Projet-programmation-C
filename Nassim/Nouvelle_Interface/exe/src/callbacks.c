#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include"function.h"

int x=0;
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
	 strcpy(L.orientation,"gauche");
	}
	if(x==2)
	{
	 strcpy(L.orientation,"centre");
	}
	if(x==3)
	{
	 strcpy(L.orientation,"droite");
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
on_radiobtn_Gauche_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=1;}
}


void
on_radiobtn_Centre_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=2;}
}


void
on_radiobtn_Droite_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=3;}
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
int id;
gchar* nomliste;
int Jour;
int Mois;
int Annee;
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
	 supprimerListe(L);
// mise a jour de l'affichage de la treeview
	 afficher_Liste(treeview);
	
}
}


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

void
on_salle1_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_salle2_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_salle3_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_treeviewBV_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}
void
on_afficherbv_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}
void
on_ajouterbv_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}
void
on_bt_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}
void
on_retourbv_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}



