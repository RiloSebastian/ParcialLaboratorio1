#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"

float set_flotante(char mensaje[], float flotante)
{
    int flag=0;
    char auxFlt[15];
    float num;

    if(mensaje != NULL && auxFlt != NULL && sizeof(auxFlt) > 0)
    {
        printf("%s",mensaje);
        do
        {
            __fpurge(stdin);
            fgets(auxFlt,sizeof(auxFlt),stdin);
            if((flag=validar_flotante(auxFlt,sizeof(auxFlt))))
            {
                num=atof(auxFlt);
                flotante= num;
            }
            else
            {
                printf("error. intenta de nuevo: ");
            }
        }
        while(flag!=1);
    }
    return flotante;
}



int set_entero(char mensaje[], int entero)
{
    int flag=0;
    char auxIntg[15];
    int num;

    if(mensaje != NULL && auxIntg != NULL && sizeof(auxIntg) > 0)
    {
        printf("%s",mensaje);
        do
        {
            __fpurge(stdin);
            fgets(auxIntg,sizeof(auxIntg),stdin);
            if((flag=validar_entero(auxIntg,sizeof(auxIntg))))
            {

                num=atoi(auxIntg);
                entero= num;
            }
            else
            {
                printf("error. intenta de nuevo: ");
            }
        }
        while(flag!=1);
    }
    return entero;
}


int set_nombre(char mensaje[], char texto[], int len)
{
    int flag=0;
    int auxlen;
    char* token;
    if(mensaje !=NULL && texto != NULL && len > 0)
    {
        printf("%s",mensaje);
        do
        {
            __fpurge(stdin);
            fgets(texto,len,stdin);
            auxlen=strlen(texto);
            if(!(flag=validar_alfabetico(texto, len)))
            {
                printf("error. intenta de nuevo: ");
            }
        }
        while(flag== 0);
        token=strtok(texto,"\n");
        strncpy(texto,token,auxlen);
    }
    return flag;
}


int set_texto(char mensaje[], char texto[], int len)
{
    int flag=0;
    int auxlen;
    char* token;
    if(mensaje !=NULL &&texto != NULL && len > 0)
    {
        printf("%s",mensaje);
        do
        {
            __fpurge(stdin);
            fgets(texto,len,stdin);
            auxlen=strlen(texto);
            if(!(flag=validar_alfanumerico(texto, len)))
            {
                printf("error. intenta de nuevo: ");
            }
        }
        while(flag== 0);
        token=strtok(texto,"\n");
        strncpy(texto,token,auxlen);
    }
    return flag;
}

int set_cuit(char mensaje[], char cuit[], int len)
{
    int flag=0;
    int auxlen;
    char* token;
    if(mensaje !=NULL &&cuit != NULL && len > 0)
    {
        printf("%s",mensaje);
        do
        {
            __fpurge(stdin);
            fgets(cuit,len,stdin);
            auxlen=strlen(cuit);
            if(!(flag=validar_cuit(cuit, len)))
            {
                printf("error. intenta de nuevo: ");
            }
        }
        while(flag== 0);
        token=strtok(cuit,"\n");
        strncpy(cuit,token,auxlen);
    }
    return flag;
}

int set_margenEntero(char mensaje[], int entero, int min, int max)
{
    if(mensaje!= NULL)
    {
        printf("%s",mensaje);
        do
        {
            entero=set_entero("",entero);
            if(entero < min || entero > max)
            {
                printf("error. intenta de nuevo: ");
            }
        }
        while(entero < min || entero > max);
    }
    return entero;
}


float set_margenFlotante(char mensaje[], float flotante, float min, float max)
{
    if(mensaje != NULL)
    {
        printf("%s",mensaje);
        do
        {
            flotante=set_flotante("",flotante);
            if(flotante < min || flotante > max)
            {
                printf("error. intenta de nuevo'n");
            }
        }
        while(flotante < min || flotante > max);
    }
    return flotante;
}


int validar_flotante(char str[], int len)
{
    int flag=1;
    int i=0;
    int auxlen;

    if(str != NULL && len >0)
    {
        auxlen=strlen(str);
        while(str[i] != '\0' && i<= auxlen && str[i] != 10)
        {
            if((str[i] < '0' || str[i] > '9') && str[i] != '-')
            {
                flag= 0;
                break;
            }

            i++;
        }
    }
    return flag;
}


int validar_entero(char str[], int len)
{
    int flag=1;
    int i=0;
    int auxlen;

    if(str != NULL && len >0)
    {
        auxlen=strlen(str);
        while(str[i] != '\0' && i<= auxlen && str[i] != 10)
        {
            if((str[i] < '0' || str[i] > '9') && str[i] != '-')
            {
                flag= 0;
                break;
            }
            i++;
        }
    }
    return flag;
}



int validar_alfabetico(char str[], int len)
{
    int i=0;
    int flag=1;
    int auxlen;

    if(str != NULL && len>0)
    {
        auxlen=strlen(str);

        while(str[i] != '\0' && i<= auxlen && str[i] != 10)
        {
            if((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && str[i] != ' ' && str[i] != -61 &&
                    str[i] != -79 && str[i] != -111)
            {
                flag=0;
                break;
            }
            i++;
        }
    }
    return flag;
}


int validar_alfanumerico(char str[], int len)
{
    int i=0;
    int flag=1;
    int auxlen;

    if(str != NULL && len >0)
    {
        auxlen=strlen(str);
        while(str[i] != '\0' && i<= auxlen)
        {
            if( (str[i] != 10 ) && (str[i] < '0' || str[i] > '9') && str[i] != '-')
            {
                flag= 0;
                break;
            }

            i++;
        }
    }
    return flag;
}

int validar_cuit(char str[], int len)
{
    int i=0;
    int flag=1;
    int auxlen;

    if(str != NULL && len >0)
    {
        auxlen=strlen(str);
        while(str[i] != '\0' && i<= auxlen)
        {
            if( (str[i] != 10 ) && (str[i] < '0' || str[i] > '9') && str[i] != '-')
            {
                flag= 0;
                break;
            }

            i++;
        }
    }
    return flag;
}
