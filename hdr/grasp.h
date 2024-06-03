#ifndef GRASP_H
#define GRASP_H

// Estrutura de solução
typedef struct solution_{
    int *partition;
    int cost;
} solution;

/**
 * @brief Função que executa o GRASP
 * 
 * @param elements Vetor de elementos
 * @param N Número de elementos
 * @param GRASPmax Número de iterações
 * @param s Solução a ser melhorada
 * 
*/
void GRASP(int *elements, int N, int GRASPmax, solution *s);

#endif // GRASP_H