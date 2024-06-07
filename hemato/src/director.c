#include "director.h"


int ajouter_br(char * filename,  bloodrequest BR )
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %d %s %d/%d/%d %s %d \n", BR.rets_name ,BR.btn ,BR.bquantity ,BR.urgency ,BR.date_d,BR.date_m,BR.date_y,BR.comment,BR.btr_id );
        fclose(f);
        return 1;
    }
    else return 0;
}



// modifier
int modifier_br( char * filename, int id,  bloodrequest NBR )
{
    int tr=0;
     bloodrequest BR;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %d %s %d/%d/%d %s %d \n", BR.rets_name ,BR.btn ,&BR.bquantity ,BR.urgency ,&BR.date_d,&BR.date_m,&BR.date_y,BR.comment,&BR.btr_id )!=EOF)
        {
            if(BR.btr_id== id)
            {
                fprintf(f2,"%s %s %d %s %d/%d/%d %s %d \n", NBR.rets_name ,NBR.btn ,NBR.bquantity ,NBR.urgency ,NBR.date_d,NBR.date_m,NBR.date_y,NBR.comment,NBR.btr_id );
                tr=1;
            }
            else
                fprintf(f2,"%s %s %d %s %d/%d/%d %s %d \n", BR.rets_name ,BR.btn ,BR.bquantity ,BR.urgency ,BR.date_d,BR.date_m,BR.date_y,BR.comment,BR.btr_id );
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}


//chercher
 bloodrequest chercher_br(char * filename, int id)
{
    int tr=0;
     bloodrequest BR;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0 && fscanf(f,"%s %s %d %s %d/%d/%d %s %d \n", BR.rets_name ,BR.btn ,&BR.bquantity ,BR.urgency ,&BR.date_d,&BR.date_m,&BR.date_y,BR.comment,&BR.btr_id )!=EOF)
        {
            if(BR.btr_id== id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        BR.btr_id=-1;
    return BR;

}

//supprimer

int supprimer_br( char * filename, int id)
{
    int tr=0;
     bloodrequest BR;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %d %s %d/%d/%d %s %d \n", BR.rets_name ,BR.btn ,&BR.bquantity ,BR.urgency ,&BR.date_d,&BR.date_m,&BR.date_y,BR.comment,&BR.btr_id )!=EOF)
        {
            if(BR.btr_id== id)
            {
                tr=1;
            }
            else
                fprintf(f2,"%s %s %d %s %d/%d/%d %s %d \n", BR.rets_name ,BR.btn ,BR.bquantity ,BR.urgency ,BR.date_d,BR.date_m,BR.date_y,BR.comment,BR.btr_id );
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}

//uncite

int uncite(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return -1; // Indicates an error
    }

    int maxBtrId = 0;
    bloodrequest request;

    while (fscanf(file, "%s %s %d %s %d/%d/%d %s %d", request.rets_name, request.btn, &request.bquantity, request.urgency, &request.date_d, &request.date_m, &request.date_y, request.comment, &request.btr_id) != EOF) {
        if (request.btr_id > maxBtrId) {
            maxBtrId = request.btr_id;
        }
    }

    fclose(file);

    // Return the highest btr_id + 1
    return maxBtrId + 1;
}
//stat


//tree view

enum
{
    erets_name,
    ebtn,
    ebquantity,
    eurgency,
    edate_d,
    edate_m,
    edate_y,
    ecomment,
    ebtr_id,
    COLUMNUS
};

void afficher_personne(char *filename, GtkWidget *liste)
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;

    char rets_name[100];
    char btn[10];
    int bquantity ;
    char urgency[10];
    int date_d ;
    int date_m ;
    int date_y ;
    char comment [1000];
    int btr_id ;
 store=NULL;

    store = gtk_tree_view_get_model(liste);
 FILE *f;
 
if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("rets_name", renderer,"text",erets_name ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("btn", renderer,"text",ebtn ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("bquantity", renderer,"text",ebquantity ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("urgency", renderer,"text",eurgency ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("date_d", renderer,"text",edate_d ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("date_m", renderer,"text",edate_m ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("date_y", renderer,"text",edate_y ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("comment", renderer,"text",ecomment ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("btr_id", renderer,"text",ebtr_id ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


store = gtk_list_store_new(COLUMNUS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING,  G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING, G_TYPE_INT);


	f = fopen(filename, "r");

        if (f != NULL)
        {
            while (fscanf(f, "%s %s %d %s %d/%d/%d %s %d", rets_name, btn, &bquantity, urgency, &date_d, &date_m, &date_y, comment, &btr_id) != EOF)
            {
                gtk_list_store_append(store, &iter);
                gtk_list_store_set(store, &iter, erets_name, rets_name, ebtn, btn, ebquantity, bquantity, eurgency, urgency, edate_d, date_d, edate_m, date_m, edate_y, date_y, ecomment, comment, ebtr_id, btr_id, -1);
            }
            fclose(f);
        }
    }

    gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
    g_object_unref(store);


  }  





/*void afficher_stat(char *filename, GtkWidget *liste){
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;

    store=NULL;

    store = gtk_tree_view_get_model(GTK_TREE_VIEW(liste));

    if (store == NULL)
    {

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Establishment Name", renderer, "text", E_ESTABLISHMENT_NAME, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Requests", renderer, "text", E_REQUESTS, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Total Requests", renderer, "text", E_TOTAL_REQUESTS, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Percentage", renderer, "text", E_PERCENTAGE, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

    gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
    g_object_unref(store);

        store = gtk_list_store_new(COLUMN_RESULT, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_FLOAT);

        FILE *file = fopen(filename, "r");

        if (file != NULL)
        {
            br_percent resultData;

            while (fscanf(file, "%s: Requests=%d, Total Requests=%d, Percentage=%f%%",
                          resultData.establishmentName, &resultData.requestsForEstablishment,
                          &resultData.totalRequests, &resultData.percentage) != EOF)
            {
                gtk_list_store_append(store, &iter);
                gtk_list_store_set(store, &iter,
                                   E_ESTABLISHMENT_NAME, resultData.establishmentName,
                                   E_REQUESTS, resultData.requestsForEstablishment,
                                   E_TOTAL_REQUESTS, resultData.totalRequests,
                                   E_PERCENTAGE, resultData.percentage,
                                   -1);
            }

            fclose(file);
        }
    }
    gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
    g_object_unref(store);

}     E_ESTABLISHMENT_NAME,
    E_REQUESTS,
    E_TOTAL_REQUESTS,
    E_PERCENTAGE,
    COLUMN_RESULT,*/



void vider(char *filename, GtkWidget *liste) {
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;

    char rets_name[100];
    char btn[10];
    int bquantity ;
    char urgency[10];
    int date_d ;
    int date_m ;
    int date_y ;
    char comment [1000];
    int btr_id ;
 store=NULL;

    store = gtk_tree_view_get_model(liste);
 FILE *f;
 
if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("rets_name", renderer,"text",erets_name ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("btn", renderer,"text",ebtn ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("bquantity", renderer,"text",ebquantity ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("urgency", renderer,"text",eurgency ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("date_d", renderer,"text",edate_d ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("date_m", renderer,"text",edate_m ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("date_y", renderer,"text",edate_y ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("comment", renderer,"text",ecomment ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("btr_id", renderer,"text",ebtr_id ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

}
store = gtk_list_store_new(COLUMNUS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING,  G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING, G_TYPE_INT);

gtk_list_store_append(store, &iter);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
}



//stat
int quantiteDemandee_type(char nomFichier[], char type_sang[]) {
    FILE *file = fopen(nomFichier, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", nomFichier);
        return -1; // Indicates an error
    }

    int totalQuantity = 0;
    bloodrequest request;

    while (fscanf(file, "%s %s %d %s %d/%d/%d %s %d",
                  request.rets_name, request.btn, &request.bquantity,
                  request.urgency, &request.date_d, &request.date_m,
                  &request.date_y, request.comment, &request.btr_id) != EOF) {
        if (strcmp(request.btn, type_sang) == 0) {
            totalQuantity += request.bquantity;
        }
    }

    fclose(file);

    return totalQuantity;
}

void sang_demande(char nomFichier[], char sangDemande[], char *maxBloodType) {
    const char *bloodTypes[] = {"A+", "A-", "B+", "B-", "AB+", "AB-", "O+", "O-"}; // List of blood types

    int maxQuantity = 0;

    if (strcmp(sangDemande, "all") == 0) {
        for (int i = 0; i < sizeof(bloodTypes) / sizeof(bloodTypes[0]); i++) {
            int quantity = quantiteDemandee_type(nomFichier, bloodTypes[i]);

            if (quantity > maxQuantity) {
                maxQuantity = quantity;
                strcpy(maxBloodType, bloodTypes[i]);
            }
        }
    } else {
        int quantity = quantiteDemandee_type(nomFichier, sangDemande);


        if (quantity > maxQuantity) {
            maxQuantity = quantity;
            strcpy(maxBloodType, sangDemande);
        }
    }

}


float pourcentage(char nomFichier[], char demandeur[]) {
    FILE *file = fopen(nomFichier, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", nomFichier);
        perror("fopen");
        return -1.0;  // Return a negative value to indicate an error
    }

    int totalRequests = 0;
    int establishmentRequests = 0;

    bloodrequest request;

    // Assuming the file is formatted as plain text
    while (fscanf(file, "%s %s %d %s %d/%d/%d %s %d \n",
                  request.rets_name, request.btn, &request.bquantity,
                  request.urgency, &request.date_d, &request.date_m, &request.date_y,
                  request.comment, &request.btr_id) == 9) {

        // Check if the current request's establishment name matches the given demandeur
        if (strcmp(request.rets_name, demandeur) == 0) {
            establishmentRequests++;
        }
        totalRequests++;
    }

    fclose(file);

    if (totalRequests == 0) {
        fprintf(stderr, "No data found in the file.\n");
        return -1.0;  // Return a negative value to indicate an error
    }

    float percentage = (float)establishmentRequests / totalRequests * 100.0;
    return percentage;
}
