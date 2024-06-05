/*
    +-------------------------------------------------------------+
    | UNIFAL – Universidade Federal de Alfenas.                   |
    | BACHARELADO EM CIENCIA DA COMPUTACAO.                       |
    | Trabalho..: Heurísticas para um problema NP-Difícil         |
    | Disciplina: Algoritmos e Estrutura de Dados III             |
    | Professor.: Iago Augusto de Carvalho                        |
    | Aluno(s)..: Rodrigo Luís Gasparino Lucatelli                |
    |             José Olavo Monteiro Travassos Pereira da Silva  |
    |             João Felipe Martins Santana                     |
    |             Leonardo Bonardi Marques Silva                  |
    |             Vinícius Henrique Piotto Boiago                 |
    |                                                             |
    | Data......: 02/04/2024                                      |
    +-------------------------------------------------------------+
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../hdr/grasp.h"
#include "../hdr/evolutiva.h"

int main()
{
    srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios
    system("clear");

    // Abertura do arquivo
    char *nomeArquivo = (char *)malloc(100 * sizeof(char));
    printf("Digite o nome do arquivo de instância (ele deve estar no caminho exe/instancias/): \n");
    scanf("%s", nomeArquivo);

    char caminho[] = "./exe/instancias/";
    char *tmp = (char *)calloc(100, sizeof(char));

    strcpy(tmp, caminho); // Copia o caminho para a variável temporária
    strcat(tmp, nomeArquivo); // Concatena o caminho com o nome do arquivo
    FILE *arquivo = fopen(tmp, "r"); // Abre o arquivo
    while (!arquivo)
    {
        printf("\nArquivo não encontrado. Digite novamente: \n");
        scanf("%s", nomeArquivo);
        strcpy(tmp, caminho);
        strcat(tmp, nomeArquivo);
        arquivo = fopen(tmp, "r");
    }

    system("clear");
    int N; // Número de elementos no conjunto

    // Leitura do número de elementos no conjunto
    fscanf(arquivo, "%d", &N);
    if (N % 3 != 0)
    {
        printf("O número de elementos no conjunto deve ser múltiplo de 3.\n");
        return 0;
    }
    int *elements = (int *)malloc(N * sizeof(int)); // Elementos do conjunto

    // Preenchimento do conjunto
    for (int i = 0; i < N; i++)
    {
        fscanf(arquivo, "%d", &elements[i]);
    }

    solution s; // Solução final
    s.partition = (int *)malloc(N * sizeof(int));

    int escolha;
    do
    {
        printf("Escolha o que quer fazer:\n");
        printf("0 - Sair\n");
        printf("1 - GRASP\n");
        printf("2 - Evolutiva\n");
        printf("3 - Alterar instância\n");
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 0:
            printf("Saindo...\n");
            break;
        case 1:
            int GRASPmax; // Número máximo de iterações

            system("clear");

            printf("Digite o número máximo de iterações: ");
            scanf("%d", &GRASPmax);

            GRASP(elements, N, GRASPmax, &s); // Executa o GRASP

            printf("\nSolução final:\n\n");
            printSolution(&s, N, elements);
            break;
        case 2:

            system("clear");

            evolutiva(elements, N, &s); // Executa a busca evolutiva

            printf("\nSolução final:\n\n");
            printSolution(&s, N, elements);
            break;
        case 3:
            system("clear");
            fclose(arquivo);
            printf("Digite o nome do arquivo: \n");
            scanf("%s", nomeArquivo);
            strcpy(tmp, caminho);
            strcat(tmp, nomeArquivo);
            arquivo = fopen(tmp, "r");
            while (!arquivo)
            {
                printf("\nArquivo não encontrado. Digite novamente: \n");
                scanf("%s", nomeArquivo);
                strcpy(tmp, caminho);
                strcat(tmp, nomeArquivo);
                arquivo = fopen(tmp, "r");
            }

            fscanf(arquivo, "%d", &N);
            if (N % 3 != 0)
            {
                printf("O número de elementos no conjunto deve ser múltiplo de 3.\n");
                return 0;
            }

            free(elements);
            elements = (int *)malloc(N * sizeof(int)); // Elementos do conjunto

            // Preenchimento do conjunto
            for (int i = 0; i < N; i++)
            {
                fscanf(arquivo, "%d", &elements[i]);
            }
            free(s.partition);
            s.partition = (int *)malloc(N * sizeof(int));

        default:
            system("clear");
            printf("Opção inválida\n");
            break;
        }
    } while (escolha);

    free(elements);
    free(s.partition);
    fclose(arquivo);
    free(nomeArquivo);
    free(tmp);
    return 0;
}


/**
 * Imprime uma solução
 * 
 * @param s Solução 
 * @param N Número de elementos no conjunto
 * @param elements Elementos do conjunto
 * 
*/
void printSolution(solution *s, int N, int *elements)
{
    
    for (int i = 0; i < ((int)N / 3); i++)
    {
        printf("Partição %d: ", i);
        for (int j = 0; j < N; j++)
        {
            if (s->partition[j] == i)
            {
                printf("%d ", elements[j]);
            }
        }
        printf("\n");
    }
    printf("Custo final: %d\n\n", s->cost);
}