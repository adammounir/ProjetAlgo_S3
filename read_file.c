#include "struct.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>


void readDictionnaire(int size, p_dictionnaire dict[size])
{   //OUVRE LE FICHIER 
    FILE *fic = fopen ("/mnt/c/EFREI/ProjetAlgo_S3/dictionnaires_de_mots/dictionnaire.txt","r");

    //VERIFIE SI LE FICHIER EXISTE
    if(fic == NULL)
        exit(1);

    for(int i=0; i<size; i++)
    {
    //CREATION D'UN ELEMENT DE LA STRUCTURE lineFile
        p_lineFile l;
        int cpt = 0;

        for(int lettre ; lettre != '\n'; lettre = fgetc(fic))
        {
            if((char)lettre == '\t')
            {
                cpt ++;
                continue;
            }
            if(cpt ==0)
                strncat(l->flechie, (char*)&lettre, 1);
            if(cpt ==1)
                strncat(l->base, (char*)&lettre, 1);
            if(cpt ==2)
                strncat(l->infos, (char*)&lettre, 1);
        }
        (dict->lineFileList)[i] = l;
        if(feof(fic))
            break;
    }
}
