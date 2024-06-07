#include "function.h"
#include <string.h>
#include <gtk/gtk.h>


int add(char * filename, crud c )
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",c.establishment_name,c.state,c.adress,c.capacity,c.email_adress,c.phone_number,c.numberof_laboratory,c.numberof_doctors,c.numberof_nurses,c.numberof_technicians,c.blood_storage,c.establishment_id);
        fclose(f);
	return 1;
    }
	else return 0;
}

crud show(char * filename, char id[20])
{
    crud c;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0 && fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",c.establishment_name,c.state,c.adress,c.capacity,c.email_adress,c.phone_number,c.numberof_laboratory,c.numberof_doctors,c.numberof_nurses,c.numberof_technicians,c.blood_storage,c.establishment_id)!=EOF)
        {
            if(strcmp(c.establishment_id, id)==0)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        strcpy(c.establishment_id,"-1");
     return c;
}


void del(char * filename, char id[20])
{
    int tr=0;
    crud c;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",c.establishment_name,c.state,c.adress,c.capacity,c.email_adress,c.phone_number,c.numberof_laboratory,c.numberof_doctors,c.numberof_nurses,c.numberof_technicians,c.blood_storage,c.establishment_id)!=EOF)
        {
            if(strcmp(c.establishment_id, id)!=0)
                
		 fprintf(f2,"%s %s %s %s %s %s %s %s %s %s %s %s\n",c.establishment_name,c.state,c.adress,c.capacity,c.email_adress,c.phone_number,c.numberof_laboratory,c.numberof_doctors,c.numberof_nurses,c.numberof_technicians,c.blood_storage,c.establishment_id);
		
            else
		tr=1;
               
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
}

int modify( char * filename,char id[20], crud nouv )
{
    int tr=0;
    crud c;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",c.establishment_name,c.state,c.adress,c.capacity,c.email_adress,c.phone_number,c.numberof_laboratory,c.numberof_doctors,c.numberof_nurses,c.numberof_technicians,c.blood_storage,c.establishment_id)!=EOF)
        {
            if(strcmp(c.establishment_id,id)==0)
            {
                fprintf(f2,"%s %s %s %s %s %s %s %s %s %s %s %s\n",nouv.establishment_name,nouv.state,nouv.adress,nouv.capacity,nouv.email_adress,nouv.phone_number,nouv.numberof_laboratory,nouv.numberof_doctors,nouv.numberof_nurses,nouv.numberof_technicians,nouv.blood_storage,nouv.establishment_id);
                tr=1;
            }
            else
                fprintf(f2,"%s %s %s %s %s %s %s %s %s %s %s %s\n",c.establishment_name,c.state,c.adress,c.capacity,c.email_adress,c.phone_number,c.numberof_laboratory,c.numberof_doctors,c.numberof_nurses,c.numberof_technicians,c.blood_storage,c.establishment_id);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}

enum {
    
    ESTABLISHMENTN,
    STATE,
    ADDRESS,
    CAPACITY,
    EMAIL,
    PHONE,
    LAB,
    DOC,
    NUR,
    TECH,
    STORAG,
    ID,
    COLUMNS
};


void afficher_fichiers(GtkWidget *list) {
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
    
    
   crud c;
    store = NULL;

    FILE *f;

    store = gtk_tree_view_get_model(list);
    if (store == NULL) {

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("establishment name", renderer, "text", ESTABLISHMENTN, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("state", renderer, "text", STATE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);
                                                                                                                          
   
        renderer = gtk_cell_renderer_text_new();                                                                   
        column = gtk_tree_view_column_new_with_attributes("capacity", renderer, "text",CAPACITY, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("email address", renderer, "text", EMAIL, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("phone number", renderer, "text", PHONE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("tnumber of laboratory", renderer, "text",LAB, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("number of doctors", renderer, "text", DOC, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("numberof_nurses", renderer, "text", NUR, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("number of technicians", renderer, "text",  TECH, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("blood_storage", renderer, "text", STORAG, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("establishment_id", renderer, "text", ID, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);
}
        store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

        f = fopen("crud.txt", "r");
        if (f == NULL) {
            perror("Erreur lors de l'ouverture du fichier");
            return;
        } else {
            while (fscanf (f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",
c.establishment_name,
c.state,
c.adress,
c.capacity,
c.email_adress,
c.phone_number,
c.numberof_laboratory,
c.numberof_doctors,
c.numberof_nurses,
c.numberof_technicians,
c.blood_storage,
c.establishment_id) != EOF) {
                gtk_list_store_append(store, &iter);
                

                gtk_list_store_set(store, &iter,
ESTABLISHMENTN,c.establishment_name,
STATE,c.state,
ADDRESS,c.adress,
CAPACITY,c.capacity,
EMAIL,c.email_adress,
PHONE,c.phone_number,
LAB,c.numberof_laboratory,
DOC,c.numberof_doctors,
NUR,c.numberof_nurses,
TECH,c.numberof_technicians,
STORAG,c.blood_storage,
 ID,c.establishment_id,
                                   -1);
            }

            fclose(f);
            gtk_tree_view_set_model(GTK_TREE_VIEW(list), GTK_TREE_MODEL(store));
            g_object_unref(store);
        }
    
}


void ETSParRegion(char *nomFichier, char reg[20]) {
    crud c;
    FILE *f = fopen(nomFichier, "r");
    FILE *f2 = fopen("nouv.txt", "w");

    if (f != NULL ) {
        char line[1024];
        while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",c.establishment_name,c.state,c.adress,c.capacity,c.email_adress,c.phone_number,c.numberof_laboratory,c.numberof_doctors,c.numberof_nurses,c.numberof_technicians,c.blood_storage,c.establishment_id)!=EOF) {
            
            if (strcmp(c.state,reg) == 0) {
                fprintf(f2,"%s %s %s %s %s %s %s %s %s %s %s %s\n",
                        c.establishment_name, c.state, c.adress, c.capacity,
                        c.email_adress, c.phone_number, c.numberof_laboratory,
                        c.numberof_doctors, c.numberof_nurses,
                        c.numberof_technicians, c.blood_storage,
                        c.establishment_id);
            }
        }
        fclose(f);
        fclose(f2);
    }
}



enum {
    
    ESTABLISHMENTNR,
    STATER,
    ADDRESSR,
    CAPACITYR,
    EMAILR,
    PHONER,
    LABR,
    DOCR,
    NURR,
    TECHR,
    STORAGR,
    IDR,
    COLUMNSR
};
void afficher_fichiers_stat(GtkWidget *list) {
    GtkCellRenderer *rendererr;
    GtkTreeViewColumn *columnr;
    GtkTreeIter iterr;
    GtkListStore *storer;
    
    
   crud c;
    storer = NULL;

    FILE *f;

    storer = gtk_tree_view_get_model(list);
    if (storer == NULL) {

        rendererr = gtk_cell_renderer_text_new();
        columnr = gtk_tree_view_column_new_with_attributes("establishment name", rendererr, "text", ESTABLISHMENTNR, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), columnr);

        rendererr = gtk_cell_renderer_text_new();
        columnr = gtk_tree_view_column_new_with_attributes("state", rendererr, "text", STATER, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), columnr);
                                                                                                                          
   
        rendererr = gtk_cell_renderer_text_new();                                                                   
        columnr = gtk_tree_view_column_new_with_attributes("capacity", rendererr, "text",CAPACITYR, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), columnr);

        rendererr = gtk_cell_renderer_text_new();
        columnr = gtk_tree_view_column_new_with_attributes("email address", rendererr, "text", EMAILR, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), columnr);

        rendererr = gtk_cell_renderer_text_new();
        columnr = gtk_tree_view_column_new_with_attributes("phone number", rendererr, "text", PHONER, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), columnr);

        rendererr = gtk_cell_renderer_text_new();
        columnr = gtk_tree_view_column_new_with_attributes("tnumber of laboratory", rendererr, "text",LABR, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), columnr);

        rendererr = gtk_cell_renderer_text_new();
        columnr = gtk_tree_view_column_new_with_attributes("number of doctors", rendererr, "text", DOCR, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), columnr);

        rendererr = gtk_cell_renderer_text_new();
        columnr = gtk_tree_view_column_new_with_attributes("numberof_nurses", rendererr, "text", NURR, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), columnr);

        rendererr = gtk_cell_renderer_text_new();
        columnr = gtk_tree_view_column_new_with_attributes("number of technicians", rendererr, "text",  TECHR, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), columnr);

        rendererr = gtk_cell_renderer_text_new();
        columnr = gtk_tree_view_column_new_with_attributes("blood_storage", rendererr, "text", STORAGR, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), columnr);

        rendererr = gtk_cell_renderer_text_new();
        columnr = gtk_tree_view_column_new_with_attributes("establishment_id", rendererr, "text", IDR, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), columnr);
	}

        storer = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

        f = fopen("nouv.txt", "r");
        if (f == NULL) {
            perror("Erreur lors de l'ouverture du fichier");
            return;
        } else {
            while (fscanf (f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",
c.establishment_name,
c.state,
c.adress,
c.capacity,
c.email_adress,
c.phone_number,
c.numberof_laboratory,
c.numberof_doctors,
c.numberof_nurses,
c.numberof_technicians,
c.blood_storage,
c.establishment_id) != EOF) {
                gtk_list_store_append(storer, &iterr);
                

                gtk_list_store_set(storer, &iterr,
ESTABLISHMENTNR,c.establishment_name,STATER,c.state,ADDRESSR,c.adress,CAPACITYR,c.capacity,EMAILR,c.email_adress,PHONER,c.phone_number,LABR,c.numberof_laboratory,DOCR,c.numberof_doctors,NURR,c.numberof_nurses,TECHR,c.numberof_technicians,STORAGR,c.blood_storage,IDR,c.establishment_id,-1);
            }

            fclose(f);
            gtk_tree_view_set_model(GTK_TREE_VIEW(list), GTK_TREE_MODEL(storer));
            g_object_unref(storer);
        }
    
}




