#ifndef SELERCAO_H
#define SELECAO_H

#include "grasp.h"

/**
 * @brief Função que realiza a seleção de indivíduos
 * 
 * @param populacao Vetor de soluções
 * @param individuos Número de indivíduos
 * @param N Número de elementos
 * 
*/
void selection(solution *populacao, int individuos, int N);

#endif // SELECAO_H