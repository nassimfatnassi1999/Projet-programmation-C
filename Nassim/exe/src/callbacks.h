#include <gtk/gtk.h>

/////////////////////////////////////////////////////////Nassim Fatnassi Hnifi////////////////////////////////////
void
on_btn_Ajouter_Nassim_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_btn_Ajouter_Liste_clicked           (GtkButton       *button,
                                        gpointer         user_data);


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_btn_Afficher_Tree_Liste_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_btn_Modifier_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_btn_retour_modifier_nassim_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_btn_Retour_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_btn_Verifier_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_btn_M_chercher_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobtn_M_G_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobtn_M_C_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobtn_M_D_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radio_btn_G_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radio_btn_C_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radio_btn_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_btn_M_Modifier_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_btn_stat_Nassim_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_btn_calc_NBV_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeviewNBRV_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_btn_actualiser_TreeNBRV_clicked     (GtkButton       *button,
                                        gpointer         user_data);
