#include "../hdr/grasp.h"
#include "../hdr/avaliacaocusto.h";

void BuscaLocal(int *elements, int N, solution *s)
{
    // Inicializa a melhor solução
    solution best = *s;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < ((int)N / 3); j++)
        {

            // Se a partição do elemento i for diferente de j
            if (s->partition[i] != j)
            {

                // Calcula um novo custo caso a solução seja alterada
                int originalPartition = s->partition[i];
                int indiceJ;
                for (int k = 0; k < N; k++)
                {
                    if (s->partition[k] == j)
                    {
                        indiceJ = k;
                        s->partition[i] = j;
                        s->partition[k] = originalPartition;
                        k = N;
                    }
                }
                int newCost = f(s, N, elements);

                // Altera a solução caso o custo seja menor
                if (newCost < best.cost)
                {
                    best = *s;
                }
                else
                {
                    int temp = s->partition[i];
                    s->partition[i] = s->partition[indiceJ];
                    s->partition[indiceJ] = temp;
                }
            }
        }
    }

    // Atualiza a solução
    s->partition = best.partition;
    s->cost = best.cost;
}