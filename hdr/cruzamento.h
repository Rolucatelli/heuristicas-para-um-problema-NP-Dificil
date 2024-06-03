#ifndef CRUZAMENTO_H
#define CRUZAMENTO_H

#include "grasp.h"

/**
 * @brief Função que realiza o cruzamento de duas soluções
 * 
 * @param populacao Vetor de soluções
 * @param individuos Número de indivíduos
 * @param N Número de elementos
 * @param elements Vetor de elementos
 * 
*/
void breeding(solution *populacao, int individuos, int N, int *elements);

#endif // CRUZAMENTO_H