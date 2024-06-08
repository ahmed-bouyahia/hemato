#include <gtk/gtk.h>


void
on_sign_upp_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_log_out_book_rdv_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiordv1_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiordv2_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_book_clicked                        (GtkWidget	*objet_graphique,
                                        gpointer         user_data);

void
on_check_avail_time_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeviewshow1_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
					GdkEventButton *event,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_log_out_show_rdv_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_show_rdv_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_log_out_modify_rdv_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_chercher_modif_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_chek_modify_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_modify_rdv_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_log_out_cancel_rdv_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_cancel_chek2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_sure_toggled                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_search_cancel_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_cancel_ip_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeviewhisto_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_log_out_history_rdv_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_show_history_clicked                (GtkWidget	*objet_graphique,
                                        gpointer         user_data);

void
on_radiobuttonfemaleusers_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonmaleusers_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttoncreateusers_clicked           (GtkWidget   	*objet_graphique,
                                        gpointer         user_data);

void
on_buttonlogoutCusers_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeviewreadusers_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttonlogoutRusers_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonreadusers_clicked             (GtkWidget   	*objet_graphique,
                                        gpointer         user_data);

void
on_radiobuttonupmaleusers_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonupfemaleusers_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttonconupusers_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonlogoutUusers_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonupdateusers_clicked           (GtkWidget   	*objet_graphique,
                                        gpointer         user_data);

void
on_buttoncherupusers_clicked           (GtkWidget   	*objet_graphique,
                                        gpointer         user_data);

void
on_checkbuttoncondlusers_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonlogoutDusers_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttoncherdlusers_clicked           (GtkWidget   	*objet_graphique,
                                        gpointer         user_data);

void
on_buttondeleteusers_clicked           (GtkWidget   	*objet_graphique,
                                        gpointer         user_data);

void
on_treeviewroleusers_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_radiobuttonDOCusers_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonlogoutSusers_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonshowstatusers_clicked         (GtkWidget   	*objet_graphique,
                                        gpointer         user_data);

void
on_radiobuttonNURusers_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonADusers_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_empty_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_average_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_full_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_create_button_amin1_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_show_button_amin1re_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_charcher_button_amin1update_clicked (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_update_button_amin1update_clicked   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_checkbutton9update_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_empty2up_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_full2up_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_average2up_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
delete_search_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_confirm_checkbutton_deltoggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_delete_button_am_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_capacity_show_button1cap_clicked    (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_search222stat_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_treeview1_afffiche_row_activated    (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_Hist_logout_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_button1_wndaj_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_button1_wndsupp_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_But_Statistics_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2_afffiche_clicked            (GtkWidget	*objet_graphique,
                                        gpointer         user_data);

void
on_button1_wndmod_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_button1_wndrech_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton1_ABP_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton1_AP_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton1_AM_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton1_OP_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton1_OM_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton1_ABM_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1_confaj_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton1_BM_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton1_BP_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1_H_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1_F_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button1_confaj_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_button1_retaj_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton2_AP_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_OP_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_BP_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_BM_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2_H_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2_F_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_ABM_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2_confmod_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button2_retmod_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_button1_confmod_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton2_ABP_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_OM_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_AM_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_treeview4_recherche_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_rechret_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_rechfiche_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_Back_Statistics_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_Butt_conf_av_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_Butt_Conf_list_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobuttonurg1_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonurg2_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonurg3_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonurg4_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonlogoutdirector_add_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonaddbr_clicked                 (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonlogoutdirector_show_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonshowalldirector_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonshowstatdirector_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonsearch_mod_clicked            (GtkWidget	*objet_graphique,
                                        gpointer         user_data);

void
on_buttonlogoutdirector_mod_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonbr_mod_clicked                (GtkWidget	*objet_graphique,
                                        gpointer         user_data);

void
on_buttondel_br_clicked                (GtkWidget	*objet_graphique,
                                        gpointer         user_data);

void
on_buttonsearch_del_clicked            (GtkWidget	*objet_graphique,
                                        gpointer         user_data);

void
on_buttonlogoutdirector_del_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbuttonsuredelete_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonrefreshdir_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonreturndir_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonreturn1_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonrefresh1_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttoncalstat_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_butlogout_CDOC_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_butcreat_CDOC_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_butmodify_MDOC_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_butlogout_MDOC_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_but_idfound_DOC_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_treeview_RDOC_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_butlogout_RDOC_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_butrefresh_RDOC_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_butlogout_DDOC_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_butdelete_DDOC_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_butsearch_DDOC_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button6_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_butrefresh_SDOC_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_radiobutnbtot_SDOC_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutqtytotblood_SDOC_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);



void
on_button_log_in1_clicked              (GtkButton       *objet,
                                        gpointer         user_data);

void
on_button_refresh_amin_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_radiobuttonDIRusers_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_logout_amin1_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_logout_amin2_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_logout_amin3_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_logout_amin4_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_logout_amin5_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_logout_amin6_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_logout_amin7_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_butlogout_SDOC_clicked              (GtkButton       *button,
                                        gpointer         user_data);
