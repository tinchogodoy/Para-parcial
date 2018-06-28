#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"



int parserDestinatarios(char* path , ArrayList* pArrayList)
{
    FILE* pFile=NULL;
    char nombre[256];
    char mail[256];
   //Destinatario* auxDestinatario;

   // int auxInt;

    pFile = fopen(path,"r");
    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^\n]\n",nombre,mail);
           // auxDestinatario = destinatario_new();
           // destinatario_setNombre(auxDestinatario,nombre);
           // destinatario_setMail(auxDestinatario,mail);
           // al_add(pArrayList,auxDestinatario);
        }
        fclose(pFile);
       // auxInt = al_len(pArrayList) ;
        //printf("\n %d",auxInt);
    }

    return 0;

}
