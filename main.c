#include "read_file.h"
#include "buildtree.h"
#include "verbs_buildtree.h"
#include <stdio.h>
#include <string.h>

int main()
{
    char *path = "./dictionnaires_de_mots/dictionnaire.txt";
    p_dict dict = createDict(path);
    printDict(dict);
    freeDict(dict);
    return 0;
}
