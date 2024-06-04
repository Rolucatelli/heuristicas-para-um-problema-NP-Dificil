#include "../hdr/grasp.h";
#include "../hdr/avaliacaocusto.h";

void Construcao(int *elements, int N, solution *s)
{
    // Aqui estou criando uma matriz com os índices das partições, para que me possibilite garantir que a solução gerada seja realmente uma solução válida

    // Aloca memória para a matriz de números
    int **numbers = (int **)malloc(((int)N / 3) * sizeof(int *));
    for (int i = 0; i < ((int)N / 3); i++)
    {
        numbers[i] = (int *)malloc(3 * sizeof(int));
    }

    // Inicializa a matriz de números com os índices dos elementos
    for (int i = 0; i < ((int)N / 3); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            numbers[i][j] = i;
        }
    }

    // Inicializa o vetor de partições com -1
    for (int i = 0; i < N; i++)
    {
        s->partition[i] = -1;
    }

    // Mesmo com a matriz de números acima, eu ainda gero números aleatórios para que a função crie uma solução diferente a cada execução

    // Preenche o vetor de partições com os elementos disponíveis do vetor de números
    for (int i = 0; i < N; i++)
    {
        int temp = rand() % ((int)N / 3);
        do
        {
            for (int j = 0; j < 3; j++)
            {
                if (numbers[temp][j] != -1)
                {
                    s->partition[i] = numbers[temp][j];
                    numbers[temp][j] = -1;
                    break;
                }
            }
            temp = (temp + 1) % ((int)N / 3);
        } while (s->partition[i] == -1);
    }

    // Calcula o custo da solução
    f(s, N, elements);

    // Libera a memória alocada
    for (int i = 0; i < ((int)N / 3); i++)
    {
        free(numbers[i]);
    }
    free(numbers);
}