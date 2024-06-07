#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED
#include <stdio.h>

typedef struct {

    char user[10];
    char pass [15];


} information;

int loginUser();

#endif // LOGIN_H_INCLUDED

