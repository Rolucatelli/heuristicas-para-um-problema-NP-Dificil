#include <stdio.h>
#include <stdlib.h>
#include "../hdr/construcao.h"
#include "../hdr/buscalocal.h"
#include "../hdr/grasp.h"

#define INT_MAX 2147483647

void GRASP(int *elements, int N, int GRASPmax, solution *s)
{
    int f_star = INT_MAX;

    // Inicializa a melhor solução
    solution s_star;
    s_star.partition = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < GRASPmax; i++)
    {
        // Constrói uma solução
        Construcao(elements, N, s);

        // Realiza uma busca local
        BuscaLocal(elements, N, s);

        // Atualiza a melhor solução
        if (s->cost < f_star)
        {
            for (int j = 0; j < N; j++)
            {
                s_star.partition[j] = s->partition[j];
            }
            s_star.cost = s->cost;
            f_star = s->cost;
            if (s->cost == 0)
            {
                break;
            }
        }
    }

    // Copia a melhor solução para a solução final
    for (int j = 0; j < N; j++)
    {
        s->partition[j] = s_star.partition[j];
    }
    s->cost = s_star.cost;

    // Libera a memória alocada
    free(s_star.partition);
}