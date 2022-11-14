#ifndef READ_FILE_H
#define READ_FILE_H
#define FILE_SIZE 287976
#include <stdio.h>

/*------------------------LECTURE DU DICTIONNAIRE----------------------------*/

// STRUCTURE CONTENANT LES CHAMPS D'UNE SEULE MODIFICATION
typedef struct s_modification
{
    size_t fieldCount;
    char **fieldArray;
} t_modification, *p_modification;

// STRUCTURE CONTENANT LES CHAMPS DE L'ENSEMBLE DES INFOS D'UNE LIGNE
typedef struct s_info
{
    char *category;
    size_t modificationsCount;
    p_modification *modificationsArray;
} t_info, *p_info;

// STRUCTURE CONTENANT LES CHAMPS D'UNE LIGNE DU DICTIONNAIRE
typedef struct s_line
{
    char *lineStart;
    char *flechie;
    char *base;
    char *real;
    char *suffix;
    p_info info;
} t_line, *p_line;

typedef struct s_dict
{
    size_t lineCount;
    p_line *lineArray;
} t_dict, *p_dict;

p_dict createDict(char *path);
p_line createLine(char *lineStart);
p_info createInfo(char *infoStart);
p_modification createModification(char *modificationStart);
char *createField(char *fieldStart);

void freeDict(p_dict dict);
void freeLine(p_line line);
void freeInfo(p_info info);
void freeModification(p_modification modification);

void printDict(p_dict dict);
void printLine(p_line line);
void printInfo(p_info info);
void printModification(p_modification modification);

#endif
