#ifndef FILE_READING

//STRUCTURE CONTENANT LES CHAMPS D'UNE LIGNE DU DICTIONNAIRE
typedef struct s_lineFile
{
    char * flechie;
    char * base;
    char * infos;
}t_lineFile,*p_lineFile;


#define dictionnaireSize 287976

typedef struct s_dictionnaire
{
    p_lineFile lineFileList[dictionnaireSize];
}t_dictionnaire,*p_dictionnaire;


void readDictionnaire(int size, p_dictionnaire dict[size]);


#endif 



