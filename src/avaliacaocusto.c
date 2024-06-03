#include <stdio.h>
#include <stdlib.h>
#include "../hdr/grasp.h"

int f(solution *s, int N, int *elements)
{
    // Aloca memória para o vetor de soma
    int *sum = (int *)calloc(((int)N / 3), sizeof(int));
    for (int i = 0; i < N; i++)
    {
        sum[s->partition[i]] += elements[i];
    }

    // Calcula o custo da solução
    s->cost = 0;
    for (int i = 1; i < ((int)N / 3); i++)
    {
        s->cost += abs(sum[i - 1] - sum[i]);
    }
    s->cost += abs(sum[0] - sum[((int)N / 3) - 1]); // Soma a diferença entre o primeiro e o último elemento

    // Libera a memória alocada
    free(sum);
    
    return s->cost;
}