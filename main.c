#include "read_file.h"
#include "buildtree.h"
#include "verbs_buildtree.h"
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
    verbsParsing(dict, infosTab); 
    freeDictionnaire(dict, dictionnaireSize);
    printInfosTab(infosTab);
    freeInfosTab(infosTab);
    return 0;
}