enum {
    
    ESTABLISHMENTNRR,
    STATERR,
    ADDRESSRR,
    CAPACITYRR,
    EMAILRR,
    PHONERR,
    LABRR,
    DOCRR,
    NURRR,
    TECHRR,
    STORAGRR,
    IDRR,
    COLUMNSRR


};
void afficher_fichiers_capacity(GtkWidget *list){
	  GtkCellRenderer *rendererrr;
    GtkTreeViewColumn *columnrr;
    GtkTreeIter iterrr;
    GtkListStore *storerr;
    
    
   crud c;
    storerr = NULL;

    FILE *f;

    storerr = gtk_tree_view_get_model(list);
    if (storerr == NULL) {

        rendererrr = gtk_cell_renderer_text_new();
        columnrr = gtk_tree_view_column_new_with_attributes("establishment name", rendererrr, "text", ESTABLISHMENTNRR, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), columnrr);

        rendererrr = gtk_cell_renderer_text_new();
        columnrr = gtk_tree_view_column_new_with_attributes("state", rendererrr, "text", STATERR, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), columnrr);
                                                                                                                          
   
        rendererrr = gtk_cell_renderer_text_new();                                                                   
        columnrr = gtk_tree_view_column_new_with_attributes("capacity", rendererrr, "text",CAPACITYRR, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), columnrr);

        rendererrr = gtk_cell_renderer_text_new();
        columnrr = gtk_tree_view_column_new_with_attributes("email address", rendererrr, "text", EMAILRR, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), columnrr);

        rendererrr = gtk_cell_renderer_text_new();
        columnrr = gtk_tree_view_column_new_with_attributes("phone number", rendererrr, "text", PHONERR, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), columnrr);

        rendererrr = gtk_cell_renderer_text_new();
        columnrr = gtk_tree_view_column_new_with_attributes("tnumber of laboratory", rendererrr, "text",LABRR, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), columnrr);

        rendererrr = gtk_cell_renderer_text_new();
        columnrr = gtk_tree_view_column_new_with_attributes("number of doctors", rendererrr, "text", DOCRR, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), columnrr);

        rendererrr = gtk_cell_renderer_text_new();
        columnrr = gtk_tree_view_column_new_with_attributes("numberof_nurses", rendererrr, "text", NURRR, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), columnrr);

        rendererrr = gtk_cell_renderer_text_new();
        columnrr = gtk_tree_view_column_new_with_attributes("number of technicians", rendererrr, "text",  TECHRR, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), columnrr);

        rendererrr = gtk_cell_renderer_text_new();
        columnrr = gtk_tree_view_column_new_with_attributes("blood_storage", rendererrr, "text", STORAGRR, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), columnrr);

        rendererrr = gtk_cell_renderer_text_new();
        columnrr = gtk_tree_view_column_new_with_attributes("establishment_id", rendererrr, "text", IDRR, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), columnrr);
	}
        storerr = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

        f = fopen("capacity.txt", "r");
        if (f == NULL) {
            perror("Erreur lors de l'ouverture du fichier");
            return;
        } else {
            while (fscanf (f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",
c.establishment_name,
c.state,
c.adress,
c.capacity,
c.email_adress,
c.phone_number,
c.numberof_laboratory,
c.numberof_doctors,
c.numberof_nurses,
c.numberof_technicians,
c.blood_storage,
c.establishment_id) != EOF) {
                gtk_list_store_append(storerr, &iterrr);
                

                gtk_list_store_set(storerr, &iterrr,
ESTABLISHMENTNR,c.establishment_name,STATER,c.state,ADDRESSR,c.adress,CAPACITYR,c.capacity,EMAILR,c.email_adress,PHONER,c.phone_number,LABR,c.numberof_laboratory,DOCR,c.numberof_doctors,NURR,c.numberof_nurses,TECHR,c.numberof_technicians,STORAGR,c.blood_storage,IDR,c.establishment_id,-1);
            }

            fclose(f);
            gtk_tree_view_set_model(GTK_TREE_VIEW(list), GTK_TREE_MODEL(storerr));
            g_object_unref(storerr);
        }
    
	

}



