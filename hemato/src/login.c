#include "login.h"
#include <stdlib.h>
#include <stdio.h>



// Function to check if a user exists in the file
int loginUser(char * filename, char  user[] , char   pass[]) {
    int found = 0;

    information inf;
    // Open the file in read mode
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file for reading.\n");
        exit(1);
    }



    // Read each line from the file and check for the user
    while (fscanf(file, "%s %s", inf.user, inf.pass) == 2) {
        if (strcmp(inf.user, user) == 0 && strcmp(inf.pass, pass) == 0) {
            found = 1;
            break;
        }
    }

    fclose(file);

    return found;
}


