#include <stdio.h>
#include <stdlib.h>


#include "../hdr/grasp.h"

void selection(solution *populacao, int individuos, int N)
{

    int media = 0;
    // Calcula a média dos custos
    for (int i = 0; i < individuos; i++)
    {
        media += populacao[i].cost;
    }
    media = (int)(media / individuos);

    // Cria um vetor de soluções aptas
    solution *aptos = (solution *)malloc(individuos * sizeof(solution));
    for (int i = 0; i < individuos; i++)
    {
        aptos[i].partition = (int *)malloc(N * sizeof(int));
        aptos[i].cost = -1;
    }

    // Adiciona as soluções aptas ao vetor, ou seja, as que tem custo menor ou igual a média
    int index = 0;
    for (int i = 0; i < individuos; i++)
    {
        if (populacao[i].cost <= media)
        {
            for (int j = 0; j < N; j++)
            {
                aptos[index].partition[j] = populacao[i].partition[j];
            }
            aptos[index++].cost = populacao[i].cost;
        }
    }

    // Adiciona as soluções aptas ao vetor de soluções
    for (int i = 0; i < individuos; i++)
    {
        populacao[i].cost = aptos[i].cost;
        for (int j = 0; j < N; j++)
        {
            populacao[i].partition[j] = aptos[i].partition[j];
        }
    }

    // Libera a memória alocada
    for (int i = 0; i < individuos; i++)
    {
        free(aptos[i].partition);
    }
    free(aptos);
    
}