void ETSTrieCapacite(char *nomFichier) {
    int tr=0,swaps;
    crud aux[200];
    crud tab_ets[200];
    FILE * f=fopen(nomFichier, "r");

    if(f!=NULL)
    {
        while (fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s %s\n",
                      tab_ets[tr].establishment_name,
                      tab_ets[tr].state,
                      tab_ets[tr].adress,
                      tab_ets[tr].capacity,
                      tab_ets[tr].email_adress,
                      tab_ets[tr].phone_number,
                      tab_ets[tr].numberof_laboratory,
                      tab_ets[tr].numberof_doctors,
                      tab_ets[tr].numberof_nurses,
                      tab_ets[tr].numberof_technicians,
                      tab_ets[tr].blood_storage,
                      tab_ets[tr].establishment_id) != EOF) {
            tr++;
        
    }
    fclose(f);

    for (int i = 0; i < tr - 1; i++) {
            swaps = 0;
            for (int j = 0; j < tr - i - 1; j++) {
                int capacity_j = atoi(tab_ets[j].capacity);
                int capacity_j1 = atoi(tab_ets[j + 1].capacity);
                if (capacity_j < capacity_j1) {
                    crud temp = tab_ets[j];
                    tab_ets[j] = tab_ets[j + 1];
                    tab_ets[j + 1] = temp;
                    swaps++;
		}
	     }
	}

    FILE *f2=fopen("capacity.txt", "w");

    for (int i = 0; i < tr; i++) {
        fprintf(f2, "%s %s %s %s %s %s %s %s %s %s %s %s\n",
                      tab_ets[i].establishment_name,
                      tab_ets[i].state,
                      tab_ets[i].adress,
                      tab_ets[i].capacity,
                      tab_ets[i].email_adress,
                      tab_ets[i].phone_number,
                      tab_ets[i].numberof_laboratory,
                      tab_ets[i].numberof_doctors,
                      tab_ets[i].numberof_nurses,
                      tab_ets[i].numberof_technicians,
                      tab_ets[i].blood_storage,
                      tab_ets[i].establishment_id);
    }

    fclose(f2);
}
}

