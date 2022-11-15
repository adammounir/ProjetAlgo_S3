#include "read_file.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>
#include <assert.h>

p_dict createDict(char *path)
{
    FILE *file = fopen(path, "r");

    if (!file)
        errx(1, "Couldn't not open file: \"%s\"\n", path);

    char *lineFile = NULL;
    size_t len;
    int n_read;

    p_dict dict = malloc(sizeof(t_dict));
    dict->lineCount = 0;
    dict->lineArray = malloc(sizeof(t_line) * FILE_SIZE);

    // First loop
    while ((n_read = getline(&lineFile, &len, file)) != -1)
    {
        // printf("%i, %s", n_read, lineFile);

        // Shrink the line so that strtok_r won't read garbage.
        lineFile[n_read - 1] = 0;
        // printf("%s\n", lineFile);
        p_line line = createLine(lineFile);
        if (!line)
            continue;
        dict->lineArray[dict->lineCount] = line;
        dict->lineCount++;
        // printf("%li\n", dict->lineCount);
    }

    free(lineFile);
    return dict;
}

p_line createLine(char *lineStart)
{
    char *lineFile = malloc(sizeof(char) * (strlen(lineStart) + 1));
    // printf("%s: \n", lineStart);
    strcpy(lineFile, lineStart);

    char *save;
    char *token;

    token = strtok_r(lineFile, "\t", &save);
    if (!token)
    {
        free(lineFile);
        return NULL;
    }
    char *flechie = token;

    token = strtok_r(NULL, "\t", &save);
    if (!token)
    {
        free(lineFile);
        return NULL;
    }
    char *base = token;

    size_t lenFlechie = strlen(flechie);
    size_t lenBase = strlen(base);
    size_t lenReal;

    char *real;
    char *suffix;
    for (lenReal = 0; lenReal < lenFlechie && lenReal < lenBase; lenReal++)
    {
        if (flechie[lenReal] != base[lenReal])
            break;
    }

    suffix = flechie + lenReal;
    real = malloc(sizeof(char) * (lenFlechie + 1));
    strcpy(real, flechie);
    real[lenReal] = 0;

    // printf("flechie: %s, base: %s\n", flechie, base);
    // printf("real : %s, suffix %s \n", real, suffix);
    // getchar();

    token = strtok_r(NULL, "\t", &save);
    if (!token)
    {
        free(lineFile);
        return NULL;
    }
    char *infoStart = token;

    // printf("\t");
    p_info info = createInfo(infoStart);
    if (!info)
        return NULL;

    p_line line = malloc(sizeof(t_line));
    line->flechie = flechie;
    line->base = base;
    line->real = real;
    line->suffix = suffix;
    line->info = info;
    line->lineStart = lineStart;
    // printf("\n");
    return line;
};

p_info createInfo(char *infoStart)
{
    char *save;
    char *token;

    token = strtok_r(infoStart, ":", &save);
    if (!token)
        return NULL;
    char *categorie = token;

    int isVer = strcmp("Ver", categorie) == 0;
    int isAdv = strcmp("Adv", categorie) == 0;
    int isAdj = strcmp("Adj", categorie) == 0;
    int isNom = strcmp("Nom", categorie) == 0;
    int isCategorie = isVer || isAdj || isAdv || isNom;
    if (!isCategorie)
        return NULL;

    // printf("%s:", categorie);

    size_t modificationsCount = 0;
    p_modification *modificationsArray = NULL;
    while (1)
    {
        token = strtok_r(NULL, ":", &save);
        if (!token)
            break;
        char *modificationStart = token;
        p_modification modification = createModification(modificationStart);
        if (!modification)
        {
            free(modificationsArray);
            return NULL;
        }
        modificationsCount++;
        modificationsArray = realloc(modificationsArray, sizeof(p_modification *) * modificationsCount);
        modificationsArray[modificationsCount - 1] = modification;
    }

    p_info info = malloc(sizeof(t_info));
    info->category = categorie;
    info->modificationsArray = modificationsArray;
    info->modificationsCount = modificationsCount;
    return info;
}

p_modification createModification(char *modificationStart)
{
    char *save;
    char *token;
    size_t fieldCount = 0;
    char **fieldArray = NULL;
    for (;; modificationStart = NULL)
    {
        token = strtok_r(modificationStart, "+", &save);
        if (!token)
            break;
        fieldCount++;
        fieldArray = realloc(fieldArray, sizeof(char *) * (fieldCount));
        fieldArray[fieldCount - 1] = token;
        // printf("%s+", token);
    }
    if (fieldCount == 0 || fieldCount > 3)
        return NULL;

    p_modification modification = malloc(sizeof(t_modification));
    modification->fieldArray = fieldArray;
    modification->fieldCount = fieldCount;
    return modification;
}

void freeDict(p_dict dict)
{
    p_line *lineArray = dict->lineArray;
    for (size_t i = 0; i < dict->lineCount; i++)
    {
        p_line line = lineArray[i];
        freeLine(line);
    }
    free(lineArray);
}

void freeLine(p_line line)
{
    freeInfo(line->info);
    free(line->lineStart);
    free(line->real);
    free(line);
}

void freeInfo(p_info info)
{
    p_modification *modificationArray = info->modificationsArray;
    for (size_t i = 0; i < info->modificationsCount; i++)
    {
        p_modification modification = modificationArray[i];
        freeModification(modification);
    }
    free(modificationArray);
    free(info);
}

void freeModification(p_modification modification)
{
    free(modification->fieldArray);
    free(modification);
}

void printDict(p_dict dict)
{
    p_line *lineArray = dict->lineArray;
    for (size_t i = 0; i < dict->lineCount; i++)
    {
        p_line line = lineArray[i];
        printLine(line);
    }
}

void printLine(p_line line)
{
    printf("%s\t%s\t", line->flechie, line->base);
    p_info info = line->info;
    printInfo(info);
    printf("\n");
}

void printInfo(p_info info)
{
    char *category = info->category;
    printf("%s:", category);
    p_modification *modificationsArray = info->modificationsArray;
    for (size_t i = 0; i < info->modificationsCount; i++)
    {
        p_modification modification = modificationsArray[i];
        printModification(modification);
        printf(":");
    }
}

void printModification(p_modification modification)
{
    char **fieldArray = modification->fieldArray;
    for (size_t i = 0; i < modification->fieldCount; i++)
    {
        char *field = fieldArray[i];
        printf("%s+", field);
    }
}

/*
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
        fscanf(fic, "%s %s %s\n",l->flechie,l->base,l->infos);
        printf("%s %s %s\n",l->flechie, l->base, l->infos);

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
    for (size_t i = 0; i < dictionnaireSize; i++) {
        p_infos inf = infosTab[i];
        if (!inf)
            continue;
        char *categorie = inf->categorie;

        printf("%s", categorie);

        p_modification *modificationsTab = inf->modificationsTab;
        int modificationsCount = inf->modificationsCount;
        for (int j = 0; j < modificationsCount; j++) {
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
*/
