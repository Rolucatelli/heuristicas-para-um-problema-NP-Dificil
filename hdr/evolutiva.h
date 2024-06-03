#ifndef EVOLUTIVA_H
#define EVOLUTIVA_H

#include "grasp.h"

/**
 * @brief Função que realiza a busca local em uma solução
 * 
 * @param elements Vetor de elementos
 * @param N Número de elementos
 * @param s Solução a ser melhorada
 * 
*/
void evolutiva(int *elements, int N, solution *s);

#endif // EVOLUTIVA_H