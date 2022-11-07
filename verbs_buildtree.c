#include "verbs_buildtree.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>



//INDICATIF

    //PRESENT SIMPLE DE L'INDICATIF
    //SINGULIER
    p_personne IndPreSimpSingFirst = p_verbes_tree->root->indicatif->present_simple->singulier->first;
    p_personne IndPreSimpSingSecond = p_verbes_tree->root->indicatif->present_simple->singulier->second;
    p_personne IndPreSimpSingThird = p_verbes_tree->root->indicatif->present_simple->singulier->first;
    //PLURIEL
    p_personne IndPreSimpPlurFirst = p_verbes_tree->root->indicatif->present_simple->pluriel->first;
    p_personne IndPreSimpPlurSecond = p_verbes_tree->root->indicatif->present_simple->pluriel->second;
    p_personne IndPreSimpPlurThird = p_verbes_tree->root->indicatif->present_simple->pluriel->third;

    //IMPARFAIT DE L'INDICATIF
    //SINGULIER
    p_personne IndImpaSingFirst = p_verbes_tree->root->indicatif->imparfait->singulier->first;
    p_personne IndImpaSingSecond = p_verbes_tree->root->indicatif->imparfait->singulier->second;
    p_personne IndImpaSingThird = p_verbes_tree->root->indicatif->imparfait->singulier->third;
    //PLURIEL
    p_personne IndImpaPlurFirst = p_verbes_tree->root->indicatif->imparfait->pluriel->first;
    p_personne IndImpaPlurSecond = p_verbes_tree->root->indicatif->imparfait->pluriel->second;
    p_personne IndImpaPlurThird = p_verbes_tree->root->indicatif->imparfait->pluriel->third;

    //PASSE SIMPLE DE L'INDICATIF
    //SINGULIER
    p_personne IndPassSimpSingFirst = p_verbes_tree->root->indicatif->passe_simple->singulier->first;
    p_personne IndPassSimpSingSecond = p_verbes_tree->root->indicatif->passe_simple->singulier->second;
    p_personne IndPassSimpSingThird = p_verbes_tree->root->indicatif->passe_simple->singulier->third;

    //PLURIEL
    p_personne IndPassSimpPlurFirst = p_verbes_tree->root->indicatif->passe_simple->pluriel->first;
    p_personne IndPassSimpPlurSecond = p_verbes_tree->root->indicatif->passe_simple->pluriel->second;
    p_personne IndPassSimpPlurThird = p_verbes_tree->root->indicatif->passe_simple->pluriel->third;
    
    //FUTUR DE L'INDICATIF
    //SINGULIER
    p_personne IndFuturSingFirst = p_verbes_tree->root->indicatif->futur->singulier->first;
    p_personne IndFuturSingSecond = p_verbes_tree->root->indicatif->futur->singulier->second;
    p_personne IndFuturSingThird = p_verbes_tree->root->indicatif->futur->singulier->third;


    //PLURIEL
    p_personne IndFuturPlurFirst = p_verbes_tree->root->indicatif->futur->singulier->first;
    p_personne IndFuturPlurSecond = p_verbes_tree->root->indicatif->futur->singulier->second;
    p_personne IndFuturPlurThird = p_verbes_tree->root->indicatif->futur->singulier->third;

//IMPERATIF
    //PRESENT
    //SINGULIER
    p_personne ImperPresSingSecond = p_verbes_tree->root->imperatif->present->singulier->second;

    //PLURIEL
    p_personne ImperPresPlurFirst = p_verbes_tree->root->imperatif->present->pluriel->first;
    p_personne ImperPresPlurSecond = p_verbes_tree->root->imperatif->present->pluriel->second;

//CONDITIONNEL
    //PRESENT
    //SINGULIER
    p_personne CondPresSingFirst = p_verbes_tree->root->conditionnel->present->singulier->first;
    p_personne CondPresSingSecond = p_verbes_tree->root->conditionnel->present->singulier->second;
    p_personne CondPresSingThird = p_verbes_tree->root->conditionnel->present->singulier->third;

    //PLURIEL
    p_personne CondPresPlurFirst = p_verbes_tree->root->conditionnel->present->pluriel->first;
    p_personne CondPresPlurSecond = p_verbes_tree->root->conditionnel->present->pluriel->second;
    p_personne CondPresPlurThird = p_verbes_tree->root->conditionnel->present->pluriel->third;


//INFINITIF
    p_infinitif Infinitif = p_verbes_tree->root->infinitif;

//PARTICIPE PASSE
    //SINGULIER
    p_genre PartPassSingMas = p_verbes_tree->root->participe_passe->singulier->masculin;
    p_genre PartPassSingFem = p_verbes_tree->root->participe_passe->singulier->feminin;
    
    //PLURIEL
    p_genre PartPassPlurMas = p_verbes_tree->root->participe_passe->pluriel->masculin;
    p_genre PartPassPlurFem = p_verbes_tree->root->participe_passe->pluriel->feminin;
