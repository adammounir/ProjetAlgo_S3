#include "struct.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>


/*void readDictionnaire(p_lineFile dict[dictionnaireSize])
{   //OUVRE LE FICHIER 
    FILE *fic = fopen ("/mnt/c/EFREI/ProjetAlgo_S3/dictionnaires_de_mots/dictionnaire.txt","r");

    //VERIFIE SI LE FICHIER EXISTE
    if(fic == NULL)
        exit(1);

    //PARCOURS DU TABLEAU LIGNE PAR LIGNE
    for(int i=0; i<dictionnaireSize; i++)
    {
        //CREATION D'UNE LIGNE DU TABLEAU
        p_lineFile l = malloc(sizeof(p_lineFile));
        int cpt = 0;

        //REMPLISSAGE DE LA LIGNE DU TABLEAU
        for(int lettre ; lettre != '\n'; lettre = fgetc(fic))
        {
            if((char)lettre == '\t')
            {
                cpt ++;
                continue;
            }
            if(cpt ==0)
                strncat(l->flechie, (char*)&lettre, sizeof(l->flechie) - strlen(l->flechie) - 1);
            if(cpt ==1)
                strncat(l->base, (char*)&lettre,sizeof(l->flechie) - strlen(l->flechie) - 1);
            if(cpt ==2)
                strncat(l->infos, (char*)&lettre,sizeof(l->flechie) - strlen(l->flechie) - 1);
        }

        //ASSIGNATION DE LA LIGNE DU TABLEAU AU DICTIONNAIRE
        dict[i] = l;
        //FERMETURE DU FICHIER SI SA LECTURE EST FINIE
        if(feof(fic))
            break;
    }
}*/
