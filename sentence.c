#include "root.h"
#include "sentence.h"
#include <stdio.h>
#include <stdlib.h>

char *getWord(p_genders gender, int isMas, int isSG)
{
    p_persons person;
    if (isMas)
        person = gender->male;
    else
        person = gender->female;

    p_flechies flechie;
    if (isSG)
        flechie = person->singular;
    else
        flechie = person->plural;

    if (flechie->flechieCount == 0)
        printf("Error: there is not flechies. \n");
    size_t randomIndex = rand() % flechie->flechieCount;
    char *nom = flechie->flechieArray[randomIndex];
    return nom;
}

void printPronomMAJ(int isMas, int isSG)
{
    if (!isSG)
    {
        printf("Les ");
        return;
    }
    if (isMas)
    {
        printf("Le ");
    }
    else
    {
        printf("La ");
    }
}

void printPronomMIN(int isMas, int isSG)
{
    if (!isSG)
    {
        printf("les ");
        return;
    }
    if (isMas)
    {
        printf("le ");
    }
    else
    {
        printf("la ");
    }
}

void printSentence(p_root root)
{
    int isMas = rand() % 2;
    int isSG = rand() % 2;

    printPronomMAJ(isMas, isSG);

    char *nom1 = getWord(root->noun, isMas, isSG);
    printf("%s ", nom1);

    char *adj = getWord(root->adjective, isMas, isSG);
    printf("%s ", adj);

    char *verb = getWord(root->verb, isMas, isSG);
    printf("%s ", verb);

    printPronomMIN(isMas, isSG);

    char *nom2 = getWord(root->noun, isMas, isSG);
    printf("%s \n", nom2);
}
