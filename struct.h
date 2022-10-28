#include <stddef.h>

#ifndef FILE_READING

//STRUCTURE CONTENANT LES CHAMPS D'UNE LIGNE DU DICTIONNAIRE
typedef struct s_lineFile
{
    char flechie[80];
    char base[80];
    char infos[80];
}t_lineFile,*p_lineFile;


#define dictionnaireSize 287976
#define miniDictionnaireSize 10

p_lineFile dictionnaire_non_accentue[dictionnaireSize];
p_lineFile mini_dictionnaire[miniDictionnaireSize];


void readDictionnaire(p_lineFile *dict);
void freeDictionnaire(p_lineFile *dict, size_t size);


#endif 



