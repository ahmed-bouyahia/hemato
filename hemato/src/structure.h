#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED
#include <stdio.h>
#include <gtk/gtk.h>

typedef struct
{ int day,month,year;

}date;


typedef struct
{
    char id_donor[89], id_don[89], blood_type[200],center[200];
    int  quantity,month,day,year;
}donn;
typedef struct
{
    int id;
    char establishment  [200];
    date date_rdv ;
    char tt [200] ;

} rdv ;
typedef struct {
char fullname[50];
char email[50];
char phone[50];
char password[50];
} sign;

typedef struct
{
    char establishment_name [200];
char state[200];
char adress[500];
int capacity ;
char email_adress[200];
int phone_number;
int numberof_laboratory;
int numberof_doctors;
int numberof_nurses;
int numberof_technicians;
char blood_storage[200];
int establishment_id;

} crude;

int ETScapacite(char* nomFichier, char establishment_name[]);
void historique (char* nomFichier, char CIN[]);
int HoraireDispo(char * nomFichier, char ETS[], int capacity, int jour, int mois , int annee, char  horaire[]);
int ajouter_RDV(char *, rdv );
int modifier_RDV( char *, int, rdv );
int supprimer_RDV(char *, int );
rdv chercher_RDV(char *, int );
void afficher_fichierss(GtkWidget *list) ;
void afficher_fichiersss(GtkWidget *list);
void supprimer_RR (rdv r);


#endif // STRUCTURE_H_INCLUDED
