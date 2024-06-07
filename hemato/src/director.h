#ifndef DIRECTOR_H_INCLUDED
#define DIRECTOR_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>

typedef struct {

    char rets_name[100];
    char btn[10];
    int bquantity ;
    char urgency[10];
    int date_d ;
    int date_m ;
    int date_y ;
    char comment [1000];
    int btr_id ;


} bloodrequest;

typedef struct {
    char establishmentName[100];
    int requestsForEstablishment;
    int totalRequests;
    float percentage;
} br_percent;

//crud
int ajouter_br(char * ,  bloodrequest  );
int modifier_br( char * , int ,  bloodrequest  );
int supprimer_br( char * , int );
bloodrequest chercher_br(char * , int );

//unic
int uncite(char *filename);

//stat
void sang_demande(char nomFichier[], char sangDemande[], char *maxBloodType);
int quantiteDemandee_type(char nomFichier[], char type_sang[]);
float pourcentage(char nomFichier[], char demandeur[]);
//tree
void afficher_personne(char *filename, GtkWidget *liste);
void vider(char *filename, GtkWidget *liste);


#endif // DIRECTOR_H_INCLUDED
