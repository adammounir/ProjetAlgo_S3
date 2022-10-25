#ifndef FILE_READING

//STRUCTURE CONTENANT LES CHAMPS D'UNE LIGNE DU DICTIONNAIRE
typedef struct s_lineFile
{
    char * flechie;
    char * base;
    char * infos;
}t_lineFile,*p_lineFile;


#define dictionnaireSize 287976

p_lineFile dictionnaire[dictionnaireSize];
p_lineFile dictionnaire_non_accentue[dictionnaireSize];


void readDictionnaire(p_lineFile dict[dictionnaireSize]);


#endif 