void afficher_fichiers_his(GtkWidget *list) {
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
    
    
   crud c;
    store = NULL;

    FILE *f;

    store = gtk_tree_view_get_model(list);
    if (store == NULL) {

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("establishment name", renderer, "text", ESTABLISHMENTN, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("state", renderer, "text", STATE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);
                                                                                                                          
   
        renderer = gtk_cell_renderer_text_new();                                                                   
        column = gtk_tree_view_column_new_with_attributes("capacity", renderer, "text",CAPACITY, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("email address", renderer, "text", EMAIL, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("phone number", renderer, "text", PHONE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("tnumber of laboratory", renderer, "text",LAB, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("number of doctors", renderer, "text", DOC, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("numberof_nurses", renderer, "text", NUR, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("number of technicians", renderer, "text",  TECH, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("blood_storage", renderer, "text", STORAG, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("establishment_id", renderer, "text", ID, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);
}
        store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

        f = fopen("history.txt", "r");
        if (f == NULL) {
            perror("Erreur lors de l'ouverture du fichier");
            return;
        } else {
            while (fscanf (f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",
c.establishment_name,
c.state,
c.adress,
c.capacity,
c.email_adress,
c.phone_number,
c.numberof_laboratory,
c.numberof_doctors,
c.numberof_nurses,
c.numberof_technicians,
c.blood_storage,
c.establishment_id) != EOF) {
                gtk_list_store_append(store, &iter);
                

                gtk_list_store_set(store, &iter,
ESTABLISHMENTN,c.establishment_name,
STATE,c.state,
ADDRESS,c.adress,
CAPACITY,c.capacity,
EMAIL,c.email_adress,
PHONE,c.phone_number,
LAB,c.numberof_laboratory,
DOC,c.numberof_doctors,
NUR,c.numberof_nurses,
TECH,c.numberof_technicians,
STORAG,c.blood_storage,
 ID,c.establishment_id,
                                   -1);
            }

            fclose(f);
            gtk_tree_view_set_model(GTK_TREE_VIEW(list), GTK_TREE_MODEL(store));
            g_object_unref(store);
        }
    
}







