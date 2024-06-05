#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../hdr/grasp.h"
#include "../hdr/avaliacaocusto.h"
#include "../hdr/construcao.h"
#include "../hdr/selecao.h"
#include "../hdr/cruzamento.h"

#define INT_MAX 2147483647

void evolutiva(int *elements, int N, solution *s)
{
    clock_t start, end;
    int escolha, individuos, geracoes = 0, parada, encerrar = 0;
    do
    {
        printf("Escolha uma condição de parada: \n");
        printf("1 - Número de gerações\n");
        printf("2 - Valor de custo\n");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            printf("Digite o número máximo de gerações: ");
            scanf("%d", &parada);
            break;
        case 2:
            printf("Digite o valor de custo (a execução será interrompida se algum individuo tiver o custo menor ou igual ao informado): ");
            scanf("%d", &parada);
            break;
        default:
            printf("Opção inválida\n");
            break;
        }
    } while (escolha != 1 && escolha != 2);

    printf("Digite o número de indivíduos das gerações: ");
    scanf("%d", &individuos);
    start = clock();
    solution *populacao = (solution *)malloc(individuos * sizeof(solution));

    // Inicializa a população
    for (int i = 0; i < individuos; i++)
    {
        populacao[i].partition = (int *)malloc(N * sizeof(int));
        Construcao(elements, N, &populacao[i]);
    }

    do
    {   
        // Seleção os individuos mais aptos
        selection(populacao, individuos, N);

        // Cruzamento entre os individuos mais aptos e mutação
        breeding(populacao, individuos, N, elements);
        geracoes++;

        switch (escolha)
        {
        case 1:
            for (int i = 0; i < individuos; i++)
            {
                if (populacao[i].cost == 0)
                {
                    encerrar = 1;
                }
            }
            if (geracoes >= parada)
            {
                encerrar = 1;
            }
            break;
        case 2:
            for (int i = 0; i < individuos; i++)
            {
                if (populacao[i].cost <= parada)
                {
                    encerrar = 1;
                    break;
                }
            }
            break;

        default:
            break;
        }
    } while (!encerrar);

    int best_cost = INT_MAX;
    // Encontra a melhor solução
    for (int i = 0; i < individuos; i++)
    {
        if (populacao[i].cost < best_cost)
        {
            best_cost = populacao[i].cost;
            for (int j = 0; j < N; j++)
            {
                s->partition[j] = populacao[i].partition[j];
            }
            s->cost = populacao[i].cost;
        }
    }

    // Libera a memória alocada
    for (int i = 0; i < individuos; i++)
    {
        free(populacao[i].partition);
    }
    free(populacao);
    end = clock();
    printf("\nNúmero de gerações: %d\n", geracoes);
    printf("Tempo de execução: %f segundos\n", ((double)(end - start)) / CLOCKS_PER_SEC);
}