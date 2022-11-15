#include <stddef.h>
#include "read_file.h"

#ifndef NOUNS_TREE_H
#define NOUNS_TREE_H

typedef struct s_gender_tree
{
    p_line firstPerson[FILE_SIZE];
    p_line secondPerson[FILE_SIZE];
    p_line thirdPerson[FILE_SIZE];
} t_gender_tree, *p_gender_tree;

typedef struct s_noun_tree
{
    t_gender_tree male_tree;
    t_gender_tree female_tree;
} t_noun_tree, *p_noun_tree;

#endif
