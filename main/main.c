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


int main()
{
    srand(time(NULL));  // Inicializa a semente do gerador de números aleatórios





    // Abertura do arquivo
    char* nomeArquivo = (char*)malloc(100 * sizeof(char));
    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArquivo);
    char caminho[] = "./exe/instancias/";
    char *tmp = (char*)calloc(100, sizeof(char));
    strcat(tmp, caminho);
    strcat(tmp, nomeArquivo);
    FILE* arquivo = fopen(tmp, "r");
    while (!arquivo)
    {
        printf("Arquivo não encontrado. Digite novamente: ");
        scanf("%s", nomeArquivo);
        strcpy(tmp, caminho);
        strcat(tmp, nomeArquivo);
        arquivo = fopen(tmp, "r");
    }






    int N;  // Número de elementos no conjunto

    fscanf(arquivo, "%d", &N);
    if (N % 3 != 0)
    {
        printf("O número de elementos no conjunto deve ser múltiplo de 3.\n");
        return 0;
    }
    int *elements = (int *)malloc(N * sizeof(int));  // Elementos do conjunto
    int GRASPmax;  // Número máximo de iterações
    solution s;

    // Preenchimento do conjunto
    for (int i = 0; i < N; i++) {
        fscanf(arquivo, "%d", &elements[i]);
    }
    
    printf("Digite o número máximo de iterações: ");
    scanf("%d", &GRASPmax);

    s.partition = (int *)malloc(N * sizeof(int));

    // Chamada do procedimento GRASP
    GRASP(elements, N, GRASPmax, &s);

    // Imprima a solução final
    printf("Partição final:\n");
    for (int i = 0; i < ((int)N/3); i++)
        {
            printf("Partição %d: ", i);
            for (int j = 0; j < N; j++)
            {
                if (s.partition[j] == i)
                {
                    printf("%d ", elements[j]);
                }
            }
            printf("\n");
        }
    printf("Custo final: %d\n", s.cost);


    free(elements);
    free(s.partition);
    fclose(arquivo);
    free(nomeArquivo);
    free(tmp);
    return 0;
}