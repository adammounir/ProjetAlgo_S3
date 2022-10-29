#include <stddef.h>


#ifndef FILE_READING

/*-----------------------LECTURE DE DICTIONNAIRE------------------------------*/


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

//DECLARATION DES FONCTIONS DE LECTURE DE DICTIONNAIRE
void readDictionnaire(p_lineFile *dict);
void freeDictionnaire(p_lineFile *dict, size_t size);



/*------------------------CREATION DES ARBRES---------------------------------*/


//LISTE DES CARACTERES ACCENTUES UTILISES 
    //      à - â - é - è - ê - ë - î - ï - ô - ö - ù - û - ü - ç

/*typedef struct s_node
{
    char value;
    *s_node next[40]; // 26+14=40 CARACTERES
}t_node , *p_node


typedef struct s_tree
{
    p_node root;
}t_tree , s_tree*/


#endif 



