#include "struct.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>


void readDictionnaire(p_lineFile *dict)
{   //OUVRE LE FICHIER 
    FILE *fic = fopen ("./dictionnaires_de_mots/dictionnaire.txt","r");

    //VERIFIE SI LE FICHIER EXISTE
    if(fic == NULL)
        exit(1);

    int i = 0;

    //PARCOURS DU TABLEAU LIGNE PAR LIGNE
    while(!feof(fic)) //CONDITION DE FIN DE FICHIER
    {
        //CREATION D'UNE LIGNE DU TABLEAU
        p_lineFile l = malloc(sizeof(t_lineFile));

        //REMPLISSAGE DE LA LIGNE DU TABLEAU
        fscanf(fic, "%s %s  %s\n",l->flechie,l->base,l->infos);
        printf("%s %s %s\n",l->flechie, l->base, l->infos);

        //ASSIGNATION DE LA LIGNE DU TABLEAU AU DICTIONNAIRE
        dict[i] = l;

        i++;
    }
}

void freeDictionnaire(p_lineFile *dict, size_t size) {
    for (size_t i = 0; i < size; i++) {
        free(dict[i]);
    }
}
