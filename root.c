#include "root.h"
#include "read_file.h"
#include <stdlib.h>
#include <string.h>

p_root initRoot()
{
    p_root root = malloc(sizeof(t_root));
    p_genders noun = initGender();
    p_genders verb = initGender();
    p_genders adjective = initGender();
    root->noun = noun;
    root->verb = verb;
    root->adjective = adjective;
    return root;
}

p_genders initGender()
{
    p_genders genders = malloc(sizeof(t_genders));
    p_persons male = initPerson();
    p_persons female = initPerson();
    genders->male = male;
    genders->female = female;
    return genders;
};

p_persons initPerson()
{
    p_persons person = malloc(sizeof(t_persons));
    p_flechies singular = initFlechies();
    p_flechies plural = initFlechies();
    person->singular = singular;
    person->plural = plural;
    return person;
};

p_flechies initFlechies();

void freeFlechies(p_flechies flechie)
{
    free(flechie->flechieArray);
    free(flechie);
}

void freePersons(p_persons person)
{
    freeFlechies(person->plural);
    freeFlechies(person->singular);
    free(person);
}

void freeGenders(p_genders gender)
{
    freePersons(gender->female);
    freePersons(gender->male);
    free(gender);
}

void freeRoot(p_root root)
{
    freeGenders(root->noun);
    freeGenders(root->verb);
    freeGenders(root->adjective);
    // freeGenders(root->adverb);
    free(root);
}

p_flechies initFlechies()
{
    p_flechies flechie = malloc(sizeof(t_flechies));
    flechie->flechieArray = malloc(sizeof(char *) * FILE_SIZE);
    flechie->flechieCount = 0;
    return flechie;
}

p_root createRoot(p_dict dict)
{
    p_root root = initRoot();
    for (size_t i = 0; i < dict->lineCount; i++)
    {
        p_line line = dict->lineArray[i];
        p_info info = line->info;
        char *categorie = info->category;
        // printf("%s %s\n", line->flechie, categorie);
        int isVer = strcmp(categorie, "Ver") == 0;
        int isNom = strcmp(categorie, "Nom") == 0;
        int isAdj = strcmp(categorie, "Adj") == 0;
        if (isVer)
            fillVerb(root->verb, info, line->flechie);
        else if (isNom)
            fill(root->noun, info, line->flechie);
        else if (isAdj)
            fill(root->adjective, info, line->flechie);
        // printf("\n");
    }
    return root;
}

void fill(p_genders gender, p_info info, char *flechie)
{
    p_modification *modifArray = info->modificationsArray;
    size_t modifCount = info->modificationsCount;
    for (size_t i = 0; i < modifCount; i++)
    {
        p_modification modif = modifArray[i];
        size_t fieldCount = modif->fieldCount;
        char **fieldArray = modif->fieldArray;
        // printf("%li \n", fieldCount);
        if (fieldCount != 2) // Means we don't have info on gender and person
            return;
        char *genre = fieldArray[0];
        char *personne = fieldArray[1];
        int isMas = strcmp(genre, "Mas") == 0 || strcmp(genre, "InvGen") == 0;
        int isFem = strcmp(genre, "Fem") == 0;

        p_persons person;
        if (isMas)
            person = gender->male;
        else if (isFem)
            person = gender->female;
        else
        {
            // printf("Found useless\n");
            return;
        }

        int isSG = strcmp(personne, "SG") == 0 || strcmp(genre, "InvPL") == 0;
        int isPL = strcmp(personne, "PL") == 0;

        p_flechies flechies;
        if (isSG)
            flechies = person->singular;
        else if (isPL)
            flechies = person->plural;
        else
        {
            // printf("Found useless \n");
            return;
        }

        // getchar();
        flechies->flechieArray[flechies->flechieCount] = flechie;
        flechies->flechieCount++;
        // printf("%li\n", flechies->flechieCount);
    }
}

void fillVerb(p_genders verb, p_info info, char *flechie)
{
    p_modification *modifArray = info->modificationsArray;
    size_t modifCount = info->modificationsCount;
    for (size_t i = 0; i < modifCount; i++)
    {
        p_modification modif = modifArray[i];
        size_t fieldCount = modif->fieldCount;
        char **fieldArray = modif->fieldArray;
        if (fieldCount != 3) // Means we don't have info on gender and person
            return;
        char *nombre = fieldArray[1];
        char *personne = fieldArray[2];
        // printf("%s, %s\n", nombre, personne);
        int isThird = strcmp(personne, "P3") == 0;
        if (!isThird)
        { // Means that it is useless;
            // printf("Found useless person \n");
            return;
        }
        int isSingular = strcmp(nombre, "SG") == 0;
        int isPlural = strcmp(nombre, "PL") == 0;
        p_flechies flechies1;
        p_flechies flechies2;
        if (isSingular)
        {
            // printf("found singular \n");
            flechies1 = verb->male->singular;
            flechies2 = verb->female->singular;
        }
        else if (isPlural)
        {
            // printf("found plural \n");

            flechies1 = verb->male->plural;
            flechies2 = verb->female->plural;
        }
        else
            return;

        // getchar();
        flechies1->flechieArray[flechies1->flechieCount] = flechie;
        flechies1->flechieCount++;

        flechies2->flechieArray[flechies2->flechieCount] = flechie;
        flechies2->flechieCount++;
    }
}
