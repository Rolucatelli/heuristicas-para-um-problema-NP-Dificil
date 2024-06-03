#include <stdio.h>
#include <stdlib.h>

#include "../hdr/grasp.h"
#include "../hdr/avaliacaocusto.h"
#include "../hdr/construcao.h"


void breeding(solution *populacao, int individuos, int N, int *elements)
{
    // Encontra a primeira solução não avaliada, ou seja, os que tem que ser gerados
    int index = 0;
    for (int i = 0; i < individuos; i++)
    {
        if (populacao[i].cost == -1)
        {
            index = i;
            break;
        }
    }

    // Cria um vetor de mudanças onde cada posição é um índice de um elemento que será trocado
    int *mudancas = (int *)malloc(((int) (2*N)/ 3) * sizeof(int));
    for (int i = 0; i < ((int) (2*N)/ 3); i++)
    {
        mudancas[i] = rand() % N;
        for (int j = 0; j < i; j++)
        {
            if (mudancas[i] == mudancas[j])
            {
                i--;
                j = i;
            }
        }
    }

    // Copia as soluções aptas para as outras soluções do vetor
    int j = 0;
    for (int i = index; i < individuos; i++)
    {
        for (int k = 0; k < N; k++)
        {
            populacao[i].partition[k] = populacao[j].partition[k];
        }
        populacao[i].cost = populacao[j].cost;
        if (j++ >= index)
        {
            j = 0;
        }
    }

    // Realiza as mudanças nas soluções geradas
    for (int i = index; i < individuos; i++)
    {
        int k;
        int temp = populacao[i].partition[mudancas[0]];
        for (k = 1; k < ((int) (2*N)/ 3); k++)
        {
            populacao[i].partition[mudancas[k - 1]] = populacao[i].partition[mudancas[k]];
        }
        populacao[i].partition[mudancas[k - 1]] = temp;
        f(&populacao[i], N, elements);
    }

    // Gera o último indivíduo da população aleatoriamente
    Construcao(elements, N, &populacao[individuos - 1]);

    // Libera a memória alocada
    free(mudancas);
}