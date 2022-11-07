#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "buildtree.h"


//FONCTION DE CREATION D'UN NOEUD
p_node createNode(int val)
{
    p_node nouv = malloc(sizeof(t_node));
    nouv->value = val;

    p_node array[40] = {NULL};
    nouv->next = array;

    return nouv;
}



//FONCTION DE CREATION DES MOTS DANS UN ARBRE
void createWord(node root)
{
    char *pbase = première lettre de notre mot de base 
    char *pflechie = première lettre de notre mot fléchie

    node_quelconque root = première noeud de notre arbre(root)  //TYPE INCONNU
    p_node tmp = root (pointeur de parcours de l'arbre)

    enum lettres lettre;

    int i=0;
    while (pbase[i+1] != NULL)
    {
        lettre = 
        // ON VERIFIE SI LE FILS DU NOEUD ACTUEL CONTIENT LA LETTRE D'INDICE SUIVANT DU POINTEUR
        if (tmp->next[indice((pflechie(lettre+1)))] == NULL)//CONDITION D'INEXISTENCE

                tmp = createNode(root=tmp->next[indicepflechie(lettre+1)]),val=indicepflechie(lettre+1);
        
        else    //CONDITION D'EXISTENCE

            tmp = tmp->next[indicepflechie(lettre+1)];
        i++;
    }
}
