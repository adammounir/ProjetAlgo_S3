#include "struct.h"
#include <stddef.h>
#include <stdio.h>

void displayString(char* s)
{
    for(int i=0 ;s[i]!=0; s++)
    {
        printf("%c",s[i]);
    }
}

int main()
{
    p_dictionnaire dict[dictionnaireSize];

    readDictionnaire(dictionnaireSize,dict);

    for(int i =0; i<dictionnaireSize; i++)
    {
        displayString((dict->lineFileList[i])->flechie);
        displayString((dict->lineFileList[i])->base);
        displayString((dict->lineFileList[i])->infos);
        printf("\n");
    }
    return 0;
}
