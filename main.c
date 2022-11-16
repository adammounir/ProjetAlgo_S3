#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "read_file.h"
#include "buildtree.h"
#include "root.h"
#include "sentence.h"

int main()
{
    srand(time(NULL));
    char *path = "./dictionnaires_de_mots/dictionnaire.txt";
    p_dict dict = createDict(path);
    p_root root = createRoot(dict);

    printSentence(root);

    freeRoot(root);
    freeDict(dict);
    return 0;
}
