#include <stddef.h>
#include "read_file.h"

#ifndef ROOT_H
#define ROOT_H

typedef struct s_flechies
{
    size_t flechieCount;
    char *flechieArray;
} t_flechies, *p_flechies;

typedef struct s_persons
{
    p_flechies singular;
    p_flechies plural;
} t_persons, *p_persons;

typedef struct s_genders
{
    p_persons male;
    p_persons female;
} t_genders, *p_genders;

typedef struct s_root
{
    p_genders noun;
    p_genders verb;
    p_genders adjective;
    p_genders adverb;
} t_root, *p_root;

p_root initRoot();
p_genders initGender();
p_persons initPerson();
p_flechies initFlechies();
void freeRoot(p_root root);
void freeGenders(p_genders gender);
void freePersons(p_persons person);
void freeFlechies(p_flechies flechie);
void freeStruct();

p_root createRoot(p_dict dict);
void fillVerb(p_root root, p_info info, char *flechie);

#endif
