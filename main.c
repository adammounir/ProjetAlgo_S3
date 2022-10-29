#include "struct.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>

void displayString(char* s)
{
    for(int i=0 ;s[i]!=0; i++)
    {
        printf("%c",s[i]);
    }
}

int main()
{
    p_lineFile dict[dictionnaireSize];
    readDictionnaire(dict);
    freeDictionnaire(dict, dictionnaireSize);
    
    return 0;
}
