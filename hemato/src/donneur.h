#include <gtk/gtk.h>

typedef struct
{ 
    char fullname[20];
    char idnumber[20];	
    int  birthday;
    char birthmonth[20];
    int  birthyear;
    char type[30];
    char gender[30];
    char ets[30] ;
}donneur;

typedef struct
{ int day,month,year;

}date1;

typedef struct rdv1 {
    char establishment[20];
    date1 date_rdv;
    char time[10];
} rdv1;

int ajouter_fiche_donneur(donneur D,char *filename);
void afficher_fiche_donneur(GtkWidget *liste);
void modifier_fiche_donneur(char cin[],donneur D1,char *filename);
void supprimer_fiche_donneur(char id[],char *filename);
int rechercher_fiche_donneur(char id[]);
void afficher_rechercher_don(GtkWidget *liste);
int remplir_tableau_Rech (donneur tab[],int nb) ;
int listeRDV(char nomFichier[],char ETS[],int jour, char mois[], int annee);
int nbETS(char nomFichier[]);
float moyRDV_ETS(char nomFichier[], int jour, char mois[], int annee);
