#include "read_file.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>

//FONCTION DE LECTURE DU DICTIONNAIRE
void readDictionnaire(p_lineFile *dict)
{   
    //OUVRE LE FICHIER 
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
        //printf("%s %s %s\n",l->flechie, l->base, l->infos);

        //ASSIGNATION DE LA LIGNE DU TABLEAU AU DICTIONNAIRE
        dict[i] = l;
        
        i++;
    }

}



//FONCTION DE DESALLOCATION DU TABLEAU DE STOCKAGE
void freeDictionnaire(p_lineFile *dict, size_t size) {
    for (size_t i = 0; i < size; i++) 
        free(dict[i]);
}



void print_string(char *s, int len) {
  for (int i = 0; i < len; i++) {
    if (s[i] == '\0') {
      printf("\\0");
    }
    else {
      printf("%c", s[i]);
    }
  }
}


//FONCTION DE PARSING DU CHAMPS INFOS 
void verbsParsing(p_lineFile *dict,p_infos *infosTab)
{
    readDictionnaire(dict);
    
    //PARCOURS DE CHAQUE LIGNE DU DICTIONNAIRE
    for(int i=0; i<dictionnaireSize; i++)
    {
        //RECUPERATION DE LA LIGNE ACTUELLE DU TABLEAU
        p_lineFile l = dict[i];
        
        //CREATION D'UN CHAMP p_infos A METTRE DANS infosTab

        char *save1,*save2;
        char *modification,*champ;
        char *token,*subtoken;

        // printf("l->infos = %s\n",l->infos);
        modification = strtok_r(l->infos, ":", &save1);
        int isVer = strcmp("Ver", modification) == 0;
        int isAdv = strcmp("Adv", modification) == 0;
        int isAdj = strcmp("Adj", modification) == 0;
        int isNom = strcmp("Nom", modification) == 0;
        int isCategorie = isVer || isAdj || isAdv || isNom;
        if(!isCategorie)
        {
            // printf("Unvalid categorie: %s \n\n", l->infos);
            continue;
        }

        p_infos inf = malloc(sizeof(t_infos));
        // Now, we have a token that must be "Ver", "Adj", "Adv" or "Nom".
        // So, we save it in our field categorie.
        inf->categorie = malloc(sizeof(char) * 4);
        strcpy(inf->categorie, modification);
        // printf("%s", inf->categorie);
       
        p_modification *modificationsTab = NULL;
        int modificationsCount = 0;

        while (1) {
            modification = strtok_r(NULL, ":", &save1);
            if (!modification)
                break;
            int num_champ = 1;
            p_modification modif = malloc(sizeof(t_modification));
            modif->first = NULL;
            modif->second = NULL;
            modif->third = NULL;
            for (champ = modification; ;champ = NULL) {
                subtoken = strtok_r(champ, "+",&save2);
                if (subtoken == NULL)
                    break;
                if (num_champ >= 4)
                    errx(1, "Erreur: plus de 3 champs ont été détectés. \n");
                if (num_champ == 1)
                {
                    modif->first = malloc(sizeof(char) * (strlen(subtoken) + 1));
                    strcpy(modif->first, subtoken);
                }
                else if (num_champ == 2)
                {
                    modif->second = malloc(sizeof(char) * (strlen(subtoken) + 1));
                    strcpy(modif->second, subtoken);
                }
                else if (num_champ == 3)
                {
                    modif->third = malloc(sizeof(char) * (strlen(subtoken) + 1));
                    strcpy(modif->third, subtoken);
                }
                num_champ++;
            }
            modificationsCount++;
            modificationsTab = realloc(modificationsTab, sizeof(p_modification) * modificationsCount);
            if (!modificationsTab)
                errx(1, "Not enough memory.\n");
            modificationsTab[modificationsCount-1] = modif;
        }
        inf->modificationsTab = modificationsTab;
        inf->modificationsCount = modificationsCount;
        infosTab[i] = inf;
    }
}

void printInfosTab(p_infos *infosTab) {
    for (size_t i = 0; i < dictionnaireSize; i++) 
    {
        p_infos inf = infosTab[i];
        if (!inf)
            continue;
        char *categorie = inf->categorie;
        
        printf("%s", categorie);
        
        p_modification *modificationsTab = inf->modificationsTab;
        int modificationsCount = inf->modificationsCount;

        for (int j = 0; j < modificationsCount; j++) 
        {
            p_modification modification = modificationsTab[j];
            char *first = modification->first;
            char *second = modification->second;
            char *third = modification->third;
            printf(":");
            if (first)
                printf("%s", first);
            if (second)
                printf("+%s", second);
            if (third)
                printf("+%s", third);
        }
        printf("\n");
    }
}

void freeInfosTab(p_infos *infosTab) {
    for (size_t i = 0; i < dictionnaireSize; i++) {
        p_infos inf = infosTab[i];
        if (!inf)
            continue;
        char *categorie = inf->categorie;
        free(categorie);

        p_modification *modificationsTab = inf->modificationsTab;
        int modificationsCount = inf->modificationsCount;
        
        for (int j = 0; j < modificationsCount; j++) {
            p_modification modification = modificationsTab[j];
            free(modification->first);
            free(modification->second);
            free(modification->third);
            free(modification);
        }
        
        free(modificationsTab);
        free(inf);
    }
}
