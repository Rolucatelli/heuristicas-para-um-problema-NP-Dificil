#ifndef AVALIACAOCUSTO_H
#define AVALIACAOCUSTO_H

#include "grasp.h"

/**
 * @brief Função que avalia o custo de uma solução
 * 
 * @param s Solução a ser avaliada
 * @param N Número de elementos
 * @param elements Vetor de elementos
 * @return int Custo da solução
 *
*/
int f(solution *s, int N, int *elements);

#endif // AVALIACAOCUSTO_H