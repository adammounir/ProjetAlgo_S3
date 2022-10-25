#include "struct.h"
#include <stddef.h>
#include <stdio.h>

void displayString(char* s)
{
    for(int i=0 ;s[i]!=0; i++)
    {
        printf("%c",s[i]);
    }
}

int main()
{

    //readDictionnaire(dictionnaire);

    for(int i =0; i<dictionnaireSize; i++)
    {
        displayString((dictionnaire[i])->flechie);
        displayString((dictionnaire[i])->base);
        displayString((dictionnaire[i])->infos);
        printf("\n");
    }
    return 0;
}
