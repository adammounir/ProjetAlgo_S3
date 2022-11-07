#include <stddef.h>


#ifndef FILE_READING

/*---------------------------------------------------------------------LECTURE DU DICTIONNAIRE------------------------------------------------------------------------------------------*/
//STRUCTURE CONTENANT LES CHAMPS D'UNE SEULE MODIFICATION
typedef struct s_modification
{
    char *first;
    char *second;
    char *third;
}t_modification , *p_modification;


//STRUCTURE CONTENANT LES CHAMPS DE L'ENSEMBLE DES INFOS D'UNE LIGNE
typedef struct s_infos
{
    char *categorie;
    p_modification *modificationsTab;
    int modificationsCount;
}t_infos , *p_infos;


//STRUCTURE CONTENANT LES CHAMPS D'UNE LIGNE DU DICTIONNAIRE
typedef struct s_lineFile
{
    char flechie[80];
    char base[80];
    char infos[80];
}t_lineFile,*p_lineFile;


//TAILLES DES DIFFERENTS DICTIONNAIRES
#define dictionnaireSize 287976
#define miniDictionnaireSize 10


//DEFINITION DES DICTIONNAIRES
p_lineFile dictionnaire_non_accentue[dictionnaireSize];
p_lineFile mini_dictionnaire[miniDictionnaireSize];
p_lineFile dict[dictionnaireSize];

p_infos infosTab[dictionnaireSize];

//DECLARATION DES FONCTIONS DE LECTURE DE DICTIONNAIRE

void readDictionnaire(p_lineFile *dict);
void freeDictionnaire(p_lineFile *dict, size_t size);

void verbsParsing(p_lineFile *dict, p_infos *infosTab);
void printInfosTab(p_infos *infosTab);
void freeInfosTab(p_infos *infosTab);

//DEFINITION DE LA STRUCTURE CONTENTANT LES INFOS DE CHAQUE LIGNE DU DICO
/*typedef struct s_infos
{
    category[4]
    char *modifications;
}*/

#endif 



