#include "read_file.h"
#include "buildtree.h"
#include <stdio.h>
#include <string.h>
#include "root.h"

int main()
{
    char *path = "./dictionnaires_de_mots/dictionnaire.txt";
    p_dict dict = createDict(path);
    // printDict(dict);
    p_root root = createRoot(dict);
    freeRoot(root);
    freeDict(dict);
    return 0;
}
